#include <iostream>
#include <fstream>

struct Transaccion {
    std::string origen;
    std::string destino;
    double monto;
};

void realizarDeposito(const Transaccion& transaccion) {
    // L�gica para realizar el dep�sito
    std::cout << "Se ha realizado un dep�sito de " << transaccion.monto << " desde " << transaccion.origen
              << " a " << transaccion.destino << std::endl;

    std::ofstream archivo("Clients.csv", std::ios_base::app);
    archivo << transaccion.origen << "," << transaccion.destino << "," << transaccion.monto << "\n";
    archivo.close();
}
