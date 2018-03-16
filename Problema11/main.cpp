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
    char var;
    int opcion;
    do{
        cout <<"\n    Escoja una opcion del menu"<<endl;
        cout << "1.Mirar los asientos de la sala.\n2.Reservar un asiento de la sala.\n3.Cancelar una reserva."<<endl;
        cout <<"\nDijite una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            asientos();
            break;
        case 2:
            reservas();
            break;
        case 3:
            cancelacion();
            break;
        default:
            cout << "Usted no escogio una opcion correcta"<<endl;
            break;
        }

        cout << "\n\nDesea continuar(s:continuar o n:salir): ";
        cin >>var;

    }while(var == 's' or var == 'S');

    //asientos();
    //reservas();
    //cancelacion();
    return 0;
}

void asientos(){

    for (int i=0;i<15;i++){
        for (int j=0;j<20;j++){
            if (matriz_asientos[i][j] != '-'){
                matriz_asientos[i][j]='+';
            }else if(matriz_asientos[i][j] == '-'){
                matriz_asientos[i][j]='-';
            }
        }
    }
    /*cout << "   ";
    for(int i = 1; i<21; i++){  //imprimir los numero de columnas
        cout << i << " ";
    }*/
    cout << endl;
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
    cout<<"\n\nEscriba el asiento que quiere reservar\nsiendo las letras(A-O) las filas, y los numeros(1-20) las columnas: ";
    cin >> reserva;

    if(reserva[0]>=65 && reserva[0]<=79){
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
        if(matriz_asientos[fila][columna] == '-'){
            cout << "\nEl asiento en posicion "<<reserva[0]<<reserva[1]<<reserva[2] <<"se encuentra reservado ya.\nPor lo cual no se puede reservar en esa posicion"<<endl;



        }else{
            matriz_asientos[fila][columna]='-';
            asientos();
            cout <<"\nLa reserva en posicion "<<reserva[0]<<reserva[1]<<reserva[2]<<"se efectuo correctamente"<<endl;
        }
    }else{
        cout << "\nRecuerde que la fila(A-O) debe ser en mayuscula"<<endl;
    }

}
void cancelacion(){

    char cancelacion[4];
    asientos();
    cout<<"\n\nEscriba el asiento que quiere cancelar\nsiendo las letras(A-O) las filas, y los numeros(1-20) las columnas: ";
    cin >> cancelacion;
    int fila,columna;

    if(cancelacion[0]>=65 && cancelacion[0]<=79 ){
        fila = int(cancelacion[0]-65);
        if (cancelacion[2] != '\0'){
            if(cancelacion[1] != '1'){
                columna= int(cancelacion[2]-49);
                columna +=20;
            }else{
                columna= int(cancelacion[2]-49);
                columna +=10;
            }
        }else{
            columna= int(cancelacion[1]-49);
        }
        if(matriz_asientos[fila][columna] == '+'){
            cout<<"\nEse lugar en posicion "<<cancelacion[0]<<cancelacion[1]<<cancelacion[2]<<" no esta reservado.\nPor lo tanto no puede cancelar ninguna reserva."<<endl;
        }else{
            matriz_asientos[fila][columna]='+';

            cout<<"\nLa cancelacion en posicion "<<cancelacion[0]<<cancelacion[1]<<cancelacion[2]<<" se efectu correctamente."<< endl;
            asientos();
        }
    }else{
        cout <<"\nRecuerde digitar la fila(A-O) en mayuscula."<<endl;
    }


}
