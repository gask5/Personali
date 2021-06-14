#include <iostream>

using namespace std;

static int passi =0;
void print(int *v, int n);
void bubblesort(int *v, int n);
void swap(int *v, int n1, int n2);
void insertionsort(int *v, int n);
void selectionsort(int *v, int n);
const int min(int *v, int n);
int * merge(int *v1, int *v2, int n1 , int n2);
void merge2(int *v, int n1 , int n2);


void mergeSort(int *v, int n);


void mergeSort(int *v, int n){
    if(n < 2) return;
    int m = n/2;
    mergeSort(v, n-m);
    mergeSort(v+(n-m), m);
    merge2(v,n-m,m);
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
    i = j = k = 0;
    while(i<n1 && j<n2){
        if(v[i]<v[n1+j]) b[k++] = v[i++];
        else b[k++] = v[n1+j++];
        passi++;
    }

    while(i<n1){
        b[k++] = v[i++];
        passi++;
    } 
    while(j<n2){
        b[k++] = v[n1+j++];
        passi++;
    } 

    for(int i=0 ; i<k ; i++){
        v[i] = b[i];
        
    }
}

const int min(int *v, int n){
    int min = 0;
    for(int i = 1; i < n; i ++){
        if(v[min] > v[i]) min = i;
        passi++;
    }
    return min;
}

void selectionsort(int *v, int n){ // caso ottimo e pessimo O(n^2)
    for(int i = 0; i < n;i++){
        swap(v, i , min(v+i,n-i) + i );
    }

    cout<< endl << "Array ordinato con SELECTION SORT" << endl;
}

void insertionsort(int *v, int n){
    for( int i = 1 ; i < n ; i++){
        int j = i;
        while(j > 0 && v[j] < v[j-1]){
            swap(v,j,j--); //swap con decremento
            passi++;
        }
    }

    cout<< endl << "Array ordinato con INSERTION SORT" << endl;
}


void print(int *v, int n){
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout<<endl;
}

void swap(int *v, int n1, int n2){
    int tmp = v[n2];
    v[n2] = v[n1];
    v[n1] = tmp;
}


void bubblesort(int *v, int n){ 
    for(int i = n ; n>1 ; n--){
        for(int j = i - 1; j > 0; j--){
            if(v[j]<v[j-1]) swap(v,j-1,j);
        }
    }
    cout<< endl << "Array ordinato con BUBBLESORT" << endl;
}
