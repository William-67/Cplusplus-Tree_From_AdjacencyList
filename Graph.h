//
// Created by weili on 2022-12-03.
//

#ifndef VINCENT_GRAPH_H
#define VINCENT_GRAPH_H

#define MAX_ELEM 100
#include <iostream>
using namespace std;

class Graph{
protected:
    int **elements;
    int capacity1;
    int capacity2;
    int size;
//    node* head;
//    DoubleLinkedList* vertices;
    int dummy;

public:
    Graph();
    Graph(int);
    Graph(const Graph&);
    ~Graph();
    bool add_edge(int, int);
    void remove_edge(int, int);
    bool edge_exist(int, int);
    int get_degree(int);

    Graph operator ++();
    Graph operator ++(int);
    Graph operator --();
    Graph operator --(int);
    bool path_exist(int, int);
    friend ostream& operator <<(ostream& out, Graph&);
};



#endif //VINCENT_GRAPH_H
