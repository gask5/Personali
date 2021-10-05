#include <iostream>

using namespace std;
#define BIT 16

int* convert(int a){
    int *T = new int[BIT];

    for(int i = 0; i<BIT;i++){
        T[i] = 0;
    }

    int tmp=a;

    for(int i=0; i<BIT && tmp>0;i++){
        T[i]= tmp%2;
        tmp/=2;
    }

    for(int i=0; i<BIT/2; i++){
        int swap = T[BIT-1-i];
        T[BIT-1-i] = T[i];
        T[i] = swap;
    }

    return T;
}

void print(int* A){
    for(int i=0; i<BIT; i++){
        cout<<A[i];
    }
    cout<<endl;
}

int* add(int* A, int* B){
    int * C = new int[BIT];

    for(int i=BIT-1; i>=0;i--){
        C[i] = A[i] + B[i];
    }

    for(int i=BIT-1; i>=0;i--){
        if(C[i]>=2){
            C[i]-=2;
            C[i-1]+=1;
        }
    }
   return C;
}

int* complemento2(int *A){
    for(int i=0; i<BIT; i++){
        if(A[i]==0) A[i] = 1;
        else A[i] = 0;
    }
    cout<<"Complemento a 2 di B: ";
    print(add(A,convert(1)));
    return add(A,convert(1));
}

int main(){
    int a;
    int b;
    
    int *A = new int[BIT];
    int *B = new int[BIT];
    int *C = new int[BIT];

    cout<<"Enter a number: ";
    cin>>a;
    cout<<endl<<"Enter a number 2: ";
    cin>>b;

    A = convert(a);
    B = convert(b);

    cout<<"A: ";
    print(A);
    cout<<"B: ";
    print(B);

    cout<<endl;

    C = add(A,complemento2(B));
    print(C);

}