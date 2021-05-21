#include "veicolo.hpp"

class Auto : public Veicolo{
     Auto(int _velocitaMassima, unsigned int _prezzo, string _marca, string _motorizzazione, string _carburante) : 
            Veicolo(4, _velocitaMassima, _prezzo, _marca, _motorizzazione, _carburante){}

        string toString() const {
            stringstream stream;
            stream << "Questa e` un'auto."<<endl<< "Ha " << numeroRuote << " ruote." << endl << "Velocita` massima: " << velocitaMassima << endl
             << "Marca: " << marca << endl <<"Motorizzazione: " << motorizzazione << endl << "Carburante: " << carburante << endl;
            return stream.str();
        }

        friend ostream& operator<<(ostream& os, const Veicolo& v){
            os << v.toString();
            return os;
        }
}