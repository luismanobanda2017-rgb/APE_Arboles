import java.util.ArrayList;
import java.util.List;

public class  RecorridoInOrder {
    public static void inOrderAux(Nodo nodo, List<Integer> resultado) {
        // TODO: Implementa tu lógica de recorrido aquí

        // Caso base: si el nodo no existe, no hay nada que recorrer
        if (nodo == null) return;

        // Primero recorremos todo el subárbol izquierdo (valores menores)
        inOrderAux(nodo.izquierdo, resultado); // Recorre izquierda

        // Luego visitamos el nodo actual y guardamos su valor
        resultado.add(nodo.valor);             // Visita nodo

        // Por último recorremos todo el subárbol derecho (valores mayores)
        inOrderAux(nodo.derecho, resultado);   // Recorre derecha
    }

    public static List<Integer> recorridoInOrder(Nodo raiz) {
        List<Integer> resultado = new ArrayList<>();
        inOrderAux(raiz, resultado);
        return resultado;
    }

    public static void main(String[] args) {
        //        4
        //      /   \
        //     2     6
        //    / \   / \
        //   1   3 5   7
        Nodo raiz = new Nodo(4);
        raiz.izquierdo = new Nodo(2);
        raiz.derecho = new Nodo(6);
        raiz.izquierdo.izquierdo = new Nodo(1);
        raiz.izquierdo.derecho = new Nodo(3);
        raiz.derecho.izquierdo = new Nodo(5);
        raiz.derecho.derecho = new Nodo(7);

        System.out.println("--- Prueba Ejercicio 4 ---");
        System.out.println("Resultado esperado: [1, 2, 3, 4, 5, 6, 7]");
        System.out.println("Tu resultado:       " + recorridoInOrder(raiz));
    }
}
