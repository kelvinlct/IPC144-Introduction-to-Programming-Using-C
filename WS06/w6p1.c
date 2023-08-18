#define _CRT_SECURE_NO_WARNINGS
#define MIN 500
#define MAX 400000

#include <stdio.h>


int main(void)
{
    int i = 0, imp[10];
    double net, forecast, cost[10], sum = 0;
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
        scanf("%lf", &forecast);
        if (forecast < 1 || forecast > 10) {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
    } while (forecast < 1 || forecast > 10);
    printf("\n");
    for (i = 0; i < forecast; i++) {
        printf("Item-%d Details:\n", i+1);

        do{
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] < 100) {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        } while (cost[i] < 100);

        do{
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
    for (i = 0; i < forecast; i++) {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, imp[i], yn[i], cost[i]);
        sum += cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", sum);

    printf("Best of luck in all your future endeavours!\n");

    return 0;
}