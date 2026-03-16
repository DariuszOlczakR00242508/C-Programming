#include <stdio.h>
#include <stdlib.h>


// Input string length check
int length_check(char *str){
	int i;
	for(i = 0;str[i] != '\0'; i++);
	return i;	
	}

// A function to duplicate string
char *duplicate(char *str_in){
	// Creates a duplicate string in memory
	// Memory is allocated dynamically
	
	int str_length = length_check(str_in);
	char *str_copy = (char *)malloc((str_length +1)*sizeof(char));
	for (int i = 0; i < str_length +1; i++){
		str_copy[i] = str_in[i];
		}
		return str_copy;
	}
	
int main(){
	char my_string[10];
	printf("Enter a string: \n");
	scanf("%s", my_string); // The name of an array is a memory address
	char *copy = duplicate(my_string);
	printf("%s", copy);
	free(copy); // deallocate the memory
	return 0;
}