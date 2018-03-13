#include <iostream>
#include <string.h>
using namespace std;
/*Escriba un programa que reciba una cadena de caracteres y elimine los caracteres repetidos.
Ejemplo: se recibe bananas debe mostrar bans.
Nota: la salida del programa debe ser: Original: bananas. Sin repetidos: bans.*/
int main()
{
    char palabra[20],modifi[20],original[20];
    cout << "Ingrese una palabra: ";
    cin.getline(palabra,20,'\n');
    //cout << palabra <<endl;
    //original = palabra;

    int longitud = strlen(palabra);
    for(int j=0; j < longitud ; j++){
        original[j]=palabra[j];
    }
    //original[j]='\0';
    for (int i=0; i<longitud;i++){

        for (int j=longitud-1;j>i;j--){
            if(palabra[i] == palabra[j]){
                palabra[j] =' ';
            }
        }
    }
    int posicion=0;
    for (int i=0; i<longitud;i++){
        if (palabra[i]!=' '){
            modifi[posicion]=palabra[i];
            posicion ++;
        }
    }
    modifi[posicion]='\0';
    cout << original << "  " <<modifi <<endl;
    return 0;
}
