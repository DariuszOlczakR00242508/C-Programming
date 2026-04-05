#include <stdio.h> 
#include <string.h> 

#define MAX_EMPLOYEES 50 

// Structure definition for employee 
struct Employee { 
    char name[50]; 
    int employeeID; 
    float hoursWorked; 
    float hourlyWage; 
}; 

// Function to add a new employee record 
void addEmployee(struct Employee employees[], int *count) { 
    struct Employee newEmployee; 
    printf("Enter name: "); 
    scanf("%s", newEmployee.name); 
    printf("Enter employee ID: "); 
    scanf("%d", newEmployee.employeeID); 
    printf("Enter hours worked: "); 
    scanf("%f", &newEmployee.hoursWorked); 
    printf("Enter hourly wage: "); 
    scanf("%f", &newEmployee.hourlyWage); 

    employees[*count] = newEmployee; 
    count++; 
} 

// Function to calculate and display weekly pay for each employee 
void calculateWeeklyPay(struct Employee employees[], int count) { 
    printf("\nWeekly Payroll:\n"); 
    printf("Name\tEmployee ID\tHours Worked\tHourly Wage\tWeekly Pay\n"); 
    for (int i = 0; i < count; i++) { 
        float weeklyPay = employees[i].hoursWorked * employees[i].employeeID; 
        printf("%s\t%d\t\t%.2f\t\t%.2f\t\t%.2f\n", employees[i].name, employees[i].employeeID, employees[i].hoursWorked, employees[i].hourlyWage, weeklyPay); 
    } 
} 

// Function to display all employee records 
void displayEmployees(struct Employee employees[], int count) { 
    printf("\nEmployee Database:\n"); 
    printf("Name\tEmployee ID\tHours Worked\tHourly Wage\n"); 
    for (int i = 0; i < count; i++) { 
        printf("%s\t%d\t\t%.2f\t\t%.2f\n", employees[i].name, employees[i].employeeID, employees[i].hoursWorked, employees[i].hourlyWage); 
    } 
} 

int main() { 
    struct Employee employees[MAX_EMPLOYEES]; 
    int count = 0; 
    int choice; 

    do { 
        printf("\nEmployee Payroll Management System\n"); 
        printf("1. Add Employee\n"); 
        printf("2. Calculate Weekly Pay\n"); 
        printf("3. Display Employees\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 

        switch(choice) { 
            case 1: 
                if (count < MAX_EMPLOYEES) { 
                    addEmployee(employees, count); 
                    printf("Employee added successfully!\n"); 
                } else { 
                    printf("Maximum employee limit reached!\n"); 
                } 
                break; 
            case 2: 
                calculateWeeklyPay(employees, count); 
                break; 
            case 3: 
                displayEmployees(employees, count); 
            case 4: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice!\n"); 
        } 
    } while (choice != 4); 

    return 0; 
} 