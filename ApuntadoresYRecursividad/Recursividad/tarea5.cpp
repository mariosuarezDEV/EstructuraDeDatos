#include <iostream>

using namespace std;

//declaración de funciones
int buscarPOS(int *pArreglo, int buscar, int tam, int indice);

int main(){
    int tam;
    cout<<"Ingresa el la cantidad: ";
    cin>>tam; 
    int arreglo[tam];
    for(int i=0; i<tam; i++){
        cout<<"Ingresa un dato: ";
        cin>>arreglo[i];
    }
    int buscar;
    cout<<"Ingresa el numero que quieres buscar: ";
    cin>>buscar;
    //puntero del arreglo
    int *pArreglo;
    pArreglo=arreglo;
    int pos= buscarPOS(pArreglo,buscar,tam,0);
    if(pos != -1){
        cout<<"El numero a buscar esta en la posición: "<<pos+1;
    } else{
        cout<<"El numero no esta en la lista!";
    }
    return 0;
}

int buscarPOS(int *pArreglo, int buscar, int tam, int indice){
    //caso base: si se recorrio todo el arreglo
    if (indice == tam)
    {
        return -1;
    }
    //comprobar si el dato es igual
    if (buscar == pArreglo[indice])
    {
        return indice;
    }

    return buscarPOS(pArreglo, buscar,tam,indice+1);
    
    
}