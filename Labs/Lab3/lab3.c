#include <stdio.h>

int main (){
	
	
	char temp_array[30];	
	char user_input;
	int i = 0;	
	
	// Task 2. Non alphabetic country
	int non_alpha_counter = 0;
	
	printf("Please enter a word:\n");
	
	while (1){		
		user_input = getchar();			
		if (user_input == '\n') break;
		
		// Task 3. 30 charcters input limit Warning	
		if (i >= 29){
			printf("Waring. Too many characters enterd.\n");
			while (getchar() != '\n');
			break;
		}
				
		temp_array[i] = user_input;
		
		// Task 2. Non Alphabetic Count
		if (!((user_input >= 'A' && user_input <= 'Z') || (user_input >= 'a' && user_input <= 'z'))){
			non_alpha_counter++;
		}
		i++;
	
	}
	
	// Task 1. Make a valid string input.
	// To have this as a valid String input we need to Nullyfy it at the end
	
	temp_array[i] = '\0';
	
	
	char reflected_array[i*2 + 1];
	
	for (int j = 0; j < i; j++){
		reflected_array[j] = temp_array[j];
		reflected_array[i*2 -1 - j]	= temp_array[j];
	}
	
	reflected_array[i*2] = '\0';
	printf("The reflected Array String is: %s\n", reflected_array);
	printf("Non alphabetic input: %d", non_alpha_counter);
	return 0;
}