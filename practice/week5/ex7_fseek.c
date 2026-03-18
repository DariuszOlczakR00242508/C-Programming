#include <stdio.h>
#include <stdlib.h>


typedef struct {
	char name[20];
	int score;
	float percentage;
	
} Record;

int main(){
	// read just the nth record from binary file
	FILE *f = fopen("records.bin", "rb");
	if (!f){
		printf("Run ex6 first\n");
		return 1;
	}
	// Skip the count integer at the beginning
	int n;
	fread(&n, sizeof(int), 1, f);
	printf("File has %d records\n", n);
	
	// Jump directly to record index 2 (the third one)
	int target = 2;
	if (target >= n){
		printf("record %d doesn't exist\n", target);
		fclose(f);
		return 1;
	}
	
	// calculate offset: after the count int, skip 'target' records
	fseek(f, target * sizeof(Record), SEEK_CUR);
	
	Record r;
	fread(&r, sizeof(Record), 1, f);
	printf("Record %d: %s score=%d (%.1f%%)\n", target, r.name, r.score, r.percentage);
	
	// Go to beggining of records and read the first one
	fseek(f, sizeof(int), SEEK_SET); // Skip the count, go first record
	fread(&r, sizeof(Record), 1, f);
	printf("Record 0: %s score=%d (%.1f%%)\n", r.name, r.score, r.percentage);
	
	fclose(f);
	
	
	return 0;
}