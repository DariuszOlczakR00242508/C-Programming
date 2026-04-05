#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int length){
	printf("{ ");
	for (int i = 0; i < length; i++){
		printf("%d ", array[i]);
	}
	printf(" }\n");
	
}

// Resample function
int *resample(const int *input, int length, int step_size){
	
	// Calculate new size
	int new_size = 0;
	for (int i = 0; i < length; i += step_size){
		new_size++;
	}
	
	// allocate memory
	int *result = malloc(new_size * sizeof(int));
	
	if (result == NULL){
		printf("Memory allocation failed");
		return NULL;
	}
	
	// Fill new array
	int k = 0;
	for (int i = 0; i < length; i += step_size){
		result[k] = input[i];
		k++;
	}
	return result;
	
}



int main(){
	int input[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int length = 10;
	int step_size = 3;
	
	printf("Original array: \n");
	print_array(input, length);
	
	int *output = resample(input, length, step_size);
	
	// calculate output size for printing	
	int new_size = 0;
	for (int i = 0; i < length; i += step_size){
		new_size++;
	}
	
	printf("Reassambled array:\n");
	print_array(output,new_size);
	
	free(output);
	
	return 0;
}