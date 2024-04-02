#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <iostream>
#include <fstream> // Para usar ficheros
#include <vector>

using namespace std;

vector<int> EliminarRepes(const vector<int>& vec);
void PrintVector(const vector<int>& vec);

int main(int argc, char *argv[]) {
	
    vector<int> v;
	int n, i, argumento;
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
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
        v.resize(n);

		// Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
		for (i= 0; i<n; i++)
            v[i]=rand()%n;

		cerr << "Ejecutando ElementosRepetidosBasico para tam. caso: " << n << endl;
		
		t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
		v=EliminarRepes(v); // Ejecutamos el algoritmo para tamaÒo de caso tam
		tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo
		
		unsigned long tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();

		cerr << "\tTiempo de ejec. (us): " << tejecucion << " para tam. caso "<< n<<endl;
		
		// Guardamos tam. de caso y t_ejecucion a fichero de salida
		fsalida<<n<<" "<<tejecucion<<"\n";
		
        //borramos el vector
        v.clear();
	}
	
	// Cerramos fichero de salida
	fsalida.close();
	
	return 0;
}

vector<int> EliminarRepes(const vector<int>& vec){
    int elem, index;
    vector<int> vec_limpio;
    bool unico = true;
    if(vec.empty())
        return vec_limpio;

    vec_limpio.push_back(vec[0]);
    for(elem = 1; elem < vec.size(); elem++){
        unico = true;
        for(index = 0; unico && index < vec_limpio.size(); 
                index++)
            if(vec_limpio[index] == vec[elem])
                unico = false;
        if(unico)
            vec_limpio.push_back(vec[elem]);
    }
    return vec_limpio;
}

void PrintVector(const vector<int>& vec){
    for(int elem: vec)
        cout << elem << " ";
    cout << endl;
}
