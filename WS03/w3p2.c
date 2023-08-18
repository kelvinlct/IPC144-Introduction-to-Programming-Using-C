#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

	// Note:
	// You can convert Celsius to Fahrenheit given the following formula:
	// fahrenheit = (celsius * 1.8) + 32.0);

    char type1, type2, type3, size1, size2, size3, cream1, cream2, cream3, str, preCream, maker;
    int weight1, weight2, weight3, ser;
    double temp1, temp2, temp3;

    //User input
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &type1);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &size1);
    printf("Bag weight (g): ");
    scanf("%d", &weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%lf", &temp1);
    printf("\n");
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &type2);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &size2);
    printf("Bag weight (g): ");
    scanf("%d", &weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%lf", &temp2);
    printf("\n");
    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &type3);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &size3);
    printf("Bag weight (g): ");
    scanf("%d", &weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%lf", &temp3);
    printf("\n");

    //Print out the table
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
    printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
    printf("   +---------------+---------------+---------------+ With  +--------------\n");
    printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf(" 1 |   %d   |   %d   |    %d   |   %d  |  %d |  %.3lf |   %d   |  %.1lf | %.1lf\n", type1 == 'L' || type1 == 'l', type1 == 'B' || type1 == 'b', size1 == 'C' || size1 == 'c', size1 == 'F' || size1 == 'f', weight1, weight1 / GRAMS_IN_LBS, cream1 == 'Y' || cream1 == 'y', temp1, (temp1 * 1.8 + 32.0));
    printf(" 2 |   %d   |   %d   |    %d   |   %d  |  %d |  %.3lf |   %d   |  %.1lf | %.1lf\n", type2 == 'L' || type2 == 'l', type2 == 'B' || type2 == 'b', size2 == 'C' || size2 == 'c', size2 == 'F' || size2 == 'f', weight2, weight2 / GRAMS_IN_LBS, cream2 == 'Y' || cream2 == 'y', temp2, (temp2 * 1.8 + 32.0));
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %d |  %.3lf |   %d   |  %.1lf | %.1lf\n\n", type3 == 'L' || type3 == 'l', type3 == 'B' || type3 == 'b', size3 == 'C' || size3 == 'c', size3 == 'F' || size3 == 'f', weight3, weight3 / GRAMS_IN_LBS, cream3 == 'Y' || cream3 == 'y', temp3, (temp3 * 1.8 + 32.0));

    //Compare 2 times
    int i;
    for (i = 0; i < 2; i++) {

        //User input
        printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");
        printf("Coffee strength ([M]ild,[R]ich): ");
        scanf(" %c", &str);
        printf("Do you like your coffee with cream ([Y]es,[N]o): ");
        scanf(" %c", &preCream);
        printf("Typical number of daily servings: ");
        scanf("%d", &ser);
        printf("Maker ([R]esidential,[C]ommercial): ");
        scanf(" %c", &maker);
        printf("\n");

        //Print out the table
        printf("The below table shows how your preferences align to the available products:\n\n");
        printf("--------------------+--------------------+-------------+-------+--------------\n");
        printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
        printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
        printf("--+-----------------+--------------------+-------------+-------+--------------\n");
        printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", ((str == 'M' || str == 'm') && (type1 == 'L' || type1 == 'l'))|| ((str == 'R' || str == 'r') && (type1 == 'B' || type1 == 'b')), ((maker == 'R' || maker == 'r') && (size1 == 'C' || size1 == 'c'))|| ((maker == 'C' || maker == 'c') && (size1 == 'F' || size1 == 'f')), (ser >= 1 && ser <= 4 && weight1 >= 0 && weight1 <= 250)|| (ser >= 5 && ser <= 9 && weight1 == 500)|| (ser >= 10 && weight1 == 1000), ((preCream == 'Y' || preCream == 'y') && (cream1 == 'Y' || cream1 == 'y'))|| ((preCream == 'N' || preCream == 'n') && (cream1 == 'N' || cream1 == 'n')), ((maker == 'R' || maker == 'r') && temp1 >= 60 && temp1 <= 69.9)|| ((maker == 'C' || maker == 'c') && temp1 >= 70));
        printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", ((str == 'M' || str == 'm') && (type2 == 'L' || type2 == 'l')) || ((str == 'R' || str == 'r') && (type2 == 'B' || type2 == 'b')), ((maker == 'R' || maker == 'r') && (size2 == 'C' || size2 == 'c')) || ((maker == 'C' || maker == 'c') && (size2 == 'F' || size2 == 'f')), (ser >= 1 && ser <= 4 && weight2 >= 0 && weight2 <= 250) || (ser >= 5 && ser <= 9 && weight2 == 500) || (ser >= 10 && weight2 == 1000), ((preCream == 'Y' || preCream == 'y') && (cream2 == 'Y' || cream2 == 'y')) || ((preCream == 'N' || preCream == 'n') && (cream2 == 'N' || cream2 == 'n')), ((maker == 'R' || maker == 'r') && temp2 >= 60 && temp2 <= 69.9) || ((maker == 'C' || maker == 'c') && temp2 >= 70));
        printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n\n", ((str == 'M' || str == 'm') && (type3 == 'L' || type3 == 'l')) || ((str == 'R' || str == 'r') && (type3 == 'B' || type3 == 'b')), ((maker == 'R' || maker == 'r') && (size3 == 'C' || size3 == 'c')) || ((maker == 'C' || maker == 'c') && (size3 == 'F' || size3 == 'f')), (ser >= 1 && ser <= 4 && weight3 >= 0 && weight3 <= 250) || (ser >= 5 && ser <= 9 && weight3 == 500) || (ser >= 10 && weight3 == 1000), ((preCream == 'Y' || preCream == 'y') && (cream3 == 'Y' || cream3 == 'y')) || ((preCream == 'N' || preCream == 'n') && (cream3 == 'N' || cream3 == 'n')), ((maker == 'R' || maker == 'r') && temp3 >= 60 && temp3 <= 69.9) || ((maker == 'C' || maker == 'c') && temp3 >= 70));

    }

    printf("Hope you found a product that suits your likes!\n");

    return 0;
}