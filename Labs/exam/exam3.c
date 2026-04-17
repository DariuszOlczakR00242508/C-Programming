#include <stdio.h>
#include <stdlib.h>



// Write a function that concatenates two int arrays.It will allocate memory for the resulting array
// pass back the length of the resulting array through a pointer parameter

int *concentrate_arrays(const int *array1, int length1, const int *array2, int length2, int *result_length){
	
	int *conc_array;
	int k = 0;
	
	*result_length = length1 + length2;
	conc_array = malloc((*result_length) * sizeof(int));
	
	
	for (int i = 0; i < length1; i++){
		conc_array[k] = array1[i];
		k++;
	}
	for (int i = 0; i < length2; i++){
		conc_array[k] = array2[i];
		k++;
	}
	
	
	return conc_array;
	
	
}


int main(){
	int array1[] = {6, 2, 8, 14, 7};
	int array2[] = {33, 9, 23, 5};
	int result_length;
	int *con_arr = concentrate_arrays(array1, 5, array2 , 4, &result_length);
	for (int i = 0; i < result_length; i++){
		printf("%d", con_arr[i]);
	}
	
	free(con_arr);
	return 0;
}