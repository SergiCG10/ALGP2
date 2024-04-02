// Fichero calendarioCampeonato_DV.cpp con la solución al quinto ejercicio de la segunda práctica de ALG

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
 * @brief funcion copiarMatrices. Copia nFilas y nColumnas desde una matriz a otra.
 *
 * @param vCopiar puntero apuntando a la direccion donde se almacena la matriz de la que copiar los elementos
 * @param f1 numero de filas de la primera matriz
 * @param c1 numero de columnas de la primera matriz
 * @param vPegar puntero apuntando a la direccion donde se almacena la matriz donde copiar los elementos
 * @param f2 numero de filas de la segunda matriz
 * @param c2 numero de columnas de la segunda matriz
 * @param filIni fila donde iniciar a copiar de la primera matriz
 * @param colIni columna donde iniciar a copiar de la primera matriz
 * @param filInsertar fila donde iniciar a insertar de la segunda matriz
 * @param colInsertar columna donde iniciar a insertar de la segunda matriz
 * @param nFilas numero de filas a copiar
 * @param nColumnas numero de columnas a copiar
 * @param suma numero para sumar a las posiciones a copiar de la matriz
 */
bool copiarMatrices(int **vCopiar, int f1, int c1, int **vPegar, int f2, int c2, int filIni, int colIni, int filInsertar, int colInsertar, int nFilas, int nColumnas, int suma = 0 ){
    if( nFilas < 0 || nColumnas < 0){
        cerr <<"Numero de filas o columnas erroneo"<<endl;
        return false;
    }
    if( (filIni > f1 - nFilas) || (colIni > c1 - nColumnas ) ){
        cerr <<"El numero de filas o columnas a copiar desde la posicion inicial seleccionada es incorrecto"<<endl;
        return false;
    }
    if( (filInsertar > f2 - nFilas) || (colInsertar > c2 - nColumnas ) ){
        cerr <<"El numero de filas o columnas a pegar desde la posicion inicial seleccionada es incorrecto"<<endl;
        return false;
    }
    for(int i =0 ; i < f1 && i < f2 && i < nFilas; i++){
        for(int j = 0; j < c1 && j < c2 && j < nColumnas; j++){
            vPegar[filInsertar + i][colInsertar+ j] = vCopiar[filIni +i][colIni+ j] + suma;
        }
    }
    return true;
}

/**
 * @brief funcion organizarCalendario. Organiza un calendario de partidos con solo ida, para n equipos.
 * La primera columna se tomará como indice numerico de cada equipo
 *
 * @param v puntero que almacena el comienzo de la matriz donde almacenar los partidos
 * @param equipos numero de equipos que participarán 
 */
void organizarCalendario( int **v, int equipos){
    //Caso base, donde el numero de equipos sea 1
    if( equipos < 2){
        v[0][0] = 1;
    }else{
        //Llamada recursiva reduciendo la matriz al primer cuarto (arriba izquierda)
        organizarCalendario(v, equipos/2);
   
        //Copiamos el primer cuadrante (arriba izquierda) en el segundo cuadrante (arriba a la derecha) sumandole equipos/2
        copiarMatrices( v, equipos, equipos, v, equipos, equipos, 0,         0,         0, equipos/2, equipos/2, equipos/2, equipos/2);
        //Copiamos el segundo cuadrante (arriba derecha) en el tercer cuadrante (abajo a la izquierda) 
        copiarMatrices( v, equipos, equipos, v, equipos, equipos, 0, equipos/2, equipos/2,         0, equipos/2, equipos/2);
        //Copiamos el primer cuadrante (arriba izquierda) en el cuarto cuadrante (abajo a la derecha)
        copiarMatrices( v, equipos, equipos, v, equipos, equipos, 0,         0, equipos/2, equipos/2, equipos/2, equipos/2);
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
        imprimirCalendario(calendario, nEquipos );

        //Liberamos memoria
        for(int i =0; i < nEquipos; i++){
            delete calendario[i];
        }
        delete [] calendario;
    }
    return 0;
}
