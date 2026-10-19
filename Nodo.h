#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
public:
    T dato;               // guarda la información seria cm el puntero
    Nodo<T>* siguiente;   // puntero al siguiente nodo de la estructura

    // recibe el dato y deja el puntero siguiente en nulo
    Nodo(T dato) : dato(dato), siguiente(nullptr) {}
};

#endif