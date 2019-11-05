#ifndef _Bolsa_Letras_h
#define _Bolsa_Letras_h

#include <vector>
#include "conjunto_letras.h"

class Bolsa_Letras{
    private:
        vector<char> letras;
    public:
        Bolsa_Letras();
        void setBolsa(const Conjunto_Letras &c);
        string sacaLetras(int n);
        int size()const;
};
#endif //_Bolsa_letras_h