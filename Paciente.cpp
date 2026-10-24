#include "Paciente.h"

Paciente::Paciente(std::string id, std::string nombre, int edad, std::string servicio)
    : id(id), nombre(nombre), edad(edad), servicio(servicio),
      temperatura(0.0), presionArterial(0), dolor(0), tipoDolor(""),
      trauma(0), sintomasNeurologicos(0), requiereCirugia(0), diasHospitalizacion(0) {}

Paciente::~Paciente() {}

std::string Paciente::getId() const { return id; }
std::string Paciente::getNombre() const { return nombre; }
int Paciente::getEdad() const { return edad; }
std::string Paciente::getServicio() const { return servicio; }
void Paciente::setServicio(std::string s) { servicio = s; }

void Paciente::setDatosClinicos(double temp, int presion, int dolor, std::string tDolor,   // agregamos lo de los pacientes
                                int trauma, int sintomasNeu, int reqCirugia, int diasHosp) {
    temperatura = temp;
    presionArterial = presion;
    this->dolor = dolor;
    tipoDolor = tDolor;
    this->trauma = trauma;
    sintomasNeurologicos = sintomasNeu;
    requiereCirugia = reqCirugia;
    diasHospitalizacion = diasHosp;
}

double Paciente::getTemperatura() const { return temperatura; }
int Paciente::getPresionArterial() const { return presionArterial; }
int Paciente::getDolor() const { return dolor; }
std::string Paciente::getTipoDolor() const { return tipoDolor; }
int Paciente::getTrauma() const { return trauma; }
int Paciente::getSintomasNeurologicos() const { return sintomasNeurologicos; }
int Paciente::getRequiereCirugia() const { return requiereCirugia; }
int Paciente::getDiasHospitalizacion() const { return diasHospitalizacion; }