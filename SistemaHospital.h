#ifndef SISTEMAHOSPITAL_H
#define SISTEMAHOSPITAL_H

#include "Paciente.h"
#include "Medico.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

class SistemaHospital {
private:
    std::vector<Paciente> pacientes;
    std::vector<Medico> medicos;

public:
    void altaPaciente();
    void bajaPaciente();
    void modificarPaciente();
    void buscarPaciente();
    void altaMedico();
    void bajaMedico();
    void guardarDatos(const std::string& archivo);
    void cargarDatos(const std::string& archivo);
    void hacerBackup(const std::string& archivo);



};
#endif // SISTEMAHOSPITAL_h