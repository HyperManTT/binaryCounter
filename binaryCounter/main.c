//
//  main.c
//  binaryCounter
//
//  Created by Randy Ram on 08/10/2015.
//  Copyright (c) 2015 Randy Ram. All rights reserved.
//

#include <stdio.h>

int integerPower(int base, int exponent)
{
    int result = 1;
    while (exponent)
    {
        if (exponent & 1)
        {
            result *= base;  //If the last digit was a 1, multiply the current result by the base
        }
        
        exponent >>= 1;  //Right shift the exponent, essentially dropping the last bit
        base *= base;
    }
    return result;
}

int getNumBits(int d)
{
    int numBits = 1;
    for (int i = 1; d > integerPower(2, i) - 1; i++) {
        numBits++;
    }
    return numBits;
}

void binaryCounter(int maxNum)
{
    //int numBits = getNumBits(maxNum); // Used to get all bit combinations until a particular int
    int numBits = 5;                    // Used to get all bit combinations for a particular number of bits
    int currentBitValues[numBits];
    for (int i = 0; i <= maxNum; i++) {
        for (int j = numBits - 1; j >= 0; j--)
        {
            int currentBit = (i / integerPower(2, j)) % 2;
            currentBitValues[j] = currentBit;
        }
        
        for(int k = 0; k < numBits; k++)
        {
            printf("%d", currentBitValues[k]);
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    binaryCounter(255);
    return 0;
}
