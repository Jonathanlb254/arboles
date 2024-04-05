#include <iostream>

using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;
};

class ArbolBinario {
private:
    Nodo* raiz;

public:
    ArbolBinario() {
        raiz = nullptr;
    }

    void insertar(int valor) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->valor = valor;
        nuevoNodo->izquierda = nullptr;
        nuevoNodo->derecha = nullptr;

        if (raiz == nullptr) {
            raiz = nuevoNodo;
        } else {
            Nodo* actual = raiz;
            bool insertado = false;

            while (!insertado) {
                if (valor < actual->valor) {
                    if (actual->izquierda == nullptr) {
                        actual->izquierda = nuevoNodo;
                        insertado = true;
                    } else {
                        actual = actual->izquierda;
                    }
                } else {
                    if (actual->derecha == nullptr) {
                        actual->derecha = nuevoNodo;
                        insertado = true;
                    } else {
                        actual = actual->derecha;
                    }
                }
            }
        }
    }

    bool buscar(int valor) {
        Nodo* actual = raiz;

        while (actual != nullptr) {
            if (actual->valor == valor) {
                return true;
            } else if (valor < actual->valor) {
                actual = actual->izquierda;
            } else {
                actual = actual->derecha;
            }
        }

        return false;
    }
};

int main() {
    ArbolBinario arbol;

    char opcion;
    int valor;

    cout << "Ingrese valores para insertar en el arbol (s para salir):" << endl;

    while (true) {
        cout << "Ingrese un valor: ";
        cin >> valor;

        arbol.insertar(valor);

        cout << "¿Desea ingresar otro valor? (s/n): ";
        cin >> opcion;

        if (opcion == 'n' || opcion == 'N') {
            break;
        }
    }

    int valorBuscar;
    cout << "Ingrese el valor que desea buscar en el arbol: ";
    cin >> valorBuscar;

    if (arbol.buscar(valorBuscar)) {
        cout << "El valor " << valorBuscar << " está en el árbol." << endl;
    } else {
        cout << "El valor " << valorBuscar << " no está en el árbol." << endl;
    }

    return 0;
}
