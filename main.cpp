#include <iostream>
#include "Graph.h"
#include "Tree.h"

using namespace std;

int main() {
//    int elements[3][7] = {{1, 4, 5, 4},
//                          {2, 6, 5, 4, 7, 1},
//                          {3,2}};
//    int size = 3;
//    int i, j, k;
//    int capacity1 = 3;
//    int capacity2 = 7;
//    int a = 5;
//    int b = 5;

    //add_edge
//    for (i = 0; i < capacity1; ++i){
//        if (elements[i][0] == a){
//            elements[i][elements[i][1]] = b;
//            elements[i][1] = elements[i][1] + 1;
//            break;
//        }
//    }

    //remove_edge
//    a = 2;
//    b = 5;
//    for (i = 0; i < capacity1; ++i){
//        if (elements[i][0] == a){
//            for (j = 2; j < capacity2; ++j){
//                if (elements[i][j] == b && j != 1){
//                    elements[i][j] = 0;                    //set empty as 0
//                    elements[i][1] = elements[i][1] - 1;
//                    for (k = j; k < capacity2; ++k){        //move all the elements on the right to left one bit if the edge is within the array
//                        elements[i][k] = elements[i][k+1];
//                        if (k == capacity2 - 1){
//                            elements[i][k] = 0;
//                        }
//                    }
//                    break;
//                }
//            }
//        }
//    }

    //edge_exist
//    a = 3;
//    b = 3;
//    for (i = 0; i < capacity1; ++i){
//        if (elements[i][0] == a){
//            for (j = 2; j < capacity2; ++j){
//                if (elements[i][j] == b && j != 1){
//                    cout << "1true" << endl;
//                    break;
//                }
//            }
//        }
//        if (elements[i][0] == b){
//            for (j = 2; j < capacity2; ++j){
//                if (elements[i][j] == a && j != 1){
//                    cout << "2true" << endl;
//                    break;
//                }
//            }
//        }
//    }
//    cout << "false" << endl;

    //get_degree
//    a = 4;
//    int count = 0;
//    for (i = 0; i < capacity1; ++i){
//        if (elements[i][0] == a){
//            count = elements[i][1] - 2;
//        }
//    }
//    cout << count << endl;

    //operator++
//    elements[size][0] = size +1;
//    elements[size][1] = 2;
//    size = size + 1;

    //operator--
//    for (i = 0; i < capacity2; i++){
//        elements[size - 1][i] = 0;
//    }
//    size = size - 1;

    //operator <<
//    cout << "V = {";
//    for (i = 0; i < size; ++i){
//        if (i != 0){
//            cout << ",";
//        }
//        if (elements[i][0] != 0){
//            cout << elements[i][0];
//        }
//        else{
//            break;
//        }
//    }
//    cout << "}" << endl;
//
//    cout << "E = " << endl;
//    cout << "{" << endl;
//    for (i = 0;  i < size; ++i){
//        cout << "   " << elements[i][0] << " => ";
//        for (j = 2; j < capacity2; ++j){
//            if (j != 2){
//                cout << ",";
//            }
//            if (elements[i][1] == 2){
//                cout << "None";
//            }
//            if (elements[i][j] != 0){
//                cout << elements[i][j];
//            }
//            else{
//                break;
//            }
//        }
//        cout << endl;
//    }
//    cout << "}" << endl;



//    cout << endl;
//    cout << elements[0][0] << " " << elements[0][1] << " " << elements[0][2] << " " << elements[0][3] << " " << elements[0][4]<< " " << elements[0][5]<< " " << elements[0][6] << endl;
//    cout << elements[1][0] << " " << elements[1][1] << " " << elements[1][2] << " " << elements[1][3] << " " << elements[1][4] << " " << elements[1][5] << " " << elements[1][6] << endl;
//    cout << elements[2][0] << " " << elements[2][1] << " " << elements[2][2] << " " << elements[2][3] << " " << elements[2][4] << " " << elements[2][5] << " " << elements[2][6] << endl;
//    cout << size;

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

    Graph tree = Graph(1);
    tree++;
    ++tree;
    cout<<tree<<endl;

    return 0;
}