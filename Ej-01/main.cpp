#include <iostream>
#include "../Pila/Pila.h"
using namespace std;

int main() {
    std::cout << "Ejercicio 03/01\n" << std::endl;

    Pila<char> p;
    char palabra[100];
    int i, c=0;

    cin >> palabra;

    for(i=0; palabra[i]!='\0'; i++)
        c++;

    i=0;
    while(i<c){
        p.push(palabra[i]);
        i++;
    }

    i=0;
    while(i<c){
        palabra[i]=p.pop();
        i++;
    }

    cout << palabra;

    return 0;
}