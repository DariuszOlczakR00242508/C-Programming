# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main(){
	
	int a[10];
	int b[10]; // Second array to store numbers
	int i, j, tmp;
	
	srandom(time(NULL));   // Added time to avoid duplicating generated numbers
	
	// Generating array with random numbers from 100 to 200
	for (i = 0; i < 10; i++){
		a[i] = random() % 101 + 100;
		}
	
	
	// Printing generated array 
	printf("Printing generated array of numbers:\n");
	for (i = 0; i < 10; i++){
		printf("%d ", a[i]); 		
		}
	printf("\n");
	
	
	// Sorting into arrays
	for (i = 0; i < 10; i++){
		tmp = 0;
		for (j = 1; j < 10; j++){
			if (a[j] > a[tmp]){
				tmp = j;
			}
		}
		b[i] = a[tmp];
		a[tmp] = -1;
	}
	
	// Print sorted array
	printf("Printing sorted array of numbers:\n");
	for (i = 0; i < 10; i++) {
		printf("%d ", b[i]); 
		}
		printf("\n");
		return 0;
}