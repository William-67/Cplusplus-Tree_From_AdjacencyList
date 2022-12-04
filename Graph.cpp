//
// Created by weili on 2022-12-03.
//

#include <iostream>
#include "Graph.h"
#include "DoubleLinkedList.h"

using namespace std;

ostream& operator <<(ostream& out, Graph& g){
    int i, j, k;
    out << "V = {";
    for (i = 0; i < g.size; ++i){
        if (i != 0){
            out << ",";
        }
        if (g.elements[i][0] != 0){
            out << g.elements[i][0];
        }
        else{
            break;
        }
    }
    out << "}" << endl;

    out << "E = " << endl;
    out << "{" << endl;
    for (i = 0;  i < g.size; ++i){
        out << "   " << g.elements[i][0] << " => ";
        if (g.elements[i][1] == 2){
            out << "None";
        }
        else{
            for (j = 2; j < g.elements[i][1]; ++j){
                if (j != 2){
                    out << ",";
                }

                if (g.elements[i][j] != 0){
                    out << g.elements[i][j];
                }
                else{
                    break;
                }
            }
        }

        out << endl;
    }
    out << "}" << endl;

    return out;
}

Graph::Graph(){

    capacity1 = 0;
    capacity2 = 0;
    dummy = 0;
    elements = NULL;
    size = 0;
    //head = NULL;
}

Graph::Graph(int n){
    capacity1 = 0;
    capacity2 = 0;
    dummy = 0;
    size = 0;

    int i, j;
    elements = new int*[n + MAX_ELEM];
    for (i = 0; i < n + MAX_ELEM; ++i){
        elements[i] = new int[n + MAX_ELEM];
        elements[i][0] = i + 1;
        elements[i][1] = 2;
        elements[i][2] = 0;
//        for (j = 2; j < n + MAX_ELEM; ++i)
//            elements[i][j] = 0;
    }

    if (elements == NULL){
        cout << "not enough memory";
    }
    else{
        size = n;
        capacity1 = n + MAX_ELEM;
        capacity2 = n + MAX_ELEM;
    }
}

Graph::Graph(const Graph& gra){

    capacity1 = 0;
    capacity2 = 0;
    dummy = 0;
    size = 0;

    int i, j;
    elements = new int*[gra.capacity1];
    for (i = 0; i < gra.capacity1; ++i){
        elements[i] = new int[gra.capacity2];
    }

    if (elements == NULL){
        cout << "not enough memory";
    }
    else{
        for(i = 0; i < gra.size; ++i){
            for (j = 0; j < gra.elements[i][1]; ++j)
                elements[i][j] = gra.elements[i][j];
        }
        capacity1 = gra.capacity1;
        capacity2 = gra.capacity2;
        size = gra.size;
    }

}

Graph::~Graph(){
    int i;
    for(i = 0; i < capacity1; ++i){
        delete[] elements[i];
    }
    delete[] elements;
}

bool Graph::add_edge(int a, int b){

    int i;

    for (i = 0; i < size; ++i){
        if (elements[i][0] == a){
            elements[i][elements[i][1]] = b;
            elements[i][1] = elements[i][1] + 1;
            return true;
        }
    }
    return false;

}

void Graph::remove_edge(int a, int b){

    int i, j, k;
    for (i = 0; i < size; ++i){
        if (elements[i][0] == a){
            for (j = 2; j < elements[i][1]; ++j){
                if (elements[i][j] == b){
                    elements[i][j] = 0;                    //set empty as 0
                    elements[i][1] = elements[i][1] - 1;
                    for (k = j; k < elements[i][1]; ++k){        //move all the elements on the right to left one bit if the edge is within the array
                        elements[i][k] = elements[i][k+1];
                        if (k == capacity2 - 1){
                            elements[i][k] = 0;
                        }
                    }
                    break;
                }
            }
        }
    }
}

bool Graph::edge_exist(int a, int b){

    int i, j, k;
    for (i = 0; i < size; ++i){
        if (elements[i][0] == a){
            for (j = 2; j < capacity2; ++j){
                if (elements[i][j] == b && j != 1){
                    return true;
                }
            }
        }
        if (elements[i][0] == b){
            for (j = 2; j < capacity2; ++j){
                if (elements[i][j] == a && j != 1){
                    return true;
                }
            }
        }
    }
    return false;
}

int Graph::get_degree(int a) {

    int i;
    int count = 0;
    for (i = 0; i < capacity1; ++i){
        if (elements[i][0] == a){
            count = elements[i][1] - 2;
        }
    }
    return count;
}

Graph Graph::operator ++(){

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
    size = size + 1;
    return (*this);
}

Graph Graph::operator ++(int a){

    Graph temp1 = (*this);
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
    size = size + 1;
    return temp1;
}

Graph Graph::operator --(){

//    int i;
//    for (i = 0; i < capacity2; ++i){
//        elements[size - 1][i] = 0;
//    }
    size = size - 1;
    return (*this);
}

Graph Graph::operator --(int a){

    Graph temp1 = (*this);
//    int i;
//    for (i = 0; i < capacity2; ++i){
//        elements[size - 1][i] = 0;
//    }
    size = size - 1;
    return temp1;
}

bool Graph::path_exist(int a, int b){
    int i, j;
    DoubleLinkedList visited1;
    DoubleLinkedList visited2;

    //from 1 to 3;
    for (i = 0; i < size; ++i) {
        if (elements[i][0]==a){
            if (edge_exist(a,b)){
                return true;
            }else{
                visited1.add_to_back(a);
                for (j = 2; j < elements[i][1]; ++j) {
                    bool flag = false;
                    for (int k = 0; k < visited1.count_nodes(); ++k) {
                        if (visited1[k]==a){
                            flag = true;
                        }
                    }
                    if (!flag){
                        return path_exist(elements[i][j],b);
                    }

                }
            }
        }
    }
    for (i = 0; i < size; ++i) {
        if (elements[i][0]==b){
            if (edge_exist(b,a)){
                return true;
            }else{
                visited2.add_to_back(b);
                for (j = 2; j < elements[i][1]; ++j) {

                    bool flag = false;
                    for (int k = 0; k < visited2.count_nodes(); ++k) {
                        if (visited1[k]==b){
                            flag = true;
                        }
                    }
                    if (!flag){
                        return path_exist(elements[i][j],a);
                    }

                }
            }
        }
    }
    return false;
}




