#ifndef SISTEMAHOSPITAL_H
#define SISTEMAHOSPITAL_H

#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

class SistemaHospital {
private:
    std::vector<Paciente> pacientes;
    std::vector<Medico> medicos;
    std::vector<Cita> citas;

public:
    void altaPaciente();
    void bajaPaciente();
    void modificarPaciente();
    void buscarPaciente();
    void modificarHistorialClinico();

    void altaMedico();
    void bajaMedico();
    void modificarEspecialidad();
    void cambiarDisponibilidad();
    void listarMedicosPorEspecialidad();
    void listarMedicosPorDisponibilidad();

    void asignarCita();
    void cancelarCita();
    void modificarCita();
    void listarCitasPorFecha();
    void listarCitasPorUrgencia();

    void reportePacientesAtendidos();
    void reporteCitasPendientesMedico();
    void reporteCitasPendientesEspecialidad();
    void reportePacientesEnfermedadesCronicas();

    void guardarDatos(const std::string& archivo);
    void cargarDatos(const std::string& archivo);
    void hacerBackup(const std::string& archivo);
};

#endif // SISTEMAHOSPITAL_H
