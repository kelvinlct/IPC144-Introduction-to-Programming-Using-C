#define _CRT_SECURE_NO_WARNINGS
#define MIN 500
#define MAX 400000

#include <stdio.h>


int main(void)
{
    int i = 0, imp[10], wish, priority, year, month, search;
    double net, item, cost[10], sum = 0, subsum, remainder;
    char yn[10];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &net);
        if (net < MIN) {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        if (net > MAX) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
        printf("\n");
    } while (net < MIN || net > MAX);

    do {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%lf", &item);
        if (item < 1 || item > 10) {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
    } while (item < 1 || item > 10);
    printf("\n");
    for (i = 0; i < item; i++) {
        printf("Item-%d Details:\n", i + 1);

        do {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] < 100) {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        } while (cost[i] < 100);

        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &imp[i]);
            if (imp[i] < 1 || imp[i]>3) {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (imp[i] < 1 || imp[i]>3);

        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &yn[i]);
            if (yn[i] != 'y' && yn[i] != 'n') {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (yn[i] != 'y' && yn[i] != 'n');

        printf("\n");
    }
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < item; i++) {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, imp[i], yn[i], cost[i]);
        sum += cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", sum);

    do {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &wish);
        printf("\n");
        if (wish < 0 || wish >2) {
            printf("ERROR: Invalid menu selection.\n\n");
        }
        else if (wish == 1) {
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   %.2lf\n", sum);

            //double cannot modulus, use a while loop to get the remainder
            remainder = sum;
            while (remainder >= net) {
                remainder = remainder - net;
            }

            //check if need 1 more months
            if (remainder > 0) {
                i = 1;
            }

            //if remainder = 0, no month added (not happen in this workshop)
            else {
                i = 0;
            }

            year = sum / net / 12;
            month = sum / net - (year * 12);
            printf("Forecast: %d years, %d months\n", year, month + i);
            search = 1;
            for (i = 0; i < item && search == 1; i++) {
                if (yn[i] == 'y') {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                    
                    search = 0;
                }
            }
            printf("====================================================\n\n");
        }

        else if (wish == 2) {
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &priority);
            printf("\n");
            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", priority);
            subsum = 0;
            for (i = 0; i < item; i++) {

                if (imp[i] == priority) {
                    subsum += cost[i];
                }
            }
            printf("Amount:   $%.2lf\n", subsum);

            //double cannot modulus, use a while loop to get the remainder
            remainder = subsum;
            while (remainder >= net) {
                remainder = remainder - net;
            }

            //check if need 1 more months
            if (remainder > 0) {
                i = 1;
            }

            //if remainder = 0, no month added (not happen in this workshop)
            else {
                i = 0;
            }

            int year = subsum / net / 12;
            int month = subsum / net - (year * 12);
            printf("Forecast: %d years, %d months\n", year, month + i);
            search = 1;
            for (i = 0; i < item && search == 1; i++) {
                if (imp[i] == priority) {

                    if (yn[i] == 'y') {
                        printf("NOTE: Financing options are available on some items.\n");
                        printf("      You can likely reduce the estimated months.\n");

                        search = 0; 
                    }
                }
            }
            printf("====================================================\n\n");
        
        }

    } while (wish != 0);

    printf("\nBest of luck in all your future endeavours!\n");

    return 0;
}