//
// Created by SuperUsuario on 25-10-2026.
//

#ifndef ARBOL_AVL_H
#define ARBOL_AVL_H

#include "Paciente.h"
#include <string>

struct NodoAVL {
    Paciente* paciente;
    std::string id;       // para ordenar
    int altura;
    NodoAVL* izquierdo;
    NodoAVL* derecho;

    NodoAVL(Paciente* p) : paciente(p), id(p->getId()), altura(1), izquierdo(nullptr), derecho(nullptr) {}
};

class ArbolAVL {
private:
    NodoAVL* raiz;

    int obtenerAltura(NodoAVL* n);
    int obtenerBalance(NodoAVL* n);
    int max(int a, int b);

    // rotaciones
    NodoAVL* rotacionDerecha(NodoAVL* y);
    NodoAVL* rotacionIzquierda(NodoAVL* x);

    NodoAVL* insertarRec(NodoAVL* nodo, Paciente* p);
    NodoAVL* buscarRec(NodoAVL* nodo, std::string id);

    void inordenRec(NodoAVL* nodo);
    void preordenRec(NodoAVL* nodo);
    void postordenRec(NodoAVL* nodo);
    void destruirAVL(NodoAVL* nodo);

public:
    ArbolAVL();
    ~ArbolAVL();

    void insertar(Paciente* p);
    NodoAVL* buscar(std::string id);

    // recorridos de los avl
    void mostrarInorden();
    void mostrarPreorden();
    void mostrarPostorden();

    bool estaVacio();
};

#endif