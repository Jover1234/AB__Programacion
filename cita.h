#ifndef CITA_H
#define CITA_H

#include <string>

class Cita {
public:
    std::string dniPaciente;
    std::string dniMedico;
    std::string fecha;
    bool urgente;

    Cita(std::string p, std::string m, std::string f, bool u);
};

#endif // CITA_H
