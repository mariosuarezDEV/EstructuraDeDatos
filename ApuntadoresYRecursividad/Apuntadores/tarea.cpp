#include <iostream>

using namespace std;

int contar_caracteres(char *pFrase, char caracter);

int main(int argc, char const *argv[])
{
    char frase[200], *pFrase, caracter;
    cout<<"Escribe tu mensaje: ";
    gets(frase);
    cout<<"Que caracter quieres contar de tu frase?: ";
    cin>>caracter;
    pFrase = frase;

    int cantidad_letras = contar_caracteres(pFrase,caracter);
    cout<<"La cantidad de veces que aparece el caracter '"<<caracter<<"' son: "<<cantidad_letras<<endl;;

    return 0;
}

int contar_caracteres(char *pFrase, char caracter){
    int i=0, contador=0;
    while(*(pFrase+i) != '\0'){
        if(caracter == *(pFrase+i)){
            contador ++;
        }
        i++;
    }
    return contador;
}