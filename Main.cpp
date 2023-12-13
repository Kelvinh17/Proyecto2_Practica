#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Todo.h"

using namespace std;

struct Clients {
    string ci;
    string client;
    string account_number;
    string account_type;
    string suspend;
};

void printClientInfo(const Clients& client) {
    cout<<"CI: "<<client.ci<<"\n";
	cout<<"Cliente: "<<client.client<<"\n"; 
    cout<<"Numero de cuenta: "<<client.account_number<<"\n";
    cout<< "Tipo de cuenta: "<<client.account_type<<"\n"; 
    cout<<"Suspendido: "<<client.suspend << "\n";
}

void realizarDeposito(Clients* clients, int numClients, const string& accountNumber, double amount) {
    for (int i = 0; i < numClients; i++) {
        if (clients[i].account_number == accountNumber) {
            cout << "Depósito realizado con éxito para el cliente: " << clients[i].client << endl;
            return;
        }
    }
    cout << "No se encontró el número de cuenta especificado." << endl;
}

void realizarRetiro(Clients* clients, int numClients, const string& accountNumber, double amount) {
    for (int i = 0; i < numClients; i++) {
        if (clients[i].account_number == accountNumber) {
            cout << "Retiro realizado con éxito para el cliente: " << clients[i].client << endl;
            return;
        }
    }
    cout << "No se encontró el número de cuenta especificado." << endl;
}

int main() {
	string searchAccountNumber;
	float saldo = 0;
    float opcion;
    double monto = 0;
    int cantidad;
    int maxClients;
    cout << "Ingrese el numero maximo de clientes a manejar en el sistema: ";
    cin >> maxClients;

    Clients* clients = new Clients[maxClients];

    ifstream infile("Clients.csv");
    if (!infile) {
        cout << "No se pudo abrir el archivo de entrada 'clients.csv'\n";
        delete[] clients;
        return 1;
    }

    int nline=0;
    string line;
    while (getline(infile, line) && nline < maxClients) {
        stringstream str(line);
        getline(str, clients[nline].ci, ','); 
        getline(str, clients[nline].client, ',');
        getline(str, clients[nline].account_number, ',');
        getline(str, clients[nline].account_type, ',');
        getline(str, clients[nline].suspend, ',');
        nline++;
        system("cls");
    }
    infile.close();

    int choice;
    do {
        cout<<"\nSistema Bancario"<<endl;
        cout<<"\n1. Mostrar todos los clientes"<<endl;
        cout<<"2. Mostrar detalles de un cliente por numero de cuenta"<<endl;
        cout<<"3. Realizar deposito"<<endl;
        cout<<"4. Realizar retiro"<<endl;
        cout<<"5. Realizar transferencia"<<endl;
        cout<<"6. Cancelar transferencia"<<endl;
        cout<<"7. Suspender cuetna"<<endl;
        cout<<"8. Registro de nuevo cliente"<<endl;
        cout<<"9. Eliminar cuenta"<<endl;
        cout<<"10 Salir"<<endl;
        cout<<"\nIngrese el numero de la opcion deseada: ";
        cin>> choice;
        
        system("cls");

        switch (choice) {
        	
        case 1:
            cout << "Clientes cargados desde el archivo:" << endl;
            for (int i = 0; i < nline; i++) {
                printClientInfo(clients[i]);
            }
            break;
            
        case 2:
            cout << "Ingrese el numero de cuenta a buscar: ";
            cin >> searchAccountNumber;
            for (int i = 0; i < nline; i++) {
                if (clients[i].account_number == searchAccountNumber) {
                    cout << "Informacion del cliente encontrado:" << endl;
                    printClientInfo(clients[i]);
                    break;
                }
            }
            break;
            
        case 3:{
        	        	string accountNumber;
            double amount;
            cout << "Ingrese el número de cuenta: ";
            cin >> accountNumber;
            cout << "Ingrese el monto a depositar: ";
            cin >> amount;
            realizarDeposito(clients, nline, accountNumber, amount);
			break;
		}
        	
        case 4:{
        	string accountNumber;
            double amount;
            cout << "Ingrese el número de cuenta: ";
            cin >> accountNumber;
            cout << "Ingrese el monto a retirar: ";
            cin >> amount;
            realizarRetiro(clients, nline, accountNumber, amount);
			break;
		}
			
		case 5:{
			string origen, destino;
            double monto;
            cout << "Ingrese el número de cuenta de origen: ";
            cin >> origen;
            cout << "Ingrese el número de cuenta de destino: ";
            cin >> destino;
            cout << "Ingrese el monto a transferir: ";
            cin >> monto;
			break;
		}
			
		case 6:
			void cancelarTransferencia();
		
		case 7:{
			string accountNumber;
            cout << "Ingrese el número de cuenta a suspender: ";
            cin >> accountNumber;
			break;
		}
		
		case 8:
			void registrarCliente();
			break;
		
		case 9:{
			string accountNumber;
            cout << "Ingrese el número de cuenta a eliminar: ";
            cin >> accountNumber;
			break;
		}

        }

    } while (choice != 10);

    delete[] clients;
    return 0;
}
