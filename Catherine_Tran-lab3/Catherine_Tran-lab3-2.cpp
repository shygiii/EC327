#include "lab3_problem2.h"
#include <stdio.h>
#include <string>

char* reverseString(const char* str) {
    if (str==NULL) return NULL;
    int lenstr = 0;
    while (str[lenstr]!='\0') lenstr++;
    char* result = new char[lenstr+1];
    for (int i=0; i<lenstr; i++) result[i] = str[lenstr-i-1];
    result[lenstr] = '\0';
    return result;
    }