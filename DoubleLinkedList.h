//
// Created by weili on 2022-12-03.
//

#ifndef VINCENT_DOUBLELINKEDLIST_H
#define VINCENT_DOUBLELINKEDLIST_H


#include <iostream>

using namespace std;

class Node{
    friend class DoubleLinkedList;

    int data;
    Node* next;
    Node* previous;

};

class DoubleLinkedList {

private:
    Node* head;
    Node* tail;
    int dummy;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    bool add_to_front(int);
    bool add_to_back(int);
    bool insert_item(int, int);
    void remove_item(int);
    void remove_from_front();
    void remove_from_back();
    int count_nodes();

    int& operator[](int);
    friend ostream& operator<<(ostream&, DoubleLinkedList&);
};



#endif //VINCENT_DOUBLELINKEDLIST_H
