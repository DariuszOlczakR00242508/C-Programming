#include <stdio.h>
#include <stdlib.h>
typedef enum{
	YEAR_ONE = 1,
	YEAR_TWO,
	YEAR_THREE,
	YEAR_FOUR,
	YEAR_FIVE
}AcademicYear;

typedef enum{
	PASS = 40,
	MERIT = 60,
	DISTINCTION = 70
}Grade;

int main(){
	
	AcademicYear yr = YEAR_TWO;
	
	switch(yr){
		case YEAR_ONE: printf("Year 1\n"); break;
		case YEAR_TWO: printf("Year 2\n"); break;
		case YEAR_THREE: printf("Year 3\n"); break;
		case YEAR_FOUR: printf("Year 4\n"); break;
		case YEAR_FIVE: printf("Year 5\n"); break;
	}
	
	printf("YEAR_ONE = %d\n", YEAR_ONE);
	printf("YEAR_TWO = %d\n", YEAR_TWO);
	printf("YEAR_FIVE = %d\n", YEAR_FIVE);
	
	Grade gr = PASS;
	
	switch(gr){
		case PASS: printf("Pass: 0\n"); break;
		case MERIT: printf("Merit: 1\n"); break;
		case DISTINCTION: printf("Distinction: 2\n"); break; 
	}
	
	printf("PASS: %d\n", PASS);
	printf("MERIT: %d\n", MERIT);
	printf("DISTINCTION: %d\n", DISTINCTION);
	
	return 0;
}