#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>

class Paciente {
protected:
    std::string id;
    std::string nombre;
    int edad;
    std::string servicio;

public:
    Paciente(std::string id, std::string nombre, int edad, std::string servicio);
    virtual ~Paciente();

    std::string getId() const;
    std::string getNombre() const;
    int getEdad() const;
    std::string getServicio() const;
};

#endif