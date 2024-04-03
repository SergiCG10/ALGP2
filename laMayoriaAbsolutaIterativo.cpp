// Fichero laMayoriaAbsolutaIterativo.cpp con la solución al primer ejercicio de la segunda práctica de ALG

#include <cstdlib> // Para usar srand y rand
#include <chrono> // Para usar el cronómetro
#include <iostream> 
#include <fstream>

using namespace std;

/**
 * @brief struct para guardar los datos del resultado
 */
struct candidato{
    bool mayoria = false;
    int nIdentificador = -1;
    int numeroVotos = -1;
};

/**
 * @brief funcion mayoriaABS. Calcula a partir de un vector de votos y de el numero de votos
 * si algun candidato posee mayoria absoluta
 * 
 * @param v Vector que contiene los votos
 * @param nVotos numero de votos que contiene el vector
 */
candidato mayoriaABS(int* v, int nVotos ){
    //Sumamos los votos a cada candidato
    int* resultado; //Vector que contendrá los votos de los candidatos, cada posición corresponde al número de indentificador de cada candidato
    int mayorID =-1;

    //Buscamos el mayor ID de los candidatos
    for(int i =0; i <nVotos; i++){
        if( v[i]> mayorID){
            mayorID = v[i];
        }
    }
    //Creamos un vector con el mismo numero que el ID mayor de los candidatos
    resultado = new int [mayorID];

    //Inicializamos el vector de resultados a 0
    for (int i = 0 ; i < mayorID; i++){
        resultado[i] = 0;
    }

    for(int i = 0 ; i < nVotos; i++){

        //Nos aseguramos de que no haya votos nulos (en este caso es imposible, pero en la realidad puede ocurrir)
        if( v[i] < 0){
            cout <<"Error, voto nulo";
        }else{
            resultado [ v[i] ]++;
        } 
    }

    int votosContados= 0; // Variable auxiliar, una vez que esta sea igual que la mitad+1 de los votos, dejamos de contar ya que no es posible la mayoría absoluta
    candidato ganador; // Variable booleana que representa si se encuentra la mayoría absoluta
    bool encontrado = false;

    //Buscamos si alguien tiene mayoría absoluta
    for( int i = 0; ( i < mayorID ) && !encontrado && ( votosContados < nVotos/2 +1 ); i++){
        if( resultado[i] > nVotos/2 ){
            encontrado = true;
            ganador.mayoria = true;
            ganador.nIdentificador = i;
            ganador.numeroVotos = resultado[i];
        }else{
            votosContados += resultado[i];
        }
    }
    return ganador;
}

int main( int argc, char * argv[] ){

    if(argc <  5){
        cerr<<"\nError: El programa se debe ejecutar de la siguiente forma:\n\n";
        cerr<<"./laMayoriaAbsolutaIterativo <nombreFicheroSalida> <semilla> <numVotantes> <numCandidatos>\n";
        cerr<<"nombreFicheroSalida: nombre del fichero de salida de datos para la eficiencia\n";
        cerr<<"semilla: variable para generar el vector de votos de forma pseudoaleatoria\n";
        cerr<<"numVotantes: numero de votante\n";
        cerr<<"idenficador maximo de candidato (solo sirve para crear el vector de forma aleatoria)\n\n";

    }
    	int semilla = 0; //Semilla para generar el vector votos pseudoaleatoriamente
        int* votos; //Vector que contendrá los votos, cada posición corresponde con un votante
        int numVotantes; // n
        int numCandidatos; // k
        int argumento;
        chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
        ofstream fsalida;
        candidato resultado;

        //Cogemos la semilla para rellenar el vector de votos
        semilla= atoi(argv[2]);
	    srand(semilla);
		
		// Cogemos el numero de votantes y el max de candidatos
		numVotantes = atoi( argv[3] );
        numCandidatos = atoi( argv[4]);

        // Reservamos memoria para el vector
		votos = new int[numVotantes];
        
        // Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
        int celdasNoIniciadas = numVotantes;
       
		for(int i =0; i < numVotantes; i++){	
            int aux = rand()%celdasNoIniciadas;
            celdasNoIniciadas -= aux;
            for(int contador =0 ; contador < aux && i<numVotantes; contador++, i++){
                votos[i] = rand()%numCandidatos;
            }
            
        }

        // Abrimos fichero de salida
        fsalida.open(argv[1]);
        if (!fsalida.is_open()) {
            cerr<<"Error: No se pudo abrir fichero para escritura "<<argv[1]<<"\n\n";
            return 0;
        }  

        t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
        
        resultado = mayoriaABS(votos, numVotantes);

        tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo
		
		unsigned long tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();

        cerr << "\tTiempo de ejec. (us): " << tejecucion << " para "<< numVotantes << " votantes y "<< numCandidatos <<" candidatos "<<endl;
		
		// Guardamos tam. de caso y t_ejecucion a fichero de salida
		fsalida<<numVotantes<<""<<numCandidatos<<" "<<tejecucion<<"\n";
		
		// Liberamos memoria del vector
		delete [] votos;

        //Cerramos el fichero de salida
        fsalida.close();

        // Sacamos por pantalla el resultado
        if( resultado.mayoria ){
            cout<< "El candidato " << resultado.nIdentificador << " posee la mayoría absoluta de los votos\n con "<< resultado.numeroVotos << " de "<<numVotantes<<endl;
        }else{
            cout<< "Ningún candidato tiene la mayoría absoluta\n";
        }
    }
    return 0;
}
