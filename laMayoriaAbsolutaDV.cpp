#include <cstdlib>
#include <chrono>
#include <iostream>
#include <fstream>
using namespace std;

int ordenarParte(int *v, int inicio, int fin ){
    int pivote = v[inicio];
	int ext_izquierdo = inicio + 1 ;
	int ext_derecho = fin;

	while( ext_izquierdo != ext_derecho){
		if( v[ext_izquierdo] <= pivote){
			ext_izquierdo++;
		}else{
			while( (ext_derecho != ext_izquierdo) && (v[ext_derecho] > pivote) ){
				ext_derecho--;
			}
			int aux = v[ext_derecho];
			v[ext_derecho] = v[ext_izquierdo];
			v[ext_izquierdo] = aux;
		}
	}

	if( v[ext_izquierdo] > pivote ){
		ext_izquierdo--;
	}

	v[inicio] = v[ext_izquierdo];
	v[ext_izquierdo] = pivote;

	return (ext_izquierdo);

}
void quickSort( int* v, int inicio, int fin){

	if(inicio < fin){
		int q = ordenarParte(v, inicio, fin);
		quickSort(v, inicio, q - 1 );
		quickSort(v, q + 1, fin);
	}
}

int MayorABS(int votos[], int n)
{
    int mayor=-1;
    quickSort(votos, 0, n-1);
    bool hayMV=false;
        for(int i=0;i+n/2<n && !hayMV;i++){
            if(votos[i]==votos[i+n/2]){
                mayor=votos[i];
                hayMV=true;
            }
        }
    return mayor;
}


int main()
{
    int n=12;
    int votos[n] {2,2,1,1,1,2,2,2,1,2,1,2};
    int mayoriabsoluta=MayorABS(votos,n);
    if(mayoriabsoluta>0)
        cout<<"El candidato con identificador: "<<mayoriabsoluta<<" ha obtenido mayoria absoluta en las votaciones"<<endl;
    else
        cout<<"No se ha alcanzado mayoria absoluta"<<endl;


    return 0;
}
