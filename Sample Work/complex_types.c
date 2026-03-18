# include <stdio.h>


struct student {
	char *name;
	int id;
	char *course;
	int year;
};



int main(){
	
	
	struct student mike;			// Single variable
	struct student cohort[30];		// Array of students
	
	// Initialising firld by field
	mike.name = "Mike";
	mike.id = 101;
	mike.course = "Business Studies";
	mike.year = 1;
	
	// Struct constant initialiser
	struct student sarah = {"Sarah", 102,"Comp Science", 2};
	
	// Designated initialiser (only set chosen fields)
	struct student anon = {.name = "TBD"};
	
	// Struct assignment (unlike arrays, this is allowed)
	struct student copy = sarah; 	// All fields are copied
	
	
	printf("Name: %s\n", mike.name);
	printf("%s Id no: %d", mike.name, mike.id");
	printf("Course name: %s", mike.course);
	printf("Year: %d", mike.year);
	
	printf("Name: %s\n", sarah.name);
	printf("%s Id no: %d", sarah.name, sarah.id";
	printf("Course name: %s", sarah.course);
	printf("Year: %d", sarah.year);
	
	printf("Name: %s\n", anon.name);
	printf("Name: %s\n", copy.name);
	return 0;
	}