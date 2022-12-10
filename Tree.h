//Lixiong Wei 300145970
//Vincent Tan 300125812
//

#ifndef VINCENT_TREE_H
#define VINCENT_TREE_H

#include "Forest.h"
#include "DoubleLinkedList.h"
class Tree : public Forest{

private:
    int root;

public:
    Tree();

//    bool add_edge(int, int);
    Tree operator++() ;
    Tree operator--() ;
    Tree operator++(int) ;
    Tree operator--(int) ;

    void set_root(int);

    friend ostream& operator <<(ostream& out, Tree&);

};


#endif //VINCENT_TREE_H
