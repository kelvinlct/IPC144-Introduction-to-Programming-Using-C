#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int checkShop, app, org, pea, tom, cab, pickApp, pickOrg, pickPea, pickTom, pickCab;
    do {
        printf("Grocery Shopping\n");
        printf("================\n");
        do {
            printf("How many APPLES do you need? : ");
            scanf("%d", &app);
            if (app < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (app < 0);
        printf("\n");
        do {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &org);
            if (org < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (org < 0);
        printf("\n");
        do {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pea);
            if (pea < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (pea < 0);
        printf("\n");
        do {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tom);
            if (tom < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (tom < 0);
        printf("\n");
        do {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cab);
            if (cab < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (cab < 0);
        printf("\n--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");
        if (app > 0) {
            do {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pickApp);
                if (pickApp < 1) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickApp > app) {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", app);
                }
                else if (pickApp < app) {
                    app = app - pickApp;
                    printf("Looks like we still need some APPLES...\n");
                }
                else {
                    app = app - pickApp;
                    printf("Great, that's the apples done!\n\n");
                }
            } while (app != 0);
        }
        if (org > 0) {
            do {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickOrg);
                if (pickOrg < 1) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickOrg > org) {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", org);
                }
                else if (pickOrg < org) {
                    org = org - pickOrg;
                    printf("Looks like we still need some ORANGES...\n");
                }
                else {
                    org = org - pickOrg;
                    printf("Great, that's the oranges done!\n\n");
                }
            } while (org != 0);
        }
        if (pea > 0) {
            do {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pickPea);
                if (pickPea < 1) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickPea > pea) {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pea);
                }
                else if (pickPea < pea) {
                    pea = pea - pickPea;
                    printf("Looks like we still need some PEARS...\n");
                }
                else {
                    pea = pea - pickPea;
                    printf("Great, that's the pears done!\n\n");
                }
            } while (pea != 0);
        }
        if (tom > 0) {
            do {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pickTom);
                if (pickTom < 1) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickTom > tom) {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tom);
                }
                else if (pickTom < tom) {
                    tom = tom - pickTom;
                    printf("Looks like we still need some TOMATOES...\n");
                }
                else {
                    tom = tom - pickTom;
                    printf("Great, that's the tomatoes done!\n\n");
                }
            } while (tom != 0);
        }
        if (cab > 0) {
            do {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pickCab);
                if (pickCab < 1) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickCab > cab) {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cab);
                }
                else if (pickCab < cab) {
                    cab = cab - pickCab;
                    printf("Looks like we still need some CABBAGES...\n");
                }
                else {
                    cab = cab - pickCab;
                    printf("Great, that's the cabbages done!\n\n");
                }
            } while (cab != 0);
        }
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &checkShop);
        printf("\n");
    } while (checkShop != 0);

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}