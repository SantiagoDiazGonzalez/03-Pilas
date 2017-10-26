#include <iostream>
#include "../Pila/Pila.h"
using namespace std;

template <class T>
bool pilasIguales(Pila<T> a, Pila<T> b){
    while(!a.esVacia() && !b.esVacia()){
        if(a.peek() != b.peek())
            return false;
        a.pop();
        b.pop();
    }
    if(a.esVacia() != b.esVacia())
        return false;
    return true;
}

int main() {
    std::cout << "Ejercicio 03/02\n" << std::endl;

    Pila<int> a,b;

    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);

    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);

    if(pilasIguales(a,b))
        cout << "pilas iguales" << endl;
    else
        cout << "pilas diferentes" << endl;

    return 0;
}