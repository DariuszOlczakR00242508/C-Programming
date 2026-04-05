#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Subject structure  
struct subject {  
    char *subject_name;  
    float grade;  
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

// Function to display statistics
void display_subject_statistics(struct student *student1) {
    float sum = 0;
    float max_grade = student1->subjects[0].grade;
    int max_index = 0;

    for (int i = 0; i < student1->num_subjects; i++) {
        sum += student1->subjects[i].grade;

        if (student1->subjects[i].grade > max_grade) {
            max_grade = student1->subjects[i].grade;
            max_index = i;
        }
    }

    float average = sum / student1->num_subjects;

    printf("\nStudent: %s\n", student1->name);
    printf("Average grade: %.2f\n", average);
    printf("Highest grade: %.2f in %s\n", max_grade, student1->subjects[max_index].subject_name);
}

int main() {
    struct student s;

    // Allocate memory for student name
    char temp_name[100];
    printf("Enter student name: ");
    scanf("%s", temp_name);

    s.name = malloc(strlen(temp_name) + 1);
    if (s.name == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    strcpy(s.name, temp_name);

    // Populate subjects
    populate_subjects(&s);

    // Display statistics
    display_subject_statistics(&s);

    // Free memory
    for (int i = 0; i < s.num_subjects; i++) {
        free(s.subjects[i].subject_name);
    }
    free(s.subjects);
    free(s.name);

    return 0;
}