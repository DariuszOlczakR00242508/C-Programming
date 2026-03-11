# include <stdio.h>

int main(){
	char name[10];	
	char input;
	int i = 0;                  // name string index position
	int j;					// Reversed string index position	
	char ref_name[i+1];
	char reflected_name[i*2+1];  //Reflected array, twice the size of original array plus nullifier
	
	printf("Please enter your name\n");
	while (1){
		input = getchar();
		if (input == '\n')
			break;
		if (i < 10){
			name[i] = input;
			i++;	
		}
	}
	name[i] = '\0';								// Nullyfiong last index to make valid string
	printf("You entered: %s\n", name);
	
	//Reflecting input
	for (j = 0; j < i; j++){
		reflected_name[j] = name[j];         	// Copying line forward
		reflected_name[i*2-1-j] = name[j];		// reversing input from the end
	}
	
	for (j = 0; j < i; j++){
		ref_name[j] = name[j];
		ref_name[i-1-j] = name[j];
	}
	printf("Your name repeted and reflected: %s\n", reflected_name);
	printf("Your name reflected: %s\n", ref_name);
	return 0;
}