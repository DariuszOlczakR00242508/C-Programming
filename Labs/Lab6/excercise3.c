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
 
int reverse_array(int *array){ 
    // return a reversed version of the array 
    int i; 
    int *reversed = malloc(length*sizeof(char)); // allocate enough bytes for an array of integers 
 
    for ( ;i<length;i++){ 
        reversed[length-1-i] == array[i]; 
    } 
    return reversed; 
} 
 
 
int main(){ 
 
    int array_length = 8; 
    int i; 
    int random_array[array_length];  
    int *p_array;  // a pointer to an integer value 

 // initialise the array with random values 
    for (i=0; i<array_length; i++){ 
        random_array[i] = rand()%10; 
    } 
 
    printf("Original array: "); 
    print_array(random_array, array_length); 
 
    p_array = reverse_array(random_array, array_length); 
    printf("Reversed array: "); 
    print_array(p_array, array_length); 
 
 
    return 0; 
} 