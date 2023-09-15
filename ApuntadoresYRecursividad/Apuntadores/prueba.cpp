#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int x = 10, *pX;
    pX = &x; //->Esto almacena a posicion en memoria de X
    cout<<"La poscion en memoria es: "<<pX<<endl;
    cout<<"El valor de X desde el apuntador es: "<<*pX<<endl;

    return 0;
}
