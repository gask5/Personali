#include <iostream>
#include <time.h>
#include "colors.h"

using namespace std;


void sleepcp(int milliseconds) // Cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end)
    {
    }
}

static int passi =0;

void print(int *v, int n);
void bubblesort(int *v, int n);
void swap(int *v, int n1, int n2);
void swapP(int *v, int n1, int n2);
void insertionsort(int *v, int n);
void selectionsort(int *v, int n);
const int minimo(int *v, int n);
int * merge(int *v1, int *v2, int n1 , int n2);
void merge2(int *v, int n1 , int n2);
void mergeSort(int *v, int n);
int partition(int *v, int n);
void quicksort(int *v, int n);

int partition(int *v, int n){
    int x = v[0]; //pivot
    int i , j;
    i = -1;
    j = n;
    do{
        do i++; while (v[i]<x);
        do j--; while (v[j]>x);
        if(i<j) swap(v,i,j);
    } while(i<j);
    return j;
}

void quicksort(int *v, int n){
    if (n<2) return;
    int m = partition(v,n);
    quicksort(v, m+1);
    quicksort(v+m+1,n-(m+1));
}




void mergeSort(int *v, int n){
    if(n < 2) return;
    int m = n/2;
    mergeSort(v, m);
    mergeSort(v+m, n-m);
    merge2(v,n,m);
}

int * merge(int *v1, int *v2, int n1 , int n2){
    int *b;
    b = new int[n1+n2];
    int i, j , k;
    i = j = k = 0;
    while(i<n1 && j<n2){
        if(v1[i]<v2[j]) b[k++] = v1[i++];
        else b[k++] = v2[j++];
    }

    while(i<n1) b[k++] = v1[i++];
    while(j<n2) b[k++] = v2[j++];

    return b;
}

void merge2(int *v, int n1 , int n2){
    int *b;
    b = new int[n1+n2];
    int i, j , k;
    i = k = 0;
    j = n2;
    while(i<n2 && j<n1){
        if(v[i]<v[j]) b[k++] = v[i++];
        else b[k++] = v[j++];
        passi++;
    }

    while(i<n2){
        b[k++] = v[i++];
        passi++;
    } 
    while(j<n1){
        b[k++] = v[j++];
        passi++;
    } 

    for(int i=0 ; i<k ; i++){
        v[i] = b[i];
        
    }
}

const int minimo(int *v, int n){
    int min = 0;
    for(int i = 1; i < n; i ++){
        if(v[min] > v[i]) min = i;
        passi++;
    }
    return min;
}

void selectionsort(int *v, int n){ // caso ottimo e pessimo O(n^2)
    for(int i = 0; i < n;i++){
        swap(v, i , minimo(v+i,n-i) + i );
    }

    //cout<< endl << "Array ordinato con SELECTION SORT" << endl;
}

void insertionsort(int *v, int n){
    for( int i = 1 ; i < n ; i++){
        int j = i;
        while(j > 0 && v[j] < v[j-1]){
            swap(v,j,j--); //swap con decremento
            passi++;
        }
    }

    //cout<< endl << "Array ordinato con INSERTION SORT" << endl;
}


void print(int *v, int n){
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout<<endl;
}

void swapP(int *v, int n1, int n2){
    int tmp = v[n2];
    
    cout<< endl;
    for(int i = 0; i<10; i++){
        if(i==n1){
            cout<<colors(v[n1],1);
        } 
        else if(i==n2){
            cout<<colors(v[n2],2);
        } 
        else{
            
            cout<< v[i];
        }
        cout<<" ";
    }
    sleepcp(1000);
    system("clear");
    v[n2] = v[n1];
    v[n1] = tmp;
}

void swap(int *v, int n1, int n2){
    int tmp = v[n2];
    v[n2] = v[n1];
    v[n1] = tmp;
}


void bubblesort(int *v, int n){ 
    for(int i = n ; i > 0 ; i--){
        for(int j = 0; j < i-1  ; j++){
            if(v[j]>v[j+1]) swap(v,j+1,j);
        }
    }
    //cout<< endl << "Array ordinato con BUBBLESORT" << endl;
}
