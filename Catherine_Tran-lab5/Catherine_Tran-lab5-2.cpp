#include "lab5_problem2.h"
#include <map>
#include <set>
#include <stdexcept>
#include <iostream>
using namespace std;

Graph::Graph() {
    edgect=0;
}

Graph& Graph::operator+=(int ID) {
    if (vertices.count(ID)>0) throw std::logic_error("Vertex with given ID already exists"); 
    std::set<int> placeholder;
    vertices[ID] = placeholder;
    return *this;
}

bool Graph::hasEdge(int ID1, int ID2) {
    if (vertices.count(ID1)<=0 || vertices.count(ID2)<=0) return false;
    return vertices[ID1].count(ID2)>0 && vertices[ID2].count(ID1)>0;
}

void Graph::addEdge(int ID1, int ID2) {
    if (vertices.count(ID1)<=0 || vertices.count(ID2)<=0)
        throw std::invalid_argument("Vertex with one of the given IDs does not exist"); 
   if (vertices[ID1].count(ID2)<=0) {
        edgect++;
        vertices[ID1].insert(ID2);
        vertices[ID2].insert(ID1);
   }
   else throw std::invalid_argument("Edge between vertices already exists!"); 
}

int Graph::numVertices() {
    return vertices.size();
}

int Graph::numEdges() {
    return edgect;
}

set<int> Graph::twoHopNeighbors(int ID) {
    std::set<int> twohops;
    std::set<int> firstneighbors = vertices[ID];
    std::set<int>::iterator i;
    for (i=firstneighbors.begin(); i!=firstneighbors.end(); i++) {
        int neighborvertex = *i;
        std::set<int> nbrs = vertices[neighborvertex];
        std::set<int>::iterator j;
        for (j=nbrs.begin(); j!=nbrs.end(); j++) {
            if (*j!=ID) twohops.insert(*j);
        }
    }
    return twohops;
}