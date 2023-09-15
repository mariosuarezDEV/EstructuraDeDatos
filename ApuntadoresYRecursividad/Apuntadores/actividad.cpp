#include <iostream>

using namespace std;

void incremento(int *pArreglo, int tam);
void incremento2(int *pArreglo, int tam);

int main(int argc, char const *argv[])
{
    int cantidad, *pArreglo;
    cout<<"Ingresa la cantidad de elementos a guardar: ";
    cin>>cantidad;

    int arreglo[cantidad];
    //llenar el arreglo
    for(int i =0; i<cantidad; i++){
        cout<<"Ingresa un valor: ";
        cin>>arreglo[i];
    }

    pArreglo = arreglo; //->Apuntador ya tiene la direccion en memoria del arreglo
    incremento(pArreglo,cantidad);
    incremento2(pArreglo,cantidad);
    //fin del programa

    return 0;
}

void incremento(int *pArreglo, int tam){
    //comenzar a incrementar
    for(int i =0; i<tam; i++){
        pArreglo[i] = pArreglo[i]+1;
    }

    //mostrar el nuevo arreglo
    for(int i =0; i<tam; i++){
        cout<<pArreglo[i]<<", ";
    }
    cout<<endl;

}

void incremento2(int *pArreglo, int tam){
    //comenzar a incrementar
    for(int i =0; i<tam; i++){
        *(pArreglo+i) = *(pArreglo+i)+1;
    }

    //mostrar el nuevo arreglo
    for(int i =0; i<tam; i++){
        cout<<*(pArreglo+i)<<", ";
    }
    cout<<endl;

}