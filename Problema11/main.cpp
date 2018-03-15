#include <iostream>

/*Escriba un programa que permita manejar las reservas de asientos en una sala de cine, los asientos de
la sala de cine están organizados en 15 filas con 20 asientos cada una. El programa debe mostrar una representación
de la sala que indique que asientos están disponibles y cuales se encuentran reservados. Además debe permitir
realizar reservas o cancelaciones al ingresar la fila (letras A-O) y el número del asiento (números 1-20).*/

using namespace std;

void reservas();
void cancelacion();
void asientos();

char matriz_asientos[15][20];
int main()
{
    //asientos();
    reservas();
    return 0;
}

void asientos(){

    for (int i=0;i<15;i++){
        for (int j=0;j<20;j++){
            matriz_asientos[i][j]='+';
        }
    }
    for (int i=0;i<15;i++){
        cout << char(65+i) << "  ";
        for (int j=0;j<20;j++){
            cout<<matriz_asientos[i][j]<<" ";
        }
        cout<<endl;
    }
}
void reservas(){
    char reserva[4];
    asientos();
    cout<<"\n\nEscriba el asiento que quiere reservar, siendo la letra la fila y el numero la columna: ";
    cin >> reserva;
    int fila,columna;

    fila = int(reserva[0]-65);
    if (reserva[2] != '\0'){
        if(reserva[1] != '1'){
            columna= int(reserva[2]-49);
            columna +=20;
        }else{
            columna= int(reserva[2]-49);
            columna +=10;
        }
    }else{
        columna= int(reserva[1]-49);
    }

    matriz_asientos[fila][columna]='-';
    for (int i=0;i<15;i++){
        cout << char(65+i) << "  ";
        for (int j=0;j<20;j++){
            cout<<matriz_asientos[i][j]<<" ";
        }
        cout<<endl;
    }
}

