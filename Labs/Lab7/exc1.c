#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
const int capacity = 100;
const int num_time_steps = 100;
int memory_state[100][20]; // 100 steps max of 20 tasks running
int step_tasks[100]; // Number of tasks at each step_tasks

int get_allocation(int time_step){
	int total = 0;
	for (int i = 0; i < step_tasks[time_step]; i++){
		total += memory_state[time_step][i];
	}
	return total;
}

int check_space(int start, int end, int amount){
	for (int i = start; i <= end; i++){
		int current = get_allocation(i);
		if (current + amount > capacity){
			return 0;
		}
	}	
	return 1;
}

void allocate_mem(int start, int end, int amount){
	for (int i = start; i <= end; i++){
		memory_state[i][step_tasks[i]] = amount;
		step_tasks[i]++;
	}
}

void print_mem(){
	// Print memory usage over time
	
	unsigned char memory[100][10];
	
	memset(memory, ' ', 1000);
	for (int i = 0; i < 100; i++){
		int cap_i = get_allocation(i);
		for (int j = 0; j < cap_i/10; j++){
			memory[i][j] = '#';
		}
		if (cap_i%10){
			memory[i][cap_i/10] = '^';
		}
	}
	// Rotate
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 100; j++){
			printf("%c", memory[j][i]);			
		}
		printf("\n");
	}

}


int main(){
	int time_step = 0;
	
	memset(step_tasks, 0, 100*sizeof(int));
	while (time_step < num_time_steps){
		// Generate some random tasks
		int num_tasks = rand()%10;
		for (int i = 0; i < num_tasks; i++){
			// Task requested memory[10-20] units
			int task_mem = 10 + rand()%10;
			
			//Task duration
			int task_len = rand()%50;
			int task_id = rand()%1000;
			printf("[%d] Task %d requested %d for %d steps\n", time_step, task_id, task_mem, task_len);
			
			// Check memory allocation
			if (time_step + task_len >= 100){
				task_len = 100 - 1 - time_step;
			}
			
			if (check_space(time_step, time_step + task_len, task_mem)){
				allocate_mem(time_step, time_step + task_len, task_mem);
			}else{
				printf("Request denied for task %d\n", task_id);
			}
			
		}
		time_step++;
		print_mem();
		getchar(); // allow visiualisation
		
	}
	return 0;
}