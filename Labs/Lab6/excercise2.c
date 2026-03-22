#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
	int lists_amount;
	
	printf("Enter number of lists:\n");
	scanf("%d", &lists_amount);
	
	int **lists = malloc(lists_amount * sizeof(int *));
	int *lists_lengths = malloc(lists_amount * sizeof(int));
	
	srand(time(NULL));
	
	// Generating lists
	for (int i = 0; i < lists_amount; i++){
		lists_lengths[i] = rand() % 10 + 1;
		lists[i] = malloc(lists_lengths[i] * sizeof(int));
		for (int j = 0; j < lists_lengths[i]; j++){
			lists[i][j] = rand() % 101 + 100;
		}
	}
	
	// Print lists
	for (int i = 0; i < lists_amount; i++){
		printf("List no %d\n", i + 1);
		for (int j = 0; j < lists_lengths[i]; j++){
			printf("%d\n", lists[i][j]);
		}		
	}
	
	// Sorting lists
	for (int k = 0; k < lists_amount; k++){
		int len = lists_lengths[k];
		int *a = lists[k];
		int *b = malloc(len * sizeof(int));
		
		for (int i = 0; i < len; i++){
			int temp = 0;
			
			for (int j = 1; j < len; j++){
				if (a[j] > a[temp]){
					temp = j;
				}
			}
			b[i] = a[temp];
			a[temp] = -1;
		}
		printf("Sorted %d lists\n", k + 1);
		for (int i = 0; i < len; i++){
			printf("%d\n", b[i]);
		}
		free(b);
	}
	
	// Dealocating memory
	for (int i = 0;  i < lists_amount; i++){
		free(lists[i]);
	}
	free(lists);
	free(lists_lengths);
	
	return 0;
}