#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure definition for employee
struct Employee {
    char name[50];
    int employeeID;
    float hoursWorked;
    float hourlyWage;
    struct Employee *next;
};

// Function to create a new employee node
struct Employee* createEmployee(const char *name, int employeeID, float hoursWorked, float hourlyWage) {
    struct Employee *newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    if (newEmployee == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(newEmployee->name, name);
    newEmployee->employeeID = employeeID;
    newEmployee->hoursWorked = hoursWorked;
    newEmployee->hourlyWage = hourlyWage;
    newEmployee->next = NULL;
    return newEmployee;
}

// Function to add a new employee record
void addEmployee(struct Employee **head, const char *name, int employeeID, float hoursWorked, float hourlyWage) {
    struct Employee *newEmployee = createEmployee(name, employeeID, hoursWorked, hourlyWage);
    if (*head == NULL) {
        *head = newEmployee;
    } else {
        struct Employee *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEmployee;
    }
}

// Function to calculate and display weekly pay for each employee
void calculateWeeklyPay(struct Employee *head) {
    printf("\nWeekly Payroll:\n");
    printf("Name\tEmployee ID\tHours Worked\tHourly Wage\tWeekly Pay\n");
    struct Employee *current = head;
    while (current != NULL) {
        float weeklyPay = current->hoursWorked * current->hourlyWage;
        printf("%s\t%d\t\t%.2f\t\t%.2f\t\t%.2f\n", current->name, current->employeeID, current->hoursWorked, current->hourlyWage, weeklyPay);
		current = current->next;
    }
}

// Function to display all employee records
void displayEmployees(struct Employee *head) {
    printf("\nEmployee Database:\n");
    printf("Name\tEmployee ID\tHours Worked\tHourly Wage\n");
    struct Employee *current = head;
    while (current != NULL) {
        printf("%s\t%d\t\t%.2f\t\t%.2f\n", current->name, current->employeeID,
               current->hoursWorked, current->hourlyWage);
        current = current->next;
    }
}

// Function to free memory allocated for the linked list
void freeLinkedList(struct Employee *head) {
    struct Employee *current = head;
    while (current != NULL) {
        struct Employee *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Employee *head = NULL;
    int choice, employeeID;
    char name[50];
    float hoursWorked, hourlyWage;

    do {
        printf("\nEmployee Payroll Management System\n");
        printf("1. Add Employee\n");
        printf("2. Calculate Weekly Pay\n");
        printf("3. Display Employees\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter employee ID: ");
                scanf("%d", &employeeID);
                printf("Enter hours worked: ");
                scanf("%f", &hoursWorked);
                printf("Enter hourly wage: ");
                scanf("%f", &hourlyWage);
                addEmployee(&head, name, employeeID, hoursWorked, hourlyWage);
                printf("Employee added successfully!\n");
                break;
            case 2:
                calculateWeeklyPay(head);
                break;
            case 3:
                displayEmployees(head);
                break;
            case 4:
                freeLinkedList(head);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
