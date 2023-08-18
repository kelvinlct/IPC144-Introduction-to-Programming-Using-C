#define _CRT_SECURE_NO_WARNINGS
#define LOG_DAYS 3
#define MIN_YEAR 2012
#define MAX_YEAR 2022

#include <stdio.h>

int main(void)
{
    int const JAN = 1, DEC = 12;
    int year, mon, i;
    double morn[LOG_DAYS], even[LOG_DAYS], sumM = 0, sumE = 0;
    char mName[37] = "JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC";

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

    for (i = 0; i < LOG_DAYS; i++) {

        //YYYY-MM-0D or YYYY-MM-DD
        if (i < 9) {
            printf("%d-%c%c%c-0%d\n", year, mName[(mon - 1) * 3], mName[(mon - 1) * 3 + 1], mName[(mon - 1) * 3 + 2], i + 1);
        }
        else {
            printf("%d-%c%c%c-%d\n", year, mName[(mon - 1) * 3], mName[(mon - 1) * 3 + 1], mName[(mon - 1) * 3 + 2], i + 1);
        }

        do {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morn[i]);
            if (morn[i] < 0 || morn[i]>5) {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (morn[i] < 0 || morn[i]>5);
        do {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &even[i]);
            if (even[i] < 0 || even[i]>5) {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (even[i] < 0 || even[i]>5);
        sumM = sumM + morn[i];
        sumE = sumE + even[i];
        printf("\n");
    }

    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %6.3lf\n", sumM);
    printf("Evening total rating: %6.3lf\n", sumE);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", sumM + sumE);
    printf("Average morning rating:  %.1lf\n", sumM / LOG_DAYS);
    printf("Average evening rating:  %.1lf\n", sumE / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", (sumM + sumE) / LOG_DAYS / 2);


    return 0;
}