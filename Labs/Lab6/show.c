#include <stdio.h>
#include <stdlib.h>

// Input array
void print_array(const int *array, int size){
	printf("Printing array: \n{");
	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("}\n");
	
}

// Count size of new array with evert third integer
int count_new_size(const int *array, int size, int step){
	int new_size = 0;
	for (int i = 0; i < size; i+= step){
		new_size++;
	}
	printf("New array size: %d\n", new_size);
	return new_size;
}

// Create new array
int *new_array(const int *array, int size, int step){
	int k = 0;
	int new_size = count_new_size(array, size, step);
	int *result_array = malloc(new_size * sizeof(int));
	for (int i = 0; i < size; i+= step){
		result_array[k] = array[i];
		k++;
	}	
	return result_array;
}


int main (){
	int numbers[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int size = 10;
	int step = 3;
	print_array(numbers, size);
	int new_size = count_new_size(numbers, size, step);
	int *result_array = new_array(numbers, size, step);
	print_array(result_array, new_size);
	free(result_array);	
	return 0;
}