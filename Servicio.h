#ifndef SERVICIO_H
#define SERVICIO_H

#include <string>
#include "Paciente.h"
#include "Nodo.h"

// clase que representa un departamento del hospital
class Servicio {
private:
    std::string nombreServicio;       // nombre del depto
    Nodo<Paciente*>* listaPacientes;  // sublista enlazada con los pacientes asignados al servicio
    Servicio* siguienteServicio;      // puntero al siguiente departamento de la lista

public:
    // Constructor y Destructor
    Servicio(std::string nombre);
    ~Servicio();

    // Getters y Setters
    std::string getNombre() const;
    Servicio* getSiguiente() const;
    void setSiguiente(Servicio* sig);

    // métodos para la gestión interna de pacientes
    void agregarPaciente(Paciente* p);
    int getCantidadPacientes() const;
    std::string obtenerTextoPacientes() const;
};

#endif