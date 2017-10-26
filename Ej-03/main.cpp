#include <iostream>
#include "../Pila/Pila.h"
using namespace std;

int main() {
    std::cout << "Ejercicio 03/03\n" << std::endl;
    
    Pila<int> a;
    
    a.push(1);
    cout << a.peek() << endl;
    a.push(3);
    cout << a.peek() << endl;
    a.pop();
    cout << a.peek() << endl;
    
    return 0;
}