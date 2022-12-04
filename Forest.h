//
// Created by weili on 2022-12-03.
//

#ifndef VINCENT_FOREST_H
#define VINCENT_FOREST_H

#include "Graph.h"

using namespace std;

class Forest : public Graph{

protected:
    int **elements;
    int capacity1;
    int capacity2;
    int size;
//    node* head;
//    DoubleLinkedList* vertices;
    int dummy;

public:

    Forest();
    Forest(int);
    Forest(const Forest&);

    bool add_edge(int, int);

};


#endif //VINCENT_FOREST_H
