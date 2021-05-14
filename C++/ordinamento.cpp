#include <iostream>
#include <stdlib.h>

using namespace std;

// un algoritmo si dice stabile se in presenza di elementi uguali l'algoritmo mantiene l'ordinamento che aveva nell'array originale

template <class T>
void bubblesort(T *v, int n);
template <class T>
void mergesort(T *v, int n);
template <class T>
void merge(T *v, int n, int m);
template <class T>
void quicksort(T *v, int n);
template <class T>
int partition(T *v, int n);
int massimo(int *v, int n);
int minimo(int *v, int n);
void massimo_minimo(int *v, int n, int& mx, int& mn);
void stampa(int *v, int n);
void stampaR(int *v, int n);
void stampaM(int *v, int n);
void scambia(int *v, int i, int j);
void selectionsort(int *v, int n);
void r_selectionsort(int *v, int n);
int posmax(int *v, int n);
void r_insertionsort(int *v, int n);
void insertionsort(int *v, int n);
void naturalmerge(int *a, int n, int *b, int k, int *c);

int main()
{
    int N = 1000;
    int *v ;
    v = new int[N];
    for(int i = 0; i < N; i++){
        v[i]=rand()%100000;
    }
    stampa(v,N);
    insertionsort(v,N);
    stampa(v,N);
    
    
}

int posmax(int *v, int n){
    int p = 0;
    for(int i = 1; i<n; i++){
        if(v[i]>v[p]) p = i;
    }
    return p;
}

void r_selectionsort(int *v, int n){
    if(n<=1) return;
    scambia(v,posmax(v,n),n-1);
    return r_selectionsort(v,n-1);
}


template <class T>
int partition(T *v, int n){ // O(N)
    T x = v[0]; //elemento pivot
    int i = -1; // indice che scorre da sinsitra verso destra 
    int j = n; // indice che scorre da destra verso sinistra
    do{ 
        do i++; while (v[i]<x);
        do j--; while (v[j]>x);
        if(i<j) scambia(v,i,j); // algoritmo non stabile
    } while(i<j);
    return j;
}

template <class T> // O(N^2) <--  n(n+1)/2 nel caso pessimo
void quicksort(T *v, int n){ // o(nlog(n)) caso ottimo 
    if (n<= 1) return;
    int m = partition(v,n); // algoritmo non stabile
    quicksort(v, m+1);
    quicksort(v+m+1, n-(m+1));
}

template <class T> 
void it_quicksort(T *v, int n){ // variante iterativa
    while(n>1){
        int m = partition(v,n);
        quicksort(v, m+1);
        v= v+m+1;
        n = n - (m+1);
    }
    return;
}

template <class T>
void mergesort(T *v, int n) // l'altezza del mergesort e' uguale a log2(n); complessita` O(nlog2(n)) detta anche complessita` linearitmica ( lineare * logaritmica);
{
    if (n <= 1)
        return;
    int m = n / 2;
    mergesort(v, m);
    mergesort(v + m, n - m);
    merge(v, n, m); //funzione ausiliaria poiche` il mergesort non e` in grado di lavorare in loco;
}

template <class T>
void merge(T *v, int n, int m) // complessita` O(n)
{
    T b[n]; // array ordinato;
    int i, j, k;
    i = k = 0;
    j = m;
    while (i<m && j<n) // scorro i due array con gli indici i  e j;
    {
        if (v[i]<v[j]) b[k++] = v[i++]; // confronto i primi due elementi degli array divisi , e quello piu` piccolo lo inserisco nell'array b; // v[i]<v[j] algoritmo non stabile // v[i]<=v[j] algoritmo stabile
        else b[k++] = v[j++];
    }
    while(i<m) b[k++] = v[i++];
    while(j<n) b[k++] = v[j++];
    for (int i = 0; i < n; i++)
    {
        v[i] = b[i];
    }
}

template <class T>
void bubblesort(T *v, int n){ // O(n^2) caso pessimo e ottimo;
    for(int i = 0; i < n-1; i++)
        for(int k = 0; k <n-1-i; k++)
            if(v[k]>v[k+1])
                scambia(v,k,k+1);
}

void stampa(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void scambia(int *v, int i, int j)
{
    int tmp = v[j];
    v[j] = v[i];
    v[i] = tmp;
}

void selectionsort(int *v, int n) // caso ottimo e pesismo O(n^2)
{
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[m])
            {
                m = j;
            }
        }
        scambia(v, i, m);
    }
}

void r_insertionsort(int *v, int n)
{
    if (n <= 1)
        return;
    r_insertionsort(v, n - 1);
    int j = n - 2;
    while (j >= 0 && v[j + 1] < v[j])
    {
        scambia(v, j, j + 1);
        cout << "Scambio" << v[j] << " con " << v[j + 1] << endl;
        j--;
    }
}

void insertionsort(int *v, int n) // caso ottimo O(n) // caso pessimo O(n^2) // ha complessita O(kn) dove k e` la distanza massima tra un elemento e la sua posizione finale

{
    static int passi = 0;
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && v[j - 1] > v[j])
        {
            scambia(v, j, j - 1);
            j--;
            passi++;
        }
    }
    cout<< "Insertion sort ha compiuto " << passi << " oprazioni"<<endl;
}

void stampaR(int *v, int n){
    if(n<1) return;
    stampaR(v,n-1);
    cout<< v[n-1] << " ";
    
}

void stampaM(int *v, int n){
    if(n==0) return;
    if(n==1) {
        cout<< v[0] << " ";
        return;
    }
    int m=n/2;
    stampaM(v,m);
    stampaM(v+m,n-m);
}

void naturalmerge(int *a, int n, int *b, int k, int *c){
    int i,j,h;
    i = j = h = 0;
    while(i<n && j<k){
        if(a[i]<b[j]) c[h++] = a[i++];
        else c[h++] = b[j++];
    }
    while(i<n) c[h++] = a[i++];
    while(j<k) c[h++] = b[j++];
}

int massimo(int *v, int n, int max){
    if(n<1) return max;
    if(v[0]>max) max=v[0];
    return massimo(v+1,n-1,max);
}

int minimo(int *v, int n,int min){
    if(n<1) return min;
    if(v[0]<min) min=v[0];
    return minimo(v+1,n-1,min);
}

void massimo_minimo(int *v, int n, int& mx, int& mn){
    mx=mn= v[0];
    for(int i =1;i<n-1;i+=2){
        if(v[i]<v[i+1]){
            if(v[i]<mn) mn = v[i];
            if(v[i+1]>mx) mx= v[i+1];
        }
        else {
            if(v[i+1]<mn) mn = v[i+1];
            if(v[i]>mx) mx= v[i];
        }
    }
    if(n%2==0){
        if(v[n-1]<mn) mn=v[n-1];
        if(v[n-1]>mx) mx=v[n-1];
    }
}
