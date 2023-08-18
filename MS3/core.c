#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

//inputInt
int inputInt(void) {
    int input;
    char newLine = 'x';
    do {
        scanf("%d%c", &input, &newLine);

        if (newLine != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");

        }

    } while (!(newLine == '\n'));
    return input;
};

//inputIntPositive
int inputIntPositive(void) {
    int input;
    char newLine = 'x';
    do {
        scanf("%d%c", &input, &newLine);

        if (newLine == '\n') {
            if (input > 0) {
                ;
            }
            else {
                printf("ERROR! Value must be > 0: ");
            }
        }
        else {
            clearInputBuffer();
            printf("Error! Input a whole number: ");

        }

    } while (!(newLine == '\n') || (input <= 0));
    return input;
};
//inputIntRange
int inputIntRange(int min, int max) {
    int input;
    char newLine = 'x';
    do {
        scanf("%d%c", &input, &newLine);

        if (newLine == '\n') {
            if (input >= min && input <= max) {
                ;
            }
            else {
                printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
            }
        }
        else {
            clearInputBuffer();
            printf("Error! Input a whole number: ");

        }

    } while (!(newLine == '\n') || !(input >= min && input <= max));
    return input;
};

//inputCharOption
char inputCharOption(const char vChar[]) {
    char input[10] = {'\0'};
    int i, j = 0, length;
    do {

        scanf("%9s", input);
        clearInputBuffer();
        for (length = 0; input[length] != '\0'; length++)
        {
            ;

        }
        if (length > 1) {
            printf("ERROR: Character must be one of [%s]: ", vChar);
        }
        else {


            for (i = 0; vChar[i] != '\0'; i++) {
                if (input[0] == vChar[i]) {
                    j = 1;
                }
            }
            if (j == 0) {
                printf("ERROR: Character must be one of [%s]:", vChar);
            }
        }

    } while (j == 0);
    return input[0];
};

//inputCString
void inputCString(char* output, int min, int max) {
    int length, j = 0;
    char input[30];
    do {
        scanf("%[^\n]s", input);
        clearInputBuffer();
        for (length = 0; input[length] != '\0'; length++) {
            ;
        }

        if ((max == min) && (max != length)) {
            printf("Invalid %d-digit number! Number: ", max);
            //printf("ERROR: String length must be exactly %d chars: ", max);
        }
        else if ((max > min) && (length > max)) {
            printf("ERROR: String length must be no more than %d chars: ", max);
        }
        else if ((max > min) && (length < min)) {
            printf("ERROR: String length must be between %d and %d chars: ", min, max);
        }
        else {
            for (length = 0; input[length] != '\0'; length++) {
                output[length] = input[length];
                output[length + 1] = '\0';
            }
            j = 1;
        }
    } while (j == 0);
};

//displayFormattedPhone
void displayFormattedPhone(const char phone[]) {
    int length, j = 0;
    if (phone != NULL) {
        for (length = 0; phone[length] != '\0'; length++) {
            if (phone[length] < '0' || phone[length] > '9') {
                j = 1;
            }
        }
        if (length != 10) {
            printf("(___)___-____");
        }
        else if (j == 1) {
            printf("(___)___-____");
        }
        else {
            printf("(%c%c%c)%c%c%c-%c%c%c%c", phone[0], phone[1], phone[2], phone[3], phone[4], phone[5], phone[6], phone[7], phone[8], phone[9]);
        }
    }
    else {
        printf("(___)___-____");
    }
};


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

