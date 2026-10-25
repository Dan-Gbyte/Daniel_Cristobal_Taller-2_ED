//
// Created by SuperUsuario on 25-10-2026.
//

#include "ArbolDecision.h"
#include <iostream> 

ArbolDecision::ArbolDecision() {

    // Raiz - vemos si es menor q 14 años
    raiz = new NodoDecision("Edad < 14", false);

    // Si es menor de 14 pasa a pediatria (hoja del arbol)
    raiz->izquierdo = new NodoDecision("Pediatria", true);

    // Si no es menor de 14 evaluamos si tiene sintomas neurologicos graves
    raiz->derecho = new NodoDecision("SintomasNeurologicos == 1", false);

    // Si tiene síntomas neurológicos -> Neurología
    raiz->derecho->izquierdo = new NodoDecision("Neurologia", true);

    // Si no evaluamos si el tipo de dolor es en el pecho (Cardiología)
    raiz->derecho->derecho = new NodoDecision("TipoDolor == pecho", false);
    raiz->derecho->derecho->izquierdo = new NodoDecision("Cardiologia", true);

    // Si no es pecho evaluamos si hay trauma
    raiz->derecho->derecho->derecho = new NodoDecision("Trauma == 1", false);

    // Si hay trauma, vemos si requiere cirugia
    raiz->derecho->derecho->derecho->izquierdo = new NodoDecision("RequiereCirugia == 1", false);
    raiz->derecho->derecho->derecho->izquierdo->izquierdo = new NodoDecision("Cirugia", true);
    raiz->derecho->derecho->derecho->izquierdo->derecho = new NodoDecision("Traumatologia", true);

    // Si no hay trauma evaluamos temperatura o presion extrema (para urgencias)
    raiz->derecho->derecho->derecho->derecho = new NodoDecision("Temperatura > 39.5", false);
    raiz->derecho->derecho->derecho->derecho->izquierdo = new NodoDecision("Urgencias", true);

    // Si la temperatura es normal evaluamos si requiere hospitalización prolongada
    raiz->derecho->derecho->derecho->derecho->derecho = new NodoDecision("DiasHospitalizacion > 3", false);
    raiz->derecho->derecho->derecho->derecho->derecho->izquierdo = new NodoDecision("Hospitalizacion", true);

    // Si nada de lo anterior aplica o no corresponde se pasa a -> Medicina General
    raiz->derecho->derecho->derecho->derecho->derecho->derecho = new NodoDecision("Medicina General", true);
}

ArbolDecision::~ArbolDecision() {
    destruirArbol(raiz);
}

void ArbolDecision::destruirArbol(NodoDecision* nodo) {
    if (nodo != nullptr) {
        destruirArbol(nodo->izquierdo);
        destruirArbol(nodo->derecho);
        delete nodo;
    }
}

std::string ArbolDecision::evaluarPaciente(Paciente* p) {
    NodoDecision* actual = raiz;

    // recorrido del arbol por las ramas
    while (actual != nullptr && !actual->esServicio) {
        if (actual->preguntaOrServicio == "Edad < 14") {
            if (p->getEdad() < 14) actual = actual->izquierdo;
            else actual = actual->derecho;
        }
        else if (actual->preguntaOrServicio == "SintomasNeurologicos == 1") {
            if (p->getSintomasNeurologicos() == 1) actual = actual->izquierdo;
            else actual = actual->derecho;
        }
        else if (actual->preguntaOrServicio == "TipoDolor == pecho") {
            if (p->getTipoDolor() == "pecho") actual = actual->izquierdo;
            else actual = actual->derecho;
        }
        else if (actual->preguntaOrServicio == "Trauma == 1") {
            if (p->getTrauma() == 1) actual = actual->izquierdo;
            else actual = actual->derecho;
        }
        else if (actual->preguntaOrServicio == "RequiereCirugia == 1") {
            if (p->getRequiereCirugia() == 1) actual = actual->izquierdo;
            else actual = actual->derecho;
        }
        else if (actual->preguntaOrServicio == "Temperatura > 39.5") {
            if (p->getTemperatura() > 39.5 || p->getPresionArterial() > 180) actual = actual->izquierdo;
            else actual = actual->derecho;
        }
        else if (actual->preguntaOrServicio == "DiasHospitalizacion > 3") {
            if (p->getDiasHospitalizacion() > 3) actual = actual->izquierdo;
            else actual = actual->derecho; // si no se cumple va al ultimo nodo q es medicina gen
        }
        else {
            // control de errores mini
            break;
        }
    }

    if (actual != nullptr && actual->esServicio) {
        return actual->preguntaOrServicio;
    }

    return "Medicina General"; // valor x defecto
}

//recorridos ---

// preorden
void ArbolDecision::preorden(NodoDecision* nodo) {
    if (nodo == nullptr) return;
    std::cout << "- " << nodo->preguntaOrServicio << (nodo->esServicio ? " [Servicio Final]" : " [Pregunta]") << std::endl;
    preorden(nodo->izquierdo);
    preorden(nodo->derecho);
}

// inorden
void ArbolDecision::inorden(NodoDecision* nodo) {
    if (nodo == nullptr) return;
    inorden(nodo->izquierdo);
    std::cout << "- " << nodo->preguntaOrServicio << (nodo->esServicio ? " [Servicio Final]" : " [Pregunta]") << std::endl;
    inorden(nodo->derecho);
}

// postorden
void ArbolDecision::postorden(NodoDecision* nodo) {
    if (nodo == nullptr) return;
    postorden(nodo->izquierdo);
    postorden(nodo->derecho);
    std::cout << "- " << nodo->preguntaOrServicio << (nodo->esServicio ? " [Servicio Final]" : " [Pregunta]") << std::endl;
}