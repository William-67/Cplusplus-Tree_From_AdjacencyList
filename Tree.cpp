//
// Created by weili on 2022-12-03.
//

#include <stack>
#include <vector>
#include "Tree.h"

#define SPACE "  "
#define LINE  "---"

using namespace std;

Tree::Tree() {

    root = 1; // The root is set to be 1 by default

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

    size++;
    add_edge(elements[size-2][0],elements[size-1][0]);


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
        capacity2 = capacity2 + MAX_ELEM / 2;
    }
//  elements[size][0] = size + 1;
//  elements[size][1] = 2;
//  elements[size][2]= 0;

    size++;
    add_edge(elements[size-2][0],elements[size-1][0]);


    return temp1;
}

Tree Tree::operator--() {

    for (int i = 0; i < size-1; ++i) {
        remove_edge(elements[i][0],elements[size-1][0]);
    }


    size = size - 1;
    return (*this);
}

Tree Tree::operator--(int a) {
    Tree temp1 = (*this);

    for (int i = 0; i < size-1; ++i) {
        remove_edge(elements[i][0],elements[size-1][0]);
    }
//    int i;
//    for (i = 0; i < capacity2; ++i){
//        elements[size - 1][i] = 0;
//    }


    size = size - 1;
    return temp1;
}

void Tree::set_root(int a) {

    bool flag = false;
    for (int i = 0; i < size; ++i) {
        if (elements[i][0]==a){
            flag = true;
            break;
        }
    }
    if (!flag){
        cout<<"The root provided does not exist"<<endl;
    } else{
        root = a;
    }



}

ostream &operator<<(ostream &out, Tree &g) {

    int i, j, k, currentHeight = 0, currentValue = 0;

    stack<int> value;//trace value
    stack<int> height;//trace height
    DoubleLinkedList visited;

    value.push(g.root);
    height.push(0);
    visited.add_to_back(g.root);



    while (!value.empty()){

        currentValue = value.top();
        currentHeight = height.top();
        value.pop();
        height.pop();

        for (k = 0; k < currentHeight; ++k) {

            out<<SPACE;

        }

        if (currentValue==g.root){

            out<<currentValue<<endl;

        }else{

            out<<LINE<<currentValue<<endl;

        }


        for (i = 0; i < g.size; ++i) {

            if (g.elements[i][0]==currentValue){

                for (j = 2; j < g.elements[i][1]; ++j) {

                    int temp = g.elements[i][j];

                    if (!visited.elementExist(temp)){

                        value.push(g.elements[i][j]);

                        height.push(currentHeight+1);

                        visited.add_to_back(currentValue);

                    }

                }

            }

        }

    }
    return out;
}

