#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

class ArbolABB;
/**CLASE NODO**/
class Nodo {
     private:
      int dato;
      Nodo *izq;
      Nodo *der;

  public:
  	Nodo(int x);
  	void setDato(int x);
    void setIzq(Nodo * p);
	void setDer(Nodo * p);
    int getDato();
    Nodo * getIzq();
    Nodo * getDer();

   };
	Nodo::Nodo(int x){
		dato = x;
		izq = NULL;
		der = NULL;
	}
  	void Nodo::setDato(int x){
  		dato = x;
	  }
    void Nodo::setIzq(Nodo * p){
    	izq = p;
	}
	void Nodo::setDer(Nodo * p){
		der = p;
	}
    int Nodo::getDato(){
    	return dato;
	}
    Nodo * Nodo::getIzq(){
    	return izq;
	}
	
    Nodo * Nodo::getDer(){
    	return der;
	}
	
	
 /***CLASE ARBOL BINARIO DE BUSQUEDA***/  
class ArbolABB {
  private:
   Nodo *raiz;
  public:
   ArbolABB() ;
   Nodo *apRaiz();
   int esVacio(Nodo *r);
   void insertar(int x, Nodo * p);
   
   
   void InOrden(Nodo *p);
   //void PreOrden(Nodo *nodo);
   //void PostOrden(Nodo *nodo);
   int profundidad (Nodo* p);
   
};

//*****CODIGOS DE METODOS******************************//
   ArbolABB::ArbolABB(){	//Constructor
     raiz = NULL;
   }

Nodo * ArbolABB::apRaiz(){  //regresa el apuntador a la raiz
  return raiz;
}
int ArbolABB::esVacio(Nodo *r) {
      return r==NULL;
   }


void ArbolABB::insertar(int x, Nodo *p){
  if(p== NULL){ 
     p = new Nodo(x);
     raiz = p;
   }
   else if (x < p->getDato()){   
      if(p->getIzq() == NULL){
	  	Nodo *n = new Nodo(x);
      	p->setIzq(n);	
	  }
	  else
     	insertar(x , p->getIzq());
 }
  else if (x > p->getDato()){
  	 if(p->getDer() == NULL){
     	Nodo *n = new Nodo(x);
      	p->setDer(n);	
	  }
	else
     	insertar(x, p->getDer());
}
  else
     cout<<"\n El dato ya existe.";
}


//**RECORRIDOS ************************************
void ArbolABB::InOrden(Nodo *p){
   if(p->getIzq() != NULL){
     InOrden(p->getIzq());
   }
   cout<<p->getDato()<<", ";
   
   if(p->getDer() != NULL){
     InOrden(p->getDer());
 }
}



//*SABER LA PROFUNDIDAD DEL ARBOL *************************
int ArbolABB::profundidad(Nodo* p){
  //p es la raiz
  //si la raiz es nula
  if (p == NULL)
  {
    return -1; //regresa -1
  }
  //si la raiz no tiene hijos, entonces:
  if (p->getIzq() == NULL && p->getDer() == NULL)
  {
    return 0; //regresamos 0
  }
  // pasamos a los casos recursivos
  int pIzq = profundidad(p->getIzq());
  int pDer = profundidad(p->getDer());

  //una vez que se hicieron los casos recursivos, vamos a comprar
  //si el dato derecho (btnApagar) es mayor
  if (pDer > pIzq)
  {
    return pDer +1;
  } else{ //en caso contrario:
          return pIzq +1;
        }
  
}

/////////////////////////////////////////////////////////
int main(){
   ArbolABB ar;
   Nodo *r;

   // Inserci�n de nodos en �rbol:
   ar.insertar(5,NULL);
   r = ar.apRaiz();
   ar.insertar(12,r);
   ar.insertar(4,r);
   ar.insertar(7,r);
   ar.insertar(3,r);
   ar.insertar(6,r);
   ar.insertar(9,r);
   ar.insertar(8,r);
   ar.insertar(11,r);
   ar.insertar(14,r);
   ar.insertar(13,r);
   ar.insertar(16,r);
   
   //Mostrar el arbol 
   cout << "\nInOrden: "; ar.InOrden(r);
   //cout << "\nPreOrden: "; ar.PreOrden(ar.apRaiz());
   //cout << "\nPostOrden: "; ar.PostOrden(ar.apRaiz());
   cout << endl;
   int prof = ar.profundidad(r);
   cout<<"La profundidad del arbol es: "<<prof;
   
   
   
   return 0;
}
