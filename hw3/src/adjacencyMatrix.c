//
// Created by Timothy Goon on 2/9/2020.
//

#include "adjacencyMatrix.h"

// Adjacency Matrix: Square array with 1s in a position if the nodes are adjacent.
int* matrix = NULL;

int* getMatrix(){
    // If the matrix doesn't exists yet read it in from file.
    if(matrix == NULL){
        FILE* file = fopen("adjacencyMatrix.txt", "r");
        int size = 0;

        // Create array for adjacency matrix
        fscanf(file, "%d", &size);
        matrix = (int*)calloc(size*size, sizeof(int));

        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                fscanf(file, "%d", (matrix + i* size + j));
            }
        }
    }

    return matrix;
}