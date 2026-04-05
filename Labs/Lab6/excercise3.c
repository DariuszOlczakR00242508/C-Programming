#include <stdio.h> 
#include <stdlib.h> 
 
void print_array(int array[], int length){ 
    // a function to print out the values in a 1D integer array 
    int i; 
    putchar('{'); 
    for (i=0; i< length; i++){ 
        printf("%d ", array[i]); 
    } 
    putchar('}'); 
    putchar('\n'); 
} 
 
int *reverse_array(int *array, int length){ 
    // return a reversed version of the array 
    int *reversed = malloc(length * sizeof(int)); // allocate enough bytes for an array of integers 
	if (reversed == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
 
    for (int i = 0;i < length; i++){ 
        reversed[length - 1 - i] = array[i]; 
    } 
    return reversed; 
} 
 
 
int main(){ 
 
    int array_length = 8; 
    int i; 
    int random_array[array_length];  
    

 // initialise the array with random values 
    for (i=0; i < array_length; i++){ 
        random_array[i] = rand()%10; 
    } 
	
	printf("Original array: "); 
    print_array(random_array, array_length); 	
	int *p_array = reverse_array(random_array, array_length);  // a pointer to an integer value 
    printf("Reversed array: "); 
    print_array(p_array, array_length); 
	free(p_array);
 
    return 0; 
} 