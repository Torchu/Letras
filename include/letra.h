#ifndef _Letra_h
#define _Letra_h

#include <iostream>
using namespace std;

class Letra{
    private:
        char letra;
        int apariciones;
        int puntuacion;
    public:
        Letra();
        char getLetra()const;
        int getApariciones()const;
        int getPuntuacion()const;
        bool operator<(const Letra &l)const;
        friend istream& operator>>(istream &is, Letra &l);
        friend ostream& operator<<(ostream &os, const Letra &l);
};
istream& operator>>(istream &is, Letra &l);
ostream& operator<<(ostream &os, const Letra &l);

#endif //_Letra_h