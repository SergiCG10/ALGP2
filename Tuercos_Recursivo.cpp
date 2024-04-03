#include <cstdlib>
#include <chrono>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;

  void ordenarVectores(vector<int>& a, vector<int>& b, int start, int end) {
    if (start >= end) {
        return; // Caso base: vector de tamaño 0 o 1
    }

    int mid = (start + end) / 2;

    // Ordenar la primera mitad de los vectores
    ordenarVectores(a, b, start, mid);
    ordenarVectores(a, b, mid + 1, end);

    // Combinar las mitades ordenadas
    inplace_merge(a.begin() + start, a.begin() + mid + 1, a.begin() + end + 1);
    inplace_merge(b.begin() + start, b.begin() + mid + 1, b.begin() + end + 1);
}
int main(int argc, char *argv[]) {
	
	int *v; int *bolti;
	int n, i, argumento;
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
		vector<int> a;
		vector<int> b;
		
		// Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
		for (i= 0; i<n; i++){
			 a.push_back(rand()%n);
		}
		b=a;
		
		std::random_device rd;
		std::mt19937 gen(rd());

		for (int i = n - 1; i > 0; --i) {
  			std::swap(b[i], b[std::uniform_int_distribution<>(0, i)(gen)]);
		}
		
		cerr << "Ejecutando QuickSort para tam. caso: " << n << endl;

		t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
		ordenarVectores(a, b,0, n ); // Ejecutamos el algoritmo para tamaÒo de caso n
		tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo
		
		unsigned long tejecucion= std::chrono::duration_cast<std::chrono::nanoseconds>(tf - t0).count();
		
		cerr << "\tTiempo de ejec. (us): " << tejecucion << " para tam. caso "<< n<<endl;
		
		// Guardamos tam. de caso y t_ejecucion a fichero de salida
		fsalida<<n<<" "<<tejecucion<<"\n";
		
		
		// Liberamos memoria del vector
		delete [] v;
	}
	
	// Cerramos fichero de salida
	fsalida.close();
	
	return 0;
}

