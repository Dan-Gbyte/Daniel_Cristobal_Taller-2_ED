#include <iostream>
#include "SistemaHospital.h"
#include "HospitalImplementado.h"

using namespace std;

int main() {
    SistemaHospital* sistema = new HospitalImplementado();

    // cargar pacientes desde el archivo al iniciar
    bool inicio = sistema->leerPacientes();

    if (!inicio) {
        cout << "No se pudo leer pacientes.txt\nfinalizando programa...";
        delete sistema;
        return 1;
    }

    int opcion = 0;

    while (opcion != 4) {
        cout << "=== HOSPITAL MARMAJA ===\n";
        cout << "1. Atender pacientes\n";
        cout << "2. Ver departamento\n";
        cout << "3. Revisar historial de atención\n";
        cout << "4. Salir\n\n";
        cout << "Seleccionar opción: ";
        cin >> opcion;
        cout << "\n";

        if (opcion == 1) {
            // muestra los pacientes en cola
            cout << sistema->listarPacientesEspera();

            int cantidad = 0;
            cout << "Indique la cantidad de pacientes a atender: ";
            cin >> cantidad;
            cout << "\n";

            if (cantidad > 0) {
                cout << sistema->atenderPacientes(cantidad);
            }
        }
        else if (opcion == 2) {
            // muestra la lista numerada de departamentos
            cout << sistema->listarDepartamentos();

            int idDep = 0;
            cout << "\n Seleccionar opción: ";
            cin >> idDep;
            cout << "\n";

            if (idDep >= 1 && idDep <= 8) {
                cout << sistema->verDepartamento(idDep);
            }
        }
        else if (opcion == 3) {
            cout << sistema->verHistorial();
        }
        else if (opcion == 4) {
            cout << "Hasta luego :D.\n";
        }
        else {
            cout << "Opción no válida.\n\n";
        }
    }

    delete sistema;
    return 0;
}