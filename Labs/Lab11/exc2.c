#include <stdio.h>

// Struct for receipt item
typedef struct {
    char name[20];
    float price;
    int qty;
} Item;


// 1. Convert text → binary
void read_text_write_binary(char *text_name, char *bin_name) {
    FILE *txt = fopen(text_name, "r");
    FILE *bin = fopen(bin_name, "wb");

    if (txt == NULL) {
        printf("Error opening text file\n");
        return;
    }
    if (bin == NULL) {
        printf("Error opening binary file\n");
        fclose(txt);
        return;
    }

    Item item;
    int count = 0;

    while (fscanf(txt, "%s %f %d", item.name, &item.price, &item.qty) == 3) {
        fwrite(&item, sizeof(Item), 1, bin);
        count++;
    }

    // Write number of items at end
    fwrite(&count, sizeof(int), 1, bin);

    fclose(txt);
    fclose(bin);

    printf("Converted %d items to binary file.\n", count);
}


// 2. List items from binary
void list_items(char *bin_name) {
    FILE *bin = fopen(bin_name, "rb");

    if (bin == NULL) {
        printf("Error opening file\n");
        return;
    }

    int count;

    // Read number of items from end
    fseek(bin, -(long)sizeof(int), SEEK_END);
    fread(&count, sizeof(int), 1, bin);

    if (count <= 0 || count > 1000) {
        printf("Invalid or corrupted file.\n");
        fclose(bin);
        return;
    }

    fseek(bin, 0, SEEK_SET);

    Item item;

    printf("\nItems in receipt:\n");

    for (int i = 0; i < count; i++) {
        if (fread(&item, sizeof(Item), 1, bin) != 1) {
            printf("Error reading item\n");
            break;
        }

        printf("%d. %s | Price: %.2f | Qty: %d\n",
               i, item.name, item.price, item.qty);
    }

    fclose(bin);
}


// 3. Modify item price
void modify_item(char *bin_name) {
    FILE *bin = fopen(bin_name, "rb+");

    if (bin == NULL) {
        printf("Error opening file\n");
        return;
    }

    int count;

    // Get number of items
    fseek(bin, -(long)sizeof(int), SEEK_END);
    fread(&count, sizeof(int), 1, bin);

    if (count <= 0 || count > 1000) {
        printf("Invalid file.\n");
        fclose(bin);
        return;
    }

    int index;
    printf("Enter item index (0 - %d): ", count - 1);
    scanf("%d", &index);
    while (getchar() != '\n'); // clear buffer

    if (index < 0 || index >= count) {
        printf("Invalid index\n");
        fclose(bin);
        return;
    }

    Item item;

    // Move to correct position
    fseek(bin, (long)index * sizeof(Item), SEEK_SET);

    // Read item
    fread(&item, sizeof(Item), 1, bin);

    printf("Current: %s | Price: %.2f | Qty: %d\n",
           item.name, item.price, item.qty);

    // Modify price
    printf("Enter new price: ");
    scanf("%f", &item.price);
    while (getchar() != '\n'); // clear buffer

    // Move back to overwrite
    fseek(bin, -(long)sizeof(Item), SEEK_CUR);

    fwrite(&item, sizeof(Item), 1, bin);

    fclose(bin);

    printf("Item updated successfully.\n");
}


// Menu
void print_menu() {
    printf("\n1. Convert text (receipt.txt) to binary (receipt.bin)\n");
    printf("2. List all receipt items\n");
    printf("3. Modify an item cost\n");
    printf("4. Exit\n");
}


int main() {
    char text_name[] = "receipt.txt";
    char bin_name[] = "receipt.bin";
    char input;

    while (1) {
        print_menu();

        input = getchar();
        while (getchar() != '\n'); // clear buffer

        switch (input) {
            case '1':
                read_text_write_binary(text_name, bin_name);
                break;
            case '2':
                list_items(bin_name);
                break;
            case '3':
                modify_item(bin_name);
                break;
            case '4':
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
}