#include <iostream>

using namespace std;

int contar(int arr[], int n, int x);

int main(int argc, char const *argv[])
{
    /* code */
    int arrelgo [] ={1,2,2,3,5};
    int tam= 5, x=2;
    int res = contar(arrelgo,tam,x);
    cout<<"El numero de veces que se repite es: "<<res;
    return 0;
}


int contar(int arr[], int n, int x){
    int c = 0;
    if (n>0)
    {
        if(arr[n-1] == x){
            c++;
        }
        c = c + contar(arr,n-1,x);
    }
    return c;
}