#include <stdio.h>


// 2. Create a function to read file
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


// 3. Create function to read and append file
void append_content(char *file_name){
	
	
	// Open file
	FILE *file = fopen(file_name, "a");
	
	// Check if exists
	if (file == NULL){
		printf("Erro opening file");		
		return;
	}
	
	// Create string array to store entry
	char text[100];
	
	// Append text to the file
	printf("\nEnter text to append: ");
	fgets(text, sizeof(text), stdin);
	fprintf(file, "%s", text);
	
	
	// Close file
	fclose(file);


}


int main(){
	// 1. Create string array to hold file name
	char file_name[] = "receipt.txt";
	
	char test[] = "test.txt";
	
	// Pass file name as parameter in function
	read_content(file_name);
	read_content(test);
	
	append_content(test);
	read_content(test);
	
	
	
	
	

	
	return 0;
}