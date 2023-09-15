#include<iostream>

using namespace std;

bool recibir(int arreglo[], int encontrar, int vueltas);
int num_palabras(char oracion[]);


int main(){
    int llenar,buscar;
    cout<<"Ingresa la cantidad de numeros a guardar: ";
    cin>>llenar;
    cin.ignore();

    cout<<"Ingresa el numero a buscar en el arreglo: ";
    cin>>buscar;
    cin.ignore();
    cout<<"Ahora llenaras tu arreglo!"<<endl;
    int arr[llenar];
    for (int i=0; i<llenar; i++){
        cout<<"Numero para el espacio "<<i<<": ";
        cin>>arr[i];
    }
    cin.ignore();

    //el arreglo ahora esta lleno, lo mandamos a la funcion
    bool resultado = recibir(arr,buscar,llenar);
    if(resultado == false){
        cout<<"No se encontro el numero!"<<endl;
    } else{
        cout<<"El numero se encontro en la lista!"<<endl;
    }

    //Ahora vamos a contar las palabras *CORREGIR*
    char mensaje[200];
    cout<<"Escribe ahora una oracion para contar las palabras!"<<endl;
    cout<<"Mi mensaje: ";
    cin.getline(mensaje,200);
    int cantidad_palabras = num_palabras(mensaje);
    cout<<"La cantidad de palabras son: "<<cantidad_palabras;

    return 1;
}

bool recibir(int arreglo[], int encontrar, int vueltas){
    bool encontrado = false;
    for(int i=0; i<vueltas; i++){
        if(encontrar == arreglo[i]){
            encontrado = true;
        }
    }
    return encontrado;
}

int num_palabras(char oracion[]) {
    int contador = 0;
    bool dentroPalabra = false;

    for (int i = 0; oracion[i] != '\0'; i++) {
        if (oracion[i] == ' ' || oracion[i] == '\t' || oracion[i] == '\n' || oracion[i] == '\r') {
            dentroPalabra = false;
        } else {
            if (!dentroPalabra) {
                dentroPalabra = true;
                contador++;
            }
        }
    }

    return contador;
}


