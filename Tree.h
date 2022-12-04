//
// Created by weili on 2022-12-03.
//

#ifndef VINCENT_TREE_H
#define VINCENT_TREE_H

#include "Forest.h"
class Tree : public Forest{

protected:
    int **elements;
    int capacity1;
    int capacity2;
    int size;
//    node* head;
//    DoubleLinkedList* vertices;
    int dummy;


public:
    Tree();

    Tree operator++() ;
    Tree operator++(int) ;

};


#endif //VINCENT_TREE_H
