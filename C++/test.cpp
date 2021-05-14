#include "iostream"

using namespace std;

int somma(int a, int b , int c=0, int d=0){
    return a+b+c+d;
}

int x2(int a);
int x3(int a);
int quad(int a);
int cubo(int a);


int main(){
    int a[5]={23,12,7,6,19};
    int(*f[4])(int)={x2,x3,quad,cubo};
    for(int i =0;i<5;i++){
        for (int j = 0; j < 4; j++)
        {
            cout<<f[j](a[i])<<" ";
        }
        cout<<endl;
    }
}

int x2(int a){
    return 2*a;
}
int x3(int a)
{
    return 3*a;
}
int quad(int a){
    return a*a;
}

int cubo(int a){
    return a*a*a;
}