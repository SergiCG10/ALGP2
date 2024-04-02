#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <iostream>
#include <fstream> // Para usar ficheros

using namespace std;

int ProductoDe3(int n);
int ProductoDe3(int n, int gap, int nactual);


int main(int argc, char *argv[]) {
	
	int n, i, argumento, numero, prod3=0;
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
	double tejecucion; // tiempo de ejecucion del algoritmo en ms
	unsigned long int semilla;
	ofstream fsalida;
	
	if (argc <= 3) {
		cerr<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
		cerr<<argv[0]<<" NombreFicheroSalida Semilla tamCaso1 tamCaso2 ... tamCasoN\n\n";
		return 0;
	}
	
	// Abrimos fichero de salida
	fsalida.open(argv[1]);
	if (!fsalida.is_open()) {
		cerr<<"Error: No se pudo abrir fichero para escritura "<<argv[1]<<"\n\n";
		return 0;
	}
	
	// Inicializamos generador de no. aleatorios
	semilla= atoi(argv[2]);
	srand(semilla);
	
	// Pasamos por cada tamaÒo de caso
	for (argumento= 3; argumento<argc; argumento++) {
		
		// Cogemos el tamanio del caso
		n= atoi(argv[argumento]);
		
		// Reservamos memoria para el vector
		
		// Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
		
        numero = n;
		cerr << "Ejecutando Productode3 para tam. caso: " << n << endl;
        
		t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
        prod3=ProductoDe3(numero);
		tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo
	    
        cerr << endl;


		unsigned long tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();
		
		cerr << "\tTiempo de ejec. (us): " << tejecucion << " para tam. caso "<< n<<endl;
	    cerr << "Resultado para " << numero << " es " << prod3 << endl;	
		// Guardamos tam. de caso y t_ejecucion a fichero de salida
		fsalida<<n<<" "<<tejecucion<<"\n";
		
		
		// Liberamos memoria del vector
	}
	
	// Cerramos fichero de salida
	fsalida.close();
	
	return 0;
}

int ProductoDe3(int n){
    return ProductoDe3(n, n/2, n/2);
}


int ProductoDe3(int n, int gap, int nactual){
    unsigned long long producto = 0;
    producto=nactual*(nactual+1)*
        (nactual+2);
    
    if(gap == 0 && producto != n) return -1;

    if(gap != 1)
        gap=(gap+1)/2;
    else gap = 0;
    if(producto == n) return nactual;
    else if(producto > n) return ProductoDe3(n, gap, nactual-gap);
    else return ProductoDe3(n, gap, nactual+gap);
}
