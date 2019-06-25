#include <iostream>
#include "Arreglo.h"
using namespace std;
int menu(){
    int op;
    cout << "Menu" << endl;
    cout << "1. Declarar el arreglo." << endl;
    cout << "2. Llenar el arreglo." << endl;
    cout << "3. Borrar el arreglo." << endl;
    cout << "4. Actualizar numero del arreglo." << endl;
    cout << "5. Buscar numero en el arreglo." << endl;
    cout << "6. Obtener el promedio" << endl;
    cout << "7. Length del arreglo" << endl;
    cout << "8. Ordenar arreglo" << endl;
    cout << "9. Cuenta numero en arreglo" << endl;
    cout << "10. Copiar arreglo" << endl;
    cout << "11. Mostrar el arreglo" << endl;
    cout << "12. Terminar el programa" << endl;
    cin >> op;
    return op;
}
int main(){
    int iOpcion, cap, x, y;
    char c;
    Arreglo *arr;
    Arreglo *arr2;
    arr=new Arreglo;
    int *nuevoPointer;
    arr2=new Arreglo;
    /* Arreglo *arr;
    Arreglo *arr2;
    int *apun;
    arr=new Arreglo(3);
    arr2=new Arreglo;
    //arr=new Reloj(iH, iM);
    arr->llenar();
    arr->ordena('M');
    *arr2=arr->copia(apun);
    arr2->toString();*/
    do{
        iOpcion=menu();
        if(iOpcion==1){
            cout << "Capacidad del arreglo: ";
            cin >> cap;
            arr=new Arreglo(cap);
        }else if(iOpcion==2){
            arr->llenar();
        }else if(iOpcion==3){
            arr->borrar();
        }else if(iOpcion==4){
            cout << "Indice a actualizar: ";
            cin >> x;
            cout << "Nuevo valor: ";
            cin >> y;
            if(arr->actualiza(y, x)){
                cout << "Correcto\n";
            }else{
                cout << "Incorrecto, prueba con otro indice.\n";
            }
        }else if(iOpcion==5){
            cout << "Numero a buscar: ";
            cin >> x;
            y=arr->busca(x);
            if(y==-1){
                cout << "No se encontro.\n";
            }else{
                cout << "Indice: " << y << endl;
            }
        }else if(iOpcion==6){
            cout << "Promedio: " << arr->promedio() << endl;
        }else if(iOpcion==7){
            cout << "Length: " << arr->length() << endl;
        }else if(iOpcion==8){
            do{
                cout << "Escribe 'm' para ordenar de menor a mayor, 'M' para lo contrario. Se alterará el arreglo actual. ";
                cin >> c;
            }while(c!='m'&&c!='M');
            arr->ordena(c);
        }else if(iOpcion==9){
            cout << "Numero a contar: ";
            cin >> x;
            cout << "Encontrado " << arr->cuenta(x) << " veces\n";
        }else if(iOpcion==10){
            *arr2=arr->copia(nuevoPointer);
            cout << "Nuevo arreglo:\n";
            arr2->toString();
        }else if(iOpcion==11){
            arr->toString();
        }
    }while(iOpcion!=12);
}