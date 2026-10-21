#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>

class Paciente {
protected:
    std::string id;
    std::string nombre;
    int edad;
    std::string servicio;

    // se agregan estos atributos
    double temperatura;
    int presionArterial;
    int dolor; // escala 0 a 10
    std::string tipoDolor; // pecho, cabeza, abdomen, extremidad u otro
    int trauma; // 0 o 1
    int sintomasNeurologicos; // 0 o 1  se podria usar un bool igual pero usare int
    int requiereCirugia; // 0 o 1
    int diasHospitalizacion;

public:
    Paciente(std::string id, std::string nombre, int edad, std::string servicio = "");
    virtual ~Paciente();

    std::string getId() const;
    std::string getNombre() const;
    int getEdad() const;
    std::string getServicio() const;
    void setServicio(std::string s);

    void setDatosClinicos(double temp, int presion, int dolor, std::string tDolor, int trauma, int sintomasNeu, int reqCirugia, int diasHosp);

    double getTemperatura() const;
    int getPresionArterial() const;
    int getDolor() const;
    std::string getTipoDolor() const;
    int getTrauma() const;
    int getSintomasNeurologicos() const;
    int getRequiereCirugia() const;
    int getDiasHospitalizacion() const;
};

#endif