#include <iostream>

using namespace std;

template <class T>
class ArrayDinamico{
    public:

        int numeroElementi;
        int dimensioneMassima;
        T* array;

    public:

        ArrayDinamico(T _dimensioneMassima){
            numeroElementi = 0;
            dimensioneMassima = _dimensioneMassima;
            array = new T[dimensioneMassima];
        }

        void insert(T valore){
            if(numeroElementi==dimensioneMassima) {
                T* tmp = array;
                dimensioneMassima *= 2;
                //delete [] array;
                array = new T[dimensioneMassima];
                memcpy(array, tmp, sizeof(T)*numeroElementi);
                //cout<<"Prima del delete tmp = : "<<tmp[0]<<endl;
                delete [] tmp;
                //cout<<"Dopo delete tmp = : "<<tmp[0]<<endl;
                cout<<"Dimensione array raddoppiata: " << dimensioneMassima <<endl;
            }
            array[numeroElementi++] = valore;
        }

        void cancella(T valore){
            int indice=-1;
            for(int i=0 ; i<numeroElementi ; i++){
                if(valore==array[i]){
                    indice = i;
                    i=numeroElementi;
                } 
            }
            if(-1 == indice){
                cout<<"Elemento " << valore << " non trovato."<<endl;
                return;
            } 
            for(int j=indice; j<numeroElementi; j++){
                array[j] = array[j+1];
            }
            numeroElementi--;
            if(numeroElementi<dimensioneMassima/2){
                T* tmp = array;
                dimensioneMassima /=2;
                array = new T[dimensioneMassima];
                memcpy(array,tmp,sizeof(T)*numeroElementi);
                delete[] tmp;
                cout<<"Dimensione array dimezzata: " << dimensioneMassima <<endl;
            }
        }


    

        void print(){
            print(array, numeroElementi);
            cout<<endl;
        }

        void print(T* v , int n){
            if(n==0) return;
            cout<< "[" << v[0] << "]";
            print(v+1 ,n-1);
        }

        T getNumeroElementi(){ return numeroElementi; }
        T getDimensione(){ return dimensioneMassima; }

        T &operator[](int i){
            if(i>=0 && i < numeroElementi){
                return array[i];
            }

            cout<< "L'indice " << i << " non e` corretto a sinistra" << endl;

            exit(0);
        }

        int &operator[](int i) const {
            if(i>=0 && i < numeroElementi){
                return array[i];
            }

            cout<< "L'indice " << i << " non e` corretto a destra" << endl;

            exit(0);
        }

      
};

int main(){
    ArrayDinamico<int> a(4);
    for(int i =1; i<=10;i++){
        a.insert(i);
    }
    a.print();
    for(int i =1; i<=5;i++){
        a.cancella(i);
    }
    a.print();
    cout<<"Dimensione array: " << a.getDimensione()<<endl;
 
}