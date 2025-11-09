#include "Account.h"
#include <stdio.h>
#include <string.h>


typedef enum { NOT_ENROLLED, BASIC_PLAN, PREMIUM_PLAN } PlanType;
typedef struct
 {
    char name[30];
    int age;
    float sum_assured;
    PlanType plan;
} Insurance;

void life_insurance(Insurance *ins)
 {
    printf("\n[Life Insurance]\n");
    printf("Enter Name: ");
    scanf(" %[^\n]", ins->name);

    printf("Enter Age: ");
    scanf("%d", &ins->age);

    if(ins->age < 18) 
	{
        printf("Not eligible for life insurance.\n");
        ins->plan = NOT_ENROLLED;
        return;
    }

    printf("Enter Sum Assured: ");
    scanf("%f", &ins->sum_assured);

    printf("Enter plan (1 for Basic, 2 for Premium): ");
    int plan_input;
    scanf("%d", &plan_input);
    if(plan_input == 1) ins->plan = BASIC_PLAN;
    else if(plan_input == 2) ins->plan = PREMIUM_PLAN;
    else ins->plan = NOT_ENROLLED;

    printf("Life insurance enrollment done!\n");
}
