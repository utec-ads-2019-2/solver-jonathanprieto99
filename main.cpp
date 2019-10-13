#include <iostream>
#include "tree.h"

using namespace std;

int main(){
    Tree<string> tree;
    auto resultado=tree.Resolver("6*5+(4+2)^a");
    cout<<"Resultado: "<<resultado<<endl;
    return 0;
}