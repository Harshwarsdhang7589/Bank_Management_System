#include <stdio.h>
#include "Account.h"
#include <string.h>

     
  
   void loan() {
    FILE *fp = fopen("accounts.dat", "rb+");
    if (!fp) { printf("File open error!\n"); return; }

    int acct_num;
    printf("Enter your account number: ");
    scanf("%d", &acct_num);

    Account acc;
    int found = 0;
    long pos;
    while ((pos = ftell(fp)), fread(&acc, sizeof(Account), 1, fp) == 1) {
        if (acc.account_no == acct_num) {
            printf("Yearly Salary: %.2f\n", acc.yearly_salary);
            float loan_amt;
            printf("Enter loan amount: ");
            scanf("%f", &loan_amt);
            acc.balance += loan_amt;
            fseek(fp, pos, SEEK_SET);
            fwrite(&acc, sizeof(Account), 1, fp);
            printf("Loan credited. New balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) printf("Account not found.\n");
}
