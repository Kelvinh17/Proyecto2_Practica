#include <iostream>
#include <fstream>

struct Cliente {
    std::string ci;
    std::string client;
    std::string account_number;
    std::string account_type;
};

void registrarCliente(const Cliente& cliente) {
    std::ofstream archivo("Clients.csv", std::ios_base::app);
    archivo << cliente.ci << "," << cliente.client << "," << cliente.account_number << ";" << cliente.account_type << "\n";
    archivo.close();
    std::cout << "Se ha registrado el nuevo cliente: " << cliente.ci << " " << cliente.client << std::endl;
}
