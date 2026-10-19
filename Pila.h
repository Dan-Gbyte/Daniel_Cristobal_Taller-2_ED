#ifndef PILA_H
#define PILA_H

#include "Nodo.h"

// estructura de pila o LIFO (last in, first out)
template <typename T>
class Pila {
private:
    Nodo<T>* tope; // Puntero al elemento superior de la pila

public:
    // inicia la pila vacía
    Pila() : tope(nullptr) {}

    // destructor
    ~Pila() {
        while (!estaVacia()) {
            desapilar();
        }
    }

    // comprueba si la pila está vacía
    bool estaVacia() const { return tope == nullptr; }

    // agrega un elemento en el tope de la pila
    void apilar(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        nuevo->siguiente = tope;
        tope = nuevo;
    }

    // remueve y retorna el elemento que está más arriba
    T desapilar() {
        if (estaVacia()) return nullptr;
        Nodo<T>* aux = tope;
        T dato = aux->dato;
        tope = tope->siguiente;
        delete aux;
        return dato;
    }

    // retorna el nodo superior para ver el historial
    Nodo<T>* getTope() const { return tope; }
};

#endif