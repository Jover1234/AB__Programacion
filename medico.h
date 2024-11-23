#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include <vector>

class Medico {
public:
    std::string nombre;
    std::string apellidos;
    std::string DNI;
    std::string especialidad;
    std::string disponibilidad;

    Medico(std::string nombre, std::string apellidos, std::string DNI, std::string especialidad,
        std::string disponibilidad)
        : nombre(nombre), apellidos(apellidos), DNI(DNI), especialidad(especialidad), disponibilidad(disponibilidad) {
    }
};

void altaMedico();
void mostrarMedicos();

#endif // MEDICO_H

