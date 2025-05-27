#ifndef LAB5_PROBLEM2_H
#define LAB5_PROBLEM2_H
#include <set>
#include <map>
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
    set<int> twoHopNeighbors(int ID);
};
#endif // LAB5_PROBLEM2_H