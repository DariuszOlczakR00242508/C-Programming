#include <stdio.h>
#include <stdlib.h>


// Check length
int check_length(char *string){
	int length = 0;
	for (int i = 0; string[i] != '\0'; i++){
		length++;
	}	
	return length;
}

// Creating array of pointers to store strings that will be rotated
char **generate_array(char *string, int rows, int length){

	char **gen_array = malloc(rows * sizeof(char *));
	
	for (int i = 0; i < rows; i++){
		gen_array[i] = malloc((length + 1) * sizeof(char));
		for (int j = 0; j < length; j++){
			gen_array[i][j] = string[j];			
		}		
		gen_array[i][length] = '\0';
	}	
	return gen_array;
}

// Rotate generated array
char **rotate_array(char **gen_array, int rows, int columns){
	char **rotated = malloc(columns * sizeof(char *)); // Rows to columns
	for (int i = 0; i < columns; i++){
		rotated[i] = malloc((rows + 1) * sizeof(char));
		for (int j = 0; j < rows; j++){
			rotated[i][j] = gen_array[j][i]; // Swaping places
		}
		rotated[i][rows] = '\0';
	}
	return rotated;
}

// Print array and deallocate memory
void print_deallocate(char **array, int count){
	for (int i = 0; i < count; i++){
		printf("%s\n", array[i]);
		free(array[i]);
	}
	free(array);
}


int main(){
	char string[5] = "abcd";
	int rows = 3;
	int length = check_length(string);	
	int columns = length;
	char **gen_array = generate_array(string, rows, length);
	char **rotated = rotate_array(gen_array, rows, columns);
	
	// Freeing up gen_array memory 
	print_deallocate(gen_array, rows);
	
	// Freeing up rotated memory
	print_deallocate(rotated, columns);
	
	
	return 0;
}