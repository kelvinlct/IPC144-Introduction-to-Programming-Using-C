#define NumProduct 3
#define GRAMS 64


// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo {
    int sku, cal;
    double price, weight;
};


// ----------------------------------------------------------------------------
// function prototypes

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
void displayCatFoodData(const struct CatFoodInfo input);

// 7. Logic entry point
void start(void);

