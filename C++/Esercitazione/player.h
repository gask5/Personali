#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Player{
        private:
                string nome, cognome, circolo;
                double punteggio;
                int anno;
        
        public:

                
                Player(string _nome, string _cognome, string _circolo, double _punteggio, int _anno): nome(_nome), cognome(_cognome), circolo(_circolo), punteggio(_punteggio), anno(_anno){};

                Player(): Player("","","",0.0,0){};
                
                double getPunteggio() const {return punteggio;}

                string getCognome() const {return cognome; }

                


                friend ostream& operator<<(ostream& os, const Player& p){
                        cout<<"\e[1;31m"<<p.cognome<<"\e[0m"<<" "<<"\e[1;32m"<<p.nome<<"\e[0m"<<" "<<"\e[0;37m"<<p.circolo<<"\e[0m"<<" "<<"\e[0;33m"<<p.punteggio<<"\e[0m"<<" "<<"\e[1;35m"<<p.anno<<"\e[0m"<<endl;
                        return os;
                };

                friend istream& operator>>(istream& in, Player& p){
                        string punteggio_string, anno_string;
                        getline(in,p.cognome,';');
                        getline(in,p.nome,';');
                        getline(in,p.circolo,';');
                        getline(in,punteggio_string,';');
                        getline(in,anno_string,'\n');
                        p.punteggio = stod(punteggio_string);
                        p.anno = stoi(anno_string);
                        return in;
                }


};

#endif