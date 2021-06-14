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

        Nodo<T>* getNext() const {
            return this->next;
        }

        void setPrev(Nodo* _prev){
            this->prev = _prev;
        }

        Nodo<T>* getPrev() const {
            return this->prev;
        }

        void setValore(T _valore){
            delete this->valore;
            valore = new T (_valore);
        }

        T getValore() const {
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
            Nodo<T>* succ = head;
            //cout<<"Riga 97";
            while(succ && succ->getValore()<valore){
                //cout<<valore<<" < "<<attuale->getValore()<<endl;
                prec=succ;
                succ=succ->getNext();
            }
            //cout<<"Riga 102";

            if(prec){
                prec->setNext(tmp);    
                tmp->setPrev(prec);
            }
            else head=tmp;

            if(succ){
                tmp->setNext(succ);
                succ->setPrev(tmp);
            }
            else{
                current=tmp;
            }


            return this;
        }

        Lista<T>* deleteValue(T valore){
            Nodo<T>* tmp = head;
            while(tmp->getNext() && tmp->getValore()!= valore){
                tmp=tmp->getNext();
            }
           
            if(tmp->getValore()==valore){
                
                if(tmp==head){
                    //cout<<"Trovato nodo in head"<<endl;
                    head = tmp->getNext();
                    head->setPrev(NULL);
                    delete tmp;
                } 
                else if(tmp==current){
                    //cout<<"Trovato nodo in current"<<endl;
                    current=tmp->getPrev();
                    current->setNext(NULL);
                    delete tmp;
                }
                else{
                    //cout<<"Trovato nodo in mezzo"<<endl;
                    tmp->getPrev()->setNext(tmp->getNext());
                    tmp->getNext()->setPrev(tmp->getPrev());
                    delete tmp;
                }
                cout<<"Cancellato nodo con valore "<<valore<<endl;
                return this;
            }
            cout<<"Nessun nodo con valore "<< valore << " trovato."<<endl;
            return this;
        }

        void stampa() const {
            stampa(head);
            cout<<endl;
        }

        void stampa3() const {
            stampa3(current);
            cout<<endl;
        }

        void stampa(Nodo<T>* n) const {
            if(!n){ return; }
            cout<<"Nodo "<<n<<" con valore: "<<n->getValore()<<", next = " << n->getNext() << " prev = " << n->getPrev()<<endl;
            stampa(n->getNext());
        }

        void stampa3(Nodo<T>* n) const {
            if(!n){ return; }
            cout<<n->getValore()<<" ";
            stampa(n->getPrev());
        }

        void stampa2() const {
            stampa2(current);
            cout<<endl;
        }

        void stampa2(Nodo<T>* n) const {
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
    ls->insertInOrder(5)->insertInOrder(3)->insertInOrder(4)->insertInOrder(10)->insertInOrder(1);
    //ls->deleteValue(10)->deleteValue(1)->deleteValue(3)->deleteValue(4);
    ls->stampa();
    

}