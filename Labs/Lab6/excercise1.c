#include <stdio.h>
#include <stdlib.h>


// Input string length check
// str is a pointer to char, this function gets address of character
// str is pointer to first character of the string
int length_check(char *str){
	int i;
	
	// Pointer arithmetic
	// go to address str[i] (*(str + i)) and get the value
	for(i = 0;str[i] != '\0'; i++);
	return i;	
	}

// A function to duplicate string
// This function returnes pointer to the char
// (char *str_in) points to first character of input string

char **duplicate(char *str_in, int n){
	// Creates a duplicate string in memory
	// Memory is allocated dynamically	
	int str_length = length_check(str_in);
	
	// Allocating a array of pointers
	char **str_copies = malloc(n * sizeof(char *));
	if (str_copies == NULL){
		printf("No memory allocated\n");
		return NULL;
	}
	
	// Creating duplicates
	for (int i= 0; i < n; i++){
		str_copies[i] = malloc((str_length + 1) * sizeof(char));
		if (str_copies[i] == NULL){
			printf("No memory allocated\n");
			return NULL;
		}
		for (int j = 0; j < str_length + 1; j++){
			str_copies[i][j] = str_in[j];
		}
	}
	return str_copies;
	
}
	
int main(){
	char my_string[10];
	int num;
	printf("Enter a string: \n");
	scanf("%s", my_string); 
	
	printf("Enter a number of copies:\n");
	scanf("%d", &num);
	
	char **copies = duplicate(my_string, num);
	if(copies == NULL){
		return 1;
	}
	
	for (int i = 0; i < num; i++){
		printf("%s\n", copies[i]);
		// deallocate the memory
		free(copies[i]);
	}	
	// deallocate the memory	
	free(copies); 
	return 0;
}