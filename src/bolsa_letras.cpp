#include <stdlib.h>
#include <cassert>
#include <string>
#include "bolsa_letras.h"

Bolsa_Letras::Bolsa_Letras(){}

void Bolsa_Letras::setBolsa(const Conjunto_Letras &c){
    for(Conjunto_Letras::const_iterator it=c.begin(); it!=c.end(); ++it)
        for(int i=0; i<(*it).getApariciones(); i++)
            letras.push_back((*it).getLetra());
}

string Bolsa_Letras::sacaLetras(int n){
    assert(n<=letras.size());
    char out[n];
    int aux;
    for(int i=0; i<n; i++){
        srand(time(NULL));
        aux=rand()%letras.size();
        out[i]=letras[aux];
        letras.erase(letras.begin()+aux);
    }
    out[n]='\0';
    return string(out);
}

int Bolsa_Letras::size()const{
    return letras.size();
}