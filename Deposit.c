#include "Account.h"
#include <stdio.h>
#include <string.h>



void deposit_money() {
    FILE *fp = fopen("accounts.dat", "rb+");
    if (!fp) { printf("File open error!\n"); return; }

    int acct_num;
    float amt;
    printf("Enter your account number: ");
    scanf("%d", &acct_num);

    Account acc;
    int found = 0;
    long pos;
    while ((pos = ftell(fp)), fread(&acc, sizeof(Account), 1, fp) == 1) {
        if (acc.account_no == acct_num) {
            printf("Previous balance: %.2f\n", acc.balance);
            printf("Enter deposit amount: ");
            scanf("%f", &amt);
            acc.balance += amt;
            fseek(fp, pos, SEEK_SET);
            fwrite(&acc, sizeof(Account), 1, fp);
            printf("New balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) printf("Account not found.\n");
}

void check_balance() {
    FILE *fp = fopen("accounts.dat", "rb");
    if (!fp) { printf("File open error!\n"); return; }

    int acct_num;
    printf("Enter your account number: ");
    scanf("%d", &acct_num);

    Account acc;
    int found = 0;
    while (fread(&acc, sizeof(Account), 1, fp) == 1) {
        if (acc.account_no == acct_num) {
            printf("Account Holder: %s\n", acc.name);
            printf("Current Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) printf("Account not found.\n");
}

