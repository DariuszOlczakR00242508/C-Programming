#include <stdio.h>

void read_input(){
    char user_input;
    while ((user_input = getchar()) != '\n'){
		if (user_input >= 'a' && user_input <= 'z'){
			user_input = user_input - 5;
			if (user_input < 'a'){
				user_input = user_input + 25;
			}
		}
		putchar(user_input);
	}
}

int main(){
	read_input();
	return 0;
}