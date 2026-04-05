#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

// Define the size of the Cartesian plane 
#define SIZE_X 10 
#define SIZE_Y 10 

// Define a struct for a point with x and y coordinates 
struct Point { 
    int x; 
    int y; 
	char symbol;
}; 

  
// Function to print Cartesian plane with points 
void print_points(struct Point points[], int num_points) { 
    char grid[SIZE_Y][SIZE_X]; 
	
	// Using memset instead of nested loops
	memset(grid, ' ', SIZE_Y * SIZE_X * sizeof(char));
	    

    // Plot points on the grid 
    for (int i = 0; i < num_points; i++) { 
        int x = points[i].x + SIZE_X / 2; // shift x to center 
        int y = SIZE_Y / 2 - points[i].y; // shift y to center and flip vertically 
        if (x >= 0 && x < SIZE_X && y >= 0 && y < SIZE_Y) { 
            grid[y][x] = points[i].symbol; // mark the point with a '*' 
        } 
    } 

    // Print the Cartesian plane 
    printf(" Cartesian Plane:\n"); 
    for (int i = 0; i < SIZE_Y; i++) { 
        for (int j = 0; j < SIZE_X; j++) { 
            printf("%c ", grid[i][j]); 
        } 
        printf("\n"); 
    } 
} 

// Function to get input points
struct Point * user_points(int *num_points){
	printf("Please enter number of points:\n");
	scanf("%d", num_points);
	
	// Allocate memory for points
	struct Point *points = malloc((*num_points) * sizeof(struct Point));
	if (points == NULL){
		printf("No memory allocated\n");
		return NULL;
	}
	// Input each point
	for (int i = 0; i < *num_points; i++){
		printf("Point %d:\n", i + 1);
		
		printf("x: ");
		scanf("%d", &points[i].x);
		
		printf("y: ");
		scanf("%d", &points[i].y);
		
		printf("Symbol: ");
		scanf(" %c", &points[i].symbol);
	}
	return points;
}

int main() { 
    // Create an array of points with symbols 
    struct Point points[] = { 
        {0, 0, 'A'}, 
        {1, 1, 'B'}, 
        {2, 3, 'C'}, 
        {-1, 2, 'D'}, 
        {4, -4, 'E'} 
    }; 

    int num_points = sizeof(points) / sizeof(points[0]); 

    // Print out the points on the Cartesian plane 
	printf("Example points:\n");
    print_points(points, num_points); 

	// Inputted points
	int input_num;
	struct Point *input_pts = user_points(&input_num);
	if (input_pts != NULL){
		printf("Inputted Points:\n");
		print_points(input_pts, input_num);
		free(input_pts);
	}

    return 0; 
}