#include <iostream>

using namespace std;

template <class T>
class Queue{
    private:
        T* queue;
        int nElem;
        int length;
        int head, tail;
    public:
        Queue(int n){
            this->queue = new T[n];
            length = n;
            head = -1;
            tail = -1;
            nElem = 0;
        }

        Queue<T>* insert(T value){

            if(isFull()){
                //cout<<"La coda e` piena."<<endl;
                return this;
            } 

            else if(isEmpty()){
                head=0;
            }

            queue[++tail %= length] = value;
            nElem++;
            return this;
        }

        Queue<T>* dequeue(){

            
            if(isEmpty()){
                head=tail= -1;
                nElem=0;
                //cout<<"La coda e` vuota."<<endl;
                return this;
            }

            head++;
            head %= length;
            nElem--;
            return this;

        }

        int isFull() const {
            return (nElem == length);
        }

        int isEmpty() const {
            //cout<<"Head: "<<head<<endl<<"Tail: "<<tail<<endl;
            
            return (head == tail);
        }

        friend ostream& operator<<(ostream& os, const Queue& q){
            for(int i=q.head; i<q.head+q.nElem;i++){
                os<<" <-- "<<q.queue[i%q.length];
            }
            os<<endl;
            os<<"Coda di lunghezza " << q.length<<endl;
            os<<"Numero elemnti: " << q.nElem<<endl;
            for(int i=0; i<q.length; i++){
                os<<"      "<<q.queue[i%q.length];
                if(i==q.head) os<<" <-- head";
                if(i==q.tail) os<<" <-- tail";
                os<<endl;
            }
            return os;
        }
};

int main(){
    Queue<int> q(4);
    //q.insert(1)->insert(2)->insert(4)->insert(3)->insert(5)->dequeue()->insert(10); 
    string command;
    int n;
    while(true){ 
        cout<<"Inserisci comando: ";
        cin>>command;
        if(command=="i"){
            cout<<endl<<"Inserisci numero: ";
            cin>>n;
            q.insert(n);
        }
        else if(command=="d") q.dequeue();
        cout<<endl<<q;
    }

}