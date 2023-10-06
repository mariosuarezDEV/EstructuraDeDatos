/*Programa que implementa el tipo de dato Pila*/

#include <iostream>
#include <stdlib.h>


using namespace std;

class Nodo{
private:
    int dato;
    Nodo *sig;
public:
  void setDato(int x);
  void setSig(Nodo *s);
  int getDato();
  Nodo *getSig();
};

void Nodo::setDato(int x){
	dato = x;
}
void Nodo::setSig(Nodo *s){
	sig = s;
}
int Nodo::getDato(){
	return dato;
}
Nodo * Nodo::getSig(){
	return sig;
}


//CLASE LISTA

class Pila{
private:
     Nodo *aptope;
public:
  //operaciones basicas
     Pila();
     int estaVacia();
     void push(int x);
     void pop();
     int datoTope();
     void muestra();

};


/*OPERACIONES BASICAS*****************************************/
Pila::Pila(){
	aptope = NULL;
}

int Pila::estaVacia(){
	return (aptope == NULL);
}

void Pila::push(int x){
	Nodo *p;
	p = new Nodo();
	p->setDato(x);
	p->setSig(aptope);
	aptope = p;
}

void Pila::pop(){
	Nodo *p = aptope;
	int x;
	if(p==NULL){
		cout<<"Error lista vacia";
    	exit(1);
	}
	aptope = aptope->getSig();
	delete p;
}

int Pila::datoTope(){
	return aptope->getDato();
}

/*Mis funciones */

void Pila::muestra(){
	//crear una pila nueva
	Pila aux;
	//saber si la pila esta vacia
	while(!estaVacia()){
		//guardar el dato
		int dato = datoTope();
		//mostrar los datos
		cout<<dato<<", ";
		//meter el dato a la aux
		aux.push(dato);
		//sacar el dato
		pop();
	}

	//regresar los datos
	while(!aux.estaVacia()){
		int dato = aux.datoTope();
		push(dato);
		aux.pop();
	}
}



int main(){
  
  Pila c1;
  c1.push(5);
  c1.push(10);
  c1.push(15);
  c1.push(20);
  c1.push(25);
  cout<<"\nPila1: ";
  c1.muestra();

  cout<<"\nPila1.1: ";
  c1.muestra();
  system("pause>>null");
 
  
}
