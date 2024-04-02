#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <iostream>
#include <fstream> // Para usar ficheros
using namespace std;

bool finder(const int &n, int &k){
	bool found = 0;
	int valor;

	for(int i = k; i * (i+1) * (i+2) <= n && found == 0 ; i++){
		if (i * (i+1) * (i+2) == n){
			found = 1;
			k = i;
		}
	}
	return found;
}

int main(int argc, char *argv[]) {
	
	int n;
    int k = 1;

    chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
	ofstream fsalida;
	
	if (argc != 3) {
		cerr<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
		cerr<<argv[0]<<" NombreFicheroSalida NumeroMultiplicado \n\n";
		return 0;
	}
	
	// Abrimos fichero de salida
	fsalida.open(argv[1]);
	if (!fsalida.is_open()) {
		cerr<<"Error: No se pudo abrir fichero para escritura "<<argv[1]<<"\n\n";
		return 0;
	}

	n = atoi(argv[2]);

	t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
	finder(n, k); // Ejecutamos el algoritmo para tamaÒo de caso n
	tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo

	cout << k;
	
	unsigned long tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();
	
	cerr << "\tTiempo de ejec. (us): " << tejecucion << " para tam. caso "<< n<<endl;
	
	//Guardamos tam. de caso y t_ejecucion a fichero de salida
	fsalida<<n<<" "<<tejecucion<<"\n";
		
	
	//Cerramos fichero de salida
	fsalida.close();
	
	return 0;
}
