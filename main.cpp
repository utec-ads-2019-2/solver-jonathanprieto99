#include <iostream>
#include "tree.h"

using namespace std;

int main(){
    Tree<string> tree;
    auto resultado=tree.Resolver("7/4*((3+1)*a)+            a))))))))))");
    cout<<"Resultado: "<<resultado<<endl;
    return 0;
}