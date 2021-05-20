
#include <iostream>

class FormaGeometrica{ // classe astratta poiche` possiede almeno una classe puramente astratta

    public:
    
        virtual double perimetro() = 0; // <- - classe puramente astratta, se non viene ridefinita sulle classi derivate. Una  
        virtual double area() { return (0); }
        virtual std::string toString() { return ""; }
        friend std::ostream& operator<<(std::ostream& os, const FormaGeometrica& forma){ return os; }
    
};

