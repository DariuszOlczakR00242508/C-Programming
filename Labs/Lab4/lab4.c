# include <stdio.h>



int main(){
	
	char key[4];
	char user_input;
	int i = 0;
	
	printf("Please enter 3 characters:\n");
	while ((user_input = getchar()) != '\n'){		
		
		if (i < 3){
			key[i++] = user_input;
		} else {
			while (getchar() != '\n');
			break;
		}					
		
	}
	key[i] = '\0';	
	printf("You have entered:\n %s\n", key);
	return 0;
}