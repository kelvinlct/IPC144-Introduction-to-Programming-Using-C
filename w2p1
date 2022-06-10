#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    const double TAX = 0.13;
    const char patSize = 'S';
    double input_small, input_medium, input_large, output_subtotal, output_tax, output_total;
    int input_numshirts, temp_tax;
    
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &input_small);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf",&input_medium);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &input_large);
    printf("\n");
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", input_small);
    printf("MEDIUM : $%.2lf\n", input_medium);
    printf("LARGE  : $%.2lf\n\n", input_large);
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &input_numshirts);
    printf("\n");
    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", input_numshirts);
    
    output_subtotal = input_small * input_numshirts;

    temp_tax = output_subtotal * TAX * 100 + 0.5; //temporary value to round up the tax
    output_tax = (float)temp_tax / 100;

    printf("Sub-total: $%.4lf\n", output_subtotal);
    printf("Taxes    : $ %.4lf\n", output_tax);

    output_total = output_subtotal + output_tax;

    printf("Total    : $%.4lf\n", output_total);

    return 0;
}
