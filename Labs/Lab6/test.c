#include <stdio.h>
#include <stdlib.h>

//Input array
void print_array(int *array, int length){
	printf("Printing array of numbers:\n { ");
	for (int i = 0; i < length; i++){
		printf("%d ", array[i]);
	}
	printf("}\n");
}

//Count size of new array for malloc
int count_new_size(int *array,int length, int step){
	int new_size = 0;
	for (int i = 0; i < length; i+= step){
		new_size++;
	}
	printf("New array size: %d\n", new_size);
	return new_size;
}

//Create new array with evert 3 number
int *new_array(int *array,int length, int step){
	int k = 0;
	int new_length = count_new_size(array, length, step);
	int *result_array = malloc(new_length * sizeof(int));
	for (int i = 0; i < length; i+= step){
		result_array[k] = array[i];
		k++;
	}	
	return result_array;
}


int main(){
	int numbers[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int step = 3;
	int length = 10;
	print_array(numbers, length);
	//count_new_size(numbers, step);
	int new_length = count_new_size(numbers, length, step);
	int *result_array = new_array(numbers,length, step);
	print_array(result_array, new_length);
	free(result_array);
	return 0;
}