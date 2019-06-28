#include <iostream>
#include <string.h>
using namespace std;

class Actor{
    private:
        int id;
        string nombre;
    public:
        Actor();
        Actor(int, string);
        int getID();
        string getNombre();
        void setID(int);
        void setNombre(string);
        void toString();
};
Actor::Actor(){
    id=0;
    nombre="Diego Luna";
}
Actor::Actor(int i, string n){
    id=i;
    nombre=n;
}
int Actor::getID(){
    return id;
}
string Actor::getNombre(){
    return nombre;
}
void Actor::setID(int i){
    id=i;
}
void Actor::setNombre(string n){
    nombre=n;
}
void Actor::toString(){
    cout << "Actor: " << nombre << " ID: " << id << endl;
}
