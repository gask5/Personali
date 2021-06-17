#include "colors.h"
#include <iostream>
#include <cstdlib>

template <class T>
class Node{
        T value;
        Node<T>* left, *right, *parent;

        public:
                Node<T>(T value,Node<T> *left=NULL,Node<T> *right=NULL):value(value),left(left),right(right){};

                T getValue()const {
                        if(!this) return 0;
                        return value;
                }
                Node<T>* getLeft()const {return left;}
                Node<T>* getRight()const {return right;}
                Node<T>* getParent()const {return parent;}

                void setValue(T _value) {value=_value;}
                void setLeft(Node<T>* _left) {left=_left;}
                void setRight(Node<T>* _right) {right=_right;}
                void setParent(Node<T>* _parent) {parent=_parent;}

                friend ostream& operator<<(ostream& os,const Node<T>& node){
                        os<<colors("Node",1)<<&node
                        <<colors("Value:",2)<<node.value
                        <<colors("Left:",3)<<node.left->getValue()
                        <<colors("Right:",4)<<node.right->getValue()
                        <<colors("Parent: ",5)<< node.parent->getValue();
                        
                        if( (node.right && node.value > node.right->getValue()) || (node.left && node.value <= node.left->getValue()) ) os<< colors("ERROR",1);
                        else os<<colors("PASS",2);
                        os<<endl;
                        return os;
                }
};

template <class T>
class Tree{
        Node<T>* radice;

        public:
                Tree(){radice=NULL;}

                void insert(T value){
                        Node<T>* tmp = new Node<T>(value);
                        if(!radice){
                                radice=tmp;
                                return;
                        }

                        Node<T>* prev = radice;
                        Node<T>* current = prev;

                        while(current){
                                prev=current;
                                if(value >= current->getValue()) current=current->getRight();
                                else current=current->getLeft();
                        }

                        if(value >= prev->getValue()) prev->setRight(tmp);
                        else prev->setLeft(tmp);

                        tmp->setParent(prev);
                }

                Node<T>* search(T value){return search(value,radice);}

                Node<T>* search(T value, Node<T>* n) const {
                        if(value == n->getValue() || !n) return n;
                        if(value > n->getValue()) return search(value, n->getRight());
                        else return search(value, n->getLeft());
                }

                Node<T>* successore(Node<T>* n){
                        if(n->getRight()) return min(n->getRight());

                        Node<T>* padre = n->getParent();

                        while(padre && padre->getValue()<n->getValue()) padre=padre->getParent();
                        return padre;
                }

                Node<T>* min(Node<T>* n){
                        if(!n->getLeft()) return n;
                        return min(n->getLeft());
                }

                void canc(T value){
                        Node<T>* nd = search(value);
                        if(nd) canc(nd);
                }

                void canc(Node<T>* toDelete){
                        if(toDelete->getLeft() && toDelete->getRight()){                    // primo caso
                                Node<T>* succ = successore(toDelete);
                                toDelete->setValue(succ->getValue());
                                canc(succ);
                                return;
                        }

                        Node<T>* padre = toDelete->getParent();
                        Node<T>* child = toDelete->getRight();
                        if(!child) child = toDelete->getLeft();
                        if(child) child->setParent(padre);

                        
                        
                        if(!padre){ radice = child; ; return; }
                        
                        if(padre->getValue()>toDelete->getValue()) padre->setLeft(child);
                        else padre->setRight(child);

                        
                }
                void inOrder(){inOrder(radice);}
                void inOrder(Node<T>* n){
                        if(!n) return;
                        inOrder(n->getLeft());
                        cout<<*n;
                        inOrder(n->getRight());
                }
};