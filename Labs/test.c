#include <stdio.h>

int main(){
	char temp_array[30];
	char user_input;
	int i = 0;
	int counter = 0;
	
	printf("Please enter a word:\n>>> ");
	while ((user_input = getchar()) != '\n'){	
		if (i < 30){
			if (!((user_input >= 'a' && user_input <= 'z') || (user_input >= 'A' && user_input <= 'Z'))){
				counter++;
			}
			temp_array[i] = user_input;
			i++;
		}	
		else {
			printf("Too many characters");
			break;
		}	
	}
	temp_array[i] = '\0';
	
	char reflected_array[i*2+1];
	for (int j = 0; j < i; j++){
		reflected_array[j] = temp_array[j];
		reflected_array[i*2-1-j] = temp_array[j];
	}
	reflected_array[i*2] = '\0';
	printf("The reflected string is:\n%s\n", reflected_array);
	printf("Non alpha characters:\n>>> %d\n", counter - 1);
	return 0;
}