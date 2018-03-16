#include <iostream>

/*Escriba un programa que permita manejar las reservas de asientos en una sala de cine, los asientos de
la sala de cine están organizados en 15 filas con 20 asientos cada una. El programa debe mostrar una representación
de la sala que indique que asientos están disponibles y cuales se encuentran reservados. Además debe permitir
realizar reservas o cancelaciones al ingresar la fila (letras A-O) y el número del asiento (números 1-20).*/

using namespace std;

void reservas(); //En esta funcion esta la estructura para realizar una reserva de la sala
void cancelacion();//En esta funcion esta la estructura para realizar una cancelacion de la sala
void asientos(); //En esta funcion esta la estrutura para mostrar los asientos de la sala

char matriz_asientos[15][20]; //Creamos una variable global, la cual vamos ha manipular en cada una de las funciones que se necesiten
int main()
{
    char var;
    char opcion;
    do{
        cout <<"\n    Escoja una opcion del menu"<<endl;
        cout << "1.Mirar los asientos de la sala.\n2.Reservar un asiento de la sala.\n3.Cancelar una reserva de la sala."<<endl;
        cout <<"\nDijite una opcion: ";
        cin >> opcion;

        switch (opcion) {       //Imprimimos el menu del programa y se ingresa una opcion la cual se ejecutara segun el caso que sea,
        case '1':               //el primer caso es imprimir la sala, el segundo caso efectuar una reserva y en el tercero haremos la
            asientos();         //cancelacion de una reserva ya hecha.En cado caso llamaremos la funcion que sea necesaria.
            break;
        case '2':
            reservas();
            break;
        case '3':
            cancelacion();
            break;
        default:
            cout << "Usted no escogio una opcion correcta"<<endl;
            break;
        }

        cout << "\n\nDesea continuar(s:continuar o n:salir): "; //Despues de ejecutar la opcion escogida se preguntara si se quiere seguir en el programa
        cin >>var;

    }while(var == 's' or var == 'S');

    return 0;
}

void asientos(){

    for (int i=0;i<15;i++){        //Almacenamos en la matriz_asientos la disposion de la sala en el momento
        for (int j=0;j<20;j++){
            if (matriz_asientos[i][j] != '-'){//si es diferente de reservado se almacena un libre
                matriz_asientos[i][j]='+';
            }else if(matriz_asientos[i][j] == '-'){ //si es igual a reservado se sobre-escribe en la posicion
                matriz_asientos[i][j]='-';
            }
        }
    }
    /*cout << "   ";
    for(int i = 1; i<21; i++){  //imprimir los numero de columnas
        cout <<i<< "  ";
    }*/
    cout << endl;
    for (int i=0;i<15;i++){         //Imprimos la matriz con su disposicion actual de la sala
        cout << char(65+i) << "  ";
        for (int j=0;j<20;j++){
            cout<<matriz_asientos[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"\nRecuerde que:\n(+)siginfica asiento libre.\n(-)significa asiento reservado.\n";
}
void reservas(){
    char reserva[4];
    asientos();
    cout<<"\n\nEscriba el asiento que quiere reservar\nsiendo las letras(A-O) las filas, y los numeros(1-20) las columnas: ";
    cin >> reserva;                 //pedimos la posicion del asiento a reservar

    if(reserva[0]>=65 && reserva[0]<=79){ //Verificamos si la letra de la posicion este en las mayusculas
        int fila,columna;

        fila = int(reserva[0]-65);      //convertimos lo ingresado por consola como una posicion de la matriz
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
        if(columna <= 19 && columna >= 0){   //verificamos que el numero ingresado si este en el rango de las columnas
            if(matriz_asientos[fila][columna] == '-'){
                cout << "\nEl asiento en posicion "<<reserva[0]<<reserva[1]<<reserva[2] <<"se encuentra reservado ya.\nPor lo cual no se puede reservar en esa posicion"<<endl;

            }else{
                matriz_asientos[fila][columna]='-';
                asientos();
                cout <<"\nLa reserva en posicion "<<reserva[0]<<reserva[1]<<reserva[2] <<"se efectuo correctamente"<<endl;
            }
        }else{
            cout<<"\nColumna Incorrecta\nRecuerde que las columnas van desde(1-20)."<<endl;
        }
    }else{
        cout << "\nFila Incorrecta\nRecuerde que la fila(A-O) debe ser en mayuscula."<<endl;
    }

}
void cancelacion(){

    char cancelacion[4];
    asientos();
    cout<<"\n\nEscriba el asiento que quiere cancelar\nsiendo las letras(A-O) las filas, y los numeros(1-20) las columnas: ";
    cin >> cancelacion;   //pedimos la posicion del asiento a cancelar
    int fila,columna;

    if(cancelacion[0]>=65 && cancelacion[0]<=79 ){  //Verificamos si la letra de la posicion este en las mayusculas
        fila = int(cancelacion[0]-65);
        if (cancelacion[2] != '\0'){    //convertimos lo ingresado por consola como una posicion de la matriz
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
        if(columna <=19 && columna >=0){    //verificamos que el numero ingresado si este en el rango de las columnas
            if(matriz_asientos[fila][columna] == '+'){
                cout<<"\nEse lugar en posicion "<<cancelacion[0]<<cancelacion[1]<<cancelacion[2]<<" no esta reservado.\nPor lo tanto no puede cancelar ninguna reserva."<<endl;
            }else{
                matriz_asientos[fila][columna]='+';

                cout<<"\nLa cancelacion en posicion "<<cancelacion[0]<<cancelacion[1]<<cancelacion[2]<<" se efectu correctamente."<< endl;
                asientos();
            }
        }else{
            cout <<"\nColumna Incorrecta\nRecuerde que las columnas van desde (1-20)."<<endl;
        }
    }else{
        cout <<"\nFila Incorrecta\nRecuerde digitar la fila(A-O) en mayuscula."<<endl;
    }

}
