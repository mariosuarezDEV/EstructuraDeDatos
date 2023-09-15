#include <iostream>
#define interes 0.09

using namespace std;

float inv(int monto, int a);

int main(int argc, char const *argv[])
{
    int a;
    float monto;
    cout<<"Ingresa el monto a invertir: ";
    cin>>monto;
    cout<<"Ingresa los años a los que quieres calcular: ";
    cin>>a;
    float gan = inv(monto,a);
    cout<<"El dinero total sera: "<<gan;


    return 0;
}

float inv(int monto, int a){
    float ganacia = monto*interes;
    //cout<<ganacia;
    float dinero = ganacia + monto;
    if (a == 1){
        return dinero;
    } else{
        return inv(dinero,a-1);
    }
    
}
