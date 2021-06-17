#include "dllist.h"

static void load(Lista& l, string filename){
        ifstream ifs(filename, ifstream::in);
        while(ifs.good()){
                Player p;
                ifs >> p;
                l.insert(p);
        }
        ifs.close();
}

static void print(Lista& l, bool ascend){
        if(!ascend){
                cout<<"-------STAMPA DECRESCENTE-------"<<endl;
                cout<<l;
        }
        else{
                cout<<"--------STAMPA CRESCENTE-------"<<endl;
                NodeP* tmp = l.getTail();
                while(tmp){
                        cout<<tmp->getPlayer();
                        tmp=tmp->getPrev();
                }
        }
        cout<<endl;
}

static void printBySurname(Lista& l, string surname){
        NodeP* tmp = l.getHead();
        
        while(tmp->getPlayer().getCognome() != surname )
        {
                tmp=tmp->getNext();
        }
        if(!tmp) return;

        double score = tmp->getPlayer().getPunteggio();

        tmp=l.getHead();
        while(tmp && tmp->getPlayer().getPunteggio()>= score)
        {
                if(tmp->getPlayer().getPunteggio()== score) cout<< tmp->getPlayer();
                tmp=tmp->getNext();
        }
}

int main(){
        // Player p1("Carlo","Miraglia","Chiazza",123,1996);
        // Player p2("Giorgio","Gaber","Castello",125,1997);
        // Player p3("Mark","Ruffalo","Casale",120,1997);
        // Player p4("Frank","Ruffalo","Casale",121,1997);
        Lista l1;
        // l1.insert(p1);
        // l1.insert(p2);
        // l1.insert(p3);
        // l1.insert(p4);

        load(l1,"punteggi.txt");
        // cout<<l1;     

        print(l1,true);

        print(l1,false);

        printBySurname(l1,"FLORIOLI");



}