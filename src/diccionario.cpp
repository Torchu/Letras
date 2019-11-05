#include "diccionario.h"
#include <iostream>

Diccionario::Diccionario(){}

int Diccionario::size()const{
    return datos.size();
}

vector<string> Diccionario::palabrasLongitud(int longitud)const{
    vector<string> palabras;
    for(Diccionario::const_iterator it=begin(); it!=end(); ++it)
        if((*it).size()==longitud)
            palabras.push_back((*it));
    return palabras;
}

bool Diccionario::esta(string palabra){
    for(Diccionario::const_iterator it=begin(); it!=end(); ++it)
        if((*it)==palabra)
            return true;
    return false;
}

Diccionario::iterator Diccionario::begin(){
    return datos.begin();
}

Diccionario::const_iterator Diccionario::begin() const{
    return datos.begin();
}

Diccionario::iterator Diccionario::end(){
    return datos.end();
}

Diccionario::const_iterator Diccionario::end() const{
    return datos.end();
}

istream& operator>>(istream &is, Diccionario &d){
    string aux;
    while(is.peek()!=EOF){
        is>>aux;
        d.datos.insert(aux);
    }
    return is;
}

ostream& operator<<(ostream &os, const Diccionario &d){
    for(Diccionario::const_iterator it=d.begin(); it!=d.end(); ++it)
        os<<(*it)<<endl;
    return os;
}