#include <iostream>
#include "Funcion.h"
#include <fstream>
using namespace std;
char menu(){
    char opcion;
    cout << "Menu:\n";
    cout << "a) Actores en lista: \n";
    cout << "b) Películas en lista: \n";
    cout << "c) Funciones disponibles: \n";
    cout << "d) Funciones por hora: \n";
    cout << "e) Funciones por clave: \n";
    cout << "f) Peliculas por actor: \n";
    cout << "g) Terminar programa: \n";
    cin >> opcion;
    return opcion;
}
int main(){
    ifstream actores;
    ifstream peliculas;
    bool noExiste;
    int i=0, idActor, num, year, dur, numActores, cantPelis=0, cantF, x;
    int h, m, sala;
    char opcion;
    Hora hora1;
    string nameActor, genero, titulo, cve;
    actores.open("Actores.txt");
    peliculas.open("Peliculas.txt");
    Actor listaActores[20];
    Funcion listaFunciones[20];
    Pelicula listaPelis[20];
    while(!actores.eof()&&i<20){
        actores >> idActor;
        actores.ignore();
        getline(actores,nameActor);
        listaActores[i].setID(idActor);
        listaActores[i].setNombre(nameActor);
        i++;
    }
    i=0;
    while(!peliculas.eof()&&cantPelis<20){
        peliculas >> num;
        peliculas >> year;
        peliculas >> dur;
        peliculas >> genero;
        peliculas >> numActores;
        for(int x=0;x<numActores;x++){
            peliculas >> idActor;
            listaPelis[cantPelis].nuevoActor(idActor);
        }
        peliculas.ignore();
        getline(peliculas,titulo);
        listaPelis[cantPelis].setNumPeli(num);
        listaPelis[cantPelis].setYear(year);
        listaPelis[cantPelis].setDuracion(dur);
        listaPelis[cantPelis].setGenero(genero);
        listaPelis[cantPelis].setTitulo(titulo);
        cantPelis++;
    }
    do{
        cout << "Ingresa el numero de funciones a agregar (max 20): \n";
        cin >> cantF;
    }while(cantF>=20&&cantF>0);
    for(i=0;i<cantF;i++){
        
        do{
            noExiste=true;
            cout << "Clave de funcion " << i+1 << " (irrepetible): ";
            cin >> cve;
            for(x=0; x<i; x++){
            if(listaFunciones[x].getCVE()==cve){
                cout << "Esa clave ya existe. Ingresa una nueva.\n";
                noExiste=false;
                x=i;
            }
        }
        }while(!noExiste);
        cout << "Numero de pelicula: ";
        cin >> num;
        cout << "Hora: ";
        cin >> h;
        cout << "Minuto: ";
        cin >> m;
        cout << "Sala: ";
        cin >> sala;
        hora1.setH(h);
        hora1.setM(m);
        listaFunciones[i].setCVE(cve);
        listaFunciones[i].setNum(num);
        listaFunciones[i].setHora(hora1);
        listaFunciones[i].setSala(sala);
    }
    do{
        opcion=menu();
        if(opcion=='a'){
            for(i=0; i<20; i++){
                listaActores[i].toString();
            }
        }else if(opcion=='b'){
            for(i=0; i<cantPelis; i++){
                listaPelis[i].toString();
                for(int x=0; x<listaPelis[i].getCantidad(); x++){
                    idActor=listaPelis[i].getIDdeLista(x);
                    for(int a=0; a<20; a++){
                        if(listaActores[a].getID()==idActor){
                            cout << listaActores[a].getNombre()<<endl;
                            a=20;
                        }
                    }
                }
            }
        }else if(opcion=='c'){
            for(i=0;i<cantF;i++){
                listaFunciones[i].toString();
                cout << "Película: ";
                num=listaFunciones[i].getNum();
                for(int a=0; a<20; a++){
                    if(listaPelis[a].getNumPeli()==num){
                        cout << listaPelis[a].getTitulo()<<endl << endl;
                        a=20;
                    }
                }
            }
        }else if(opcion=='d'){
            do{
            cout << "Hora: ";
            cin >> h;
            cout << "Minuto: ";
            cin >> m;
            }while(h>24||h<0||m>60||h<0);
            for(i=0;i<cantF;i++){
                if(listaFunciones[i].getHora().getH()==h&&listaFunciones[i].getHora().getM()==m){
                    num=listaFunciones[i].getNum();
                    for(int a=0; a<20; a++){
                        if(listaPelis[a].getNumPeli()==num){
                            cout << "Titulo: " << listaPelis[a].getTitulo()<< endl;
                            a=20;
                        }
                    }
                    cout << "Sala: " << listaFunciones[i].getSala() << endl;
                }
            }
        }else if(opcion=='e'){
            noExiste=true;
            cout << "Ingrese clave de funcion: ";
            cin >> cve;
            for(i=0;i<cantF;i++){
                if(listaFunciones[i].getCVE()==cve){
                    noExiste=false;
                    num=i;
                    i=cantF;
                }
            }
            if(noExiste){
                cout << "Clave inexistente.\n";

            }else{
                cout << "Numero de sala: " << listaFunciones[num].getNum() << endl;
                cout << "Titulo: ";
                x=listaFunciones[num].getNum();
                for(int a=0; a<20; a++){
                    if(listaPelis[a].getNumPeli()==x){
                        cout << listaPelis[a].getTitulo()<<endl << endl;
                        x=a;
                        a=20;
                    }
                }
                cout << "Hora: ";
                listaFunciones[num].getHora().toString();
                cout << "Duracion: " << listaPelis[x].getDuracion() << endl;
                cout << "Genero: " << listaPelis[x].getGenero() << endl;
                for(int a=0; a<listaPelis[x].getCantidad(); a++){
                    idActor=listaPelis[x].getIDdeLista(a);
                    for(int a=0; a<20; a++){
                        if(listaActores[a].getID()==idActor){
                            cout << listaActores[a].getNombre()<<endl;
                            a=20;
                        }
                    }
                }
            }
        }else if(opcion=='f'){
            noExiste=true;
            cout << "Ingresa ID de actor: ";
            cin >> idActor;
            for(i=0; i<20; i++){
                if(listaActores[i].getID()==idActor){
                    noExiste=false;
                }
            }
            if(noExiste){
                cout << "ID de actor inválido.\n";
            }else{
                for(i=0; i<cantPelis; i++){
                    for(x=0; x<listaPelis[i].getCantidad(); x++){
                        if(listaPelis[i].getIDdeLista(x)==idActor){
                            cout << "Titulo: " << listaPelis[i].getTitulo()<<endl;
                            cout << "Año: " << listaPelis[i].getYear()<<endl;
                            x=20;
                        }
                    }
                }
            }
        }
    }while(opcion!='g');
    return 0;
}