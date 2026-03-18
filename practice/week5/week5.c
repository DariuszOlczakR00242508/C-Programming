#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	int age = 21;
	float gpa = 3.75;
	char grade = 'A';
	char name[] = "Alice";
	
	printf("Name: %s\n", name);
	printf("Age: %d\n", age);
	printf("Grade: %c\n", grade);
	printf("gpa: %f\n", gpa);
	printf("gpa (2 dec): %.2f\n", gpa);
	
	int chars = printf("this line has how many characters?\n");
	printf("Answer: %d characters printed\n", chars);
	
	char dangerous[] = "Hello %d world";
    printf("%s\n", dangerous);
	
	return 0;
}