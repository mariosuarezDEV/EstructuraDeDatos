#include <iostream>
using namespace std;

class Nodo{
private:
    int dato; //Es el dato que se estará recibiendo
    Nodo *sig; //Este nos sirve para asignar los siguientes datos
public:
    void setDato(int dato); //Asignar un dato
    void setSig(Nodo *s); // o asignar al próximo dato
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

class Lista{
private:
     Nodo *cab;  //apuntador al primer nodo de la lista
public:
  	//operaciones basicas
	Lista();
	int estaVacia();
    void mete(int x);
    void saca();
    void muestra();
    int cantidad_elementos();
    void meterFinal(int x);
    void sacaFinal();
    void buscar_eliminar(int x);
    int posicion(int x);
    bool validar();
};

/*OPERACIONES BASICAS*/
Lista::Lista(){  //constructor, inicializa la cabeza
  cab = NULL;
}

//regresa 1 si esta vacia y 0 si no lo esta
int Lista::estaVacia(){
  if (cab == NULL)
     return 1;
  else
 	return 0;    
}

void Lista::mete(int x){
  Nodo *p;
  p = new Nodo();
  p->setDato(x);
  p->setSig(cab);
  cab = p;
}

void Lista::saca(){
  Nodo *p = cab;
  if(p==NULL){
     cout<<"Error lista vacia";
     system("exit"); 
  }
  cab = cab->getSig();
  delete p;
}

void Lista::muestra(){ 
	//cout << "Metodo para imprimir los datos" << endl;
    Nodo *p;
	p=cab; //asignamos p a la cabeza de la lista
	if(p==NULL){
     cout<<"Error lista vacia";
     system("exit"); 
	} else{
		while (p!=NULL){
	        cout<<p->getDato()<<", ";
	        p=p->getSig();
    	}
	}
    
}
//funcion mia
int Lista::cantidad_elementos(){
	Nodo *p;
	int elemento=0;
	p=cab; //asignamos p a la cabeza de la lista
	if(p==NULL){
     cout<<"La lista tiene "<<elemento<<" elementos";
     return elemento;
     system("exit"); 
	} else{
		while (p!=NULL){
	        elemento ++;
	        p=p->getSig();
    	}
    	cout<<"\nLa cantidad de elementos en la lista es: "<<elemento;
    	return elemento;
	}
	
}

void Lista::meterFinal(int x){
    Nodo *nuevo, *p;
    p = new Nodo(); // recorrer la lista
    p=cab;
    nuevo = new Nodo();
    nuevo->setDato(x);
    while (p->getSig() != NULL)
    {
        p=p->getSig();
        if (p->getSig() == NULL)
    	{
        	p->setSig(nuevo);
        	nuevo->setSig(NULL);
    	}
    }  
}

void Lista::sacaFinal(){
    Nodo *pAnt, *p;
    p = new Nodo(); // recorrer la lista
    p=cab;
    pAnt = new Nodo();
    //pAnt->setDato(NULL);
    while (p->getSig() != NULL)
    {
    	//cout<<"\nNumero en la lista: "<<p->getDato();
        pAnt=p;
        p=p->getSig(); 
    }
    pAnt->setSig(NULL);
    delete p;
}

void Lista::buscar_eliminar(int x){ 
    Nodo *pAnt, *p, *buscar;
    p = new Nodo(); // recorrer la lista
    p=cab;
    pAnt = new Nodo();
    buscar= new Nodo();
    buscar->setDato(x);
    //pAnt->setDato(NULL);
    while (p->getSig() != NULL) 
    {
    	//cout<<"\nNumero en la lista: "<<p->getDato();
        pAnt=p;
        p=p->getSig();
		if (pAnt->getDato()==buscar->getDato()){
			cout<<"\nSe elimino el ultimo dato!";
			
		} 
    }
    pAnt->setSig(NULL);
    delete p;
    
}

int Lista::posicion(int x){
	Nodo *p;
	p = new Nodo();
	p=cab;
	int contador = 1;
	while(p!=NULL){
		if(p->getDato() == x){
			return contador;
			break;
		}
		contador++;
		p=p->getSig();
	}
	return contador;
}

bool Lista::validar(){
	Nodo* p;
	p = new Nodo();
	p=cab;
	while(p!=NULL){
		//comparar si la lista va ordenada
		if(p->getDato() > p->getSig()->getDato()){
			return false; //la lista no va ordenada
			break;
		}
		p=p->getSig();
	}
	return true; //la lista esta ordenada
}

int main(){
	cout << "Mi lista LMCS" << endl;
	
	Lista l1;
	l1.mete(1);
	l1.mete(5);
	l1.mete(10);
	l1.mete(15);
    l1.meterFinal(31);
    l1.mete(32);

	l1.muestra();
    l1.sacaFinal();
    cout<<endl;
    l1.muestra();
    l1.buscar_eliminar(10);
    cout<<endl;
    l1.muestra();
	l1.cantidad_elementos();
	int pos = l1.posicion(10);
	cout<<"\nLa posicion del dato buscado es: "<<pos;
	if(l1.validar() == true){
		cout<<"\nLa lista esta ordenada"<<endl;
	} else{
		cout<<"\nLa lista no esta ordenada!";
	}
	
}