#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    double small, medium, large, patSub, salSub, tomSub, subTotal;
    double patTax, salTax, tomTax, totalTax, patTotal, salTotal, tomTotal, finalTotal, remainer;
    int numPat, numSal, numTom, tempNum, numToo, numLoo, numQua, numDim, numNic, numPen;

    //Input Shirt Price
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &small);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &medium);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &large);
    printf("\n");

    //Input number of shirts buying
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", small);
    printf("MEDIUM : $%.2lf\n", medium);
    printf("LARGE  : $%.2lf\n\n", large);
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numPat);
    printf("\n");
    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &numTom);
    printf("\n");
    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &numSal);
    printf("\n");

    //Calucate each person sub-total
    patSub = small * numPat;
    salSub = medium * numSal;
    tomSub = large * numTom;

    //Calucate each person tax
    tempNum = patSub * TAX * 100 + 0.5; //temporary value to round up the tax
    patTax = (float)tempNum / 100;
    tempNum = (int)tempNum;
    tempNum = salSub * TAX * 100 + 0.5; //temporary value to round up the tax
    salTax = (float)tempNum / 100;
    tempNum = (int)tempNum;
    tempNum = tomSub * TAX * 100 + 0.5; //temporary value to round up the tax
    tomTax = (float)tempNum / 100;

    //Calucate each person total
    patTotal = patSub + patTax;
    salTotal = salSub + salTax;
    tomTotal = tomSub + tomTax;
    
    //Calaucate total
    subTotal = patSub + salSub + tomSub;
    totalTax = patTax + salTax + tomTax;
    finalTotal = subTotal + totalTax;

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %c    %.2lf   %d  %.4lf   %.4lf  %.4lf\n", patSize, small, numPat, patSub, patTax, patTotal);
    printf("Sally    %c    %.2lf   %d  %.4lf   %.4lf  %.4lf\n", salSize, medium, numSal, salSub, salTax, salTotal);
    printf("Tommy    %c    %.2lf   %d  %.4lf   %.4lf  %.4lf\n", tomSize, large, numTom, tomSub, tomTax, tomTotal);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("                         %.4lf   %.4lf  %.4lf\n\n", subTotal, totalTax, finalTotal);

    //Calaucate coin EXCLUDING tax
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %.4lf\n", subTotal);
    tempNum = subTotal * 100;
    numToo = tempNum / 200;
    tempNum = tempNum % 200;
    remainer = (double)tempNum / 100;
    printf("Toonies  %d    %.4lf\n", numToo, remainer);
    numLoo = tempNum / 100;
    tempNum = (int)tempNum;
    tempNum = tempNum % 100;
    remainer = (double)tempNum / 100;
    printf("Loonies    %d    %.4lf\n", numLoo, remainer);
    numQua = tempNum / 25;
    tempNum = (int)tempNum;
    tempNum = tempNum % 25;
    remainer = (double)tempNum / 100;
    printf("Quarters   %d    %.4lf\n", numQua, remainer);
    numDim = tempNum / 10;
    tempNum = (int)tempNum;
    tempNum = tempNum % 10;
    remainer = (double)tempNum / 100;
    printf("Dimes      %d    %.4lf\n", numDim, remainer);
    numNic = tempNum / 5;
    tempNum = (int)tempNum;
    tempNum = tempNum % 5;
    remainer = (double)tempNum / 100;
    printf("Nickels    %d    %.4lf\n", numNic, remainer);
    numPen = tempNum / 1;
    remainer = tempNum / 100;
    printf("Pennies    %d    %.4lf\n\n", numPen, remainer);
    printf("Average cost/shirt: $%.4lf\n\n", subTotal / (numPat + numSal + numTom));

    //Calaucate coin INCLUDING tax
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %.4lf\n", finalTotal);
    tempNum = finalTotal * 100;
    numToo = tempNum / 200;
    tempNum = tempNum % 200;
    remainer = (double)tempNum / 100;
    printf("Toonies  %d    %.4lf\n", numToo, remainer);
    numLoo = tempNum / 100;
    tempNum = (int)tempNum;
    tempNum = tempNum % 100;
    remainer = (double)tempNum / 100;
    printf("Loonies    %d    %.4lf\n", numLoo, remainer);
    numQua = tempNum / 25;
    tempNum = (int)tempNum;
    tempNum = tempNum % 25;
    remainer = (double)tempNum / 100;
    printf("Quarters   %d    %.4lf\n", numQua, remainer);
    numDim = tempNum / 10;
    tempNum = (int)tempNum;
    tempNum = tempNum % 10;
    remainer = (double)tempNum / 100;
    printf("Dimes      %d    %.4lf\n", numDim, remainer);
    numNic = tempNum / 5;
    tempNum = (int)tempNum;
    tempNum = tempNum % 5;
    remainer = (double)tempNum / 100;
    printf("Nickels    %d    %.4lf\n", numNic, remainer);
    numPen = tempNum / 1;
    remainer = tempNum / 100;
    printf("Pennies    %d    %.4lf\n\n", numPen, remainer);
    printf("Average cost/shirt: $%.4lf\n", finalTotal / (numPat + numSal + numTom));
    
    return 0;
}