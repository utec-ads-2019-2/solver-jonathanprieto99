#ifndef SOLVER_JONATHANPRIETO99_NODE_H
#define SOLVER_JONATHANPRIETO99_NODE_H

#include <string>
#include <utility>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;

template <typename T>
class Node {
    T data;
    Node<T> *left;
    Node<T> *right;
    bool typeoperator;
    int prioridad;

    template<class>
    friend class Tree;
    explicit Node(T data): data(data), left(nullptr),right(nullptr){

        typeoperator = true;

        if (data == "+" or data == "-"){
            prioridad = 1;
        }

        else if (data == "*" or data=="/"){
            prioridad = 2;
        }

        else if(data == "^"){
            prioridad = 3;
        }

        else{
            typeoperator = false;
            prioridad = 0;
            }
    }


    void eliminar(){
        if(this->left)
            left->eliminar();
        if(this->right)
            right->eliminar();
        delete this;
    }

    double Operar(){
        return evaluar2(this);
    }

private:


    bool Ihoja(){
        return (!this->left && !this->right);
    }

    double evaluar(Node* root, vector<double> &resultados){

        //Excepciones

        if (!root) {
            resultados.push_back(0);
            return 0;
        }

        if (root->Ihoja()) {
            resultados.push_back(stod(root->data));
            return stod(root->data);
        }

        double operando_izquierdo = evaluar(root->left,resultados);

        double operando_derecho = evaluar(root->right,resultados);


        if (root->data=="+"){
            resultados.push_back(operando_izquierdo + operando_derecho);
            return (operando_izquierdo + operando_derecho);
        }

        else if (root->data=="-"){
            resultados.push_back(operando_izquierdo - operando_derecho);
            return (operando_izquierdo - operando_derecho);
        }

        else if (root->data=="*"){
            resultados.push_back(operando_izquierdo * operando_derecho);
            return (operando_izquierdo * operando_derecho);
        }

        else if (root->data=="/"){
            resultados.push_back(operando_izquierdo / operando_derecho);
            return (operando_izquierdo / operando_derecho);
        }

        else{
            resultados.push_back(pow(operando_izquierdo , operando_derecho));
            return pow(operando_izquierdo , operando_derecho);
        }
    }

    double evaluar2(Node* root){

        vector<double> resultados1;

        evaluar(root, resultados1);
        return resultados1.back();

    }


};


#endif //SOLVER_JONATHANPRIETO99_NODE_H


