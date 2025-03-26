#include <iostream>
#include "chair.h"

using namespace std;

void putCupOfTea(int h,int l,int w){
    cout<<"Table"<<endl;
}

class Table{
    int height;
    int lenght;
    int width;

    void putCapOfTee(){
        cout<<"Table\n"<<height<<"\n"<<lenght<<"\n"<<width<<endl;
    }
};

int main(){
    chair chair;
    chair.sit();
}