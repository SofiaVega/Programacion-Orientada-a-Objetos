#include <iostream>
#include <string.h>
#include "Hora.h"
#include "Pelicula.h"
using namespace std;

class Funcion{
    private:
        string cveFuncion;
        int numPeli;
        Hora hora;
        int sala;
    public:
        Funcion();
        Funcion(string, int, Hora, int);
        string getCVE();
        int getNum();
        Hora getHora();
        int getSala();
        void setCVE(string);
        void setNum(int);
        void setHora(Hora);
        void setSala(int);
        void toString();
};
Funcion::Funcion(){
    cveFuncion="A";
    numPeli=0;
    hora.setH(0);
    hora.setM(0);
    sala=1;
}
Funcion::Funcion(string c, int n, Hora h, int s){
    cveFuncion=c;
    numPeli=n;
    hora=h;
    sala=s;
}
string Funcion::getCVE(){
    return cveFuncion;
}
int Funcion::getNum(){
    return numPeli;
}
Hora Funcion::getHora(){
    return hora;
}
int Funcion::getSala(){
    return sala;
}
void Funcion::setCVE(string c){
    cveFuncion=c;
}
void Funcion::setNum(int n){
    numPeli=n;
}
void Funcion::setHora(Hora h){
    hora=h;
}
void Funcion::setSala(int s){
    sala=s;
}
void Funcion::toString(){
    cout << "Clave: " << cveFuncion << endl;
    //cout << "Pelicula: " << numPeli << endl;
    cout << "Hora: ";
    hora.toString();
    cout << "Sala: " << sala << endl;
}