#include <iostream> 

using namespace std;

template<class T> class Nodo{
    private:
        T* valore;
        Nodo<T>* next;
        Nodo<T>* prev;
    public:
        Nodo(T _valore){
            this->valore = new T (_valore);
            next = prev = NULL;
        }

        void setNext(Nodo* _next){
            this->next = _next;
        }

        Nodo<T>* getNext(){
            return this->next;
        }

        void setPrev(Nodo* _prev){
            this->prev = _prev;
        }

        Nodo<T>* getPrev(){
            return this->prev;
        }

        void setValore(T _valore){
            delete this->valore;
            valore = new T (_valore);
        }

        T getValore(){
            return *valore;
        }

};

template<class T>
class Lista{

    private:
        Nodo<T>* head;
        Nodo<T>* current;

    public:
        Lista(){ 
            head = current = NULL;
        }

        Lista* insert(T valore){
            if(!head){
                head = current = new Nodo<T>(valore);
                return this;
            }
            Nodo<T>* tmp = new Nodo<T>(valore); 
            tmp->setPrev(current);
            current->setNext(tmp);
            current = tmp;
            return this;
        }

        void stampa(){
            stampa(head);
            cout<<endl;
        }

        void stampaL(){
            stampaL(head);
        }

        void stampaL(Nodo<T>* l){
            if(!l){ return; }
            l->getValore()->stampa();
            stampaL(l->getNext());
        }

        void stampa(Nodo<T>* n){
            if(!n){ return; }
            cout<<n->getValore()<<" ";
            stampa(n->getNext());
        }

        void stampa2(){
            stampa2(current);
            cout<<endl;
        }

        void stampa2(Nodo<T>* n){
            if(!n){ return; }
            cout<<n->getValore()<<" ";
            stampa2(n->getPrev());
        }
};

template<class T>
ostream& operator<<(ostream& os, const Lista<T>& l){
    l->stampa();
    return os;
}

int main(){
    Lista<Lista<int>*>* ls = new Lista<Lista<int>*>;
    for(int i =0 ; i < 100 ; i++){
        Lista<int>* tmp = new Lista<int>;
        for(int j=0; j<50 ;j++ ){
            tmp->insert(j);
        }
        ls->insert(tmp);
    }

    ls->stampaL();
}