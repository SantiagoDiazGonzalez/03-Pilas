#include <iostream>
#include "../Pila/Pila.h"

using namespace std;

int prioridad(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    if (c == '(')
        return 0;
    return 10;
}

string postfija(string e) {
    Pila<char> p;
    string r; // r = "";
    for (int i = 0; e[i] != '\0'; ++i) {
        if ((e[i] >= 0 && e[i] <= 9) || (e[i] >= 'a' && e[i] <= 'z') || e[i] >= 'A' && e[i] <= 'Z') {
            r += (e[i]);
        } else {
            if (e[i] != ')') {
                bool desapilar = true;
                while (desapilar) {
                    if (p.esVacia() || e[i] == '(' || e[i] == '^' || prioridad(e[i]) > prioridad(p.peek())) {
                        p.push(e[i]);
                        desapilar = false;
                    } else {
                        if (prioridad(e[i]) <= prioridad(p.peek())) {
                            r += p.pop();
                            desapilar = true;
                        }
                    }
                }
            } else {
                while (p.peek() != '(')
                    r += p.pop();
                p.pop();
            }
        }
    }

    while (!p.esVacia())
        r += p.pop();
    return r;
}

int main() {
    std::cout << "Ejercicio 03/05\n" << std::endl;
    cout << "Ingresar expresion infija\n";
    cout << "La expresion posfija es \n" << postfija("a*(b+c-(d/e^f)-g)-h") << endl;

    return 0;
}