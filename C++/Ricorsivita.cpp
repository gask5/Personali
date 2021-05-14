#include "iostream"

using namespace std;

int mul(int x, int y){
    if(y<=1) return x;
    return mul(x,y-1) + x;
}

int fatt(int x){
    if(x==1) return x;
    return fatt(x-1)*x; 
}

int fib(int x){
    if(x<=2) return 1;
    return fib(x-2) + fib(x-1);
}

int potenza(int x ,int y){
    if(y==1) return x;
    return potenza(x,y-1) * x;
}

int potenza2(int x ,int y){
    if(y==0) return 1;
    if(y==1) return x;
    return potenza(x,y/2) * potenza(x,y-y/2);
}

int log2(int x){
    if(x==1) return 0;
    return log2(x/2) +1 ;
}


int main(){
    cout<<fib(83);
}

