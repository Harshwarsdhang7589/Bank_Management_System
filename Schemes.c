#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Enum for Scholarship Types
typedef enum {
    NONE,
    SCHOLAR_UNDER18_HIGH,
    SCHOLAR_18TO23
} ScholarshipType;

// Union for reimbursement types
typedef union {
    float cash_amount;
    char voucher_code[20];
} Reimbursement;

#include "Account.h"
// Structure for Student
typedef struct {
    char name[30];
    int age;
    float percentage;
    ScholarshipType scholarship;
    Reimbursement reimbursement;
} Student;

// Sorting logic based on percentage (descending)
void sortStudentsByPercentage(Student *students, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (students[i].percentage < students[j].percentage) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Searching logic by name
int searchStudentByName(Student *students, int n, const char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i; // student found, return index
        }
    }
    return -1; // not found
}

// *** MAIN FUNCTION FOR YOUR SCHEMES MODULE ***
void schemes(void) { // name matches menu call!
    int n;
    Student students[MAX_STUDENTS];
    printf("\n=== Student/Govt Schemes ===\n");
    printf("How many students? ");
    scanf("%d", &n);
    if(n <= 0 || n > MAX_STUDENTS) {
        printf("Invalid number of students!\n");
        return;
    }

    for(int i=0; i<n; i++) {
        printf("\nEnter name for student %d: ", i+1);
        scanf(" %[^\n]", students[i].name);
        printf("Enter age for %s: ", students[i].name);
        scanf("%d", &students[i].age);
        printf("Enter percentage for %s: ", students[i].name);
        scanf("%f", &students[i].percentage);

        // Scheme logic
        if(students[i].age < 18 && students[i].percentage > 91.0) {
            students[i].scholarship = SCHOLAR_UNDER18_HIGH;
            students[i].reimbursement.cash_amount = 25000;
        } else if(students[i].age >= 18 && students[i].age <= 23) {
            students[i].scholarship = SCHOLAR_18TO23;
            students[i].reimbursement.cash_amount = 60000;
        } else {
            students[i].scholarship = NONE;
        }
    }

    // Sorting Logic (by percentage, descending)
    sortStudentsByPercentage(students, n);

    // Output all results
    printf("\nSorted Student List (by percentage):\n");
    for(int i=0; i<n; i++) {
        printf("\nName: %s | Age: %d | Percentage: %.2f\n", students[i].name, students[i].age, students[i].percentage);
        if(students[i].scholarship == SCHOLAR_UNDER18_HIGH)
            printf("Award: Rs 25000 Scholarship\n");
        else if(students[i].scholarship == SCHOLAR_18TO23)
            printf("Award: Rs 60000 Scholarship\n");
        else
            printf("Award: Not Eligible\n");
    }

    // Optional: Search logic
    char searchName[30];
    printf("\nEnter a student name to search eligibility: ");
    scanf(" %[^\n]", searchName);
    int idx = searchStudentByName(students, n, searchName);
    if(idx != -1) {
        printf("\nStudent found!\nName: %s | Age: %d | Percentage: %.2f\n", students[idx].name, students[idx].age, students[idx].percentage);
        if(students[idx].scholarship == SCHOLAR_UNDER18_HIGH)
            printf("Award: Rs 25000 Scholarship\n");
        else if(students[idx].scholarship == SCHOLAR_18TO23)
            printf("Award: Rs 60000 Scholarship\n");
        else
            printf("Award: Not Eligible\n");
    } else {
        printf("Student not found!\n");
    }
}
