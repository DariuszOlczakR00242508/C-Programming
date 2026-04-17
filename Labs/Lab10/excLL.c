#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Student node
struct Student{
	char name[50];
	int stud_id;
	struct Student *next;
};



int main(){
	struct Student *new_student = malloc(sizeof(struct Student));
	if (new_student == NULL){
		printf("Memory allocation fail");
		return 1;
	}
	
	strcpy(new_student->name, "Anna");
	new_student->stud_id = 1;
	new_student->next=NULL;
	
	printf("Name: %s, ID: %d\n", new_student->name, new_student->stud_id);
	
	//Add employee
	
	
	free(new_student);
	
	return 0;
}