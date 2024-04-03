// Fichero calendarioCampeonato_iterativo.cpp con la solución al quinto ejercicio de la segunda práctica de ALG

#include <cstdlib> // Para usar srand y rand
#include <chrono> // Para usar el cronómetro
#include <iostream> 
#include <fstream>
#include <cmath>

using namespace std;


/**
 * @brief Funcion imprimirCalendario. Se utiliza para imprimir una matriz f*f de enteros, 
 * con la primera columna como indice de cada fila, representando un calendario deportivo.
 * 
 * @param v puntero que contiene la direccion de memoria donde comienza la matriz
 * @param f numero de filas de la matriz
 */
void imprimirCalendario(int **v, int f){
    int cont = 0;
    cout<<"   | ";
    for(int k = f; k > 0; k/=10){
        cont++;
    }
    for(int i =1; i < f; i++){
        for(int k=i; k < pow(10, cont); k*=10){
            if( k <= 0) k = 1;
            cout<<" ";
        }
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i =0; i < f; i++){
        cout<<"----" ;
    }
    cout<<endl;
    for(int i =0; i < f; i++){
        for(int k=v[i][0]; k < pow(10, cont); k*=10){
            if( k <= 0) k = 1;
            cout<<" ";
        }
        cout<< v[i][0]<<"|";
        for(int j = 1; j< f; j++){
            for(int k=v[i][j]; k < pow(10, cont); k*=10){
                if( k <= 0) k = 1;
                cout<<" ";
            }
            cout<<" "<<v[i][j];
        }
        cout<<endl;
    }
}

/**
 * @brief funcion organizarCalendario. Organiza un calendario de partidos con solo ida, para n equipos.
 * La primera columna se tomará como indice numerico de cada equipo
 *
 * @param v puntero que almacena el comienzo de la matriz donde almacenar los partidos
 * @param equipos numero de equipos que participarán 
 */
void organizarCalendario( int **v, int equipos){
    int siguiente = equipos-1;
    int fila = 0;
    int contador = 0;
    int columna = 1;
    
    //Inicializamos la primera columna con los codigos numericos de los equipos
    for(int i = 0; i < equipos; i++){
        v[i][0] = i+1;
    }
    
    //
    while( columna != equipos ){

        v[fila][columna] = equipos; 
        v[ equipos - 1 ][columna] = fila + 1;
        fila++;

        while( contador < equipos/2 -1){
            fila = fila % (equipos -1);
            if( siguiente == 0) siguiente = equipos-1;
            v[fila][columna] = siguiente;
            v[siguiente - 1][columna] = fila + 1;
            siguiente--;
            fila++;
            

            contador++;
        }
        columna++;
        contador =0;
    }
}
/**
 * @brief funcion potenciaDe2. Funcion auxiliar para comprobar si un numero es potencia de 2
 *
 * @param n Numero a comprobar   
 */
bool potenciaDe2(int n){
    if( n == 1){
        return true;
    }else if( n%2 != 0){
        return false;
    }else{
        return potenciaDe2( n/2 );
    }
}

int main(int argc, char* argv[]){
    if( argc != 3){
        cerr<<"\nError: El programa se debe ejecutar de la siguiente forma:\n\n";
        cerr<<"./calendarioCampeonato_DV <nombreFicheroSalida> <numEquipos>\n";
        cerr<<"nombreFicheroSalida: nombre del fichero de salida de datos para la eficiencia\n";
        cerr<<"numEquipos: numero de equipos para organizar el campeonato (debe de ser potencia de 2) \n\n";
    }else{
        ofstream fsalida;
        chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
        
        //Numero de equipos
        int nEquipos = atoi(argv[2]);
      
        //Comprobamos que sea potencia de 2
        if( !potenciaDe2(nEquipos) || nEquipos <= 1){
            cerr<<"\nError: el numero de equipos debe de ser potencia de 2 o mayor que 1"<<endl;
            return 1;
        }
        //Reservamos memoria para la matriz donde guardar el calendario
        int **calendario = new int* [nEquipos];
        for(int i=0; i< nEquipos; i++){
            calendario[i] = new int [nEquipos];
        }
        
        // Abrimos fichero de salida
        fsalida.open(argv[1]);
        if (!fsalida.is_open()) {
            cerr<<"Error: No se pudo abrir fichero para escritura "<<argv[1]<<"\n\n";
            return 0;
        }

        t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
        organizarCalendario( calendario, nEquipos);
        tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo

        unsigned long tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();

        cerr << "\tTiempo de ejec. (us): " << tejecucion << " para "<< nEquipos << " equipos"<<endl;
		
		// Guardamos tam. de caso y t_ejecucion a fichero de salida
		fsalida<<""<<nEquipos<<" "<<tejecucion<<"\n";

        //Imprimimos el calendario 
//        imprimirCalendario(calendario, nEquipos );

        //Liberamos memoria
        for(int i =0; i < nEquipos; i++){
            delete calendario[i];
        }
        delete [] calendario;
    }
    return 0;
}
