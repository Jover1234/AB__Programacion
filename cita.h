#ifndef CITA_H
#define CITA_H

#include "paciente.h"
#include "medico.h"
#include <string>
#include <vector>

class Cita {
public:
    Paciente paciente;
    Medico medico;
    std::string fecha;
    std::string hora;
    bool urgente;

    Cita(Paciente paciente, Medico medico, std::string fecha, std::string hora, bool urgente)
        : paciente(paciente), medico(medico), fecha(fecha), hora(hora), urgente(urgente) {
    }
};

class GestionCitas {
public:
    std::vector<Cita> citas;

    void agregarCita(Cita cita) {
        citas.push_back(cita);
    }

    void mostrarCitas() {
        for (const auto& cita : citas) {
            std::cout << "Paciente: " << cita.paciente.nombre << " " << cita.paciente.apellidos << ", Médico: "
                << cita.medico.nombre << " " << cita.medico.apellidos << ", Fecha: " << cita.fecha
                << ", Hora: " << cita.hora << ", Urgente: " << (cita.urgente ? "Sí" : "No") << std::endl;
        }
    }

    void generarReporteCitasPorMedico(std::string dniMedico) {
        std::cout << "Citas del médico con DNI " << dniMedico << ":\n";
        for (const auto& cita : citas) {
            if (cita.medico.DNI == dniMedico) {
                std::cout << "Paciente: " << cita.paciente.nombre << " " << cita.paciente.apellidos << ", Fecha: "
                    << cita.fecha << ", Hora: " << cita.hora << "\n";
            }
        }
    }

    void generarReportePacientesConEnfermedadesCronicas() {
        std::cout << "Pacientes con enfermedades crónicas:\n";
        for (const auto& cita : citas) {
            if (cita.paciente.fechaBaja == "N/A") { // Solo como ejemplo para crónicos
                std::cout << "Paciente: " << cita.paciente.nombre << " " << cita.paciente.apellidos << ", Fecha de Ingreso: "
                    << cita.paciente.FechaIngreso << "\n";
            }
        }
    }
};

#endif // CITA_H

