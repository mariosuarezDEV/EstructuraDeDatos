#ifndef _CLASS_
#define _CLASS_

#include <iostream>

using namespace std;

class Nodo{
private:
    char dato;
    Nodo *sig;
public:
    
  void setDato(char x);
  void setSig(Nodo *s);
  char getDato();
  Nodo *getSig();
};

void Nodo::setDato(char x){
	dato = x;
}
void Nodo::setSig(Nodo *s){
	sig = s;
}
char Nodo::getDato(){
	return dato;
}
Nodo * Nodo::getSig(){
	return sig;
}

/* Nodos y Pila de enteros */
class Nodo2{
private:
    int dato;
    Nodo2 *sig;
public:
    
  void setDato(int x);
  void setSig(Nodo2 *s);
  int getDato();
  Nodo2 *getSig();
};

void Nodo2::setDato(int x){
	dato = x;
}
void Nodo2::setSig(Nodo2 *s){
	sig = s;
}
int Nodo2::getDato(){
	return dato;
}
Nodo2 * Nodo2::getSig(){
	return sig;
}

//crear clase pila caracteres

class Pila2{
private:
     Nodo2 *aptope;
public:
  //operaciones basicas
     Pila2();
     int estaVacia();
     void push(int x);
     void pop();
     int datoTope();
     void muestra();
};

Pila2::Pila2(){
	aptope = NULL;
}

int Pila2::estaVacia(){
	return (aptope == NULL);
}

void Pila2::push(int x){
	Nodo2 *p;
	p = new Nodo2();
	p->setDato(x);
	p->setSig(aptope);
	aptope = p;
}

void Pila2::pop(){
	Nodo2 *p = aptope;
	if(p==NULL){
		cout<<"Error lista vacia";
    	exit(1);
	}
	aptope = aptope->getSig();
	delete p;
}

int Pila2::datoTope(){
	return aptope->getDato();
}

void Pila2::muestra(){
	Pila2 aux;
	while (!estaVacia())
	{
		cout<<datoTope()<<" ";
		aux.push(datoTope());
		pop();
	}
	while (!aux.estaVacia())
	{
		push(aux.datoTope());
		aux.pop();
	}
	
	
}


//crear clase pila caracteres

class Pila{
private:
     Nodo *aptope;
public:
  //operaciones basicas
     Pila();
     int estaVacia();
     void push(char x);
     void pop();
     char datoTope();
     void muestra();
};

Pila::Pila(){
	aptope = NULL;
}

int Pila::estaVacia(){
	return (aptope == NULL);
}

void Pila::push(char x){
	Nodo *p;
	p = new Nodo();
	p->setDato(x);
	p->setSig(aptope);
	aptope = p;
}

void Pila::pop(){
	Nodo *p = aptope;
	if(p==NULL){
		cout<<"Error lista vacia";
    	exit(1);
	}
	aptope = aptope->getSig();
	delete p;
}

char Pila::datoTope(){
	return aptope->getDato();
}

#endif