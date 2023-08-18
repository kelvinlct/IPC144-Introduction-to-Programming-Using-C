#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Function

//clearinputBuffer
void clearinputBuffer(void) {
    while (getchar() != '\n') {
        ;
    }
};

//inputInt
int inputInt(void) {
    int input;
    char newLine = 'x';
    do {
        scanf("%d%c", &input, &newLine);

        if (newLine != '\n') {
            clearinputBuffer();
            printf("Error! Input a whole number: ");
            
        }
        
    } while(!(newLine == '\n'));
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
            clearinputBuffer();
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
            if (input >= min  && input <=max ) {
                ;
            }
            else {
                printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
            }
        }
        else {
            clearinputBuffer();
            printf("Error! Input a whole number: ");

        }

    } while (!(newLine == '\n') || !(input >= min && input <= max));
    return input;
};

//inputCharOption
char inputCharOption(const char vChar[]) {
    char input;
    int i, j = 0;
    do {
        
        scanf("%c", &input);
        clearinputBuffer();
        for (i = 0; vChar[i] != '\0'; i++) {
            if (input == vChar[i]) {
                j = 1;
            }
        }
        if (j == 0) {
            printf("ERROR: Character must be one of [%s]:", vChar);
        }


    } while (j == 0);
    return input;
};

//inputCString
void inputCString(char output[], int min, int max) {
    int length, j = 0;
    char input[20];
    do {
        scanf("%[^\n]s", input);
        clearinputBuffer();
        for (length = 0; input[length] != '\0'; length++) {
            ;
        }

        if ((max == min) && (max !=length)) {
            printf("ERROR: String length must be exactly %d chars: ",max);
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
        else if (j==1) {
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
