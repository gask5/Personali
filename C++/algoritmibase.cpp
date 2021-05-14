#include <iostream>

using namespace std;

void swap(char *s, int i,int j){
    char t = s[i];
    s[i] = s[j];
    s[j] = t;
}

void print(char *s,int n){
    if(n==0){
        cout<<endl;
        return; 
    } 
    cout<<s[0];
    print(s+1,n-1);
}

void permutationi(char *s, int n , int i=0){
    if(i==n){
        print(s,n);
        return;
    }
    for(int j=i; j<n;j++){
        swap(s,i,j);
        permutationi(s,n,i+1);
        swap(s,j,i);
    }
}

int main(){
    char t[]= "abcdef";
    permutationi(t,6);
}