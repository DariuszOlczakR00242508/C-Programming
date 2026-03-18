#include <stdio.h>

// Countiing characters in sting
int length(const char *string){
	int j = 0;
	while (string[j++] != '\0');
	return j - 1;			
	}
	
// Copying String
void copy_string(const char *source, char *dest){	
	int j = 0;
	while(source[j] != '\0'){ // While not nullifier 
		dest[j] = source[j];
		j++;
	}
	dest[j] = source[j]; // Copies nullifier
}

int main(){
	char name[10];
	char copy_name[10];
	char input;
	int i = 0;
	
	printf("Please enter name:\n");
	while((input = getchar()) != '\n'){
		name[i++] = input;		
	}
	name[i] = '\0';
	
	
	printf("You enterd: %s\n", name);
	printf("Your name has %d characters\n", length(name));
	copy_string(name, copy_name);
	printf("Copy of name: %s\n", copy_name);
	return 0;
}