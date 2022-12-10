//Lixiong Wei 300145970
//Vincent Tan 300125812
//

#include "Bipartite.h"

Bipartite::Bipartite() {

    capacity1 = 0;
    capacity2 = 0;
    dummy = 0;
    size = 0;

    int i, j, n = 2;
    elements = new int*[n + MAX_ELEM];
    for (i = 0; i < n + MAX_ELEM; ++i){
        elements[i] = new int[n + MAX_ELEM];
        elements[i][0] = i + 1;
        elements[i][1] = 2;
        elements[i][2] = 0;
//        for (j = 2; j < n + MAX_ELEM; ++i)
//            elements[i][j] = 0;

        if (i<n){
            notConnect.add_to_back(i+1);
        }

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

Bipartite::Bipartite(int n){

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

        if (i<n){
            notConnect.add_to_back(i+1);
        }

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

bool Bipartite::add_edge(int a, int b) {

    //check valid (a belongs to first set and b belong to second set)

    if (first.elementExist(a) && first.elementExist(b)){
        cout<<"Vertices "<< a <<" and "<< b << " are in the same set" <<endl;
        cout<<"Therefore edge cannot be added" <<endl;
        cout<<endl;
        return false;
    }

    if (second.elementExist(a) && second.elementExist(b)){
        cout<<"Vertices "<< a <<" and "<< b << " are in the same set" <<endl;
        cout<<"Therefore edge cannot be added" <<endl;
        cout<<endl;
        return false;
    }

    if (first.elementExist(a)){

        if (!second.elementExist(b)){

            notConnect.remove_item(b);

            second.add_to_back(b);
        }

    }else if (second.elementExist(a)){

        if (!first.elementExist(b)){

            notConnect.remove_item(b);

            first.add_to_back(b);

        }

    }else if (second.elementExist(b)){

        if (!first.elementExist(a)){

            notConnect.remove_item(a);

            first.add_to_back(a);

        }

    }else if (first.elementExist(b)){

        if (!second.elementExist(a)){

            notConnect.remove_item(a);

            second.add_to_back(a);

        }

    }else{

        notConnect.remove_item(a);

        notConnect.remove_item(b);

        first.add_to_back(a);//put vertex a into first set by default

        second.add_to_back(b);
    }

    Graph::add_edge(a,b);
    Graph::add_edge(b,a);

    return true;
}

ostream &operator<<(ostream &out, Bipartite & g) {

    out<<"Set A ={" << g.first<< "}" <<endl;
    out<<"Set B ={" << g.second<< "}" <<endl;
    out<<"Not connected ={" << g.notConnect<< "}" <<endl;

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
