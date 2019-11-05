#ifndef _Conjunto_Letras_h
#define _ConjuntoLetras_h

#include <set>
#include "letra.h"

class Conjunto_Letras{
    private:
        set<Letra> letras;
    public:
        Conjunto_Letras();
        int getPuntuacion(char letra)const;
        typedef set<Letra>::iterator iterator;
        typedef set<Letra>::const_iterator const_iterator;
        Conjunto_Letras::iterator begin();
        Conjunto_Letras::const_iterator begin()const;
        Conjunto_Letras::iterator end();
        Conjunto_Letras::const_iterator end()const;
        friend istream& operator>>(istream &is, Conjunto_Letras &c);
        friend ostream& operator<<(ostream &os, Conjunto_Letras &c);
};

istream& operator>>(istream &is, Conjunto_Letras &c);
ostream& operator<<(ostream &os, Conjunto_Letras &c);
#endif //_Conjunto_Letras_h