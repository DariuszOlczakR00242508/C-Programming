#include <stdio.h>
#include <stdlib.h>


struct student {
	char *name;
	char *course;
	int id;
	int year;
};



void print_data(struct student s){
	printf("\n***Printing Students data***\n");
	printf("Student name: %s\n", s.name);
	printf("Student course: %s\n", s.course);
	printf("Student id: %d\n", s.id);
	printf("Student year: %d\n", s.year);
};



int main(){
	
	// Delaring a variable
	struct student mike;
	
		
	// Array of students
	struct student cohort[30];
	
	// Initialising fields
	mike.name = "Mike";
	mike.id = 101;
	mike.year = 1;
	mike.course = "Soft. Dev";
	
	
	// Structure constant initialiser
	struct student sarah = {"Sarah", "Cloud Computing", 102, 2};
	
	// Designated initialiser (only sets chosen fields)
	struct student anon = {.name = "TBD"};
	
	// Struct assignment (unlike arrays this is allowed)
	struct student copy = sarah; // All fields are copied
	
		
	struct student john = sarah;
	john.name = "John";
	
	print_data(mike);
	print_data(sarah);
	print_data(john);
	
	return 0;
}