#include <stdio.h>

int main(){
	char name[10];
	char input;
	int i = 0;
	
	printf("Please enter a name\n");
	
	while((input = getchar()) != '\n'){
		if (i < 9){
			name[i] = input;
			i++;
		} 
		else {
			while (getchar() != '\n'){
				;
			}
			break;
		}
	}
	name[i] = '\0';
	printf("you entered: %s\n", name);
	return 0;
}