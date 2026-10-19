#ifndef HOSPITALIMPLEMENTADO_H
#define HOSPITALIMPLEMENTADO_H

#include "SistemaHospital.h"
#include "Cola.h"
#include "Pila.h"
#include "Servicio.h"

// heresa e implementa SistemaHospital
class HospitalImplementado : public SistemaHospital {
private:
    Cola<Paciente*> colaEspera;          // Cola FIFO
    Pila<Paciente*> historialAtenciones; // Pila LIFO para el historial
    Servicio* listaServicios;           // linked list con los deptos

    void inicializarServicios();
    Servicio* buscarServicio(const std::string& nombre);

public:
    HospitalImplementado();
    ~HospitalImplementado() override;

    // metodos heredados de la interfaz pura SistemaHospital
    bool leerPacientes() override;
    std::string listarPacientesEspera() override;
    std::string atenderPacientes(int cantidad) override;
    std::string listarDepartamentos() override;
    std::string verDepartamento(int id) override;
    std::string verHistorial() override;
};

#endif