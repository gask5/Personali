#include <cstdlib>
#include "veicolo.hpp"
#include "auto.hpp"
#include "moto.hpp"

class Corsa{
    private:
        int durata;
        int nVeicoli;
        Veicolo** veicoli;
        unsigned int* distanzaVeicoli;
    public:
        Corsa(int _durata, int _nVeicoli) : durata(_durata), nVeicoli(_nVeicoli){
            veicoli = new Veicolo*[nVeicoli];
            distanzaVeicoli = new unsigned int[nVeicoli];
            for(int i = 0; i < nVeicoli; i++){
                distanzaVeicoli[i]=0;
                veicoli[i] = new Auto(rand()%20+1, rand()%20000 + 5000, "Auto", rand()%2001 + 500 + "cc", "A siccu");
            }
        }

        

        ~Corsa(){
            delete[] veicoli;
            delete[] distanzaVeicoli;
        }

        void stampaClassifica(){
            for(int i=0; i< nVeicoli ; i++){
                cout<< i+1 << " Classificato " << veicoli[i]->getVelocitaMassima() << " con " << distanzaVeicoli[i] << " distanza percorsa."<<endl;
            }
        }
        
        void sorpasso(int i, int j){
            cout << veicoli[i]->getVelocitaMassima() << " a distanza "<< distanzaVeicoli[i] << " sorpassa " 
                 << veicoli[j]->getVelocitaMassima()<< " a distanza "<< distanzaVeicoli[j] << endl;
            Veicolo* tmp = veicoli[j];
            veicoli[j] = veicoli[i];
            veicoli[i] = tmp;
            int tmp1 = distanzaVeicoli[j];
            distanzaVeicoli[j] = distanzaVeicoli[i];
            distanzaVeicoli[i] = tmp1;
        }

        void controlla(){ // bubblesort?
            for(int i = nVeicoli-1 ; i>0 ; i--)
                for(int j= i ; j>0  ; j--){
                    if(distanzaVeicoli[j]>distanzaVeicoli[j-1]){
                        sorpasso(j,j-1);
                    }
                }
            }



        void partenza(){
            for(int i=0; i<durata ; i++){
                for(int j=0; j<nVeicoli ; j++){
                    int random = rand()%2;
                    if(random==0) veicoli[j]->accelera();
                    else veicoli[j]->decelera();
                    distanzaVeicoli[j]+= veicoli[j]->getVelocita();
                }
                //cout<< "Turno: "<< i+1 << endl;

                controlla();
                //cout<<endl;
            }
            stampaClassifica();
        }  
};