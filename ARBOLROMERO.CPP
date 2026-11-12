#include <iostream>
using namespace std;

struct Nodo {
    int numero;
    Nodo* menor;
    Nodo* mayor;
};

// Generar un nodo nuevo
Nodo* nuevoNodo(int dato) {
    Nodo* auxiliar = new Nodo;

    auxiliar->numero = dato;
    auxiliar->menor = NULL;
    auxiliar->mayor = NULL;

    return auxiliar;
}

// Agregar valores al arbol
Nodo* agregar(Nodo* arbol, int dato) {
    if (arbol == NULL) {
        return nuevoNodo(dato);
    }

    if (dato < arbol->numero) {
        arbol->menor = agregar(arbol->menor, dato);
    }
    else {
        arbol->mayor = agregar(arbol->mayor, dato);
    }

    return arbol;
}

// Recorrido de izquierda a derecha
void recorridoInorden(Nodo* arbol) {
    if (arbol != NULL) {
        recorridoInorden(arbol->menor);
        cout << arbol->numero << " ";
        recorridoInorden(arbol->mayor);
    }
}

// Recorrido desde la raiz
void recorridoPreorden(Nodo* arbol) {
    if (arbol != NULL) {
        cout << arbol->numero << " ";
        recorridoPreorden(arbol->menor);
        recorridoPreorden(arbol->mayor);
    }
}

// Recorrido con la raiz al final
void recorridoPosorden(Nodo* arbol) {
    if (arbol != NULL) {
        recorridoPosorden(arbol->menor);
        recorridoPosorden(arbol->mayor);
        cout << arbol->numero << " ";
    }
}

int main() {
    Nodo* arbol = NULL;
    int entrada;
    int contador = 1;

    cout << "Digite cinco valores:\n";

    while (contador <= 5) {
        cout << "Valor " << contador << ": ";
        cin >> entrada;

        arbol = agregar(arbol, entrada);
        contador++;
    }

    cout << "\nRESULTADOS DE LOS RECORRIDOS\n";

    cout << "\nInorden: ";
    recorridoInorden(arbol);

    cout << "\nPreorden: ";
    recorridoPreorden(arbol);

    cout << "\nPosorden: ";
    recorridoPosorden(arbol);

    cout << "\n";

    return 0;
}