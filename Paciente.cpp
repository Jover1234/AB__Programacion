#include "Paciente.h"
#include <ctime>


Paciente::Paciente(std::string n, std::string a, std::string d) : nombre(n), apellidos(a), dni(d) {
    time_t now = time(0);
    fechaIngreso = ctime(&now);
}
