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
	
	int n, i, argumento, numero, prod3=0;
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
	double tejecucion; // tiempo de ejecucion del algoritmo en ms
	ofstream fsalida;
	
	if (argc <= 2) {
		cerr<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
		cerr<<argv[0]<<" NombreFicheroSalida tamCaso1 tamCaso2 ... tamCasoN\n\n";
		return 0;
	}
	
	// Abrimos fichero de salida
	fsalida.open(argv[1]);
	if (!fsalida.is_open()) {
		cerr<<"Error: No se pudo abrir fichero para escritura "<<argv[1]<<"\n\n";
		return 0;
	}
	
	
	// Pasamos por cada tamaÒo de caso
	for (argumento= 2; argumento<argc; argumento++) {
		
		// Cogemos el tamanio del caso
		n= atoi(argv[argumento]);
		
		// Reservamos memoria para el vector
		
		// Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
		
        numero = n;
		cerr << "Ejecutando Productode3 para tam. caso: " << n << endl;
        
		t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
        finder(numero, prod3);
		tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo
	    
        cerr << endl;


		unsigned long tejecucion= std::chrono::duration_cast<std::chrono::nanoseconds>(tf - t0).count();
		
		cerr << "\tTiempo de ejec. (ns): " << tejecucion << " para tam. caso "<< n<<endl;
	    cerr << "Resultado para " << numero << " es " << prod3 << endl;	
		// Guardamos tam. de caso y t_ejecucion a fichero de salida
		fsalida<<n<<" "<<tejecucion<<"\n";
		
		
		// Liberamos memoria del vector
	}
	
	// Cerramos fichero de salida
	fsalida.close();
	
	return 0;
}
