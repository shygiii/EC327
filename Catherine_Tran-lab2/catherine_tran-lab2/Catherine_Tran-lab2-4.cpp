#include "lab2_problem4.h"
GreatestCommonFactorResult identifyGCF(int input[5]) {
    bool hasallzero = true;
    for (int i=0; i<5; i++) {
        if (input[i]!=0) {
            hasallzero = false;
        }
    }
    if (hasallzero==true) {
        return {0,0};
    }

    int number = input[0];
    number<0 ? number *= -1 : number;
    for (int i=1; i<5; i++) {
        int greaternum = number;
        int lessernum = input[i];
        lessernum<0 ? lessernum *= -1 : lessernum;

        while (lessernum!=0) {
            int temp = lessernum;
            lessernum = greaternum%lessernum;
            greaternum = temp;
        }
        number = greaternum;
    }
    
    int ct = 0;
    bool cf;
    for (int i=1; i<=number; i++) {
        cf = true;
        for (int j=0; j<5; j++) {
            cf = false;
            j+=5;
        }
    }
    ct += (cf==true);
   
    return {number, ct};
}