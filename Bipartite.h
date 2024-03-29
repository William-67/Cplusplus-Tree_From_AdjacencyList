//Lixiong Wei 300145970
//Vincent Tan 300125812
//

#ifndef VINCENT_BIPARTITE_H
#define VINCENT_BIPARTITE_H

#include "DoubleLinkedList.h"
#include "Graph.h"

class Bipartite :public Graph{

protected:

     DoubleLinkedList first;
     DoubleLinkedList second;
     DoubleLinkedList notConnect;

public:

    Bipartite();
    Bipartite(int);
    bool add_edge(int,int);
    friend ostream& operator <<(ostream& out, Bipartite&);


};


#endif //VINCENT_BIPARTITE_H
