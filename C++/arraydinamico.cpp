#include <iostream>

using namespace std;

class ArrayDinamico{
    public:

        int numeroElementi;
        int dimensioneMassima;
        int *array;

    public:

        ArrayDinamico(int _dimensioneMassima){
            numeroElementi = 0;
            dimensioneMassima = _dimensioneMassima;
            array = new int[dimensioneMassima];
        }

        void insert(int valore){
            if(numeroElementi==dimensioneMassima) {
                int *tmp = array;
                dimensioneMassima *= 2;
                array = new int[dimensioneMassima];
                memcpy(array, tmp, sizeof(int)*numeroElementi);
            }
            array[numeroElementi++] = valore;
        }

        void print(){
            print(array, numeroElementi);
            cout<<endl;
        }

        void print(int* v , int n){
            if(n==0) return;
            cout<< "[" << v[0] << "]";
            print(v+1 ,n-1);
        }

        int getNumeroElementi(){ return numeroElementi; }
        int getDimensione(){ return dimensioneMassima; }

};

int main(){
    ArrayDinamico a(4);
    for(int i =1; i<=300;i++){
        a.insert(i);
    }
    a.print();

}