#include "iostream"
#include <sstream>
using namespace std;

#ifndef VEICOLO_HPP //evita di ridefinire la classe se e` inclusa in piu` file
#define VEICOLO_HPP //se non e` stato mai definito, cio` che va da riga 5 , fino ad #endif



class Veicolo{
    protected:
        int numeroRuote;
        int velocitaMassima;
        int velocita;
        unsigned int prezzo;
        string marca;
        string carburante;
        string motorizzazione;

    public:
        Veicolo(int _numeroRuote, int _velocitaMassima, unsigned int _prezzo, string _marca, string _motorizzazione,string _carburante) :
                velocitaMassima(_velocitaMassima), prezzo(_prezzo), marca(_marca), motorizzazione(_motorizzazione), numeroRuote(_numeroRuote), carburante(_carburante) {}

        int getNumeroRuote(){ return numeroRuote; }
        int getVelocitaMassima(){ return velocitaMassima;}
        int getVelocita(){ return velocita; }
        unsigned int getPrezzo(){ return prezzo; }
        string getMarca(){ return marca;}
        string getCarburante(){ return carburante;}
        string getMotorizzazione(){ return motorizzazione;}

        void setNumeroRuote(int _numeroRuote){ numeroRuote = _numeroRuote; }
        //void setVelocita(int _velocita){ velocita =_velocita; }
        void setPrezzo(unsigned int _prezzo){ prezzo =_prezzo; }
        void setVelocitaMassima(int _velocitaMassima){ velocitaMassima = _velocitaMassima; }
        void setMarca(string _marca){ marca = _marca; }
        void setCarburante(string _carburante){ carburante = _carburante;}
        void setMotorizzazione(string _motorizzazione){ motorizzazione = _motorizzazione; }

        void accelera() {
            if(velocita<velocitaMassima) velocita++;
        }

        void decelera() {
            if(velocita>0) velocita--;
        }

        virtual string toString() const = 0;

        friend ostream& operator<<(ostream& os, const Veicolo& v){
            os << v.toString();
            return os;
        }

};

#endif