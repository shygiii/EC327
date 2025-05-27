#include "lab2_problem1.h"
#include <string>
# include <iostream>

std::string diagonalStars(int n) {
    if (n<=0) {
        return "Not Supported";
    }
    std::string diagonals = "";
    int halfpt = n/2 + (n%2);
    for (int i=0; i<halfpt; i++) {

        for (int j=0; j<i; j++) {
            diagonals += " ";
        }
        diagonals += "-";

        int midspaces = n - 2 - (2*i);
        for (int j=0; j<midspaces; j++) {
            diagonals += " ";
        }
        if (midspaces>=0) {
            diagonals += "-";
        }

        for (int j=0; j<i; j++) {
            diagonals += " ";
        }
        diagonals += "\n";
    }
    for (int i=diagonals.length()-2 - ((n+1)*(n%2==1)); i>=0; i--) {
        diagonals += diagonals[i];
    }
    return diagonals;
}