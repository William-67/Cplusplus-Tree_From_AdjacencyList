//
// Created by weili on 2022-12-03.
//

#include "Forest.h"

Forest::Forest() {

    capacity1 = 0;
    capacity2 = 0;
    dummy = 0;
    elements = NULL;
    size = 0;

}

Forest::Forest(int n){

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



Forest::Forest(const Forest &gra) {

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


bool Forest::add_edge(int a, int b) {

    int i;

    if (path_exist(a,b)){

        cout<<"Cannot added edge between "<< a<<"and "<<b <<" edges since it will cause a circle"<<endl;

        return false;

    }


    for (i = 0; i < size; ++i){

        if (elements[i][0] == b){

            elements[i][elements[i][1]] = a;

            elements[i][1] = elements[i][1] + 1;

        }

        if (elements[i][0] == a){

            elements[i][elements[i][1]] = b;

            elements[i][1] = elements[i][1] + 1;


        }

    }

    return true;

}



