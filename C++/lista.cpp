#include <iostream> 
#include <cstdlib>

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

        friend int operator>(const Nodo<T>& n1, const Nodo<T>& n2){
            return n1->getValore()>n2->getValore()? 1 : 0;
        }

        friend int operator<(const Nodo<T>& n1, const Nodo<T>& n2){
            return n1->getValore()<n2->getValore()? 1 : 0;
        }

        friend int operator==(const Nodo<T>& n1, const Nodo<T>& n2){
            return n1->getValore()==n2->getValore()? 1 : 0;
        }

        friend int operator>=(const Nodo<T>& n1, const Nodo<T>& n2){
            return n1->getValore()>=n2->getValore()? 1 : 0;
        }

        friend int operator<=(const Nodo<T>& n1, const Nodo<T>& n2){
            return n1->getValore()<=n2->getValore()? 1 : 0;
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

        Lista* insertInOrder(T valore){
            //cout<<"Inserisco "<<valore<<endl;
            if(!head){
                head = current = new Nodo<T>(valore);
                return this;
            }
            Nodo<T>* tmp = new Nodo<T>(valore); 
            Nodo<T>* prec = NULL;
            Nodo<T>* attuale = head;
            //cout<<"Riga 97";
            while(attuale&&attuale->getValore()<valore){
                //cout<<valore<<" < "<<attuale->getValore()<<endl;
                prec=attuale;
                attuale=attuale->getNext();
            }
            //cout<<"Riga 102";

            if(prec){
                prec->setNext(tmp);    
                tmp->setPrev(prec);
            }
            else head=tmp;

            if(attuale){
                tmp->setNext(attuale);
                attuale->setPrev(tmp);
            }

            return this;
        }

        void stampa(){
            stampa(head);
            cout<<endl;
        }

        void stampa3(){
            stampa3(current);
            cout<<endl;
        }

        void stampa(Nodo<T>* n){
            if(!n){ return; }
            cout<<n->getValore()<<" ";
            stampa(n->getNext());
        }

        void stampa3(Nodo<T>* n){
            if(!n){ return; }
            cout<<n->getValore()<<" ";
            stampa(n->getPrev());
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
    Lista<int>* ls = new Lista<int>;
    for(int i=0;i<10;i++){
        ls->insertInOrder(rand()%100+1);
    }
    ls->stampa();
    

}