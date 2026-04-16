#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Subject structure  
struct subject {  
    char *subject_name;  
    float grade;  
	struct subject *next;
};  

// Student structure  
struct student {  
    char *name;  
    int num_subjects;  
    struct subject *subjects;  
}; 

// Function to populate subjects
void populate_subjects(struct student *student1) {
    printf("Enter number of subjects: ");
    scanf("%d", &student1->num_subjects);

    // Allocate memory for subjects
    student1->subjects = malloc(student1->num_subjects * sizeof(struct subject));
    if (student1->subjects == NULL) {
        printf("No memory allocated\n");
        return;
    }

	// Temporary subject name
    char temp[100]; 

    for (int i = 0; i < student1->num_subjects; i++) {
        printf("Subject %d name: ", i + 1);
        scanf("%s", temp);

        // Allocate memory for subject name
        student1->subjects[i].subject_name = malloc(strlen(temp) + 1);
        if (student1->subjects[i].subject_name == NULL) {
            printf("No memory allocated\n");
            return;
        }

        strcpy(student1->subjects[i].subject_name, temp);

        printf("Grade: ");
        scanf("%f", &student1->subjects[i].grade);
    }
}

void add_subject(struct student *student1) {
    struct subject *new_subject = malloc(sizeof(struct subject));
    if (new_subject == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    char temp[100];

    printf("Enter subject name: ");
    scanf("%s", temp);

    // Allocate memory for subject name
    new_subject->subject_name = malloc(strlen(temp) + 1);
    if (new_subject->subject_name == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(new_subject->subject_name, temp);

    printf("Enter grade: ");
    scanf("%f", &new_subject->grade);

    new_subject->next = NULL;

    // If list is empty first node
    if (student1->subjects == NULL) {
        student1->subjects = new_subject;
    } 
    else {
        // Traverse to end
        struct subject *current = student1->subjects;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_subject;
    }

    student1->num_subjects++;
}

// Function to display statistics
void display_subject_statistics(struct student *student1) {
    if (student1->subjects == NULL) {
        printf("No subjects available.\n");
        return;
    }

    float sum = 0;
    float max_grade = -1;
    char *top_subject = NULL;

    struct subject *current = student1->subjects;

    while (current != NULL) {
        sum += current->grade;

        if (current->grade > max_grade) {
            max_grade = current->grade;
            top_subject = current->subject_name;
        }

        current = current->next;
    }

    float average = sum / student1->num_subjects;

    printf("\nStudent: %s\n", student1->name);
    printf("Average grade: %.2f\n", average);
    printf("Highest grade: %.2f in %s\n", max_grade, top_subject);
}

void free_subjects(struct student *student1) {
    struct subject *current = student1->subjects;
    struct subject *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;

        free(temp->subject_name);
        free(temp);
    }
}

int main() {
    struct student s;
    s.subjects = NULL;
    s.num_subjects = 0;

    char temp_name[100];
    printf("Enter student name: ");
    scanf("%s", temp_name);

    s.name = malloc(strlen(temp_name) + 1);
    strcpy(s.name, temp_name);

    int choice;

    do {
        printf("\n1. Add Subject\n2. Show Statistics\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            add_subject(&s);
        } 
        else if (choice == 2) {
            display_subject_statistics(&s);
        }

    } while (choice != 3);

    // Free memory
    free_subjects(&s);
    free(s.name);


    return 0;
}