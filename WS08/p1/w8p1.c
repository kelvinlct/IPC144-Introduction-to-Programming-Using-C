#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* ip) {
	int input;
	do {
		scanf("%d", &input);
		if (input < 1) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (input < 1);
	if (ip != NULL) {
		*ip = input;
	}
	return input;
};

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* dp) {
	double input;
	do {
		scanf("%lf", &input);
		if (input <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (input <= 0);
	if (dp != NULL) {
		*dp = input;
	}
	return input;
};


// 3. Opening Message (include the number of products that need entering)
void openingMessage(void) {
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", NumProduct);
	printf("NOTE: A 'serving' is %dg\n\n",GRAMS);
};

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int i) {
	struct CatFoodInfo input;
	printf("Cat Food Product #%d\n", i + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&input.sku);
	printf("PRICE         : $");
	getDoublePositive(&input.price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&input.weight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&input.cal);
	printf("\n");

	return input;
};

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
};

// 6. Display a formatted record of cat food data
void displayCatFoodData(const struct CatFoodInfo input) {
	printf("%07d %10.2lf %10.1lf %8d\n", input.sku, input.price, input.weight, input.cal);
};

// 7. Logic entry point
void start(void) {
	int i;
	struct CatFoodInfo	 catFood[NumProduct];
	openingMessage();
	for (i = 0; i < NumProduct; i++) {
		catFood[i] = getCatFoodInfo(i);
	}
	displayCatFoodHeader();
	for (i = 0; i < NumProduct; i++) {
		displayCatFoodData(catFood[i]);
	}

};