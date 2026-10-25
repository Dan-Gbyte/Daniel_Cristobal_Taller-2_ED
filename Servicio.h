#ifndef SERVICIO_H
#define SERVICIO_H

#include <string>
#include "Paciente.h"
#include "Nodo.h"
#include "ArbolAVL.h"

// clase que representa un departamento del hospital
class Servicio {
private:
    std::string nombreServicio;       // nombre del depto
    ArbolAVL arbolPacientes;
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
    int getCantidadPacientes();
    std::string obtenerTextoPacientes();
};

#endif