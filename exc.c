#include <stdio.h>
#include <string.h>

int main(){
	
	char name1[10] = "Anne"; //String name
	char name2[10] = "Bill";
	char name3[10] = "Lucas";
	char names[5][10]; // Array of names
	
	strcpy(names[0], name1);
	strcpy(names[1], name2);
	strcpy(names[2], name3);
	
	printf("Names in array:\n");
	for (int i = 0; i < 3; i++){
		printf("Name: %s\n", names[i]);
	}
	
	return 0;
}