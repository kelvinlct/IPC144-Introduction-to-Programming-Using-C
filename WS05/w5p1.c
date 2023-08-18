#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    int JAN = 1, DEC = 12, year, mon;

    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d%d", &year, &mon);
        if (year < MIN_YEAR || year > MAX_YEAR) {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        if (mon < JAN || mon > DEC) {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
    } while (year < MIN_YEAR || year > MAX_YEAR || mon < 1 || mon > 12);
    printf("\n*** Log date set! ***\n\n");

    switch(mon) {
        case 1:
            printf("Log starting date: %d-JAN-01", year);
            break;

        case 2:
            printf("Log starting date: %d-FEB-01", year);
            break;

        case 3:
            printf("Log starting date: %d-MAR-01", year);
            break;

        case 4:
            printf("Log starting date: %d-APR-01", year);
            break;

        case 5:
            printf("Log starting date: %d-MAY-01", year);
            break;

        case 6:
            printf("Log starting date: %d-JUN-01", year);
            break;

        case 7:
            printf("Log starting date: %d-JUL-01", year);
            break;

        case 8:
            printf("Log starting date: %d-AUG-01", year);
            break;

        case 9:
            printf("Log starting date: %d-SEP-01", year);
            break;

        case 10:
            printf("Log starting date: %d-OCT-01", year);
            break;

        case 11:
            printf("Log starting date: %d-NOV-01", year);
            break;

        case 12:
            printf("Log starting date: %d-DEC-01", year);
            break;

    }

    printf("\n");

    return 0;

}