//
// Created by SuperUsuario on 25-10-2026.
//

#ifndef ARBOL_DECISION_H
#define ARBOL_DECISION_H

#include "Paciente.h"
#include <string>

struct NodoDecision {
    std::string preguntaOrServicio; // Si es hoja, tiene el nombre del servicio
    bool esServicio;                // true si es una hoja, pero seria false si es una pregunta
    NodoDecision* izquierdo;       // Rama si se cumple / menor / opción A
    NodoDecision* derecho;          // Rama si no se cumple / mayor / opción B

    NodoDecision(std::string valor, bool hoja)
        : preguntaOrServicio(valor), esServicio(hoja), izquierdo(nullptr), derecho(nullptr) {}
};

class ArbolDecision {
private:
    NodoDecision* raiz;

    // para destruir el arbol recursivamente basicamente un destructor
    void destruirArbol(NodoDecision* nodo);

public:
    ArbolDecision();
    ~ArbolDecision();

    // para evaluar el paciente
    std::string evaluarPaciente(Paciente* p);

    // aca los recorridos
    void preorden(NodoDecision* nodo);
    void inorden(NodoDecision* nodo);
    void postorden(NodoDecision* nodo);
    NodoDecision* getRaiz() { return raiz; }
};

#endif
