#include <stdio.h.>
#include <stdlib.h>

int main(void){
	FILE *f;
	char name[50];
	int year, group;
	
	
	if ((f = fopen("students.txt", "r")) == NULL){
		perror("Cannot open students.txt");
		return 1;
	}
	
	//Skip the header line
	char header[100];
	fgets(header, sizeof(header), f);
	printf("Header: %s", header);

	// read all students records
	int count = 0;
	printf("\nStudents\n");
	while(fscanf(f, "%49[^,],%d,%d\n", name, &year, &group) == 3){
		printf(" Name: %-10s Year: %d Group: %d\n", name, year, group);
		count++;
	}
	
	printf("\nTotal: %d students\n", count);
	fclose(f);
	
	return 0;
}