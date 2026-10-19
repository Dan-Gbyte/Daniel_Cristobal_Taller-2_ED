#ifndef PACIENTEURGENCIA_H
#define PACIENTEURGENCIA_H

#include "Paciente.h"

class PacienteUrgencia : public Paciente {
private:
    int nivelUrgencia;

public:
    PacienteUrgencia(std::string id, std::string nombre, int edad, std::string servicio, int nivelUrgencia);
    ~PacienteUrgencia();

    int getNivelUrgencia() const;
};

#endif