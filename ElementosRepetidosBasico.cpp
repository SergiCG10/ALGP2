#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <iostream>
#include <fstream> // Para usar ficheros
#include <vector>

using namespace std;

void OrdenaConteo(vector <int>& v);
void EliminarRepes(vector<int>& vec);
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
		EliminarRepes(v); // Ejecutamos el algoritmo para tamaÒo de caso tam
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

void OrdenaConteo(vector<int>& v) {
    
    int max_value=0, i = 0, n = v.size(); //O(1)
    for(i = 0; i < n; i++) //O(n)
        if(max_value < v[i]) //O(1)
            max_value = v[i]; //O(1)

    vector<int> count(max_value+1, 0); //O(n)
    for(i = 0; i < n; i++) //O(n)
        ++count[v[i]]; //O(1)

    for(i = 1; i <= max_value; i++) //O(max_value)
        count[i] += count[i-1]; //O(1)
    vector<int> out(n); //O(n)
    for(int i = n-1; i >= 0; i--){ //O(n)
        out[count[v[i]]-1] = v[i]; //O(1)
        count[v[i]]--; //O(1)
    }
    v=out; //O(n)
}

void EliminarRepes(vector<int>& vec){
    int elem, elem_actual=1; //O(1)
    vector<int> vec_limpio; //O(1)
    if(vec.empty())
        return;
    vec_limpio=vec; //O(n);
    OrdenaConteo(vec_limpio); //O(n+k)
    vec[0]=vec_limpio[0]; //O(1)
    for(elem = 1; elem < vec_limpio.size(); elem++) //O(n-1)
        if(vec_limpio[elem-1] != vec_limpio[elem]){ //O(1)
            vec[elem_actual]=vec_limpio[elem]; //O(1)
            ++elem_actual; //O(1)
        }
    vec.resize(elem_actual); //O(1), no tiene que hacer realloc
}

void PrintVector(const vector<int>& vec){
    for(int elem: vec)
        cout << elem << " ";
    cout << endl;
}
