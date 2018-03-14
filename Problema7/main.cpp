#include <iostream>

using namespace std;
/*Escriba un programa que reciba una cadena de caracteres y elimine los caracteres repetidos.
Ejemplo: se recibe bananas debe mostrar bans.
Nota: la salida del programa debe ser: Original: bananas. Sin repetidos: bans.*/

int strlen(char s[])    //con esta función encontramos la longitud de la cadena
{
int i;
for (i=0; s[i]!='\0'; i++)
/* avanzamos hasta el final de la cadena */ ;
return i;
}

int main()
{
    char palabra[30],modificada[30],original[30]; //en la variable palabra almacenamos lo ingresado por consola
    cout << "Ingrese una palabra: ";          //en  modificada almacenamos la plabra sin letras repetidas
    cin.getline(palabra,30,'\n');             //en original guardamos los caracteres ingresados


    int longitud = strlen(palabra);    //utilizamos la función strlen para hallar la longitud de la cadena

    for(int j=0; j <= longitud ; j++){
        if (longitud != j){             //almacenamos la cadena ingresada en original
            original[j]=palabra[j];
        }else{
            original[j]='\0';
        }
    }

    for (int i=0; i<longitud;i++){     //remplazamos las letras repetidas por un espacio para despues modificarlas

        for (int j=longitud-1;j>i;j--){
            if(palabra[i] == palabra[j]){
                palabra[j] =' ';
            }
        }
    }
    int posicion=0;
    for (int i=0; i<longitud;i++){      //ya con la variable palabra modificada si es el caso con espacios, ya esa
        if (palabra[i]!=' '){           //es la base para guardar la palabra modificada en otra variable para mostrala
            modificada[posicion]=palabra[i];
            posicion ++;
        }
    }

    modificada[posicion]='\0';  //En la variable original se encuentra la palabra ingresada, y en modificada esta la palabra sin repetidos
    cout <<"Original: "<<original << "    "<< "Sin repetidos: " <<modificada <<endl;
    return 0;
}
