#ifndef LAB5_PROBLEM1_H
#define LAB5_PROBLEM1_H
#include <map>
#include <set>
#include <stdexcept>
#include <iostream>
using namespace std;

class Graph {
private:
    std::map<int, std::set<int>> vertices;
    int edgect;
public:
    Graph(); // default constructor to initialize an empty graph
    Graph &operator+=(int ID);
    bool hasEdge(int ID1, int ID2);
    void addEdge(int ID1, int ID2);
    int numVertices();
    int numEdges();
};
#endif // LAB5_PROBLEM1_H