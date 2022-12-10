#include <iostream>

#include "Graph.h"
#include "Tree.h"
#include "Bipartite.h"

using namespace std;

void testTree();
void testGraph();
void testBipartite();
void testElse();

int main() {


    testTree();
//    testGraph();

//    testBipartite();
    return 0;
}

void testTree(){

    Tree tree;

    for (int j = 0; j < 4; ++j) {
        tree++;
    }

//    cout<<tree<<endl;

    for (int j = 0; j < 4; ++j) {
        ++tree;
    }
//    cout<<tree<<endl;

    tree--;

//    cout<<tree<<endl;

    tree.remove_edge(3,4);

    tree.remove_edge(4,5);

    tree.remove_edge(8,7);

//    cout<<tree<<endl;

    tree.add_edge(1,8);
    tree.add_edge(1,5);
    tree.add_edge(2,4);

    cout<<tree<<endl;

    tree.set_root(5);

    cout<<tree<<endl;

}

void testGraph(){

    Graph g(8);
    int i;
    cout << g << endl;
    --g;
    cout << g << endl;
    g--;
    cout << g << endl;
    g++;
    cout << g << endl;
    ++g;
    cout << g << endl;

    g.add_edge(1,2);
    g.add_edge(2,1);
    g.add_edge(2,3);
    g.add_edge(2,4);
    g.add_edge(3,3);
    g.add_edge(4,1);
    g.add_edge(4,3);
    g.add_edge(5,6);

    cout << g << endl;

    g.remove_edge(2,1);
    //g.add_edge(5,5);

    cout << g << endl;

    cout << g.path_exist(1,5) << endl;
    cout << g.path_exist(1,3) << endl;
    cout << g.path_exist(1,2) << endl;
    cout << g.path_exist(4,3) << endl;

    cout << g.edge_exist(1,3) << endl;
    cout << g.edge_exist(2,1) << endl;

    cout<<endl;
}

void testBipartite(){

    Bipartite b(8);
    cout<<b<<endl;

    b.add_edge(1,2);
    b.add_edge(1,3);
    b.add_edge(2,4);
    b.add_edge(1,4);

    cout<<b<<endl;

}