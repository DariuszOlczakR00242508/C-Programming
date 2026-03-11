# include <stdio.h>

int main(){
	char name [10];
	char input;
	int i = 0;
	
	while (1){
		input = getchar();
		if (input == '\n')
			break;
		if (i < 10){
			name[i] = input;
			i++;
		}
	}
	name[i]= '\0';
	printf("You entered: %s\n", name);
	char rev_name[10];
	int j = 0;
	for(i; i < 10; i--){
		name[i] = rev_name[j];
		j++
	}
	return 0;
}