#include "tree.h"

int main(){
        Tree<int> t;
        
        // t.insert(10);
        // t.insert(15);
        // t.insert(20);
        // t.insert(25);
        // t.insert(5);
        // t.insert(2);
        // t.insert(7);
        // t.insert(9);
        // t.insert(1);
        // t.insert(13);

        for(int i=0; i<20 ; i++){
                t.insert(rand()%50+1);
        }

        cout<<"-----------BEFORE----------"<<endl;

        t.inOrder();

        for(int i=0; i<10 ; i++){
                t.canc(rand()%50+1);
        }

        cout<<"-----------AFTER----------"<<endl;
       

        t.inOrder();
}