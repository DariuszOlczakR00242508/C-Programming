#include <stdio.h>

void calculate_receiept(char *file_name){
	char item_name[10];
	float total_price = 0, price;
	int number_of_items = 0, qty, matched;

	FILE *f = fopen(file_name, "r");
	
	while (!feof(f)){    // While not at the end of the file_name
		matched = fscanf(f, "%s %f %d\n", item_name, &price, &qty);
		if (matched == 3){  //If the line matches the expected pattern
			total_price += (price * qty);
			number_of_items += qty;
			
		}		
	}
	
	printf("Total price: %0.2f\n", total_price);
	printf("Average price per item: %0.2f\n", total_price/qty);
	
}

int main(){
	
	char file_name[] = "receipt.txt";
	calculate_receiept(file_name);
	
	return 0;
}