#include <stdio.h>

//Time structure
struct Time{
	int hrs;
	int mns;
};

// Print time
void print_time(struct Time t){
	printf("%02d:%02d\n", t.hrs, t.mns);
}

//Increment time by 1 mniute
void increment_time(struct Time *t){
	t->mns++;
	if (t->mns == 60){
		t->mns = 0;
		t->hrs++;
	}
	if (t->hrs == 24){
		t->hrs = 0;		
	}
}

// Delay function
void delay(){
	for (long i = 0; i < 10000000; i++);
}

int main(){
	struct Time time = {17,00};	
	print_time(time);
	// 60 minute simulation
	for (int i = 0; i < 60; i++){
		print_time(time);
		increment_time(&time);
		delay();
	}
	
	return 0;
}