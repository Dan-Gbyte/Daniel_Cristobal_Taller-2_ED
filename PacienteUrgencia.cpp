#include "PacienteUrgencia.h"

// inicia los atributos heredados de Paciente y asigna el nivel de urgencia
PacienteUrgencia::PacienteUrgencia(std::string id, std::string nombre, int edad, std::string servicio, int nivelUrgencia)
    : Paciente(id, nombre, edad, servicio), nivelUrgencia(nivelUrgencia) {}

// destructor
PacienteUrgencia::~PacienteUrgencia() {}

// retorna el nivel de urgencia del paciente
int PacienteUrgencia::getNivelUrgencia() const {
    return nivelUrgencia;
}