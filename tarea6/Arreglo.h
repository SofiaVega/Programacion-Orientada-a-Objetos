#include <iostream>
#include <string.h>
#include <unordered_set>
#include <set>
using namespace std;

class Arreglo{
    private:
        int *iArr;
        int Cap;
    public:
        Arreglo();
        Arreglo(int);
        int getPointer();
        int getCap();
        void setPointer(int*);
        void setCap(int);
        int length();
        void ordena(char);
        int cuenta(int);
        Arreglo copia(int*);
        int busca(int);
        double promedio();
        void borrar();
        void llenar();
        bool actualiza(int, int);
        void toString();
};
Arreglo::Arreglo(){
    Cap=20;
    iArr=new int[Cap];
}
Arreglo::Arreglo(int cap){
    Cap=cap;
    iArr=new int[Cap];
}
int Arreglo::getPointer(){
    return *iArr;
}
int Arreglo::getCap(){
    return Cap;
}
void Arreglo::setPointer(int* p){
    iArr=p;
}
void Arreglo::setCap(int c){
    Cap=c;
}
int Arreglo::length(){
    return Cap;
}
void Arreglo::ordena(char c){
    if(c=='m'){
        set<int>s;
        for(int i=0; i<Cap; i++){
            s.insert(iArr[i]);
        }
        int x=0;
        int y;
        set<int>::iterator it;
        for(it=s.begin(); it!=s.end(); ++it){
            y=*it;
            iArr[x]= y;
            x++;
        }
    }else if(c=='M'){
        set<int, greater<int> >s;
        for(int i=0; i<Cap; i++){
            s.insert(iArr[i]);
        }
        int x=0;
        int y;
        set<int>::iterator it;
        for(it=s.begin(); it!=s.end(); ++it){
            y=*it;
            iArr[x]= y;
            x++;
        }
    }
}
void Arreglo::llenar(){
    for(int i=0; i<Cap; i++){
        cout << i << " ";
        cin>>iArr[i];
    }
}
int Arreglo::cuenta(int x){
    int cont=0;
    for(int i=0; i<Cap; i++){
        if(iArr[i]==x){
            cont++;
        }
    }
    return cont;
}
Arreglo Arreglo::copia(int *ap){
    ap=iArr;
    Arreglo *ap2;
    ap2=new Arreglo(Cap);
    ap2->setPointer(ap);
    return *ap2;
}
int Arreglo::busca(int x){
    int indice=-1;
    for(int i=0; i<Cap; i++){
        if(iArr[i]==x){
            indice=i;
            i=Cap;
        }
    }
    return indice;
}
double Arreglo::promedio(){
    double sum;
    for(int i=0; i<Cap; i++){
        sum+=iArr[i];
    }
    return sum/Cap;
}
void Arreglo::borrar(){
    for(int i=0; i<Cap; i++){
        iArr[i]=0;
    }
    //idk
}
bool Arreglo::actualiza(int n, int i){
    if(Cap-1<=i){
        iArr[i]=n;
        return true;
    }
    return false;
}
void Arreglo::toString(){
    for(int i=0; i<Cap; i++){
        cout << i << ": " << iArr[i] << endl;
    }
}