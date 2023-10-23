#include <iostream>
#include <map>
#include <cstdlib>
#include "lib/clases.h"


using namespace std;

int main(int argc, char const *argv[])
{
    //recibir expresion
    char exp[100];
    cout<<"Ingresa la expresion matematica: ";
    cin.getline(exp,100);

    Pila pc1;
    //leemos la expresion
    int i=0, RP=0;
    char postfija[100];
    while (exp[i] != '\0')
    {
        //comparar si el valor en el que estamos es una x
        if (exp[i] == 'x')
        {
            while (true)
            {
                cout<<"Ingresa un valor para X: ";
                cin>>exp[i];
                if (isdigit(exp[i]))
                {
                    break;
                }else{
                    cout<<"Debes ingresar un digito, vuelve a intentarlo:)"<<endl;
                }
                
            }
        }
        
        //si es ( metemos el caracter a la pila
        if (exp[i] == '(')
        {
            //cout<<"Se dectecto un parentesis inicial"<<endl;
            pc1.push(exp[i]);
        }
        //si es un numero, lo metemos a la cadena postfija
        if (isdigit(exp[i]))
        {
            //cout<<"Se encontre un numero"<<endl;
            postfija[RP] = exp[i];
            RP++;
            //aqui esta el problema de solo leer un numero
            
            // Declarar una variable para almacenar el número que se está leyendo
            /*int numero = 0;

            while (isdigit(exp[i]))
            {
                // Construir el número completo leyendo dígito por dígito
                numero = numero * 10 + (exp[i] - '0');
                i++;
            }

            // Almacena el número completo en la cadena postfija
            postfija[RP] = '0' + numero; // Convierte el número a su representación como carácter
            RP++;*/

        }
        //si es un operador
        if (exp[i] == '-' || exp[i] == '+' || exp[i] == '/' || exp[i] == '*')
        {
            //cout<<"Hay un operador"<<endl;
            //asignar prioridades a los signos
            map<char, int> operadorPrioridad;
            operadorPrioridad['('] = 0;
            operadorPrioridad['+'] = 1;
            operadorPrioridad['-'] = 1;
            operadorPrioridad['*'] = 2;
            operadorPrioridad['/'] = 2;

            int prioridadTope;
            int prioridadUsr;
           //repetir las instrucciones hasta que el operador se meta a la pila
            while (true)
            {
                //cout<<"Vuelta en el while"<<endl;
                if (pc1.estaVacia())
                {
                    //cout<<"Se metio operador a la pila"<<endl;
                    pc1.push(exp[i]);
                    break;
                } else
                {
                    prioridadTope = operadorPrioridad[pc1.datoTope()];
                    //cout<<"Se obtiene el dato tope"<<endl;
                    prioridadUsr = operadorPrioridad[exp[i]];
                    if (prioridadTope < prioridadUsr)
                    {
                        //cout<<"Se metio operador a la pila"<<endl;
                        pc1.push(exp[i]);
                        break;
                    }else{
                        //sacar de pila y mandar a postfija
                        
                        postfija[RP] = pc1.datoTope();
                        RP++;
                        //cout<<"Se mando un operador a la postfija"<<endl;
                        pc1.pop();
                    }
                    
                }
            }
        }
        /*si es ) entonces sacar elementos de la pila y agregarlos a la
        cadena postfija, hasta que se haya sacado un parentesis
        izquierdo (este ultimo no se guarda) */

        if (exp[i] == ')')
        {
            //cout<<"Se cerro un parentesis"<<endl;
            while (pc1.datoTope() != '('  )
            {
                //agregar a la postfija
                //cout<<"Se metio de la pila a la postfija un operador"<<endl;
                postfija[RP] = pc1.datoTope();
                RP++;
                pc1.pop();
            }
            //ya estamos en el paretensis, asi que lo sacamos
            pc1.pop();
        }
        //cout<<"Se hizo el if, pasamos al siguiente careacter de la cadena"<<endl;
        i++;
    }
    //si la pila no esta vacia, pasamos lo que falta a la postfija
    while (!pc1.estaVacia())
    {
        postfija[RP] = pc1.datoTope();
        pc1.pop();
        RP++;
    }
    
    //DEPURACION ver post
    int y=0;
    cout<<"Expresion postfija: ";
    while (y < RP)
    {
        cout<<postfija[y]<<"";
        y++;
    }
    cout<<endl;

    //resolver operacion
    Pila2 pi1;

    //recorrer la cadena
    int o=0;
    while ( o < RP )
    {
        //si es un numero se mete a la pila
        if (isdigit(postfija[o]))
        {
            int dato = postfija[o] - '0';
            //cout<<"se metio un dato a la pila: "<<dato<<endl;
            pi1.push(dato);
            /*cout<<"Pila: "; 
            pi1.muestra();
            cout<<endl;*/
        }
        //si es un operador, sacamos dos elementos de la pila y hacemos la correspondientes operacion
        if (postfija[o] == '-')
        {
            /* resta */
            int d2 = pi1.datoTope();
            pi1.pop();
            int d1 = pi1.datoTope();
            pi1.pop();
            int resultado = d1 - d2;
            pi1.push(resultado);
            //cout<<"Se hizo un resta y se metio a la pila el resultado: "<<resultado<<endl;
        }
        if (postfija[o] == '+')
        {
            /* suma */
            int d2 = pi1.datoTope();
            pi1.pop();
            int d1 = pi1.datoTope();
            pi1.pop();
            int resultado = d1 + d2;
            pi1.push(resultado);
            //cout<<"Se hizo una suma y se metio a la pila el resultado: "<<resultado<<endl;
        }
        if (postfija[o] == '*')
        {
            /* multiplicacion */
            int d2 = pi1.datoTope();
            pi1.pop();
            int d1 = pi1.datoTope();
            pi1.pop();
            int resultado = d1 * d2;
            pi1.push(resultado);
            //cout<<"Se hizo una multiplicacion y se metio a la pila el resultado: "<<resultado<<endl;
        }
        if (postfija[o] == '/')
        {
            /* divicion */
            int d2 = pi1.datoTope();
            pi1.pop();
            int d1 = pi1.datoTope();
            pi1.pop();
            int resultado = d1 / d2;
            pi1.push(resultado);
            //cout<<"Se hizo una divicio y se metio a la pila el resultado: "<<resultado<<endl;
        }
        o++;
    }

    cout<<"El resultado es: "<<pi1.datoTope()<<endl;; 
    //pi1.muestra();
    

    return 0;
}
