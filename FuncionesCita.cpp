#ifndef CITAS_H
#define CITAS_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include "paciente.h"  // Incluir el archivo de pacientes
#include "medico.h"    // Incluir el archivo de médicos

using namespace std;

// Clase para almacenar la información de una cita
class Cita {
public:
    Paciente paciente;
    Medico medico;
    string fecha;
    string hora;
    bool urgente;
    bool atendida;

    Cita(Paciente paciente, Medico medico, string fecha, string hora, bool urgente)
        : paciente(paciente), medico(medico), fecha(fecha), hora(hora), urgente(urgente), atendida(false) {
    }

    void marcarAtendida() {
        atendida = true;
    }

    void cancelarCita() {
        atendida = false;
    }
};

// Clase para gestionar las citas médicas y reportes
class GestionCitas {
private:
    vector<Cita> citas;

public:
    void agregarCita(Cita cita);
    void eliminarCita(int index);
    void modificarCita(int index, string nuevaFecha, string nuevaHora, bool urgencia);
    void ordenarCitasPorFecha();
    void ordenarCitasPorUrgencia();
    void imprimirReportePacientes(string fechaInicio, string fechaFin);
    void imprimirReporteCitasPendientes();
    void imprimirReportePacientesConEnfermedadesCronicas();
    void guardarCitasEnArchivo(const string& filename);
    void cargarCitasDesdeArchivo(const string& filename);
};

#endif // CITAS_H
