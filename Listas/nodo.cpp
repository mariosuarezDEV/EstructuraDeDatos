#include <iostream>
using namespace std;

class Nodo{
private:
    int dato; //Es el dato que se estara recibiendo
    Nodo *sig; //Este nos sirve para asignar los siguientes datos
public:
    void setDato(int dato); //Asignar un dato
    void setSig(Nodo *s); // o asignar al proximo dato
    int getDato(); //obtener el dato en el que estamos apuntando
    Nodo* getSig(); //obtener el siguiente dato
};

void Nodo::setDato(int dato){
    this->dato=dato;
}
void Nodo::setSig(Nodo *s){
    sig = s;
}
int Nodo::getDato(){
    return dato;
}
Nodo* Nodo::getSig(){
    return sig;
}