#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char *name;
	int id;
	int year;
} Student;

void try_increment(Student s){
	s.year++;
	printf("Inside function: year = %d\n", s.year);
}

void increment_year(Student *s){
	s->year++;
}

void reset_id(Student s){
	s.id = 0;
}

void reset_id_ptr(Student *s){
	s->id = 0;
}

int main(){
	Student tom = {"Tom", 106, 1};
	printf("Before: year = %d\n", tom.year);
	try_increment(tom);
	printf("After increment: year = %d\n", tom.year);
	increment_year(&tom);
	printf("After pointer increment: year = %d\n", tom.year);	
	printf("Before reseting id: id = %d\n", tom.id);
	reset_id(tom);
	printf("After reseting id: id = %d\n", tom.id);
	
	reset_id_ptr(&tom);
	printf("After reseting id with pointer: id = %d\n", tom.id);
	
	return 0;
}