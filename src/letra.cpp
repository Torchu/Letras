#include "letra.h"

Letra::Letra(){
    letra = '0';
    apariciones = 0;
    puntuacion = 0;
}

char Letra::getLetra()const{
    return letra;
}

int Letra::getApariciones()const{
    return apariciones;
}

int Letra::getPuntuacion()const{
    return puntuacion;
}

bool Letra::operator<(const Letra &l)const{
    return (this->letra < l.letra);
}

istream& operator>>(istream &is, Letra &l){
    is>>l.letra>>l.apariciones>>l.puntuacion;
    return is;
}

ostream& operator<<(ostream &os, const Letra &l){
    os<<l.letra<<"\t"<<l.apariciones<<"\t"<<l.puntuacion<<endl;
    return os;
}