#ifndef COLA_H
#define COLA_H

#include "Nodo.h"

// clase plantilla (template) para la estructura de datos Cola (FIFO: el primero en entrar es el primero en salir)
template <typename T>
class Cola {
private:
    Nodo<T>* frente; // apunta al primer elemento que ingresa
    Nodo<T>* fin;    // apunta al último elemento ingresado

public:
    // inicializa la cola vacía
    Cola() : frente(nullptr), fin(nullptr) {}

    // vacía la cola liberando los nodos de la memoria dinámica / destructor
    ~Cola() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    // retorna true si la cola no tiene elementos
    bool estaVacia() const { return frente == nullptr; }

    // agrega un nuevo elemento al final de la cola
    void encolar(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (estaVacia()) {
            frente = nuevo;
            fin = nuevo;
        } else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
    }

    T desencolar() {
        if (estaVacia()) return nullptr;
        Nodo<T>* aux = frente;
        T dato = aux->dato;
        frente = frente->siguiente;
        if (frente == nullptr) fin = nullptr;
        delete aux;
        return dato;
    }

    Nodo<T>* getFrente() const { return frente; }

    // Mostrar los pacientes en espera por consola
    /*void Cola::mostrar() const {
        if (estaVacia()) {
            std::cout << "No hay pacientes en espera." << std::endl;
            return;
        }

        NodoPaciente* actual = frente;
        int i = 1;
        while (actual != nullptr) {
            std::cout << i << ". " << actual->paciente->getId() << " "
                      << actual->paciente->getNombre() << std::endl;
            actual = actual->siguiente;
            i++;
        }
    }
    */
};

#endif