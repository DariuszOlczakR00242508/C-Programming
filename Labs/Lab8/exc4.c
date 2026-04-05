#include <stdio.h>

// Time structure
struct Time {
    int hours;
    int minutes;
};

// Function to display time
void display_time(struct Time t) {
    printf("%02d:%02d\n", t.hours, t.minutes);
}

// Function to increment time by 1 minute
void increment_time(struct Time *t) {
    t->minutes++;

    if (t->minutes == 60) {
        t->minutes = 0;
        t->hours++;
    }

    if (t->hours == 24) {
        t->hours = 0;
    }
}

// Sleep function
void delay() {
    for (long i = 0; i < 100000000; i++);
}

int main() {
    struct Time current_time = {23, 58}; 

	// 60 minute simulation
    for (int i = 0; i < 60; i++){
        display_time(current_time);
        increment_time(&current_time);
        delay();  
    }

    return 0;
}