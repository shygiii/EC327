
#include "lab2_problem3.h"
#include <iostream>
#include <cstring>

std::string allSubstringsWithoutChar(CharArrayWithSize input,char excludeChar) {
    std::string result = "";
    std::string  chararr = std::string(input.charArray);
    for (int i=1; i<chararr.length(); i++) {
        for (int j=0; j<chararr.length()-i+1; j++) {
            std::string portion = chararr.substr(j,i);
             if (portion.find(excludeChar) == std::string::npos) {
                 result += portion + "\n";
             }
        }
    }
    return result;
}