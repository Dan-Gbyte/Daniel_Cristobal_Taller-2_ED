#include "Paciente.h"

Paciente::Paciente(std::string id, std::string nombre, int edad, std::string servicio)
    : id(id), nombre(nombre), edad(edad), servicio(servicio) {}

Paciente::~Paciente() {}

std::string Paciente::getId() const { return id; }
std::string Paciente::getNombre() const { return nombre; }
int Paciente::getEdad() const { return edad; }
std::string Paciente::getServicio() const { return servicio; }