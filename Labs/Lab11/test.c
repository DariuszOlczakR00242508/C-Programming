#include <stdio.h>


//Function to read file
void read_content(char *file_name){
	
	FILE *file = fopen(file_name, "r");	
	
	char line[100];
	
	while (fgets(line, sizeof(line), file) != NULL){
		printf("%s", line);
		
	}
	fclose(file);
}


int main(){
	char file_name[] = "receipt.txt";
	read_content(file_name);
	
	
	
	
	

	
	return 0;
}