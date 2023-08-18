// ----------------------------------------------------------------------------
// defines/macros
#define NumProduct 3
#define GRAMS 64
#define CONVERSION 2.20462


// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int sku, cal;
    double price, weight;
};
struct ReportData {
    int sku, cal, grams;
    double price, lbs, kg, serving, costperSer, ccperSer;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int*);


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double*);


// 3. Opening Message (include the number of products that need entering)
void openingMessage(void);


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int i);


// 5. Display the formatted table header
void displayCatFoodHeader(void);


// 6. Display a formatted record of cat food data
void displayCatFoodData(const struct CatFoodInfo output);



// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* kg);

// 9. convert lbs: g
int convertLbsG(const double* lbs, int* g);

// 10. convert lbs: kg / g
void convertLbs(const double* lbs, double* kg, int* g);

// 11. calculate: servings based on gPerServ
double calculateServings(const int ssg, const int tg, double* numSer);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* pp, const double* tnumSer, double* cps);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* pp, const double* tnumCal, double* cpc);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo input);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData, const int option);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);
