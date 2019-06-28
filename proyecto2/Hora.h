#include <iostream>
#include <string.h>
using namespace std;

class Hora{
    private:
        int hh;
        int mm;

    public:
        Hora();
        Hora(int, int);
        int getH();
        int getM();
        void setH(int);
        void setM(int);
        void toString();
        friend bool operator==(Hora, Hora);
};
Hora::Hora(){
    hh=0;
    mm=0;
}
Hora::Hora(int h, int m){
    hh=h;
    mm=m;
}
int Hora::getH(){
    return hh;
}
int Hora::getM(){
    return mm;
}
void Hora::setH(int h){
    hh=h;
}
void Hora::setM(int m){
    mm=m;
}
void Hora::toString(){
    if(hh<10){
    cout << "0";
  }
  cout << hh << ":";
  if(mm<10){
    cout << "0";
  }
  cout << mm << endl;
}
bool operator==(Hora h1, Hora h2){
    if(h1.hh!=h2.hh){
        return false;
    }
    if(h1.mm!=h2.mm){
        return false;
    }
    return true;
}