#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    int num, i;
    char ch;

    do {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &ch, &num);
        if (ch != 'D' && ch != 'W' && ch != 'F' && ch != 'Q') {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }
        else if (ch == 'Q' && num != 0) {
            printf("ERROR: To quit, the number of iterations should be 0!\n\n");
        }
        else if((num<3 || num>20) && num!=0) {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
        }
        else if (ch == 'D') {
            printf("DO-WHILE: ");
            i = 0;
            do {
                printf("%c", ch);
                i++;
            } while (i < num);
            printf("\n\n");
        }
        else if (ch == 'W') {
            printf("WHILE   : ");
            i = 0;
            while (i < num) {
                printf("%c", ch);
                i++;
            }
            printf("\n\n");

        }
        else if (ch == 'F' ) {
            printf("FOR     : ");
            for (i = 0; i < num; i++) {
                printf("%c", ch);
            }
            printf("\n\n");
        }
        
    } while (ch != 'Q' || num != 0);
    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}