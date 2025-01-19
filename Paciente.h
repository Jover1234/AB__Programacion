#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <vector>

class Paciente {
public:
    std::string nombre;
    std::string apellidos;
    std::string dni;
    std::string fechaIngreso;
    std::string fechaBaja;
    std::vector<std::string> historialClinico;
    bool tieneEnfermedadCronica;
    std::string enfermedadCronica;

    Paciente(std::string n, std::string a, std::string d);
};

#endif // PACIENTE_H
