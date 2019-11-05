#ifndef _Diccionario_h
#define _Diccionario_h
#include <set>
#include <vector>
#include <string>
using namespace std;

class Diccionario{
private:
    set<string> datos;
public:
    /**
    @brief Construye un diccionario vacío.
    **/
    Diccionario();
    /**
    @brief Devuelve el numero de palabras en el diccionario
    **/
    int size() const;
    /**
    @brief Obtiene todas las palabras en el diccionario de un longitud dada
    @param longitud: la longitud de las palabras de salida
    @return un vector con las palabras de longitud especifica en el parametro de entrada
    **/
    vector<string> palabrasLongitud(int longitud)const;
    /**
    @brief Indica si una palabra está en el diccionario o no
    @param palabra: la palabra que se quiere buscar
    @return true si la palabra esta en el diccionario. False en caso contrario
    **/
    bool esta(string palabra);
    /**
    @brief Lee de un flujo de entrada un diccionario
    @param is:flujo de entrada
    @param D: el objeto donde se realiza la lectura.
    @return el flujo de entrada
    **/
    friend istream& operator>>(istream & is,Diccionario &d);
    /**
    @brief Escribe en un flujo de salida un diccionario
    @param os:flujo de salida
    @param D: el objeto diccionario que se escribe
    @return el flujo de salida
    **/
    friend ostream& operator<<(ostream & os, const Diccionario &d);
    /**
  * @brief Iterador de Diccionario
  */
    typedef set<string>::iterator iterator;
/**
  * @brief Iterador constante de Diccionario
  */
    typedef set<string>::const_iterator const_iterator;
/**
  * @brief Comienzo del iterador 
  * @return Devuelve un iterador de Diccionario apuntando a la primera posicion del conjunto de palabras
  */
    Diccionario::iterator begin();
/**
  * @brief Comienzo del iterador constante
  * @return Devuelve un iterador constante de Diccionario apuntando a la primera posicion del conjunto de palabras
  */
    Diccionario::const_iterator begin() const;
/**
  * @brief Fin del iterador
  * @return Devuelve un iterador de Diccionario apuntando a la ultima posicion del conjunto de palabras
  */
    Diccionario::iterator end();
/**
  * @brief Fin del iterador constante
  * @return Devuelve un iterador constante de Diccionario apuntando a la ultima posicion del conjunto de palabras
  */
    Diccionario::const_iterator end() const;
};

istream& operator>>(istream & is,Diccionario &d);

ostream& operator<<(ostream & os, const Diccionario &d);

#endif //_Diccionario_h