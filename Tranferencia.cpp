#include <iostream>
#include <fstream>

struct Transaccion {
    std::string origen;
    std::string destino;
    double monto;
};

void realizarTransferencia(const Transaccion& transaccion) {

    std::cout << "Se ha realizado una transferencia de " << transaccion.monto << " desde " << transaccion.origen
              << " a " << transaccion.destino << std::endl;

    std::ofstream archivo("Clients.csv", std::ios_base::app);
    archivo << transaccion.origen << "," << transaccion.destino << "," << (-transaccion.monto) << "\n"; 
    archivo.close();
}

