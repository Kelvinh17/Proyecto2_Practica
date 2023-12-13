#include <iostream>
#include <fstream>

struct Suspension {
    std::string cuenta;
    std::string motivo;
};

void suspenderCuenta(const Suspension& suspension) {

    std::cout << "Se ha suspendido la cuenta " << suspension.cuenta << " por el motivo: " << suspension.motivo << std::endl;

    std::ofstream archivo("Clients.csv", std::ios_base::app);
    archivo << suspension.cuenta << "," << suspension.motivo << "\n";
    archivo.close();
}
