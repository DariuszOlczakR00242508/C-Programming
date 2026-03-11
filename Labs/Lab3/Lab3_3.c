# include<stdio.h>

int main(){
	int numbers[10];
	char input;
	int i = 0;	
	int sum = 0;
	
	
	// Read in 10 integers and populate the array	
	printf("Please enter 10 numbers (0-9):\n");
	while (i < 10){
		input = getchar();
		if (input == '\n')
			continue;		
		if (input < '0' || input > '9'){
			printf("Please enter number from 0 to 9\n");
			continue;
		}
		numbers[i] = input - '0';   // convert ASCII char to int
		i++;
	}
		
	
	// Sum up the values in the array
	for (i = 0; i < 10; i++){
		sum += numbers[i];
	}
	printf("Sum: %d\n", sum);
	return 0;
	
}