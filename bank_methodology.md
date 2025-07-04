# Bank Management System : BANK OF MAHARASHTRA!!!

            *Created by .....@Harshwardhan Gaikwad
##  Step 1. Project Objective

### 💡 **Why this project?**

>In real life, banks use software to manage accounts, deposits, withdrawals, loans, insurance, and card services.  
This mini project simulates the **Bank of Maharashtra** console-based system to practice **C structures, functions, menus, and data handling**.

---

##  Step 2. Include Necessary Libraries

### 💡 **Why are we including these?**

>- `stdio.h`: For standard input/output functions like printf, scanf.
>- `string.h`: For string operations like fgets, strcspn.

### 🔷 **Code:**

```c
#include <stdio.h>
#include <string.h>
```

## Step 3. Declare Function Prototypes

💡 **Why declare them first?**

>Function it tell the compiler that these functions exist and will be defined later.  
This avoids errors when calling them from `main()` before their actual definition.
---
```c
void create_account();
void life_insurance();
void gov_schemes();
void bank_card_renewation();
void deposit_money();
void loan();
void withdraw_money();
void check_balance();
void exit_message();
```
## **Step 4. Create Structure for Account Details**
---
💡 What is a structure here?
>A **struct** groups different types of data into one logical unit – like a database record for each account holder.
Here it stores personal details + account balance + account number in a single variable.
---
```c
typedef struct {
	int date_of_birth[30];
	char holder_name[50];
	char father_name[50];
	char mother_name[70];
	char place_of_birth[49];
	char domicile_country[90];
	int mob[12];
	int aadhar_card[12];
	char address[100];
	int pincode;
	float balance;
	int acc_no;
} Account; 
```
---
## **Step 5. Main Function and Menu Design :**
###  Why while(1) is used?

>To display menu infinitely until user exits.
Switch-case executes options based on user’s choice.
---
```c
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
        
        int choice;
        printf("\n Enter Your Choice: ");
        scanf("%d", &choice);
    
        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                life_insurance();
                break;
            case 3:
                gov_schemes();
                break;
            case 4:
                bank_card_renewation();
                break;
            case 5:
                deposit_money();
                break;
            case 6:
                loan();
                break;
            case 7:
                withdraw_money();
                break;
            case 8:
                check_balance();
                break;
            case 9:
                exit_message();
                return 0;
            default:
                printf("\n INVALID CHOICE!!!!");
                break;
        }
    }
}
```
---
## Step 6. Implement create_account() Function:
###  Why this function?
>To collect new account holder details and store them in a structure variable for backend logic.
Uses fgets to input strings safely including spaces, then replaces newline \n with \0 for proper string termination.

 **fgets** are used to Collecting inputs user deatils from the user ( like: **Holder name,father,mother name**,etc).

 **strcspn** removes newline (\n) added by fgets.
 


---
# FILE HANDLING :
## Step 07:Implement create_account() Function with File Handling
>In this step, 
    I am going to collect the user deatils from the user ( like: **Holder name,father,mother name**,etc)and after that we  are saving these details permanently into a file so that they are not lost when the program ends. [ file handling]

---    
```c
void create_account() {
    FILE *file = fopen("account.dat", "ab+"); // opens file in append-binary mode
    if(file == NULL) {
        printf("\n Unable to open a file!!!");
        return;
    }

    Account acc;

    printf("\n Enter the Holder's name:");
    fgets(acc.holder_name, sizeof(acc.holder_name), stdin);
    int ind = strcspn(acc.holder_name, "\n");
    acc.holder_name[ind] = '\0';

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

    // To write data into file
    fwrite(&acc, sizeof(acc), 1, file);
    fclose(file);

    printf("\n Account created successfully!");
}
```
@ function ecplaination:
**FILE file :

1.fopen("account.dat", "ab+");**
>here, in the above function which tells that [eg a notebook is opened like file name] **"account.dat"**:
["Opening your personal diary at the last page to add a new entry without erasing old entries."]

* a = append (add data at end)
* b = binary mode (store data as it is)
* "+"= read and write both allowed.
---
2. If(file == NULL)
>here, to understand by checking if file opened successfully.
but, If it didn’t open (maybe file missing or permission denied) then it will **print** error and exit function.
---
3.**fwrite(&acc, sizeof(acc), 1, file)**;
>Inside the *structure's data members*, are being stored in the file in  *Binary format*.
* &acc: address of structure
* sizeof(acc): how many bytes to write
* 1: write only one record at a time
* file: where to write

*That means*: the dta or any notes written in rough paper is written in a specific file so that is is safe forever.

**Simple words:** This line takes the entire account details stored in the variable acc and saves them into your file (account.dat) as a single block of binary data.
**Analogy** : After pasting the photocopy into the bank register, you close the register and keep it safely back in the locker, so that data is not lost or damaged.




4. **fclose(file)**;Closes the file safely after writing.
5. **printf("\n Account created successfully!")**;to tell that the  account details are recieved and saved inside the file in safe forever.
---
## Step 08: Before taking input,washing out the before errors:
>For preparing to  clean the  input stream before *fgets* so that  to avoid unwanted bugs.

```c
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

```
**explanation**:*Here*, Purpose of using do-while loop is that, if the user take any input or to clear an previous input can be done and to do this till the buffer is empty.So, that i can start writing inside the *fgets* by considering it is empty. 

---
#                     Part II: Function Performance:
## Step 09: **void  checking the balance():**

### CASE 01:
```c
 / to use const
const char* ACCOUNT_NAME="account.dat"; 
.....................................................
// to create an STRUCTURE: for backened logic:
typedef struct {.........}
```
>// to use const
const char* ACCOUNT_NAME="account.dat";

for declaring  a *constant* *pointer* to a *string* *literal*.It stores the file name "account.dat" in a constant variable called ACCOUNT_NAME.

You write the name “account.dat” on a label and stick it on your bank file.
If you use "account.dat" in multiple places, just change it here once if needed later.

> const char* ACCOUNT_NAME = "account.dat"; defines a permanent, unchangeable label for your file name in your code to avoid errors and improve readability.

## CASE 02:
It allows users to check their balance anytime by entering account numbers and also uses file reading (fread) to access saved account data efficiently
```c
void check_balance() {
    FILE *file = fopen("ACCOUNT_NAME","rb+");
    if(file==NULL) {
        printf("\n Unable to open a file!!!");
        return;
    }
    
    int acc_no;
    Account acc_read;
    
    printf("Enter your account number:");
    scanf("%d", &acc_no);
    
    while(fread(&acc_read, sizeof(acc_read), 1, file)) {
        if(acc_read.acc_no == acc_no) {
            printf("Your Account balance is Rs:%.2f", acc_read.balance);
            fclose(file);
            return;
        }
    }
    
    fclose(file);
    printf(" \n Account No:%d was not found!!....", acc_no);
}
```
 *explanation* :  

 ### case 01:
 ```c
 FILE *file = fopen("ACCOUNT_NAME", "rb+");
 ```
 it opens the  file (this used constant ACCOUNT_NAME which holds "account.dat") in read-binary mode with update capability (rb+).[Imagine you are opening the bank register file to check customer balances.]

### case 02: Check if file opened successfully
```c
if(file == NULL) {
    printf("\n Unable to open a file!!!");
    return;
}
```
If the file couldn’t open (maybe file not present or permission denied), it prints an error and exits the function.[If the bank register is missing or locked, you inform the customer and stop the process.]

### case 03: for taking an inout from the user for account number
```c
int acc_no;
printf("Enter your account number:");
scanf("%d", &acc_no);
```
after taking the user input for their account number  then to search for user balance.[The bank cashier asks you “What is your account number?” before checking records.]

### case 04: by using fread to raed the file which is written.
```c
while(fread(&acc_read, sizeof(acc_read), 1, file))
```
it read's 1 Account record at a time from the file until end of file is reached.

### case 05:If account number matches, display balance
```c
if(acc_read.acc_no == acc_no) {
    printf("Your Account balance is Rs:%.2f", acc_read.balance);
    fclose(file);
    return;
}
```
When the correct account number is found, it prints the balance and exits the function after closing the file.

## **Step 10 : TO Generate a unique random account number.**

### case 01:Include functions used.


```c
#include <stdlib.h>  // for rand(), srand()
#include <time.h>    // for time()
```
rand():to generates a random number

srand(): to sets the seed for random number generation
### case 02: Account number:
```c
// TO Generate a unique random account number
    srand(time(NULL));
    acc.acc_no = rand() % 900000 + 100000; // 6-digit account number
    printf("Generated Account Number: %d \n", acc.acc_no);

    // to  set initial balance to 0
    acc.balance = 0.0f;
```
srand(time(null)): 
        **time(NULL)** gets the current time in seconds.**srand()** sets the seed value for **rand()**, using the current time as a seed.This ensures different random numbers every time you run your program.[it is like if you give any number it will generate at another second new account nymber which will be *unique*]

>  To get an  6-digit numbers starting from 100000 to 999999.

>**acc.balance = 0.0f**: In which , it Sets the initial balance of the new account to Rs. 0.00 when it is first  time created.
---
# PART IV: **void deposit():**
```c
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
			printf("Your Account balance with successfully deposited money:Rs %.2f\n", money);
			printf("New balance is: Rs %.2f\n", acc_r.balance);

			fclose(file);
			return;
		}
	}
	fclose(file);
	printf("Account number not found in the records amd Money could not be deposited!!!!",acc_no);
	
		
	
	
    printf("\n --Deposit Money function is Sucessfully executed---\n");
}
```
---

## Step 11: add the function of loan that the user can get as per thier monthly base salary with 8% intrest:


```c
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

```


>File opening uses ACCOUNT_NAME :
*  it will take user input with account number and base salary.
*  it will calculates loan_amount = base_salary × 10 per your requirement.
*  to add 8% interest with loan_with_interest.
*  loan credited and new balance will be printed to the user.

---

                           *Successfully executed!!!!*




















