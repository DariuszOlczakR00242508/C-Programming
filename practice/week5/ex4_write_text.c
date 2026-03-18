#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *f;

	if ((f = fopen("students.txt", "a")) == NULL){
		perror("Error opening file");
		return 1;
	}
	// Write header
	fprintf(f, "Name, Year, Group\n");
	
	// Write students records
	fprintf(f, "%s,%d,%d\n", "Alice", 3, 1);
	fprintf(f, "%s,%d,%d\n", "Bob", 3, 2);
	fprintf(f, "%s,%d,%d\n", "Carol", 2, 1);
	fprintf(f, "%s,%d,%d\n", "Dave", 2, 2);
	
	fclose(f);
	
	printf("Written to students.txt\n");
	printf("Check with cat students.txt");
	
	return 0;
}