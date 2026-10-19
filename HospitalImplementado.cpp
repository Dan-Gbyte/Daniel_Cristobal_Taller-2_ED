//
// Created by danux on 17-09-2026.
//

#include "HospitalImplementado.h"
#include "PacienteUrgencia.h"
#include <fstream>
#include <iostream>

using namespace std;

HospitalImplementado::HospitalImplementado() : listaServicios(nullptr) {
    inicializarServicios();
}

//destructor para usar menos memoria
HospitalImplementado::~HospitalImplementado() {
    // libera memoria dinam de la cola
    while (!colaEspera.estaVacia()) {
        delete colaEspera.desencolar();
    }
    // libera memoria dinam del historial
    while (!historialAtenciones.estaVacia()) {
        delete historialAtenciones.desapilar();
    }
    // libera la linked list de los servicios
    Servicio* actual = listaServicios;
    while (actual != nullptr) {
        Servicio* aux = actual;
        actual = actual->getSiguiente();
        delete aux;
    }
}

// crea e inserta los 8 servicios solicitados
void HospitalImplementado::inicializarServicios() {
    string nombres[] = {
        "Urgencias", "Medicina General", "Cardiologia", "Neurologia",
        "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"
    };

    Servicio* ultimo = nullptr;
    for (int i = 0; i < 8; i++) {
        Servicio* nuevo = new Servicio(nombres[i]);
        if (listaServicios == nullptr) {
            listaServicios = nuevo;
        } else {
            ultimo->setSiguiente(nuevo);
        }
        ultimo = nuevo;
    }
}

// recorre la lista para buscar algo especifico
Servicio* HospitalImplementado::buscarServicio(const string& nombre) {
    Servicio* aux = listaServicios;
    while (aux != nullptr) {
        if (aux->getNombre() == nombre) return aux;
        aux = aux->getSiguiente();
    }
    return nullptr;
}

// para leer el txt con un bool (lo k hiciste tu dani)
bool HospitalImplementado::leerPacientes() {
    ifstream archivo("pacientes.txt");
    if (!archivo.is_open()) return false;

    char linea[200];
    while (archivo.getline(linea, 200)) {
        if (linea[0] == '\0') continue;

        char id[50], nombre[50], servicio[50];
        int edad = 0;

        // para recorrer el arreglo con caracteres con el char* p
        char* p = linea;
        int campo = 0, idx = 0;
        bool pacienteValido = true;


        while (*p != '\0' && *p != '\r' && *p != '\n') {
            if (*p == ';') {

                if (idx == 0) {
                    pacienteValido = false;
                    break;
                }

                if (campo == 0) id[idx] = '\0';
                else if (campo == 1) nombre[idx] = '\0';
                else if (campo == 2) {
                    edad = 0;
                    for (int i = 0; i < idx; i++) {
                        char c = linea[p - linea - idx + i];
                        if (c >= '0' && c <= '9') {
                            edad = edad * 10 + (c - '0');
                        } else {
                            pacienteValido = false;
                            break;
                        }
                    }
                }
                campo++;
                idx = 0;
            } else {
                if (idx != 0 || *p != ' ') {
                    if (campo == 0) id[idx++] = *p;
                    else if (campo == 1) nombre[idx++] = *p;
                    else if (campo == 2) idx++;
                    else if (campo == 3) servicio[idx++] = *p;
                }
            }
            if (!pacienteValido) {
                break;
            }
            p++; // avanza la dirección de memoria del puntero
        }

        if (idx == 0 || campo != 3) {
            pacienteValido = false;
        }

        servicio[idx] = '\0';

        if (pacienteValido) {
            string sServicio = servicio;
            if (sServicio != "Urgencias" && sServicio != "Medicina General" &&
                sServicio != "Cardiologia" && sServicio != "Neurologia" &&
                sServicio != "Traumatologia" && sServicio != "Cirugia" &&
                sServicio != "Pediatria" && sServicio != "Hospitalizacion") {
                pacienteValido = false;
            }

        }

        // insercion de la cola fifo
        if (pacienteValido) {
            Paciente* paciente = nullptr;
            string sServicio = servicio;

            if (sServicio == "Urgencias") {
                paciente = new PacienteUrgencia(id, nombre, edad, sServicio, 1);
            } else {
                paciente = new Paciente(id, nombre, edad, sServicio);
            }
            colaEspera.encolar(paciente);
        }
    }
    archivo.close();
    return true;
}

// printea los pacientes en espera, es para el menú
string HospitalImplementado::listarPacientesEspera() {
    string salida = "=== PACIENTES EN ESPERA ===\n";

    Nodo<Paciente*>* aux = colaEspera.getFrente();
    if (aux == nullptr) {
        salida += "No hay pacientes pendientes.\n";
        return salida;
    }

    int i = 1;
    while (aux != nullptr) {
        salida += to_string(i) + ". " + aux->dato->getId() + " " + aux->dato->getNombre() + "\n";
        aux = aux->siguiente;
        i++;
    }
    return salida;
}

// atiende un numero x de pacientes, la funcion principal
string HospitalImplementado::atenderPacientes(int cantidad) {
    string salida = "=== ATENDIENDO PACIENTES ===\n";

    for (int i = 0; i < cantidad; i++) {
        if (colaEspera.estaVacia()) {
            salida += "No quedan mas pacientes en la cola.\n";
            break;
        }

        // desencola el paciente (FIFO)
        Paciente* p = colaEspera.desencolar();
        salida += "ID: " + p->getId() + "\n";
        salida += "Nombre: " + p->getNombre() + "\n";
        salida += "Edad: " + to_string(p->getEdad()) + "\n";
        salida += "Servicio: " + p->getServicio() + "\n";

        // asigna al paciente a su depto
        Servicio* s = buscarServicio(p->getServicio());
        if (s != nullptr) {
            s->agregarPaciente(p);
            salida += "Paciente enviado a " + p->getServicio() + ".\n";
        } else {
            salida += "Paciente enviado a Medicina General.\n";
            Servicio* gen = buscarServicio("Medicina General");
            if (gen) gen->agregarPaciente(p);
        }

        // apila el paciente a la lista de atenciones (LIFO)
        historialAtenciones.apilar(p);
        salida += "-----------------------------\n";
    }
    return salida;
}

// printea los departamentos, para el menú
string HospitalImplementado::listarDepartamentos() {
    string salida = "=== DEPARTAMENTOS/SERVICIOS ===\n";

    Servicio* aux = listaServicios;
    int i = 1;
    while (aux != nullptr) {
        salida += to_string(i) + ". " + aux->getNombre() + "\n";
        aux = aux->getSiguiente();
        i++;
    }
    return salida;
}

// te da la informacion del departamento específico, la funcion principal
string HospitalImplementado::verDepartamento(int id) {
    string salida = "";
    Servicio* aux = listaServicios;
    int i = 1;

    // avanza en la lista hasta la posicion del departamento indicado por el id (de 1 hasta el 8)
    while (aux != nullptr && i < id) {
        aux = aux->getSiguiente();
        i++;
    }

    if (aux != nullptr) {
        salida += "=== ESTADO " + aux->getNombre() + " ===\n";
        salida += "Pacientes en el departamento de " + aux->getNombre() + ": "
               + to_string(aux->getCantidadPacientes()) + "\n";
        salida += aux->obtenerTextoPacientes();
    } else {
        salida += "Opcion invalida.\n";
    }
    return salida;
}

// esta fucnion solo requiere un metodo
string HospitalImplementado::verHistorial() {
    string salida = "=== HISTORIAL DE ULTIMAS ATENCIONES DEL HOSPITAL ===\n";

    // recorre la Pila desde el Top
    Nodo<Paciente*>* aux = historialAtenciones.getTope();
    if (aux == nullptr) {
        salida += "No hay atenciones en el historial.\n";
        return salida;
    }

    while (aux != nullptr) {
        salida += "Nombre: " + aux->dato->getNombre()
               + " | Edad: " + to_string(aux->dato->getEdad())
               + " | Departamento: " + aux->dato->getServicio() + "\n";
        salida += "--\n";
        aux = aux->siguiente;
    }
    return salida;
}