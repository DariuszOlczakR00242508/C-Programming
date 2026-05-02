#include <stdio.h>


// Defining receipt structure
typedef struct{
	char name[20];
	float price;
	int qty;
}



// Function to read text and save to binary
void read_text_write_binary(text_name, bin_name){
	
	
}


// function to list items
void list_items(bin_name){
	
	
}

void modify_item(bin_name){
	
	
}









void print_menu(){
    printf("1. Convert text (receipt.txt) to binary (receipt.bin)\n");
    printf("2. List all receipt items\n");
    printf("3. Modify a item cost\n");
    printf("4. Exit\n");
}

int main(){
    char text_name[] = "receipt.txt";
    char bin_name[] = "receipt.bin";
    char input = 0;

    while (1){
        print_menu();
        while ((input = getchar())=='\n');
        getchar(); // consume newline
        switch (input){
            case '1':
                read_text_write_binary(text_name, bin_name);
                break;
            case '2':
                list_items(bin_name);
                break;
            case '3':
                modify_item(bin_name);
                break;
        }
        if (input == '4') break;
    }

}