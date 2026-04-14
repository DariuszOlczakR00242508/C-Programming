#include <stdio.h>
#include <stdlib.h>



/*Write a function that takes an array of integer arrays and returns another array containing all the negative values in the input arrays.

The parameters for the function are the list of arrays, which should be an int **, so an array of pointers, each pointer representing an array of ints; as well as an array containing the lengths of the arrays.

The function should allocate memory for the output array - this does not need to be precise, but sufficient space should be allocated to prevent buffer overflow.

The length of the output array should be passed back through a pointer parameter. In case no negative values are found the function will free the allocated memory and return NULL.
*/

int *get_negative(int *arrays, int arr_lengths[], int input_array){
	
	int i = 0;
	
	int total_size = 0;
	
	
	// Calculate size for malloc
	for (int i = 0; i < arr_lengths; i++){
		total_size += arr_lengths[i];
	}
	
	int *result_array = malloc(total_size * sizeof(int));
	
	
	// Create negative array
	for (i = 0; i < input_array; i++){
		
		
	}
	
	
	
	
	
	return result_array;
	
	
}


int main(){
	// Arrys
	int array1[] = {6, -2, 8, -14, 7};
	int array2[] = {33, 9, 23, 5};
	int array3[] = {-33, 9, 23, -5};
	
	// Array of pointers
	int *arrays[] = (array1, array2, array3);
	
	int arr_lengths[] = {5, 4, 4};
	
	int result_length;
	
	// Array to store negatives
	int *negative = get_negative(arrays, arr_lengths, 3, &result_length);
	
	printf("Negative values: ");
	for (int i = 0; i < result_length; i++) {
		printf("%d ", negative[i]);
        }
	
	free(negative);
	return 0;
}