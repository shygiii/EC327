#include "lab3_problem1.h"

int sumElements(int* arr, int size) {
    int totalsum = arr[0]*arr[size-1];
    for (int i=0; i<size; i++) {
        if (i%2==0) totalsum += arr[i];
        if (arr[i]%2==0) totalsum += arr[i];
    }
    return totalsum;
}