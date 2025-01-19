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
    void mostrarPacientes();
    void buscarPacienteDNI();
    void buscarPacienteNombre();
    void buscarPacienteFechaIngreso();
    void bajaPaciente();
    void altaMedico();
    void mostrarMedicos();
    void buscarMedicoDNI();
    void bajaMedico();
    void modificarMedico();
};
#endif // SISTEMAHOSPITAL_h