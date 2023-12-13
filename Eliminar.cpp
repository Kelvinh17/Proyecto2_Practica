#include <iostream>
#include <fstream>
#include <sstream>

struct Cliente {
    std::string ci;
    std::string client;
    std::string account_number;
    std::string account_type;
    std::string cuenta;
};

void eliminarCuenta(const std::string& account_number) {
    std::ifstream archivoEntrada("Clients.csv");
    std::ofstream archivoTemporal("temporal.csv");

    std::string linea;
    while (std::getline(archivoEntrada, linea)) {
        std::istringstream ss(linea);
        std::string ci, client, account_number, account_type, cuenta;
        std::getline(ss, ci, ',');
        std::getline(ss, client, ',');
        std::getline(ss, account_number, ',');
        std::getline(ss, account_type, ',');
        std::getline(ss, cuenta, ',');

        if (cuenta != account_number) {
            archivoTemporal << ci << "," << client << "," << account_number << "," << account_type << cuenta << "\n";
        }
    }

    archivoEntrada.close();
    archivoTemporal.close();

    remove("Clients.csv");
    rename("temporal.csv", "Clients.csv");

    std::cout << "Se ha eliminado la cuenta " << account_number << " del archivo CSV." << std::endl;
}

