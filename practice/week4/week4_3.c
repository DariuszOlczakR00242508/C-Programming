#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char *name;
	char *course;
	int id;
	int year;	
} Student;

void print_data(Student s){
	printf("\n***Printing Students data***\n");
	printf("Student name: %s\n", s.name);
	printf("Student course: %s\n", s.course);
	printf("Student id: %d\n", s.id);
	printf("Student year: %d\n", s.year);
};

int main(){
	Student morgan = {"Morgan", "political studies", 103, 3};
	Student albert = {"Albert", "Physics", 104, 4};
	
	print_data(morgan);
	print_data(albert);
	
	Student *ptr = &morgan;
	Student *ptr_al = &albert;
	
	
	printf("%s\n", (*ptr).name);
	printf("%s\n", ptr->name);
	
	
	
	ptr->year = 4;
	ptr_al->id = 105;
	printf("%d\n", morgan.year);
	printf("*ptr.name");
	
	print_data(morgan);
	print_data(albert);
	
	
	return 0;
}