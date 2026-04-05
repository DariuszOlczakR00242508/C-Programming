#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, int length){
	printf("Printing array: \n{ ");
	for (int i = 0; i < length; i++){
		printf("%d ", array[i]);
	}
	printf(" }");
};

int counting_new_size(const int *array, int length, int step){
	int new_size = 0;
	for (int i = 0; i < length; i += step){
		new_size++;
	}
	return new_size;
}

int *new_array(const int *array, int length, int step){
	int k = 0;
	int size = counting_new_size(array, length, step);
	int *result_array = malloc(size * sizeof(int));	
	
	for (int i = 0; i < length; i += step){
		result_array[k] = array[i];
		k++;		
	}	
	return result_array;
}


int main(){
	int numbers[10] = {20, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int length = 10;
	int step = 3;
	print_array(numbers, length);
	int size = counting_new_size(numbers, length, step);
	int *result_array = new_array(numbers, length, step);
	print_array(result_array, size);
	free(result_array);
	
	return 0;
}