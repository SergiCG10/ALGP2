// Fichero laMayoriaAbsoluta.cpp con la solución al primer ejercicio de la segunda práctica de ALG

#include <cstdlib> // Para usar srand y rand
#include <chrono> // Para usar el cronómetro
#include <iostream> 
#include <fstream>

using namespace std;

int main( int argc, char * argv[] ){

    if(argc < 5){
        cerr<<"\nError: El programa se debe ejecutar de la siguiente forma:\n\n";
        cerr<<"./laMayoriaAbsoluta <nombreFicheroSalida> <semilla> <numVotantes> <numCandidatos>\n";
        cerr<<"nombreFicheroSalida: nombre del fichero de salida de datos para la eficiencia\n";
        cerr<<"semilla: variable para generar el vector de votos de forma pseudoaleatoria\n";
        cerr<<"numVotantes: numero de votantes";
        cerr<<"numCandidatos: numero de candidatos que se presentan\n\n";

    }else{
    	int semilla = 0; //Semilla para generar el vector votos pseudoaleatoriamente
        int* votos; //Vector que contendrá los votos, cada posición corresponde con un votante
        int* resultado; //Vector que contendrá los votos de los candidatos, cada posición corresponde al número de indentificador de cada candidato
        int numVotantes; // n
        int numCandidatos; // k
        chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
        ofstream fsalida;

        //Inicializamos el vector de resultados a 0
        for (int i = 0 ; i < numCandidatos; i++){
            resultado[i] = 0;
        }

        //Cogemos la semilla para rellenar el vector de votos
        semilla= atoi(argv[2]);
	    srand(semilla);
		
		// Cogemos el numero de votantes y el numero de candidatos
		numVotantes = atoi( argv[3] );
        numCandidatos = atoi( argv[4] );

        // Reservamos memoria para el vector
		votos = new int[numVotantes];
        resultado = new int [numCandidatos];

        // Abrimos fichero de salida
        fsalida.open(argv[1]);
        if (!fsalida.is_open()) {
            cerr<<"Error: No se pudo abrir fichero para escritura "<<argv[1]<<"\n\n";
            return 0;
        }

		// Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
		for (int i = 0; i<numVotantes; i++){
			votos[i] = rand()%numCandidatos;
        }  

        t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo

        //Sumamos los votos a cada candidato
        for(int i = 0 ; i < numVotantes; i++){

            //Nos aseguramos de que no haya votos nulos (en este caso es imposible, pero en la realidad puede ocurrir)
            if( votos[i] > numCandidatos || votos[i] < 0){
                cout <<"Error, voto nulo";
            }else{
                resultado [ votos[i] ]++;
            } 
        }
        int votosContados= 0; // Variable auxiliar, una vez que esta sea igual que la mitad+1 de los votos, dejamos de contar ya que no es posible la mayoría absoluta
        bool encontrado= false; // Variable booleana que representa si se encuentra la mayoría absoluta
        int mayoriaAbsoluta = -1; // Código numérico del candidato con mayoría absoluta, por defecto -1;
        int nVotos = -1; //Numero de votos del candidato con mayoría absoluta

        //Buscamos si alguien tiene mayoría absoluta
        for( int i = 0; ( i < numCandidatos ) && !encontrado && ( votosContados < numVotantes/2 +1 ); i++){
            if( resultado[i] > numVotantes/2 ){
                encontrado = true;
                mayoriaAbsoluta = i;
                nVotos = resultado[i];
            }else{
                votosContados += resultado[i];
            }
        }
        tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo
		
		unsigned long tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();

        cerr << "\tTiempo de ejec. (us): " << tejecucion << " para "<< numVotantes << " votantes y "<<numCandidatos<<" candidatos "<<endl;
		
		// Guardamos tam. de caso y t_ejecucion a fichero de salida
		fsalida<<numVotantes<<""<<numCandidatos<<" "<<tejecucion<<"\n";
		
		// Liberamos memoria del vector
		delete [] votos;
        delete [] resultado;

        //Cerramos el fichero de salida
        fsalida.close();

        // Sacamos por pantalla el resultado
        if( encontrado ){
            cout<< "El candidato " << mayoriaAbsoluta << " posee la mayoría absoluta de los votos\n con "<<nVotos<< " de "<<numVotantes<<endl;
        }else{
            cout<< "Ningún candidato tiene la mayoría absoluta\n";
        }
    }
    return 0;
}
