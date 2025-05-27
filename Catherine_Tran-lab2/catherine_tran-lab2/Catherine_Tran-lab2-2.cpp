#include "lab2_problem2.h"
#include <iostream>

int digitSums(int number) {
    int digitsum = 0;
    int second = 0;
    int secondtolast = 0;
    int numdigits = 0;

    number<0 ? number *= -1 : number;
    int ognumber = number;

    while (number >= 10) {
        numdigits++;
        int currentdigit = number%10;
        digitsum += currentdigit;
        if (numdigits==2) {
            secondtolast = currentdigit;
        }
        if (9<number && number<100) {
            second = currentdigit;
        }
        number /= 10;
    }
    digitsum += number + number*(9<ognumber && ognumber<100);

    return digitsum + second + secondtolast;
}