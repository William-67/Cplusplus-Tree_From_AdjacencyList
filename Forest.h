//
// Created by weili on 2022-12-03.
//

#ifndef VINCENT_FOREST_H
#define VINCENT_FOREST_H

#include "Graph.h"

using namespace std;

class Forest : public Graph{


public:

    Forest();
    Forest(int);
    Forest(const Forest&);

    bool add_edge(int, int);
    void remove_edge(int, int);

};


#endif //VINCENT_FOREST_H
