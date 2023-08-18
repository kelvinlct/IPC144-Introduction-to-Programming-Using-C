#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p2.h"

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
	printf("NOTE: A 'serving' is %dg\n\n", GRAMS);
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



// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* kg) {
	double outputKG;
	outputKG = *lbs / CONVERSION;
	if (kg != NULL) {
		*kg = outputKG;
	}
	return outputKG;
};

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* g) {
	int gr;
	gr = ( *lbs * 1000 / CONVERSION);
	if (g != NULL) {
		*g = gr;
	}
	return gr;
};

// 10. convert lbs: kg and g
void convertLbs(const double* lbs, double* kg, int* g) {
	*kg = *lbs / CONVERSION;
	*g = *lbs*1000 / CONVERSION;
};

// 11. calculate: servings based on gPerServ
double calculateServings(const int ssg, const int tg, double* numSer) {
	double numofSer;
	numofSer = (double)tg / (double)ssg;
	if (numSer !=NULL) {
		*numSer = numofSer;
	}
	return numofSer;
};

// 12. calculate: cost per serving
double calculateCostPerServing(const double* pp, const double* tnumSer, double* cps) {
	double dcps;
	dcps = *pp / *tnumSer;
	if (cps != NULL) {
		*cps = dcps;
	}
	return dcps;
};


// 13. calculate: cost per calorie
double calculateCostPerCal(const double* pp, const double* tnumCal, double* cpc) {
	double dcpc;
	dcpc = *pp / *tnumCal;
	if (dcpc != 0) {
		*cpc = dcpc;
	}
	return dcpc;
};

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo input) {
	struct ReportData output;
	double cal = input.cal;
	output.sku = input.sku;
	output.price = input.price;
	output.lbs = input.weight;
	output.cal = input.cal;
	convertLbsKg(&input.weight, &output.kg);
	convertLbsG(&input.weight, &output.grams);
	calculateServings(GRAMS,output.grams,&output.serving);
	calculateCostPerServing(&input.price,&output.serving,&output.costperSer);
	calculateCostPerCal(&output.costperSer,&cal,&output.ccperSer);
	return output;
};

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS );
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
};

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData input, const int i){
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", input.sku, input.price, input.lbs, input.kg, input.grams, input.cal, input.serving, input.costperSer, input.ccperSer);
	if (i == input.sku) {
		printf(" ***");
	}
	printf("\n");
};

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo input) {
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d PRICE: $%.2lf\n\n",input.sku, input.price);
	printf("Happy shopping!\n");
};

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void) {
	int i;
	struct CatFoodInfo catFood[NumProduct];
	struct ReportData repData[NumProduct];
	openingMessage();
	for (i = 0; i < NumProduct; i++) {
		catFood[i] = getCatFoodInfo(i);
	}
	displayCatFoodHeader();
	for (i = 0; i < NumProduct; i++) {
		displayCatFoodData(catFood[i]);
	}

	printf("\n");


	for (i = 0; i < NumProduct; i++) {
		repData[i] = calculateReportData(catFood[i]);
	}

	double min = repData[0].costperSer;
	int j;

	for (i = 0; i < NumProduct; i++) {
		if (repData[i].costperSer < min) {
			min = repData[i].costperSer;
			if (repData[i].costperSer == min) {
				j = repData[i].sku;
			}
		}
	}
	displayReportHeader();

	for (i = 0; i < NumProduct; i++) {
		displayReportData(repData[i],j);
	}
	printf("\n");
	for (i = 0; i < NumProduct; i++) {
		if (repData[i].costperSer == min) {
			displayFinalAnalysis(catFood[i]);
		}
	}
};
