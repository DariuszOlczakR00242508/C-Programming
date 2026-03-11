# include <stdio.h>

int main(){
	int size = 20;
	char name[size];
	char input;
	int i = 0;
	
	printf("Please enter your name:\n");
	while (1){
		
		input = getchar();
		if (input == '\n')
			break;
		if (i < size-1){
			name[i] = input;
			i++;
		} else {
			printf("To Many characters entered. Should be %d", size - 1);
			break;
		}
	}
	name[i] = '\0';
	
	printf("You entered: %s\n", name);
	
	return 0;
}