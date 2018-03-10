#include <iostream>

using namespace std;
/*Haga una función que compare 2 cadenas de caracteres y retorno un valor lógico verdadero si son
iguales y falso en caso contrario, no olvide también tener en cuenta la longitud de las cadenas. Escriba un programa
de prueba.*/
int main()
{
    char cadena1[5]="hola";
    char cadena2[5]="hola";
    cout << cadena1 << "  "<< cadena1[2] << endl;
    //cout << sizeof(cadena1) <<endl;
    int cont=0;
    int m = sizeof(cadena1);
    for (int i=0; i < m; i++){
        if (cadena1 [i] == cadena2[i]){
            cont ++;
        }
    }
    if (cont <= m)
        cout << "son iguales" <<endl;

    return 0;
}
