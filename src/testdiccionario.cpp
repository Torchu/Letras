#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "diccionario.h"

int main(int argc, char *argv[]){
    if(argc!=2){
        cout<<"Los parametros son:"<<endl;
        cout<<"1.-El fichero con las palabras";

        return -1;
    }
    ifstream f(argv[1]);
    if(!f){
        cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return -1;
    }
    Diccionario D;
    cout<<"Cargando diccionario..."<<endl;
    f>>D;
    cout<<"Leido el diccionario..."<<endl;
    cout<<D;

    int longitud;
    cout<<"Dime la longitud de las palabras que quieres ver: ";
    cin>>longitud;
    vector<string> v=D.palabrasLongitud(longitud);

    cout<<"Palabras de longitud "<<longitud<<endl;
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<endl;

    string p;
    cout<<"Dime una palabra: ";
    cin>>p;
    if(D.esta(p))
        cout<<"Esa palabra sí existe"<<endl;
    else
        cout<<"Esa palabra no existe"<<endl;
}