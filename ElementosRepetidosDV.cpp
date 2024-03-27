#include <iostream>
#include <cstring>
#include <utility>
using namespace std;

void fusionaMS(int *v, int posIni, int centro, int posFin, int *vaux) {
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
        else{
            v[posIni+i] = 0; //Borrado, O(1)
            j=posIni+i; //Desplazamos el elemento borrado al inicio
            while(v[j] <  v[j-1] &&
                    j > posIni){ //ESTE, inicio, porque es el punto que estamos
                                 //manipulando
                swap(v[j], v[j-1]);
                --j;
            }
        }
    }
}

void MergeSort(int *v, int posIni, int posFin, int *vaux) {

    if (posIni>=posFin) return;

    int centro= (posIni+posFin)/2;

    MergeSort(v, posIni, centro, vaux);
    MergeSort(v, centro+1, posFin, vaux);
    fusionaMS(v, posIni, centro+1, posFin, vaux);
}

int main() {
    int v[] = {4, 8, 4, 5, 9, 7, 2, 7};
    int vaux[8], i;
    for (i = 0; i < 8; ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl << std::endl;
    MergeSort(v, 0, 7, vaux);
    for (i = 0; i < 8; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
