#include <stdio.h>
#include <stdlib.h>



// Function that clones string passed in parameter
char *copied_parameter(char *string){
	int i = 0;
	char *copied_param = malloc(20 * sizeof(char));
	while (string[i] != '\0'){
		copied_param[i] = string[i];
		i++;		
	}
	copied_param[i] = '\0';
	printf("Copy of string: %s\n", copied_param);
	return copied_param;
}

int main(){
	char *copy = copied_parameter("Exam");
	free(copy);
	return 0;
}