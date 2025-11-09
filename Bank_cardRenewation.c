#include "Account.h"
#include <stdio.h>
#include <string.h>

typedef enum { DEBIT, CREDIT } CardType;
typedef struct {
    char name[30];
    char card_number[20];
    CardType card_type;
    int valid_year;
} CardInfo;

void bank_card_renewation(CardInfo *card) {
    printf("\n[Card Renewation]\n");
    printf("Enter Name: ");
    scanf(" %[^\n]", card->name);

    printf("Enter Card Number: ");
    scanf("%s", card->card_number);

    printf("Enter type (0-Debit, 1-Credit): ");
    int t;
    scanf("%d", &t);
    card->card_type = (CardType)t;

    printf("Enter renewal year: ");
    scanf("%d", &card->valid_year);

    printf("Your card has been renewed!\n");
}
