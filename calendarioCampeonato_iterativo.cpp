#include <iostream>
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

int main(int argc, char* argv[]){

    int nEquipos=8192;

    int **calendario = new int* [nEquipos];
    
    for(int i=0; i< nEquipos; i++){
        calendario[i] = new int [nEquipos];
    }
 
    organizarCalendario( calendario, nEquipos);
    imprimirCalendario(calendario, nEquipos );
     
    for(int i =0; i < nEquipos; i++){
        delete calendario[i];
    }
    delete [] calendario;
}