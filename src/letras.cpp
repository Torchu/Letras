#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "bolsa_letras.h"
#include "diccionario.h"
using namespace std;

bool palabraCorrecta(string palabra, string letras){
    bool correcta=true, encontrada;
    int pos;
    for(int i=0; i<palabra.size() && correcta; i++){
        encontrada=false;
        pos=letras.find(palabra[i]);
        if(pos!=string::npos){
            letras.erase(pos,1);
        }else
            correcta=false;
    }
    return correcta;
}

string solucionLongitud(string letras, const Diccionario &d, int max){
    string ia_sol;
    vector<string> v;
    bool encontrada=false;
    for(int i=max; i>0 && !encontrada; i--){
        v=d.palabrasLongitud(i);
        for(int j=0; j<v.size(); j++){
            if(palabraCorrecta(v[j], letras)){
                cout<<v[j]<<"\tPuntuacion: "<<i<<endl;
                ia_sol=v[j];
                encontrada=true;
            }
        }
    }
    return ia_sol;
}

int calculaPuntos(string palabra, const Conjunto_Letras &c){
    int puntos=0;
    for(int i=0; i<palabra.size(); i++){
        puntos+=c.getPuntuacion(palabra[i]);
    }
    return puntos;
}

string solucionPuntuacion(string letras, const Diccionario &d, int max, const Conjunto_Letras &c){
    int maxP=0, ptos;
    vector<string> v;
    for(Diccionario::const_iterator it=d.begin(); it!=d.end(); ++it){
        if(palabraCorrecta((*it), letras) && (*it).size()<=max){
            ptos=calculaPuntos((*it), c);
            if(ptos>maxP){
                maxP=ptos;
                v.clear();
                v.push_back((*it));
            }
            else if(ptos==maxP)
                v.push_back((*it));
        }
    }
    for(vector<string>::const_iterator it=v.begin(); it!=v.end(); ++it)
        cout<<(*it)<<"\tPuntuacion: "<<maxP<<endl;
    return v.back();
}

int main(int argc, char *argv[]){
    //Comprobacion de argumentos
    if(argc!=5 || (strcmp(argv[4], "P")!=0 && strcmp(argv[4], "L")!=0)){
        cerr<<"Sintaxis incorrecta: ./letras <diccionario> <fichero_letras> <numero_letras> <modalidad (L/P)>"<<endl;
        return -1;
    }
    //Variables
    int nLetras=atoi(argv[3]);
    Diccionario dic;
    Conjunto_Letras misLetras;
    Bolsa_Letras bolsa;
    string letras, user_sol, ia_sol;
    int ptos;
    char opt='S';
    //Cargamos el diccionario
    ifstream f1(argv[1]);
    if(!f1){
        cerr<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return -1;
    }
    f1>>dic;
    //Cargamos las letras del fichero y creamos la bolsa
    ifstream f2(argv[2]);
    if(!f2){
        cerr<<"No puedo abrir el fichero "<<argv[2]<<endl;
        return -1;
    }
    f2>>misLetras;
    bolsa.setBolsa(misLetras);
    //Seccion interactiva
    while(opt=='S' || opt=='s'){
        //1ª Diferencia entre modos
        if(strcmp(argv[4], "P")==0){
            cout<<"******Puntuaciones Letras******"<<endl;
            for(Conjunto_Letras::const_iterator it=misLetras.begin(); it!=misLetras.end(); ++it)
                cout<<(*it).getLetra()<<"\t"<<(*it).getPuntuacion()<<endl;
        }
        cout<<"Las letras son: "<<endl;
        letras=bolsa.sacaLetras(nLetras);
        for(int i=0; i<nLetras; i++){
            cout<<letras[i]<<"\t";
            letras[i] = tolower(letras[i]);
        }
        cout<<"\nDime tu solucion: ";
        cin>>user_sol;
        if(dic.esta(user_sol) && palabraCorrecta(user_sol, letras))
            //2ª Diferencia entre modos
            ptos=(strcmp(argv[4], "P")==0)? calculaPuntos(user_sol, misLetras) : user_sol.size();
        else{
            cout<<"Solucion invalida. La palabra no es correcta o no se encuentra en el diccionario"<<endl;
            ptos=0;
        }
        cout<<user_sol<<"\tPuntuacion: "<<ptos<<endl<<"Mis soluciones son: "<<endl;
        //3ª Diferencia entre modos
        ia_sol=(strcmp(argv[4], "P")==0)? ia_sol=solucionPuntuacion(letras, dic, nLetras, misLetras) : solucionLongitud(letras, dic, nLetras);
        cout<<"Mejor solucion: "<<ia_sol<<endl;
        //Fin de programa o repeticion
        cout<<"¿Quieres seguir jugando[S/N]?";
        cin>>opt;
    }
}