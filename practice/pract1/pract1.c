# include<stdio.h>

int main(){
	
	// String "A"
	// Character 'A'
	// getchar(); input of a single character returns an int representing character ie '0' = 48(ASCII)
	// Every keypress is a character ie Enter key = '\n'
	// Integer: %d (ASCII)
	// Character: %c
	// A string is char array ending with '\0'
	// char welcoming[6] = "Hello";  (includes '\0' as last character empty space)
	
	char name[20];   				// Array to hold characters as string
	char input;						// declaring variable to hold input
	int i = 0;      				// next free index position in string array
	
	printf("Please enter your name: \n");
	
	while (1){						// Loop to keep enter characters
		input = getchar();			// Enter character
		if (input == '\n')			// If enter finish
			break;
		if (i < 19){				// Prevent overflow
			name[i] = input;		// place character in string array position
			i++;					// Increment index position
		}
		
	}
	name[i] = '\0';					// Make it a String
	
	printf("You entered: %s\n", name);	
	return 0;
}