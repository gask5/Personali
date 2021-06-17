#ifndef NODEP_H
#define NODEP_H

#include "player.h"

class NodeP{
        private: 
                Player p;
                NodeP *next, *prev;
        
        public: 
                NodeP(Player _p, NodeP *_next = NULL, NodeP *_prev = NULL) : p(_p), next(_next), prev(_prev){};

                void setNext(NodeP *_next){ next=_next; }

                void setPrev(NodeP *_prev){ prev=_prev; }

                void setPlayer(Player _player){ p=_player;}


                Player getPlayer() const { return p; }
                NodeP *getNext() const { return next; }
                NodeP *getPrev() const { return prev; }

                friend bool operator<(const NodeP& n, const NodeP& n2){
                        return (n.p.getPunteggio()<n2.p.getPunteggio()?1:0);
                }

                friend bool operator>(const NodeP& n, const NodeP& n2){
                        return (n.p.getPunteggio()>n2.p.getPunteggio()?1:0);
                }



};

#endif