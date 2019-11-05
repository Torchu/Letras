#include <iostream>
#include <fstream>
#include <queue>
#include <string.h>
#include "diccionario.h"
#include "conjunto_letras.h"
using namespace std;

int calcularFrecuencia(char l, const Diccionario &d){
    int frec=0;
    for(Diccionario::const_iterator it=d.begin(); it!=d.end(); ++it)
        for(int i=0; i<(*it).size(); i++)
            if(l==(*it)[i])
                frec++;
    return frec;
}

int main(int argc, char* argv[]){
    //Comprobacion de argumentos
    if(argc!=4){
        cerr<<"Sintaxis incorrecta: cantidad_letras <diccionario> <fichero_letras> <fichero_salida>"<<endl;
        return -1;
    }
    //Variables
    Diccionario dic;
    Conjunto_Letras misLetras;
    queue<double> fabs;
    int cont=0;
    //Cargamos el diccionario
    ifstream f1(argv[1]);
    if(!f1){
        cerr<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return -1;
    }
    f1>>dic;
    //Cargamos las letras del fichero
    ifstream f2(argv[2]);
    if(!f2){
        cerr<<"No puedo abrir el fichero "<<argv[2]<<endl;
        return -1;
    }
    f2>>misLetras;
    //Abrimos el fichero de salida
    ofstream f3(argv[3]);
    if(!f3){
        cerr<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return -1;
    }
    //Calculamos los datos
    for(Conjunto_Letras::const_iterator it=misLetras.begin(); it!=misLetras.end(); ++it){
        fabs.push(calcularFrecuencia(tolower((*it).getLetra()), dic));
        cont+=fabs.back();
    }
    f3<<"#Letra FAbs. Frel."<<endl;
    for(Conjunto_Letras::const_iterator it=misLetras.begin(); it!=misLetras.end(); ++it){
        f3<<(*it).getLetra()<<"\t"<<fabs.front()<<"\t"<<fabs.front()*100/cont<<endl;
        fabs.pop();
    }
    return 0;
}