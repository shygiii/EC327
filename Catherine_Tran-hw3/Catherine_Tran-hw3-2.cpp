#include "hw3_problem2.h"
#include "stdlib.h"

ReverseResult reverseOdd(const char** inputStrings, int inputStringsLength) {
    ReverseResult result = {true, (char**)malloc(sizeof(char*)*inputStringsLength)};
    
    for (int i=0; i<inputStringsLength; i++) {
        const char* chararr = inputStrings[i];
        int strlen = 0;
        while (chararr[strlen]!='\0') strlen++;
        if (strlen%2==0) {
            result.success = false;
            for (int j=0; j<i; j++) free(result.reversedStrings[j]);
            free(result.reversedStrings);
            result.reversedStrings = NULL;
            return result;
        }
        char* reversedchararr = (char*)malloc((sizeof(char)*strlen)+1);
        for (int i=strlen; i>0; i--) reversedchararr[strlen-i] = chararr[i-1];
        reversedchararr[strlen] = '\0';
        result.reversedStrings[i] = reversedchararr;
    }
    return result;
    
}