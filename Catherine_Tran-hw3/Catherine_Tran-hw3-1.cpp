#include "hw3_problem1.h"
#include "stdlib.h"

char *concatenate(const char *first, const char *second) {
    int firstlen = 0, secondlen = 0;
    while (first[firstlen]!='\0') firstlen++;
    while (second[secondlen]!='\0') secondlen++;
    char* result = (char*)malloc(sizeof(char)*(firstlen+secondlen+1));
    for (int i=0; i<firstlen; i++) result[i] = first[i];
    for (int j=0; j<secondlen; j++) result[j+firstlen] = second[j];
    result[firstlen+secondlen] = '\0';
    return result;
}