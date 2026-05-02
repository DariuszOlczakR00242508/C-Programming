#include <stdio.h>
#include <string.h>


// function to read contents of list
void read_content(char *file_name){
	
	// 1. Open and read file
	FILE *file = fopen(file_name, "r");	
	
	// 2. Check if file exists
	if (file == NULL){
		printf("Error opening file\n");
		return;
	}	
	
	// 3. Create string array to hold lines
	char line[100];
	
	// 4. Read lines and print to the screen 
	while (fgets(line, sizeof(line), file) != NULL){
		printf("%s", line);
		
	}
	// 5. Close file
	fclose(file);
}

void calculate_receipt(char *file_name){
	char item_name[20], highest_item[20];
	float total_price = 0, price, highest_price = 0;
	int number_of_items = 0, qty, matched;

	FILE *f = fopen(file_name, "r");
	
	if (f == NULL) {
    printf("Error opening file\n");
    return;
}
	
	while (!feof(f)){    // While not at the end of the file_name
		matched = fscanf(f, "%s %f %d\n", item_name, &price, &qty); // 
		if (matched == 3){  //If the line matches the expected pattern
			total_price += (price * qty);
			number_of_items += qty;
			if (price > highest_price){
				highest_price = price;
				strcpy(highest_item, item_name);
			}
			
		}		
	}
	
	printf("Total price: %0.2f\n", total_price);
	printf("Average price per item: %0.2f\n", total_price/number_of_items);
	printf("Most expensive item : %s price: %0.2f\n", highest_item, highest_price);
	
}

// 3. Create function to read and append file
void add_item(char *file_name){
	
	
	// Open file
	FILE *file = fopen(file_name, "a");
	
	// Check if exists
	if (file == NULL){
		printf("Error opening file");		
		return;
	}
	
	// Create string array to store entry
	char item[100];
	
	// Append text to the file
	printf("\nAdd item, cost and quantity to list: ");
	fgets(item, sizeof(item), stdin);
	fprintf(file, "%s", item);
		
	// Close file
	fclose(file);


}

// Function to find most expensive item

int main(){
	
	char file_name[] = "receipt.txt";
	read_content(file_name);
	calculate_receipt(file_name);
	add_item(file_name);
	read_content(file_name);
	
	return 0;
}