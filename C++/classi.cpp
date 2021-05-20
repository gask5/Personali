#include <iostream>

using namespace std;

class Mammifero{
    protected:
        string nome; //Questi si chiamano ATTRIBUTI e NON PROPRIETA'
        char sesso;
        int eta;
    public: //QUESTI SI CHIAMANO METODI
        Mammifero(string n, char s, int _eta) : nome(n), sesso(s), eta(_eta) {
        }

        void print(){ 
            cout<<"Questo mammifero si chiama "<<nome<<", ha " << eta << " anni ed e` di sesso ";
            if(sesso=='m') cout<<"maschile.";
            else cout<<"femminile.";
            cout<<endl;
        }

         string getNome(){ return nome; }

        
};

ostream& operator<<(ostream& os, Mammifero& m){
            os<<m.getNome();
            return os;
        }

class Cane : public Mammifero{
    private:
        string razza;
    public:
        Cane(string n, char s , int _eta , string _razza) : Mammifero(n, s, _eta){
            razza=_razza;
        }
        
        void print(){
            cout<<"Questo cane si chiama "<<nome<<", ha " << eta << " anni, e` di sesso ";
            if(sesso=='m') cout<<"maschile.";
            else cout<<"femminile.";
            cout<<"ed e` di razza "<<razza<<endl;
        }

        void abbaia(){
            cout<<nome+": Bau Bau"<<endl;
        }

        friend ostream& operator<<(ostream& os, Cane& m){
            os<<"Cane di razza " + m.razza << endl;
            return os;
        }


};

class Umano : public Mammifero{
    public:
        Umano(string n, char s , int _eta ) : Mammifero(n, s, _eta){
        }
        
        void print(){ //polimorfismo, viene rilevata in esecuzione 
            cout<<"Questo umano si chiama "<<nome<<", ha " << eta << " anni ed e` di sesso ";
            if(sesso=='m') cout<<"maschile.";
            else cout<<"femminile."<<endl;
        }

        void parla(){                                   //
            cout<<nome+": Ciao a tutti"<<endl;
        }

        void parla(string s){                           // overload dele metodo parla(), nello specifico e` un overload statico perche` viene rilevato a compile time, come anche l'identificazione
            cout<<nome+": "+s<<endl;
        }
};


int main(){
    //Mammifero e` un tipo di dato, m1 e` un'istanza di Mammifero
    Mammifero m1= Mammifero("Gigi",'m',20);
    m1.print();
    Cane c1=Cane("Billy",'m',3,"Pastore Tedesco");
    c1.print();
    c1.abbaia();
    Umano u1=Umano("Giorgia",'f',24);
    u1.print();
    u1.parla();
    u1.parla("Bumma tritolu!");

    cout<<c1<<endl;
}