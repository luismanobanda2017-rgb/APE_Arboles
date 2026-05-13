#include <iostream>
#include <vector>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

void inOrderAux(Nodo* nodo, vector<int>& resultado) {
    // TODO: Implementa tu logica de recorrido aqui

    // Caso base: si el nodo no existe, no hay nada que recorrer
    if (nodo == nullptr) return;

    // Primero recorremos todo el subárbol izquierdo (valores menores)
    inOrderAux(nodo->izquierdo, resultado); // Recorre izquierda

    // Luego visitamos el nodo actual y guardamos su valor
    resultado.push_back(nodo->valor);       // Visita nodo

    // Por último recorremos todo el subárbol derecho (valores mayores)
    inOrderAux(nodo->derecho, resultado);   // Recorre derecha
}

vector<int> recorridoInOrder(Nodo* raiz) {
    vector<int> resultado;
    inOrderAux(raiz, resultado);
    return resultado;
}

int main() {
    Nodo* raiz = new Nodo(4);
    raiz->izquierdo = new Nodo(2);
    raiz->derecho = new Nodo(6);
    raiz->izquierdo->izquierdo = new Nodo(1);
    raiz->izquierdo->derecho = new Nodo(3);
    raiz->derecho->izquierdo = new Nodo(5);
    raiz->derecho->derecho = new Nodo(7);

    vector<int> res = recorridoInOrder(raiz);
    
    cout << "--- Prueba Ejercicio 4 ---" << endl;
    cout << "Resultado esperado: 1 2 3 4 5 6 7 " << endl;
    cout << "Tu resultado:       ";
    for(int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
