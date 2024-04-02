#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;

void PrintVector(const vector<int>& v);
void EliminarRepes(vector<int>& v);
void fusionaMS(vector<int>& v, int posIni, int centro, int posFin, vector<int>& vaux);
void MergeSort(vector<int>& v, int posIni, int posFin, vector<int>& vaux);

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
			v[i]= rand()%n;
	
		cerr << "Ejecutando ElementosRepetidosBasico para tam. caso: " << n << endl;
		
		t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
		EliminarRepes(v); // Ejecutamos el algoritmo para tamaÒo de caso tam
		tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo
		
		unsigned long tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();


		cerr << "\tTiempo de ejec. (us): " << tejecucion << " para tam. caso "<< n<<endl;
		
		// Guardamos tam. de caso y t_ejecucion a fichero de salida
		fsalida<<n<<" "<<tejecucion<<"\n";
		
		
		// Limpiamos el vector
		v.clear();
	}
	
	// Cerramos fichero de salida
	fsalida.close();
	
	return 0;
}


void PrintVector(const vector<int>& v){
    for(int elem : v)
        cout << elem << " ";
    cout << endl;
}

void EliminarRepes(vector<int>& v){
    vector<int> vaux;
    vaux.resize(v.size());
    MergeSort(v, 0, v.size()-1, vaux);
    int elem_v=0;
    for(int elem : vaux){
        if(elem != -1){
            v[elem_v]=elem;
            ++elem_v;
        }
    }
    v.resize(elem_v);
}

void fusionaMS(vector<int>& v, int posIni, int centro, int posFin, vector<int>& vaux) {
    int i = posIni;
    int j = centro;
    int k = 0;
    
    while (i < centro && j <= posFin){
        if(v[i] <= v[j]){
            vaux[k] = v[i];
            ++i;
        } else {
            vaux[k] = v[j];
            ++j;
        }
        ++k;
    }
    while (i < centro){
        vaux[k] = v[i];
        ++i;
        ++k;
    }

    while (j <= posFin){
        vaux[k] = v[j];
        ++j;
        ++k;
    }
    
    //El pobre memcpy ha sido sustituido por esto

    v[posIni] = vaux[0]; //segmentation fault? no gracias
    for(i = 1; i < k; i++){ //O(k-1)
        //Vaux ordenado por lo que los elementos que sean
        //igual serán contiguos, si no es igual al último elemento
        //entonces que lo guarde
        if(vaux[i-1] != vaux[i]) //O(1)
            v[posIni+i] = vaux[i];
        //Si son iguales, entonces que lo borre (con un 0), este else {
        //el peor caso
        else
            v[posIni+i] = -1; //Borrado, O(1)
    }
}

void MergeSort(vector<int>& v, int posIni, int posFin, vector<int>& vaux) {

    if (posIni>=posFin) return;

    int centro= (posIni+posFin)/2;

    MergeSort(v, posIni, centro, vaux);
    MergeSort(v, centro+1, posFin, vaux);
    fusionaMS(v, posIni, centro+1, posFin, vaux);
}
