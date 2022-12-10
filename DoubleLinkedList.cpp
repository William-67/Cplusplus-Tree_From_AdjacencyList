//Lixiong Wei 300145970
//Vincent Tan 300125812
//

#include "DoubleLinkedList.h"
#include <iostream>

using namespace std;

DoubleLinkedList::DoubleLinkedList() {
    head = NULL;
    tail = NULL;
    dummy = 0;
}

DoubleLinkedList::~DoubleLinkedList() {

    if (head==NULL && tail==NULL){
        return;
    }

    Node* current;
    current = head;
    while (current != NULL){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = NULL;
    tail = NULL;
}

bool DoubleLinkedList::add_to_front(int x) {
    Node* new_node = new Node;
    new_node->next = NULL;
    new_node->previous = NULL;

    if (new_node == NULL)
        return false;

    new_node->data = x;
    if (tail == NULL){
        head = new_node;
        tail = new_node;
        return true;
    }

    new_node -> next = head;
    head->previous = new_node;
    head = new_node;

    return true;

}

bool DoubleLinkedList::add_to_back(int x) {
    Node* new_node = new Node;

    new_node->next = NULL;
    new_node->previous = NULL;

    if (new_node == NULL)
        return false;

    new_node -> data = x;

    if (head == NULL){
        head = new_node;
        tail = new_node;
        return true;
    }


    new_node->previous = tail;
    tail->next = new_node;
    tail = new_node;

    return true;
}

bool DoubleLinkedList::insert_item(int pos, int x) {

    if (pos == 0){
        return add_to_front(x);
    }

    int i;
    Node* current;
    Node* new_node;

    new_node = new Node;

    if (new_node == NULL)
        return false;

    new_node->data = x;
    new_node->next = NULL;
    new_node->previous = NULL;

    current = head;
    for (i = 0; i < pos -1; ++i) {
        current = current->next;
    }

    new_node->next = current->next;
    new_node->previous = current;
    current->next->previous = new_node;
    current->next = new_node;

    return true;
}

void DoubleLinkedList::remove_item(int x) {
    if (head == NULL){
        return;
    }
    if (head->data == x){
        remove_from_front();
        return;
    }
    if (tail->data == x){
        remove_from_back();
        return;
    }

    Node* current;
    for (current = head; current->next!=NULL;current = current->next) {
        if (current->next->data == x){
            Node *temp = current->next;
            current->next = current->next->next;
            current->next->previous = current;
            delete temp;
            break;
        }
    }
}

void DoubleLinkedList::remove_from_front() {
    if (head == NULL){
        return;
    }

    if (tail==head){
        head = NULL;
        tail = NULL;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}
int DoubleLinkedList::count_nodes() {
    int c = 0;
    Node* current;

    for (current = head; current != NULL; current = current->next)
        ++c;

    return c;
}

void DoubleLinkedList::remove_from_back() {
    if (tail == NULL){
        return;
    }
    if (tail==head){
        head = NULL;
        tail = NULL;
        return;
    }
    Node* temp = tail;
    tail = tail->previous;
    tail->next = NULL;
    delete temp;
}

int &DoubleLinkedList::operator[](int index) {
    int i, n =count_nodes();

    if (index < 0 || index >= n){
        return dummy;
    }

    Node* current = head;
    for (i = 0; i < index; ++i) {
        current = current-> next;
    }
    return current->data;
}

ostream &operator<<(ostream &out, DoubleLinkedList &list) {
    int n = list.count_nodes(), i;
    for (i = 0; i < n; ++i) {
        if (i != 0) out << ",";
        out << list[i];
    }
    return out;
}

bool DoubleLinkedList::elementExist(int x) {

    if (head==NULL){
        return false;
    }

    Node* current;
    for (current = head; current!=NULL;current = current->next) {

        if (current->data == x){

            return true;

        }

    }

    return false;
}

