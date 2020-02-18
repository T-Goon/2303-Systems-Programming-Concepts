//
// Created by Timothy Goon, Patrick Houlihan on 2/16/2020.
//

#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include <cstdlib>
#include <cstdio>

class AdjacencyMatrix {
public:
    AdjacencyMatrix();
    ~AdjacencyMatrix();
    int* getMatrix();
    int getNumRooms();
private:
    int* _matrix = nullptr;
    int _numRooms = -1;
};


#endif //ADJACENCYMATRIX_H
