#include "Account.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Helper: get next prime after random number, for account number
int next_prime(int n) {
    int i, j, is_prime;
    for (i = n + 1; i < 1000; i++) { // Only for 3 digits
        is_prime = 1;
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                is_prime = 0; break;
            }
        }
        if (is_prime) return i;
    }
    return 101; // Default
}



void create_account() {
    Account acc;
    FILE *fp = fopen("accounts.dat", "ab+"); // Append binary
    if (fp == NULL) {
        printf("Failed to open account file.\n");
        return;
    }

    // Name
    printf("Enter Name: ");
    scanf(" %[^\n]", acc.name);

    // Age
    printf("Enter Age: ");
    scanf("%d", &acc.age);

    // Working or not
    printf("Are you working? (1-Yes, 0-No): ");
    scanf("%d", &acc.working);

    if (acc.working) {
        printf("Enter Institution: ");
        scanf(" %[^\n]", acc.institution);
        printf("Enter Yearly Salary: ");
        scanf("%f", &acc.yearly_salary);
    } else {
        acc.institution[0] = '\0';
        acc.yearly_salary = 0;
    }

    // Balance input
    printf("Enter initial balance: ");
    scanf("%f", &acc.balance);

    // 3-digit account number, must be prime
    srand((unsigned) time(NULL));
    int rand_num = rand() % 900 + 100; // Between 100-999
    acc.account_no = next_prime(rand_num);
    printf("Generated 3-digit Prime Account Number: %d\n", acc.account_no);

    // Save data to file
    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);
    printf("Account created and saved!\n");
}
