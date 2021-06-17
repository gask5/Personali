#ifndef DLLIST_H
#define DLLIST_H
#include "nodeP.h"

class Lista{
        private:
                NodeP* head, *tail;
        
        public:
                Lista(): head(NULL), tail(NULL) {};

                void insert(Player p){
                        NodeP* node = new NodeP(p);
                        if(!head){
                                head = tail = node;
                                return;
                        }

                        NodeP *tmp = head;

                        while(tmp && *node < *tmp){
                                tmp=tmp->getNext();
                        }

                        if(!tmp){
                                tail->setNext(node);
                                node->setPrev(tail);
                                tail=node;
                                return;
                        }
                        
                        if(tmp->getPrev()){
                                node->setPrev(tmp->getPrev());
                                tmp->getPrev()->setNext(node);
                        } 
                        else head=node;

                        tmp->setPrev(node);
                        node->setNext(tmp);

                        return;
                }

                void canc(double score){
                        NodeP* tmp = head;
                        while(tmp && tmp->getPlayer().getPunteggio() >= score){
                                if(tmp->getPlayer().getPunteggio()== score) cancNode(tmp);
                                tmp=tmp->getNext();
                        }
                }

                void cancNode(NodeP* node){
                        if(node!=head){
                                node->getPrev()->setNext(node->getNext());
                        }
                        else head=node->getNext();

                        if(node!=tail) node->getNext()->setPrev(node->getPrev());
                        else tail=node->getPrev();

                        delete node;
                }

                NodeP* getTail() const { return tail; }
                NodeP* getHead() const { return head; }

                friend ostream& operator<<(ostream& os, const Lista& lista){
                        NodeP *tmp =lista.head;
                        while(tmp){
                                cout<<tmp->getPlayer();
                                tmp=tmp->getNext();
                        }
                        return os;
                }
};
#endif