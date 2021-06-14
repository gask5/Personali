#include "funzioniripasso.hpp"


int main(){
    const int N = 10;

    // int *a = new int[10];
    // for(int i = 0; i < N; i++){
    //     a[i]=rand()%100000;
    // }

    int a[N]= {23,12,2,4,51,7,20,14,6,3};

    int b[N]= {13,5,22,124,1,17,10,11,36,0};

    print(a,N);

    insertionsort(a,N);

    print(a,N);

    cout<<endl<<"Passi eseguiti: "<< passi<<endl;



}
