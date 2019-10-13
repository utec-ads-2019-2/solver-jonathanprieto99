#include <iostream>
#include "tree.h"

using namespace std;

int main(){
    Tree<string> tree;
    auto resultado=tree.Resolver("33+1");
    cout<<"Resultado: "<<resultado<<endl;
    return 0;
}