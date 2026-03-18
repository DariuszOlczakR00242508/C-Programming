# include <stdio.h>

void change(int *a){
	*a = 50;
}

int main (){
	int x = 10;
	printf("x = %d\n", x);
	change(&x);
	printf("x = %d\n", x);
	
	return 0;
}