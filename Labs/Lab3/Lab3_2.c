#include <stdio.h>



int validation(int length, int upper_case, int lower_case, int digit){
	password[length] = '\0';
	if (length < 8){
		printf("Password too short (min 8 characters)\n");
		return 0;
	}

	if (upper_case == 0){
		printf("Please use at least 1 uper case character\n");
		return 0;
	}

	if (lower_case == 0){
		printf("Please use at least 1 lower case character\n");
		return 0;
	}

	if (digit == 0){
		printf("Please use at least 1 number character\n");
		return 0;
	}

		
	return 1;
			
}

int main (){
	char password[17];	
	char copied_password[17];
	char user_input;
	int length = 0;	
	
	int non_alpha_counter = 0;
	int upper_case = 0;
	int lower_case = 0;
	int digit = 0;
	int special_sign = 0;
	
	while (1){
		length = 0;
		upper_case = 0;
		lower_case = 0;
		digit = 0;
		special_sign = 0;
		printf("Please enter a password:\n");
		
		while (1){	
		user_input = getchar();	
		
		if (user_input == '\n') break;
		
		if (length == 16){
			printf("Warning. Password Too Long (max 16 characters).\n");
			while (getchar() != '\n');
			break;
		}
		password[length] = user_input;		
		
		
		if (!((user_input >= 'A' && user_input <= 'Z') || (user_input >= 'a' && user_input <= 'z')))
			non_alpha_counter++;
		
		if (user_input >= 'A' && user_input <= 'Z')
			upper_case++;
		
		if (user_input >= 'a' && user_input <= 'z')
			lower_case++;
		
		if (user_input >= '0' && user_input <= '9')
			digit++;
		
		if (!((user_input >= 'A' && user_input <= 'Z') || (user_input >= 'a' && user_input <= 'z') || (
user_input >= '0' && user_input <= '9')))
			special_sign++;
					
		length++;	
		
		}
		password[length] = '\0';
	
		if (validation(length, upper_case, lower_case, digit))
			break;
	}
	
	if (special_sign > '0'){
		printf("You have %d Special Characters. Your Password is Strong\n", special_sign);
	}
	else {
		printf("You have no special characters. Your Password is Weak\n");
	}
	
	/*
	printf("Non alphabetic input: %d\n", non_alpha_counter);
	printf("Upper Case input: %d\n", upper_case);
	printf("Lower Case input: %d\n", lower_case);
	printf("Number input: %d\n", digit);
	printf("Special sign input: %d\n", special_sign);
	*/
	
	return 0;
}