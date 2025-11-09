#include "Account.h"
#include <stdio.h>

// Function prototypes — implement these in your respective .c files
void create_account();
void life_insurance();
void bank_card_renewation();
void deposit_money();
void loan();
void schemes();
void check_balance();

int main() {
    int ch;
    while (1) {
        printf("\n=== Bank Management System Main Menu ===\n");
        printf("1. Create Account\n");
        printf("2. Life Insurance\n");
        printf("3. Bank Card Renewation\n");
        printf("4. Deposit Money\n");
        printf("5. Apply for Loan\n");
        printf("6. Student/Govt Schemes\n");
        printf("7. Check Balance\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: 
                create_account(); 
                break;
            case 2:
                life_insurance();
                break;
            case 3:
                bank_card_renewation();
                break;
            case 4:
                deposit_money();
                break;
            case 5:
                loan();
                break;
            case 6:
                schemes();
                break;
            case 7:
                check_balance();
                break;
            case 0: 
                printf("\nThank you for using the Bank Management System!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
