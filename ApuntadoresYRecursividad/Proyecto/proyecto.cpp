#include <iostream>

using namespace std;

void ordenar(char* palabras[], int cantPalabras);

int main(int argc, char const *argv[])
{
    //recibir la frase
    char frase[500];
    cout<<"Ingresa una frase: ";
    cin.getline(frase,500);
    //cout<<"\nFrase registrada";
    
    //crear el apuntador
    char *pFrase[30]; //-> Asi es un caracter
    int i =0;
    int y =0;
    //cout<<"\nApuntadores creadores e inicialisadorez listos!";

	pFrase[y] = &frase[i];
	y++;
    while (frase[i] != '\0' && y < 30)
    {
        if (frase[i] == ' ')
        {
            //cout<<"\nEntamos al if";
            frase[i] = '\0';
            pFrase[y] = &frase[i+1];
            //cout<<"\nLa palabra guardada es: "<<pFrase[y];
            y++;
        }
        i++;
    }

    // Imprimir las palabras almacenadas
    cout<<"\nPalabras desonrdenadas: ";
    for (int j = 0; j < y; j++)
    {
        cout << pFrase[j] << " ";
    }
    
    //mostrar las palabras ordenadas
    ordenar(pFrase , y);
    cout<<"\nPalabras ordenadas: ";
    for (int j = 0; j < y; j++)
    {
        cout << pFrase[j] << " ";
    }

    return 0;
}


void ordenar(char* palabras[], int cantPalabras){
    for (int i = 0; i < cantPalabras - 1; i++) {
        for (int j = 0; j < cantPalabras - i - 1; j++) {
            if (strcmp(palabras[j], palabras[j + 1]) > 0) {
                // Intercambia los apuntadores de las palabras
                char* temp = palabras[j];
                palabras[j] = palabras[j + 1];
                palabras[j + 1] = temp;
            }
        }
    }
}