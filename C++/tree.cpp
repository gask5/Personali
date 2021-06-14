#include <iostream>
#include <cstdlib>
#include <windows.h> //not working on Linux

using namespace std;

static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
static int total = 0;
static int correct = 0;

template <class T>
class Node{
    private:
        T value;
        Node<T>* parent, *right, *left;
    
    public:
        Node(T _value) : value(_value){parent = right = left = NULL;}

        T getValue() const {
            if(!this) return NULL ;
            return value;
        }
        Node<T>* getParent() const {return parent;}
        Node<T>* getRight() const {return right;}
        Node<T>* getLeft() const {return left;}

        void setValue(T _value) {value = _value;}
        void setParent(Node<T>* _parent) {parent = _parent;}
        void setRight(Node<T>* _right) {right = _right;}
        void setLeft(Node<T>* _left) {left = _left;}

        ~Node<T>() {}

        friend ostream& operator<<(ostream& os,const Node<T>& n){ 
            
            os<<"Nodo: "<<&n << "   key = "<< n.value << " , left = " << n.left->getValue() << " , right = "<< n.right->getValue() << " , parent = "<< n.parent->getValue() ;
            if( (n.left && n.left->getValue()>= n.value) || (n.right && n.right->getValue() < n.value ) ){
               
                SetConsoleTextAttribute(hConsole, 12);
                cout << " ERROR " << endl;
                SetConsoleTextAttribute(hConsole, 7);
                }
            else {
                SetConsoleTextAttribute(hConsole, 10);
                cout<< " PASS " << endl;
                correct++;
                SetConsoleTextAttribute(hConsole, 7);
                }
            total++;
            return os;
        }

};

template <class T>
class BST{
    private:
        Node<T>* radice;
    public:
        BST(){ radice = NULL;}

        BST<T>* insert(T value){
            Node<T>* tmp = new Node<T>(value);
            Node<T>* ptr = radice;
            Node<T>* padre = ptr;
            if(!radice){
                radice = tmp;
                return this;
            }

            while(ptr){
                padre = ptr;
                if(value>= ptr->getValue()) {
                    ptr = ptr->getRight();
                }
                else ptr = ptr->getLeft();
            }
            
            if(value>=padre->getValue()) padre->setRight(tmp);
            else padre->setLeft(tmp);

            tmp -> setParent(padre);

            return this;
        }

        Node<T> *search(T key){
           return search(radice,key);
        }

        Node<T> *search(Node<T>* node ,T key){
            if(!node) return NULL;
            if(node->getValue()==key) return node;

            if(key > node->getValue()) search(node->getRight(),key);
            else  search(node->getLeft(),key);
        }

        BST<T>* canc(T key){
            Node<T>* tmp = search(key);
            if(tmp) canc(tmp,key);
            return this;
        }

        void canc(Node<T>* node, T key){
            // if(!node) return; <- controllo non necessario;
            if(node->getLeft()&&node->getRight()){
                Node<T>* successore = succ(node);

                node->setValue( successore-> getValue() );

                canc( successore, successore->getValue() );
            }

            else{
                
                Node<T>* child = node->getRight();
                if(!child) child = node->getLeft();

                Node<T>* padre = node->getParent();

                if(child) child ->setParent(padre);

                if(!padre) {
                    radice = child;
                    delete node;
                    return;
                }

                if(node->getValue() >= padre->getValue()) padre->setRight(child);
                else padre->setLeft(child);

                
                delete node;
                return;
                
            }
        }

        Node<T> *succ(Node<T>* node){
            if(node->getRight()) return minimo(node->getRight());
            
            Node<T>* p = node->getParent() ;
            while(p && node->getValue() > p->getValue()){
                p = p->getParent();
            }

            return p;
        }

    

        Node<T> *minimo(Node<T>* node){
            if(node->getLeft()) return minimo(node->getLeft());
            return node;
        }

        

        
        void print() const{
            print(radice);
            if(total==correct) SetConsoleTextAttribute(hConsole, 10);
            else SetConsoleTextAttribute(hConsole, 12);

            cout<<"Test "<< correct<<" / "<<total<<endl; 

            SetConsoleTextAttribute(hConsole, 7);

            total = correct = 0;
        }

        void print(Node<T> *node) const{
            if(!node) return;
            
            print(node->getLeft());
            cout<<*node;
            print(node->getRight());       
        }

        void postOrder(Node<T> *node) const{
            if(!node) return;
            
            postOrder(node->getLeft());
            
            postOrder(node->getRight());  

            cout<<*node;   
        }

        void postOrder() const{
            postOrder(radice);
        }

        
};

int main(){ 
    BST<float> tree;

    // tree.insert(10)->insert(20);

    for(int i = 0 ; i < 10 ; i++){
        tree.insert(rand()%50+1);
    }


    cout<<"--------------- Before ----------------"<<endl;
    tree.print();

    for(int i = 0 ; i < 100 ; i++){
        int n = rand()%50+1;
        //tree.canc(n);
    }

    // tree.canc(25);
    // tree.print();
    // tree.canc(20);
    
    cout<<endl<<"--------------- After ----------------"<<endl;
    tree.print();

    cout<<endl<<"--------------- END ----------------"<<endl;

    tree.postOrder();
}