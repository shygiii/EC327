#include "hw2_structs.h"
#include "hw2_problem4.h"
#include <math.h>
#include <iostream>

std::string convertToBinaryFraction(double num) {
    if (num<0) {
        return "Negative numbers not supported!";
    }
    if (num==0) {
        return "0";
    }
    float fracpart = fmod(num,1);
    int wholepart = int(num);
    std::string whole = "", decimal = "";

    while (wholepart>0) {
        int addtowhole = wholepart%2;
        whole = std::to_string(addtowhole) + whole;
        wholepart/=2;
    }

    while (fracpart>0 && decimal.length()<18) {
        fracpart*=2;
        int addtodec = int(fracpart);
        decimal += std::to_string(addtodec);
        fracpart -= addtodec;
    }
    std::string result = whole;
    if (decimal!="") {
        if (whole=="") {
            result += "0." + decimal;
        }
        else {
            result += "." + decimal;
        }
    }
    if (result.length() > 33) {
        return "Input number too large!";
    }
    return result;
}