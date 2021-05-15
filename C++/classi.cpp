#include <iostream>

using namespace std;

class Mammifero{
    protected:
        string nome; //Questi si chiamano ATTRIBUTI e NON PROPRIETA'
        char sesso;
        int eta;
    public: //QUESTI SI CHIAMANO METODI
        Mammifero(string n, char s, int _eta){
            nome = n;
            sesso = s;
            eta = _eta;
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
};


int main(){
    Mammifero m1= Mammifero("Gigi",'m',20);
    m1.print();
    Cane c1=Cane("Billy",'m',3,"Pastore Tedesco");
    c1.print();
    c1.abbaia();
    cout<<m1;
}