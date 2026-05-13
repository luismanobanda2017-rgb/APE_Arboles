public class Ejercicio5_Transformacion {
    public static Nodo invertir(Nodo raiz) {
        // TODO: Implementa tu lógica aquí

        // Caso base: si el nodo no existe, no hay nada que invertir
        if (raiz == null) return null;

        // Usamos una variable temporal para intercambiar los hijos
        // izquierdo y derecho del nodo actual
        Nodo temp = raiz.izquierdo;         // Guardamos el hijo izquierdo
        raiz.izquierdo = raiz.derecho;      // Intercambiamos los hijos izquierdo y derecho
        raiz.derecho = temp;

        // Aplicamos la misma inversión de forma recursiva en ambos subárboles
        invertir(raiz.izquierdo);           // Invertimos recursivamente ambos subárboles
        invertir(raiz.derecho);

        // Retornamos la raíz ya invertida
        return raiz;
    }

    public static void main(String[] args) {
        //        1                 1
        //      /   \    -->      /   \
        //     2     3           3     2
        Nodo raiz = new Nodo(1);
        raiz.izquierdo = new Nodo(2);
        raiz.derecho = new Nodo(3);

        System.out.println("--- Prueba Ejercicio 5 ---");
        System.out.println("Antes de invertir:");
        System.out.println("Hijo Izq: " + raiz.izquierdo.valor + " | Hijo Der: " + raiz.derecho.valor);
        
        invertir(raiz);
        
        System.out.println("\nDespués de invertir (Esperado: Izq 3 | Der 2):");
        String izq = (raiz.izquierdo != null) ? String.valueOf(raiz.izquierdo.valor) : "null";
        String der = (raiz.derecho != null) ? String.valueOf(raiz.derecho.valor) : "null";
        
        System.out.println("Hijo Izq: " + izq + " | Hijo Der: " + der);
    }
}
