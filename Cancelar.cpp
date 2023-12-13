#include <iostream>
#include <fstream>
#include "Todo.h"

using namespace std;

struct Transaccion {
    std::string origen;
    std::string destino;
    double monto;
};

void cancelarTransferencia(const Transaccion& transaccion) {

    std::cout << "Se ha cancelado una transferencia de " << transaccion.monto << " desde " << transaccion.origen
              << " a " << transaccion.destino << std::endl;

    std::ofstream archivo("Clients.csv", std::ios_base::app);
    archivo << transaccion.origen << "," << transaccion.destino << "," << transaccion.monto << " (CANCELADA)\n";  
    archivo.close();
}
