#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[20];
	int score;
	float percentage;
} Record;

void write_records(const char *filename){
	Record data[] = {
		{"Alice", 85, 91.2f},
		{"Bob", 72, 77.4f},
		{"Carol", 95, 77.4f}
	};
	int n = 3;
	FILE *f = fopen(filename, "wb");
	if (!f){ 
	perror("write fopen"); 
	return;
	}
	
	// Write the count first
	fwrite(&n, sizeof(int), 1, f);
	
	//Write all records
	size_t written = fwrite(data, sizeof(Record), n, f);
	printf("Wrote %zu records (%zu bytes each)\n", written, sizeof(Record));
	fclose(f);
	}
	
	
	// read records from binary filelength
	void read_records(const char *filename){
		FILE *f = fopen(filename, "rb");
		if (!f){
			perror("read fopen");
			return;
		}
		int n;
		fread(&n,sizeof(int), 1,f);
		printf("File contains %d records\n", n);
		
		// Allocate and read
		Record *data = malloc(n * sizeof(Record));
		if (!data){
			perror("malloc");
			fclose(f);
			return;
		}
		size_t numread = fread(data, sizeof(Record), n, f);
		printf("Read %zu records:\n", numread);
		
		for (int i = 0; i < (int)numread; i++){
			printf(" %-10s score=%d (%.1f%%)\n", data[i].name, data[i].score, data[i].percentage);
		}
		free(data);
		fclose(f);
	}


int main(void){
	const char *file = "records.bin";
	write_records(file);
	printf("\nNow reading back:\n");
	read_records(file);
	
	// try to cat itoa
	printf("\nFile is binary - 'cat records.bin' will show garbage");
	
	
	return 0;
}