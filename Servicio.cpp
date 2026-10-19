#include "Servicio.h"
#include <sstream>

// constructor: configura el nombre e inicializa los punteros en el nullptr
Servicio::Servicio(std::string nombre)
    : nombreServicio(nombre), listaPacientes(nullptr), siguienteServicio(nullptr) {}

// recorre la sub-lista enlazada liberando tanto los objetos "Paciente" como los Nodos / destructor
Servicio::~Servicio() {
    Nodo<Paciente*>* actual = listaPacientes;
    while (actual != nullptr) {
        Nodo<Paciente*>* aux = actual;
        actual = actual->siguiente;
        //delete aux->dato; // libera el objeto Paciente dinámico -> HospitalImplementado lo hace y esto intenta hacerlo 2 veces
        delete aux;       // libera el nodo de la lista
    }
}

std::string Servicio::getNombre() const { return nombreServicio; }
Servicio* Servicio::getSiguiente() const { return siguienteServicio; }
void Servicio::setSiguiente(Servicio* sig) { siguienteServicio = sig; }

// agrega un paciente al final de la sublista del depto

void Servicio::agregarPaciente(Paciente* p) {
    Nodo<Paciente*>* nuevo = new Nodo<Paciente*>(p);
    if (listaPacientes == nullptr) {
        listaPacientes = nuevo;
    } else {
        Nodo<Paciente*>* aux = listaPacientes;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

// para contar la cant de pacientes del depto
int Servicio::getCantidadPacientes() const {
    int cont = 0;
    Nodo<Paciente*>* aux = listaPacientes;
    while (aux != nullptr) {
        cont++;
        aux = aux->siguiente;
    }
    return cont;
}

std::string Servicio::obtenerTextoPacientes() const {
    if (listaPacientes == nullptr) {
        return "No hay pacientes en este servicio.\n";
    }
    std::string resultado = "";
    Nodo<Paciente*>* aux = listaPacientes;
    while (aux != nullptr) {
        resultado += aux->dato->getNombre() + " (" + std::to_string(aux->dato->getEdad()) + " anos)\n";
        aux = aux->siguiente;
    }
    return resultado;
}