#include "veicolo.hpp"

class Moto : public Veicolo{
    public:
        Moto(int _velocitaMassima, unsigned int _prezzo, string _marca, string _motorizzazione, string _carburante) : 
            Veicolo(2, _velocitaMassima, _prezzo, _marca, _motorizzazione, _carburante){}

        string toString() const {
            stringstream stream;
            stream << "Questa e` una moto."<<endl<< "Ha " << numeroRuote << " ruote." << endl << "Velocita` massima: " << velocitaMassima << endl
             << "Marca: " << marca << endl <<"Motorizzazione: " << motorizzazione << endl << "Carburante: " << carburante << endl;
            return stream.str();
        }


};