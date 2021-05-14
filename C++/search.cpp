#include "iostream"

using namespace std;

int search(int *v,int n , int k){
    if(v[0]==k || n==0) return 0;
    return search(v+1,n-1,k) + 1;
}

int search2(int *v,int n , int k){
    if(n==0) return 0;
    return (v[0]==k) || search2(v+1,n-1,k); //or logico ritorna 1 se trova l'elemento
}

int search3(int *v,int n , int k){
    cout<<v[0]<<" ";
    if(v[0]==k) return 1;
    if(n==1) return 0;
    return search3(v,n/2,k) || search3(v+n/2,n-n/2,k); //or logico ritorna 1 se trova l'elemento
}

int search4(int *v,int n , int k){
    cout<<v[0]<<" ";
    if(n==0) return 0;
    if(n==1) return v[0]==k; // v[0]==k ritorna 1 se e` vero
    return search3(v,n/2,k) || search3(v+n/2,n-n/2,k); //or logico ritorna 1 se trova l'elemento
}

int binarySearch(int *v,int n , int k){
    
    if(n==0) return 0;
    if(n==1) return v[0]==k; // v[0]==k ritorna 1 se e` vero
    int m = n/2;
    if(v[m] > k) return binarySearch(v,m,k);
    else  return binarySearch(v+m,n-m,k);
}

int palindroma(char *v, int n){
    if(n<=1) return 1;
    return (v[0] == v[n-1]) && palindroma(v+1,n-2);
}

int main(){
    char s[] = "osssso";
    int v[] = {2,5,9,14,17,24,27,99};
    int n=5;
    cout<<palindroma(s,6);
}

