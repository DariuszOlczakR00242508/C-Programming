#include <stdio.h>
#include <string.h>

int main(){
	
	//String name
	char name1[10] = "Anne"; 
	char name2[10] = "Bill";
	char name3[10] = "Lucas";
	
	// Array of names
	char names[5][10]; 
	
	// Adding strings
	strcpy(names[0], name1);
	strcpy(names[1], name2);
	strcpy(names[2], name3);
	
	// Printing names from array
	printf("Names in array:\n");
	for (int i = 0; i < 3; i++){
		printf("Name: %s\n", names[i]);
	}
	
	return 0;
}