cmake_minimum_required(VERSION 3.20)
project(Daniel_Cristobal_Taller_1_ED)

set(CMAKE_CXX_STANDARD 17)

add_executable(T1
        main.cpp
        Paciente.cpp
        SistemaHospital.h
        HospitalImplementado.cpp
        HospitalImplementado.h
        Pila.h
        Nodo.h
        PacienteUrgencia.cpp
        PacienteUrgencia.h
        Servicio.cpp
        Servicio.h
)