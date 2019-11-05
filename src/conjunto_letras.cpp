#include <string>
#include "conjunto_letras.h"

Conjunto_Letras::Conjunto_Letras(){}

int Conjunto_Letras::getPuntuacion(char letra)const{
    for(Conjunto_Letras::const_iterator it=begin(); it!=end(); ++it){
        if(letra==tolower((*it).getLetra()))
            return (*it).getPuntuacion();
    }
    return 0;
}

Conjunto_Letras::iterator Conjunto_Letras::begin(){
    return letras.begin();
}

Conjunto_Letras::const_iterator Conjunto_Letras::begin()const{
    return letras.begin();
}

Conjunto_Letras::iterator Conjunto_Letras::end(){
    return letras.end();
}

Conjunto_Letras::const_iterator Conjunto_Letras::end()const{
    return letras.end();
}

istream& operator>>(istream &is, Conjunto_Letras &c){
    string chain;
    Letra aux;
    is>>chain>>chain>>chain;
    while(is.peek()!=EOF){
        is>>aux;
        c.letras.insert(aux);
    }
    return is;
}

ostream& operator<<(ostream &os, Conjunto_Letras &c){
    os<<"#Letra Cantidad Puntos";
    for(Conjunto_Letras::const_iterator it=c.begin(); it!=c.end(); ++it)
        os<<*it;
    return os;
}