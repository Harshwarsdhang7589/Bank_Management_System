#include <stdio.h>
#include <string.h>

// step 08:
#include <stdlib.h>  // for rand(), srand()
#include <time.h>    // for time()



// Function declarations
void create_account();
void life_insurance();
void gov_schemes();
void bank_card_renewation();
void deposit_money();
void loan();
void withdraw_money();
void check_balance();
void exit_message();


// to use const
const char* ACCOUNT_NAME="account.dat";

// to create an STRUCTURE: for backened logic:
typedef struct {
	/// data member:
	char  date_of_birth[30];//31-12-2000 
	char holder_name[50];
	char father_name[50];
	char mother_name[70];
	char place_of_birth[49];
	char domicile_country[90];
	char mob[12];
	char aadhar_card[12];
	char address[100];
	int pincode;
	char pan_card[8];
	char account_number[20];
	
	
	
	float balance;
	int acc_no;
	
}Account; // object created;

int main() {
    while (1) {
        printf("\n\n <<<<<<<<<<Bank Management System>>>>>>>>>>>>>\n");
        printf("\n\n <<<<<<<<<<**Bank of Maharashtra**>>>>>>>>>>>>\n");
        
        printf("\n 1. Create Account");
        printf("\n 2. Special Life Insurance Schemes");
        printf("\n 3. Special Gov. Schemes");
        printf("\n 4. Credit/Debit Card Renewation");
        printf("\n 5. Deposit Money");
        printf("\n 6. Loan");
        printf("\n 7. Withdraw Money");
        printf("\n 8. Check Balance");
        printf("\n 9. EXIT");
		
		
        
        char  choice;
        printf("\n Enter Your Choice: ");
        scanf("%c", &choice);
		getchar();
    
        switch (choice) {
            case '1':
                create_account();
                break;
            case '2':
                life_insurance();
                break;
            case '3':
                gov_schemes();
                break;
            case '4':
                bank_card_renewation();
                break;
            case '5':
                deposit_money();
                break;
            case '6':
                loan();
                break;
            case '7':
                withdraw_money();
                break;
            case '8':
                check_balance();
                break;
            case '9':
                exit_message();
                return 0; // Exit the program
            default:
                printf("\n INVALID CHOICE!!!!");
                break;
        }
    }
}

// Function implementations
void create_account() 
{
    Account acc;
	// by using the file handling : before taking the file name to check is the file opening or not.
		FILE *file = fopen("ACCOUNT_NAME","ab+");
			if(file==NULL) 
			{	printf("\n Unable to open a file!!!");
				return;
			}
			
	char c;
	do 
	 {
		c = getchar();
	}
	while(c !='\n' &&c !=EOF);
	{	
	/* printf("\n Enter Title_name (Mr/Mrs.):");
	fgets(acc.Title_name, sizeof(acc.Title_name), stdin);
	int ind = strcspn(acc.Title_name, "\n");
	acc.Title_name[ind] ='\0'; */
	

	printf("\n Enter the Account Holder's name:");
	fgets(acc.holder_name, sizeof(acc.holder_name), stdin);
	int ind = strcspn(acc.holder_name, "\n");
	acc.holder_name[ind] ='\0';
	

    printf("\n Enter Father's Name: ");
    fgets(acc.father_name, sizeof(acc.father_name), stdin);
    ind = strcspn(acc.father_name, "\n");
    acc.father_name[ind] = '\0';

    printf("\n Enter Mother's Name: ");
    fgets(acc.mother_name, sizeof(acc.mother_name), stdin);
    ind = strcspn(acc.mother_name, "\n");
    acc.mother_name[ind] = '\0';

    printf("\n Enter Place of Birth: ");
    fgets(acc.place_of_birth, sizeof(acc.place_of_birth), stdin);
    ind = strcspn(acc.place_of_birth, "\n");
    acc.place_of_birth[ind] = '\0';

    printf("\n Enter Domicile Country: ");
    fgets(acc.domicile_country, sizeof(acc.domicile_country), stdin);
    ind = strcspn(acc.domicile_country, "\n");
    acc.domicile_country[ind] = '\0';
	
	printf("\n Enter PAN Card Number: ");
	fgets(acc.pan_card, sizeof(acc.pan_card), stdin);
	ind = strcspn(acc.pan_card, "\n");
	acc.pan_card[ind] = '\0';
	
	printf("\n Enter Account Number: ");
	fgets(acc.account_number, sizeof(acc.account_number), stdin);
	ind = strcspn(acc.account_number, "\n");
	acc.account_number[ind] = '\0';


	// TO Generate a unique random account number
    srand(time(NULL));
    acc.acc_no = rand() % 900000 + 100000; // 6-digit account number
    printf("Generated Account Number: %d \n", acc.acc_no);

    // to  set initial balance to 0
    acc.balance = 0.0f;

	
	
	// to write the file:
	fwrite(&acc, sizeof(acc),1,file);// inside this file all the details ( holder name,domicile certificate,place of birth,date of birth) of user defined will get saved inside the 
	fclose(file);
	printf("\n Account created sucessfully!");
	
	}
    
}

void life_insurance() {
    printf("\n Logic not created<<<< \n");
}

void gov_schemes() {
    printf("\n Government Schemes\n");
	printf("\n Logic not created<<<< \n");
}

void bank_card_renewation() {
    printf("\n - Credit/Debit Card Renewation -\n");
	printf("\n Logic not created<<<< \n");
}

void deposit_money() 
{
	// to study all these arguments by practising:
	FILE *file = fopen(ACCOUNT_NAME,"rb+");
		if(file==NULL) 
		{	printf("\n Unable to open a file Due to server down!!!");
				return;
			}
			
	int acc_no;
	float money;
	Account acc_r;
	printf("Enter your account number:");
	scanf("%d", &acc_no); 
	
	printf("Enter an Amount to get Deposited:");
	scanf("%f", &money); 
	
	// to check the original account user details:
	while(fread(&acc_r, sizeof(acc_r),1, file))
	{
		if(acc_r.acc_no==acc_no)
		{
			acc_r.balance +=money;
			fseek(file, -sizeof(acc_r),SEEK_CUR);// this argument is not understood at all;
			fwrite(&acc_r, sizeof(acc_r),1,file);
			printf("Your Account balance with successfully deposited money: Rs %.2f\n", money);
			printf("New balance is: Rs %.2f\n", acc_r.balance);

			fclose(file);
			return;
		}
	}
	fclose(file);
	printf("Account number not found in the records amd Money could not be deposited!!!!",acc_no);
	
		
	
	
    printf("\n --Deposit Money function is Sucessfully executed---\n");
}

void loan()
 {
	 FILE *file = fopen(ACCOUNT_NAME, "rb+");
    if (file == NULL)
		{
        printf("\n Unable to open the file due to server issues!!!\n");
        return;
	
    printf("\n --Loan function is executed Sucessfully--\n");
}

   int acc_no;
    float base_salary, loan_amount, loan_with_interest;
    Account acc_r;

    printf("Enter your account number: ");
    scanf("%d", &acc_no);

    printf("Enter your monthly salary: ");
    scanf("%f", &base_salary);

    // Calculate max eligible loan as 10 times salary
    loan_amount = base_salary * 10;

    // Add common 8% interest
    loan_with_interest = loan_amount * 1.08;

    printf("Eligible loan amount with 8%% interest is: Rs %.2f\n", loan_with_interest);

    // Search and update account
    while (fread(&acc_r, sizeof(acc_r), 1, file)) {
        if (acc_r.acc_no == acc_no) {
            acc_r.balance += loan_with_interest;
            fseek(file, -sizeof(acc_r), SEEK_CUR); // Move back to overwrite record
            fwrite(&acc_r, sizeof(acc_r), 1, file);

            printf("Loan of Rs %.2f credited successfully.\n", loan_with_interest);
            printf("New balance is: Rs %.2f\n", acc_r.balance);

            fclose(file);
            return;
        }
    }
 }

void withdraw_money() {
    printf("\n ---Withdraw Money---\n");
}

void check_balance() {
	
	FILE *file = fopen("ACCOUNT_NAME","rb+");
		if(file==NULL) 
		{	printf("\n Unable to open a file!!!");
				return;
			}
	
	int acc_no;
	Account acc_read;
	
	printf("Enter your account number:");
	scanf("%d", &acc_no);
	
	
	
	while(fread(&acc_read, sizeof(acc_read), 1, file))
	{
		if(acc_read.acc_no==acc_no)
		{
			printf("Your Account balance is Rs:%.2f",acc_read.balance);;
			fclose(file);
			return;
			
		}
		
	
	}
	fclose(file);
		printf(" \n Account No:%d was not found!!....", acc_no);
}
	

void exit_message() {
    printf("\n <<<$CLOSING THE BANK$, Thanks for your Visiting..!!!!>>>>\n");
}

	
	
		
		
		