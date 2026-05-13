#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

Nodo* insertar(Nodo* raiz, int valor) {
    // TODO: Implementa tu lógica aquí

    // Caso base: si llegamos a un espacio vacío, creamos el nuevo nodo aquí
    if (raiz == nullptr) return new Nodo(valor);

    // Si el valor es menor, pertenece al subárbol izquierdo
    if (valor < raiz->valor)
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    else
        // Si el valor es mayor o igual, pertenece al subárbol derecho
        raiz->derecho = insertar(raiz->derecho, valor);

    // Retornamos la raíz con el nuevo nodo ya insertado
    return raiz;
}

int main() {
    Nodo* raiz = new Nodo(10);
    
    raiz = insertar(raiz, 5);
    raiz = insertar(raiz, 15);
    raiz = insertar(raiz, 3);
    
    cout << "--- Prueba Ejercicio 2 ---" << endl;
    cout << "Raiz (Esperado 10): " << raiz->valor << endl;
    
    if(raiz->izquierdo) cout << "Hijo Izquierdo (Esperado 5): " << raiz->izquierdo->valor << endl;
    else cout << "Hijo Izquierdo: null" << endl;
    
    if(raiz->derecho) cout << "Hijo Derecho (Esperado 15): " << raiz->derecho->valor << endl;
    else cout << "Hijo Derecho: null" << endl;
    
    if(raiz->izquierdo && raiz->izquierdo->izquierdo) 
        cout << "Hijo Izq del 5 (Esperado 3): " << raiz->izquierdo->izquierdo->valor << endl;
    else cout << "Hijo Izq del 5: null" << endl;

    return 0;
}
