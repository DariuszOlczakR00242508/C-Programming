#include <stdio.h>
#include <stdlib.h>

typedef struct {	
	int x;
	int y;
} Point;

int main(){
	Point point = {3, 7};
	printf("Value of x: %d\n", point.x);
	printf("Value of y: %d\n", point.y);
	
	return 0;
}