#ifndef MEDICO_H
#define MEDICO_H

#include <string>

class Medico {
public:
    std::string nombre;
    std::string apellidos;
    std::string dni;
    std::string especialidad;
    bool disponible;

    Medico(std::string n, std::string a, std::string d, std::string e);
};

#endif // MEDICO_H
