#include <stdio.h>

int main(){
	int num;
	float fnum;
	char word[50];
	int result;
	int c;
	int count;
	
	printf("Enter an integer:\n");
	result = scanf("%d", &num);
	printf("scanf returned: %d, you enterd: %d\n", result, num);
	while ((c = getchar() != '\n') &&  c != EOF)
	
	
	printf("Enter a float:\n");
	result = scanf("%f", &fnum);
	printf("scanf returne: %d, you entered: %.2f\n", result, fnum);
	while ((c = getchar() != '\n') &&  c != EOF)
	
	printf("Enter a word\n");
	result = scanf("%s", &word);
	printf("scanf returnedL: %d,you entered: %s\n", result, word);	
	while ((c = getchar() != '\n') &&  c != EOF)
		
	printf("Type a line and press Enter:\n");
	while((c = getchar()) != '\n' && c != EOF){
		printf(" char[%d] = '%c' (ASCII %d)\n", count, c, c);
		count++;
	}
	printf("Total characters (excluding '\n'): %d\n", count);
	
	
	return 0;
}