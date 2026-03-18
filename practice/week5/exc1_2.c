#include <stdio.h>

int main(void){
	int c;
	int count = 0;
	int vowel_count = 0;
	
	
	while((c = getchar()) != '\n' && c != EOF){
		printf(" char[%d] = '%c' (ASCII %d)\n", count, c, c);
		count++;
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ){
			printf("^vowel!\n");
			vowel_count++;
		}
	}
	

	
	printf("Totoal characters (excl. enter): %d\n", count);
	printf("Total vowels entered: %d\n", vowel_count);
	return 0;
}