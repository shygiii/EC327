#include "hw3_problem5.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

void possibleChangeAmountsHelper(int totalCents, Coin* arr, int len, int startind, CoinArrays* result) {
    Coin coins[] = {PENNY, NICKEL, DIME, QUARTER};
    if (totalCents == 0) {
        CoinArray newArray = {(Coin*)malloc(sizeof(Coin) * len), len};
        for (int i=0; i<len; i++) newArray.coins[i] = arr[i];
        result->arrays = (CoinArray*)realloc(result->arrays, sizeof(CoinArray) * (result->size + 1));
        result->arrays[result->size] = newArray;
        (result->size) += 1;
    }
    for (int i=startind; i<4; i++) {
        if (coins[i] <= totalCents) {
            arr[len] = coins[i];
            possibleChangeAmountsHelper(totalCents-coins[i],arr,len+1,i,result);
        }
    }
}

CoinArrays possibleChangeAmounts(int totalCents) {
    int numarrays = 0;
    CoinArrays result = {NULL,numarrays};
    if (totalCents<=0) return result;
    Coin coins[] = {PENNY, NICKEL, DIME, QUARTER};
    Coin* largestPossibleArr = (Coin*)malloc(sizeof(Coin) * totalCents);
    possibleChangeAmountsHelper(totalCents,largestPossibleArr,numarrays,0,&result);
    free(largestPossibleArr);

    CoinArray* finalarrs = result.arrays;
    for (int i=0; i<result.size; i++) qsort(finalarrs[i].coins,finalarrs[i].size,sizeof(Coin),compareCoins);
    qsort(finalarrs, result.size,sizeof(CoinArray),compareCoinArrays);
    return result;
}
