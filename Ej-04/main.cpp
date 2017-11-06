#include <iostream>
#include "../Pila/Pila.h"

using namespace std;

bool control_parentesis(string &f) {
    Pila<char> p;
    for (int i = 0; i < f.length(); i++) {
        if (f[i] == '(' || f[i] == '[' || f[i] == '{')
            p.push(f[i]);

        if (f[i] == ')')
            if (p.esVacia()) return false;
            else if (p.peek() != '(') return false;
            else p.pop();

        if (f[i] == ']')
            if (p.esVacia()) return false;
            else if (p.peek() != '[') return false;
            else p.pop();

        if (f[i] == '}')
            if (p.esVacia()) return false;
            else if (p.peek() != '{') return false;
            else p.pop();
    }
    return p.esVacia();
}

int main() {
    std::cout << "Ejercicio 03/04\n" << std::endl;

    string funcion;

    cout << "ingrese la funcion: ";
    getline(cin, funcion);
    cout << endl;

    if (control_parentesis(funcion))
        cout << "parentesis correctos" << endl;
    else
        cout << "parentesis incorrectos" << endl;

    return 0;
}