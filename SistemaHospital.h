//
// Created by danux on 17-09-2026.
//

#pragma once
#include <string>

// puse los metodos de menú porque en el sistema se supone que no podemos pedir entradas ni printear nada
class SistemaHospital {
public:
    virtual ~SistemaHospital() {}

    // para leer el txt, el bool es por si acaso pero no creo que lo usemos.
    virtual bool leerPacientes() = 0;

    // printea los pacientes en espera, es para el menú
    virtual std::string listarPacientesEspera() = 0;
    // atiende un numero x de pacientes, la funcion principal
    virtual std::string atenderPacientes(int cantidad) = 0;

    // printea los departamentos, para el menú
    virtual std::string listarDepartamentos() = 0;
    // te da la informacion del departamento específico, la funcion principal
    virtual std::string verDepartamento(int id) = 0;

    // esta funcion solo requiere un metodo 
    virtual std::string verHistorial() = 0;
};