//
// Created by SuperUsuario on 25-10-2026.
//

#include "ArbolAVL.h"
#include <iostream>

ArbolAVL::ArbolAVL() : raiz(nullptr) {}

ArbolAVL::~ArbolAVL() {
    destruirAVL(raiz);
}

void ArbolAVL::destruirAVL(NodoAVL* nodo) {
    if (nodo != nullptr) {
        destruirAVL(nodo->izquierdo);
        destruirAVL(nodo->derecho);
        delete nodo->paciente;
        delete nodo;
    }
}

int ArbolAVL::obtenerAltura(NodoAVL* n) {
    return (n == nullptr) ? 0 : n->altura;
}

int ArbolAVL::max(int a, int b) {
    return (a > b) ? a : b;
}

int ArbolAVL::obtenerBalance(NodoAVL* n) {
    if (n == nullptr) return 0;
    return obtenerAltura(n->izquierdo) - obtenerAltura(n->derecho);
}

// rotacion a la derecha
NodoAVL* ArbolAVL::rotacionDerecha(NodoAVL* y) {
    NodoAVL* x = y->izquierdo;
    NodoAVL* T2 = x->derecho;

    x->derecho = y;
    y->izquierdo = T2;

    y->altura = max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;
    x->altura = max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;

    return x;
}

// rotacion a la izq
NodoAVL* ArbolAVL::rotacionIzquierda(NodoAVL* x) {
    NodoAVL* y = x->derecho;
    NodoAVL* T2 = y->izquierdo;

    y->izquierdo = x;
    x->derecho = T2;

    x->altura = max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;
    y->altura = max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;

    return y;
}

// insercion con balance
NodoAVL* ArbolAVL::insertarRec(NodoAVL* nodo, Paciente* p) {
    std::string id = p->getId();

    if (nodo == nullptr) return new NodoAVL(p);

    if (id < nodo->id)
        nodo->izquierdo = insertarRec(nodo->izquierdo, p);
    else if (id > nodo->id)
        nodo->derecho = insertarRec(nodo->derecho, p);
    else
        return nodo; // para los id duplicados

    nodo->altura = 1 + max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));

    int balance = obtenerBalance(nodo);

    // izq - izq
    if (balance > 1 && id < nodo->izquierdo->id)
        return rotacionDerecha(nodo);

    // der - der
    if (balance < -1 && id > nodo->derecho->id)
        return rotacionIzquierda(nodo);

    // izq - der
    if (balance > 1 && id > nodo->izquierdo->id) {
        nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
        return rotacionDerecha(nodo);
    }

    // der - izq
    if (balance < -1 && id < nodo->derecho->id) {
        nodo->derecho = rotacionDerecha(nodo->derecho);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

void ArbolAVL::insertar(Paciente* p) {
    raiz = insertarRec(raiz, p);
}

NodoAVL* ArbolAVL::buscarRec(NodoAVL* nodo, std::string id) {
    if (nodo == nullptr || nodo->id == id)
        return nodo;

    if (nodo->id > id)
        return buscarRec(nodo->izquierdo, id);

    return buscarRec(nodo->derecho, id);
}

NodoAVL* ArbolAVL::buscar(std::string id) {
    return buscarRec(raiz, id);
}

void ArbolAVL::inordenRec(NodoAVL* nodo) {
    if (nodo != nullptr) {
        inordenRec(nodo->izquierdo);
        std::cout << "ID: " << nodo->id << " | Nombre: " << nodo->paciente->getNombre() << std::endl;
        inordenRec(nodo->derecho);
    }
}

void ArbolAVL::mostrarInorden() {
    inordenRec(raiz);
}

void ArbolAVL::preordenRec(NodoAVL* nodo) {
    if (nodo != nullptr) {
        std::cout << "ID: " << nodo->id << " | Nombre: " << nodo->paciente->getNombre() << std::endl;
        preordenRec(nodo->izquierdo);
        preordenRec(nodo->derecho);
    }
}

void ArbolAVL::mostrarPreorden() {
    preordenRec(raiz);
}

void ArbolAVL::postordenRec(NodoAVL* nodo) {
    if (nodo != nullptr) {
        postordenRec(nodo->izquierdo);
        postordenRec(nodo->derecho);
        std::cout << "ID: " << nodo->id << " | Nombre: " << nodo->paciente->getNombre() << std::endl;
    }
}

void ArbolAVL::mostrarPostorden() {
    postordenRec(raiz);
}

bool ArbolAVL::estaVacio() {
    return raiz == nullptr;
}