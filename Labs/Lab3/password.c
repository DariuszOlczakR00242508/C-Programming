#include <stdio.h>

int main (){
	
	
	char password[17];	
	char user_input;
	int i = 0;	
	int non_alpha_counter = 0;
		
	printf("Please enter you password (8 -16 charactters long):\n");
	
	while (1){		
		user_input = getchar();			
		if (user_input == '\n') break;
		
		// Task 3. 30 charcters input limit Warning
		if (1 <=7){
			printf("Your password is to short. Please enter again\n");
			break;
		}		
		else if (i >= 16){
			printf("Your password is to long. Please enter again\n");
			while (getchar() != '\n');
			break;
		}
		else if (non_alpha_counter == 0){
			printf("Your password has no digits. Please enter at least 1 again\n");
			break;
		}
		
		
		password[i] = user_input;		
		
		if (!((user_input >= 'A' && user_input <= 'Z') || (user_input >= 'a' && user_input <= 'z'))){
			non_alpha_counter++;
		}
		i++;
	
	}	

	password[i] = '\0';
		
	
	printf("You entered: %s\n", password);
	return 0;
}