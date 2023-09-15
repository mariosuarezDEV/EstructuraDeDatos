#include <iostream>

using namespace std;

int par(int n);

int impar(int n);

int main(int argc, char const *argv[])
{
    int num;
    cout<<"Ingresa un numero: ";
    cin>>num; //->4
    int verificar = impar(num);
    if (verificar == 1)
    {
        cout<<"El numero es par";
    } else{
        cout<<"El numero es impar";
    }
    

    return 0;
}


int impar(int n){
    if ( n== 0)
    {
        return 0;
    } else{
        return par(n-1);
    }
    
}

int par(int n){ //cualquier numero que se divada entre 2
    if (n == 0)
    {
        return 1;
    } else{
        return impar(n-1);
    }
    
}