# Taller 02 - Estructura de Datos: Clasificación y AVL (Hospital Marmaja)

Universidad Católica del Norte
Asignatura: Estructura de Datos

## Integrantes

**Integrante 1:**
* Nombre: Daniel Gabriel Moreno Moreno
* github: Dan-Gbyte
* RUT: 22.152.252-4
* Carrera: ICCI
* Paralelo: (C1)

**Integrante 2:**
* Nombre: Cristóbal Isaías Espinoza Foix
* github: cristxbai
* RUT: 21.735.612-1
* Carrera: ICCI
* Paralelo: (C1)

## Descripción
Extensión del sistema de gestión de pacientes del hospital Marmaja realizado en el Taller 1 de Estructura de Datos.
hecho en C++.

## Instrucciones de Compilación y Ejecución
1. Abra una terminal en la raíz del proyecto (donde se ubica el `CMakeLists.txt`).
2. Suba el `"pacientes.txt"` a la carpeta raiz.
3. Abra la terminal y compile los archivos ejecutando: 
   cmake -B build
   cmake --build build
4. Desde la terminal, inicie el programa ejecutando:
   ./build/T1

# Esquema del árbol 
¿Edad < 14?
|-- Sí: Pediatria
|-- No:
     |-- ¿SintomasNeurologicos == 1?
     |-- Sí: Neurologia
     |-- No:
          |-- ¿TipoDolor == pecho?
          |-- Sí: Cardiologia
          |-- No:
               |-- ¿Trauma == 1?
               |-- Sí:
                    |-- ¿RequiereCirugia == 1?
                    |-- Sí: Cirugia
                    |-- No: Traumatologia
               |-- No:
                    |-- ¿Temperatura > 39.5? *(o Presión > 180)*
                    |-- Sí: Urgencias
                    |-- No:
                         |-- ¿DiasHospitalizacion > 3?
                         |-- Sí: Hospitalizacion
                         |-- No: Medicina General

### Por qué lo armamos así el árbol
- La idea era filtrar primero lo más urgente y específico:
1. Primero sacamos a los niños (`Pediatria`).
2. Vemos temas neurológicos (`Neurologia`) y dolores al pecho (`Cardiologia`) que son críticos.
3. Despachamos los casos de golpes o accidentes (`Trauma` -> `Cirugia` o `Traumatologia`).
4. Revisamos si hay fiebre alta o presión extrema (`Urgencias`) o si llevan más de 3 días hospitalizados, dejando al resto en `Medicina General`.
5. Básicamente filtramos los que no son tan urgentes y dejamos a los urgentes como prioridad.
