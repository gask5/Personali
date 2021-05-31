#include <iostream>

using namespace std;

template <class T>
class Stack{
    private:
        T* stack;
        int nElem;
        int length;
    public:
        Stack(int n){
            this->stack = new T[n];
            length = n;
            nElem = 0;
        }

        Stack<T>* insert(T value){

            if(isFull()){
                return this;
            } 
            stack[nElem++] = value;
            return this;
        }

        Stack<T>* remove(){
            if(isEmpty()){
                return this;
            }

            nElem--;
            return this;
        }

        int isFull(){
            return nElem == length;
        }

        int isEmpty(){
            return nElem <= 0;
        }

        friend ostream& operator<<(ostream& os, const Stack& s){
            for(int i = 0; i < s.nElem; i++){
                os<<s.stack[i]<< " --> ";
            }
            os<<endl;
            return os;
        }
};

int main(){
    Stack<int> s(4);
    s.insert(3)->insert(30)-> insert(13)->remove()-> insert(8)->insert(414124)->remove();
    cout<<s;
}