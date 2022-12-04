//
// Created by weili on 2022-12-03.
//

#include "Tree.h"

Tree::Tree() {

    capacity1 = 0;
    capacity2 = 0;
    dummy = 0;
    size = 0;

    int i;
    elements = new int*[1 + MAX_ELEM];

    for (i = 0; i < 1 + MAX_ELEM; ++i){
        elements[i] = new int[1 + MAX_ELEM];
        elements[i][0] = i + 1;
        elements[i][1] = 2;
        elements[i][2] = 0;
    }

    if (elements == NULL){
        cout << "not enough memory";
    }
    else{
        size = 1;
        capacity1 = 1 + MAX_ELEM;
        capacity2 = 1 + MAX_ELEM;
    }

}

Tree Tree::operator++() {

    int n = size;
    if (size == capacity1){
        int i, j;
        int **temp = new int*[capacity1 + MAX_ELEM / 2];
        for(i = 0; i < capacity1; ++i){
            temp[i] = new int[capacity2 + MAX_ELEM / 2];
        }

        for(i = 0; i < capacity1; ++i){
            for (j = 0; j < capacity2; ++j){
                temp[i][j] = elements[i][j];
            }
        }
        delete[] elements;
        elements = temp;
        capacity1 = capacity1 + MAX_ELEM / 2;
        capacity2 = capacity2 + MAX_ELEM / 2;
    }
//    elements[size][0] = size + 1;
//    elements[size][1] = 2;
//    elements[size][2] = 0;

    add_edge(elements[size-1][0],elements[size][0]);
    size = size + 1;
    return (*this);
}

Tree Tree::operator++(int) {

    Tree temp1 = (*this);
    int n = size;

    if (size == capacity1){
        int i, j;
        int **temp = new int*[capacity1 + MAX_ELEM / 2];
        for(i = 0; i < size; ++i){
            temp[i] = new int[capacity2];
        }

        for(i = 0; i < size; ++i){
            for (j = 0; j < capacity2; ++j){
                temp[i][j] = elements[i][j];
            }
        }
        delete[] elements;
        elements = temp;
        capacity1 = capacity1 + MAX_ELEM / 2;
        capacity2 = capacity2;
    }
//  elements[size][0] = size + 1;
//  elements[size][1] = 2;
//  elements[size][2]= 0;


    add_edge(elements[size-1][0],elements[size][0]);
    size = size + 1;
    return temp1;
}
