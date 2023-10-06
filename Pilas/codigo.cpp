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
     void eliminar_xdato(int x);

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

//funcion para eliminar elemento
void Pila::eliminar_xdato(int x){
	//crear una pila aux
	Pila aux;

	//recorrer la pila
	while(!estaVacia()){
		int dato = datoTope();
		if (dato != x)
		{
			//cout<<"Entro al if"<<endl;
			aux.push(dato); //se meten todos los datos siempre y cuando no sea el dato que se mando como parametro
			//cout<<"Se metio un dato que no estas buscando"<<endl;
		}
		pop();
		//cout<<"Se elimino un dato"<<endl;
	}	

	//pasar todo a la original
	while(!aux.estaVacia()){
		//cout<<"Se devolvio un dato a la original"<<endl;
		int dato = aux.datoTope();
		push(dato);
		//cout<<"Se devolvio un dato a la original"<<endl;
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
  c1.eliminar_xdato(10);
  cout<<"\nPila sin datos: ";
  c1.muestra();
  system("pause>>null"); 
}
