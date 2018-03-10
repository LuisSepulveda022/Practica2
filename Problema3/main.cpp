#include <iostream>

using namespace std;
/*Haga una función que compare 2 cadenas de caracteres y retorno un valor lógico verdadero si son
iguales y falso en caso contrario, no olvide también tener en cuenta la longitud de las cadenas. Escriba un programa
de prueba.*/

void Compare_cadenas (char cadena1[] , char cadena2[],int longitud1,int longitud2); //definimos la funcion para comparar las cadenas.
//en la funcion se necesitan las dos cadenas, y la longitud de cada cadena respectivamente
int main()
{
    int longitud1,longitud2; //En estas variables guardaremos la longitud de cada cadena, para saber
                            //si se pueden compara o no, ya que es necesario la misma longitud en las dos cadenas

    char cadena1[]="h6%o&l1a";     //Creamos las cadenas de caracteres tipo char
    char cadena2[]="h6%o&l1a";
    longitud1 = sizeof(cadena1);    //Determinamos la longitud(tamaño) de cada cadena
    longitud2 = sizeof(cadena2);
    Compare_cadenas(cadena1,cadena2,longitud1,longitud2); // Utilizamos la función para comparar las cadenas
    // Debe mostrar True

    cout << endl;

    char cadena3[] = "Carlos12";  //Un ejemplo
    char cadena4[] = "carl0s12";
    longitud1 = sizeof(cadena3);
    longitud2 = sizeof(cadena4);
    Compare_cadenas(cadena3,cadena4,longitud1,longitud2);
    // Debe mostrar False

    cout << endl;

    char cade1[] = "holae";     // Un ejemplo
    char cade2[] = "hodffsffla";
    longitud1 = sizeof(cade1);
    longitud2 = sizeof(cade2);
    Compare_cadenas(cade1,cade2,longitud1,longitud2);
    // Debe mostrar Que la longitud de las cadenas no es la misma

    return 0;
}

void Compare_cadenas (char cadena1[] , char cadena2[],int longitud1,int longitud2){

    if (longitud1 == longitud2){ //Verificamos que cumplan con la misma longitud para así verificar si son iguales

        int cont=0;   // Este contador nos servira para saber si cuentan con los mismo elementos las dos cadenas


        for (int i=0; i < longitud1; i++){  //El ciclo for itera hasta la longitud de las cadenas que es la misma para las dos
            if (cadena1[i] == cadena2[i]) //Si los elementos coinciden se suma al contador
                cont ++;
        }

        if (cont == longitud1){  // Si el contador tiene el mismo valor que la longitud, las cadenas son iguales
            cout << "True" << endl;
        }else{
            cout << "False" << endl;   //Si no tiene el mismo valor es porque no son iguales cadenas
        }
    }else{
        cout << "La longitud de las cadenas no es la misma"<<endl; //Si la longitud de las cadenas no coinciden no debemos hacer nada mas
    }
}
