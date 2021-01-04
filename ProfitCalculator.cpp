#include <iostream>
#include <cmath>

float convertToDollars(int input)
{
    return input / 100.0;
}


int findCashTotal(int denominations[10], int amounts[10]) 
{
    double cashTotal{};

    for (int i = 0; i < 10; i++) {
        cashTotal += denominations[i] * amounts[i];
    }

    return cashTotal;
}


int findProfitDenomination(int cashTotal, int denomination, int amount)
{
    int maxDenominationOff = floor(cashTotal / denomination); // Given infinite notes and coins, how many would be taken for profit

    if (amount >= maxDenominationOff) {
        return maxDenominationOff;
    } else {
        return amount;
    }
}


void printProfits(int amounts[10])
{
    int denominations[10] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10}; // All values internally tracked in cents to avoid float arithmetic errors
    // int amounts[10]       = { };
    int profitAmounts[10] = { };


    // for (int i = 0; i < 10; i++) {
    //     std::cout << "Enter number of $" << convertToDollars(denominations[i]) << " values: ";
    //     std::cin >> amounts[i];
    // }

    int cashTotal = findCashTotal(denominations, amounts);
    cashTotal -= 15000; // Removing float
    int decreasingCashTotal = cashTotal;

    for (int i = 0; i < 10; i++) {
        
        profitAmounts[i] = findProfitDenomination(decreasingCashTotal, denominations[i], amounts[i]);
        decreasingCashTotal -= profitAmounts[i] * denominations[i];
    }
    printf("\n======================================\n\n");
    printf("Profit denominations:\n");
    for (int i = 0; i < 10; i++) {
        if (profitAmounts[i] > 0) {
            std::cout << profitAmounts[i] << " x $" << convertToDollars(denominations[i]) << "\n";
        }
    }
    std::cout << "\nAdding to total profits of $" << convertToDollars(cashTotal) << "\n\n";
}


int main()
{
    int testValues[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    printProfits(testValues);
    return 0;
}
