#include <iostream>

using namespace std;


class A{
    private:
        int a;
        float b;
    public: 

        A(){}

        A(int _a, float _b) : a(_a), b(_b){}

        A(int _a) : A(_a,0.0f){}

        A(float _b) : A(0,_b){}

        void print(){
            cout<<"a = "<< a <<endl<< "b = " <<b<<endl<<endl;
        }

        friend void saluta(A test){ // il metodo friend e` un metodo esterno, che però messo dentro la classe, riesce ad accedere ai suoi membri
            cout<<"ciao a tutti "<<test.a<<endl;
        }

};

void saluta(A a);

int main(){
    A a1(1,1.0f);
    A a2(3);
    A a3(4.0f);
    A a4 = {1,2.0f};
    A a5 = 5;

    a1.print();
    a2.print();
    a3.print();
    a4.print();
    a5.print();

    saluta(a2);
}