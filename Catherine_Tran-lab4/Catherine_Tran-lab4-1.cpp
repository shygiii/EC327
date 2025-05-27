#include "lab4_problem1.h"
#include <fstream>

int *alphabetCounter(string filename) {
    int* abcct = new int[26]();
    ifstream in_file(filename);
    char ch;
    while (in_file.get(ch)) {
        ch = tolower(ch);
        if ('a'<=ch && ch<='z') abcct[ch-'a']++;
    }
    return abcct;
}