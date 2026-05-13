#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

Nodo* invertir(Nodo* raiz) {
    // TODO: Implementa tu lógica aquí

    // Caso base: si el nodo no existe, no hay nada que invertir
    if (raiz == nullptr) return nullptr;

    // Usamos una variable temporal para intercambiar los hijos
    // izquierdo y derecho del nodo actual
    Nodo* temp = raiz->izquierdo;       // Guardamos el hijo izquierdo
    raiz->izquierdo = raiz->derecho;    // Intercambiamos los hijos izquierdo y derecho
    raiz->derecho = temp;

    // Aplicamos la misma inversión de forma recursiva en ambos subárboles
    invertir(raiz->izquierdo);          // Invertimos recursivamente ambos subárboles
    invertir(raiz->derecho);

    // Retornamos la raíz ya invertida
    return raiz;
}

int main() {
    Nodo* raiz = new Nodo(1);
    raiz->izquierdo = new Nodo(2);
    raiz->derecho = new Nodo(3);

    cout << "--- Prueba Ejercicio 5 ---" << endl;
    cout << "Antes de invertir:" << endl;
    cout << "Hijo Izq: " << raiz->izquierdo->valor << " | Hijo Der: " << raiz->derecho->valor << endl;
    
    invertir(raiz);
    
    cout << "\nDespues de invertir (Esperado: Izq 3 | Der 2):" << endl;
    
    if(raiz->izquierdo) cout << "Hijo Izq: " << raiz->izquierdo->valor;
    else cout << "Hijo Izq: null";
    
    cout << " | ";
    
    if(raiz->derecho) cout << "Hijo Der: " << raiz->derecho->valor << endl;
    else cout << "Hijo Der: null" << endl;

    return 0;
}
