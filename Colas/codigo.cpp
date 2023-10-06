#include <iostream>


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


class Cola{
private:
     Nodo *ini;
     Nodo *fin;
public:
  //operaciones basicas
     Cola();
     int estaVacia();
     void mete(int x);
     void saca();
     int datoFte();
     void muestra();
     bool encontrar(int x);
     void eliminar_xdato(int x);
     void concatenar(Cola);

};


/*OPERACIONES BASICAS*/
Cola::Cola(){
  ini = NULL;
  fin = NULL;
}
int Cola::estaVacia(){
  if (ini == NULL && fin == NULL)
  	return 1;
  else
  	return 0;
}

//agregar un elemento al final de la cola
void Cola::mete(int x){
  //1) crear el nodo
  Nodo *p;
  p = new Nodo();
  p->setDato(x);
  //2) Nodo siguiente apunta a NULL
  p->setSig(NULL);
  //3) si hay elementos, el ultimo apunta al nuevo nodo
  if(fin != NULL){
    fin->setSig(p);
  }
  //4) ultimo apunta al nuevo nodo
  fin = p;
  //5) Si la cola estaba vacia, primero apunta al nodo
  if(ini == NULL){
    ini = p;
  }
}

//Sacar un dato de la cola
void Cola::saca(){
  //0) Verificar que tiene elementos
  if(ini==NULL && fin == NULL){
     cout<<"Error Cola vacia";
     exit(1);
  }
  //1)Nodo apunta al primer elemento de la cola
  Nodo *p = ini;
  //2) Asignar a ini la direccion el segundo nodo de la lista
  ini = ini->getSig();
  //3) Si ini apunta a NULL, hace que fin tambien apunta a NULL
  //   ya que la lista tenia un solo elemento
  if(ini == NULL){
    fin = NULL;
  }
  //4)Liberamos memoria del nodo
 		// int x = p->getDato();
  delete p;

}

int Cola::datoFte(){
  Nodo *p = ini;
  if(p == NULL){
     cout<<"Error: Apuntador nulo";
     exit(1);
  }
  return p->getDato();
}

//mis funciones
void Cola::muestra(){
  Cola aux;
  int dato;
  //llenar la cola aux
  while(!estaVacia()){
    dato=datoFte();
    aux.mete(dato);
    cout<<dato<<", ";
    saca();
  }

  //vovler a la normalidad
  int volver;
  while(!aux.estaVacia()){
    volver= aux.datoFte();
    mete(volver);
    aux.saca();
  }
}

/*Encontrar el dato que pide el usuario*/
bool Cola::encontrar(int x){
	/*Crear una cola auxiliar*/
	Cola aux;
	int dato;
	bool band=false;
	while(!estaVacia()){
		/*La cola tiene datos*/
		dato=datoFte();
		if(dato == x){
			band=true;
		}
		aux.mete(dato);
		saca();
	}
	int original;
	while(!aux.estaVacia()){
		original = aux.datoFte();
		mete(original);
		aux.saca();
	}
	return band;	
}

/*Eliminar un dato de la cola*/
void Cola::eliminar_xdato(int x){
	/*Crear cola auxiliar*/
	Cola aux;
	int dato;
	while(!estaVacia()){
		dato=datoFte();
		if(dato == x){
			saca();
		} else{
			aux.mete(dato);
			saca();
		}
	}
	/*Volver a acomodar los datos*/
	while(!aux.estaVacia()){
		mete(aux.datoFte());
		aux.saca();
	}
	
}

void Cola::concatenar(Cola colaNueva){
  Cola aux;
  while(!estaVacia() && !colaNueva.estaVacia()){
    if (datoFte() < colaNueva.datoFte())
    {
      aux.mete(datoFte());
      saca();
    } else{
      aux.mete(colaNueva.datoFte());
      colaNueva.saca();
    }
  }

  /*se rompe el while*/

  //meter datos si la cola original tiene datos
  while(!estaVacia()){
    aux.mete(datoFte());
    saca();
  }

  //meter datos si la cola nueva tiene datos
  while(!colaNueva.estaVacia()){
    aux.mete(colaNueva.datoFte());
    colaNueva.saca();
  }
  
   
  /*volver todo a la cola original*/
    while(!aux.estaVacia()){
      mete(aux.datoFte());
      aux.saca();
    } 
}


int main(){
  Cola c1,c2;
  c1.mete(5);
  c1.mete(10);
  c1.mete(15);
  c1.mete(20);
  cout<<"Cola1: ";
  c1.muestra();
  cout<<"\nLa original: ";
  c1.muestra();
  bool encontrar=c1.encontrar(10); 
  if(encontrar == true){
  	cout<<"\nEl dato esta en la cola!";
  } else{
  	cout<<"\nEl dato no esta en la cola!";
  }
  /*cout<<"\nCola despues de buscar el dato: ";
  c1.muestra();*/
  c1.eliminar_xdato(20);
  cout<<"\nCola1.1: ";
  c1.muestra(); 

  c2.mete(2);
  c2.mete(4);
  c2.mete(6);
  cout<<"\nCola 2: ";
  c2.muestra();

  c1.concatenar(c2);
  cout<<"\nLa cola concatenada y ordenada es: ";
  c1.muestra();

  system("pause>>null");
  
}
