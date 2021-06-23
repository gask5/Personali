#ifndef COLORS_H
#define COLORS_H

#include <sstream>
#include <string>

using namespace std;

template <class T>
string colors(T s, int n, int n2=0){
        stringstream ss;
        ss<< "\e["<<n2<<";3"<<n<<"m"<<" "<<s<<" "<<"\e[0m";
        return ss.str();
}

#endif