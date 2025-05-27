#include "lab4_problem2.h"
#include <fstream>
#include <string>

int fieldCounter(string filenameCSV) {
    ifstream in_file(filenameCSV);
    string line;
    int finalcount = 0;
    while (getline(in_file, line)) {
        int fieldct = 0;
        bool hasquote = false;
        for (int i=0; i<line.length(); i++) {
            if (line[i]=='"') hasquote = !hasquote;
            if (line[i]==',' && hasquote==false) fieldct++;
        }
    fieldct++;
    if (fieldct>finalcount) finalcount = fieldct;
    }
    return finalcount;
}