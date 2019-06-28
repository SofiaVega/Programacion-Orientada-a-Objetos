#include <iostream>
#include <string.h>
#include "Actor.h"
using namespace std;

class Pelicula{
    private:
        int numPeli;
        string titulo;
        int year;
        int duracion;
        string genero;
        int cantidadActores;
        int listaActores[10];
    public:
        Pelicula();
        int getNumPeli();
        string getTitulo();
        int getYear();
        int getDuracion();
        string getGenero();
        int getCantidad();
        void setNumPeli(int);
        void setTitulo(string);
        void setYear(int);
        void setDuracion(int);
        void setGenero(string);
        void toString();

        int getIDdeLista(int);
        bool nuevoActor(int);
};
Pelicula::Pelicula(){
    numPeli=0;
    titulo="Atlantis";
    year=2019;
    duracion=120;
    genero="Accion";
    cantidadActores=0;
}
int Pelicula::getNumPeli(){
    return numPeli;
}
string Pelicula::getTitulo(){
    return titulo;
}
int Pelicula::getYear(){
    return year;
}
int Pelicula::getDuracion(){
    return duracion;
}
string Pelicula::getGenero(){
    return genero;
}
int Pelicula::getCantidad(){
    return cantidadActores;
}
void Pelicula::setNumPeli(int n){
    numPeli=n;
}
void Pelicula::setTitulo(string t){
    titulo=t;
}
void Pelicula::setYear(int y){
    year=y;
}
void Pelicula::setDuracion(int d){
    duracion=d;
}
void Pelicula::setGenero(string g){
    genero=g;
}
int Pelicula::getIDdeLista(int id){
    return listaActores[id];
}
bool Pelicula::nuevoActor(int a){
    if(cantidadActores>=10){
        cout << "No se pueden agregar más actores.\n";
        return false;
    }
    for(int i=0; i<cantidadActores;i++){
        if(listaActores[i]==a){
            cout << "Ese actor ya existe.\n";
            return false;
        }
    }
    listaActores[cantidadActores]=a;
    cantidadActores++;
    return true;
}
void Pelicula::toString(){
    cout << "Titulo: " << titulo << endl;
    cout << " Año: " << year;
    cout << " Duracion: " << duracion;
    cout << " Genero: " << genero << endl;
    cout << "Actores: " << endl;
    /*for(int i=0; i<cantidadActores; i++){
        cout << i+1 << ". " << listaActores[i] << endl;
    }*/
}