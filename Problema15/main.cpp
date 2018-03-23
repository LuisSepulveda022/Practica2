#include <iostream>

using namespace std;

int* interseccion( int * , int *);  //Funcion que halla la interseccion de dos rectangulos(los valores de cada rectangulo deben ser positivos)
int main()
{
    int a[] ={0,0,8,4},b[]={5,2,6,7}; /*Los primeros 2 datos corresponden a las coordenadas de la esquina superior izquierda del rectángulo (x,y)
                                        Los siguientes 2 datos representan el ancho(A) y la altura(H) del rectángulo.*/
    //int interse[4];
    int *inter;
    inter = interseccion(a,b); //utilizamos la funcion para hallar la interseccion respectiva

    //mostramos los valores hallados en la funcion
    cout << inter[0] << " " << inter[1] << " " << inter[2] << " " << inter[3] << endl;
    return 0;
}

int * interseccion(int *recta1 , int *recta2){
    int *recta3 = new int[4];                   //Creamos el arreglo que vamos ha devolver con los datos
    int x1,y1,A1,H1,x2,y2,A2,H2,x3,y3,A3,H3;    //Definimos las variables de cada aspecto del rectangulo,sus coordenadas(x,y),ancho(A) y altura(H)

    //le damos los valores ha cada variable segun la posicion en el arreglo ingresado
    //Rectangulo1
    x1 = recta1[0];
    y1 = recta1[1];
    A1 = recta1[2];
    H1 = recta1[3];
    //Rectangulo2
    x2 = recta2[0];
    y2 = recta2[1];
    A2 = recta2[2];
    H2 = recta2[3];

    if(x1 > x2){
        if(x1 < (A2+x2))
            x3 = x1;
        if(x3 < (x2+A2))
             A3 = (x2+A2)-x3;

    }else if(x2 > x1){
        if(x2 < (A1+x1))
            x3=x2;
        if (x3 < (x1+A1))
            A3 = (x1+A1)-x3;
    }
    //cout << x3 << endl;
    if(y1 > y2){
        if(y1 < (H2+y2))
            y3 = y1;
        if(y3 < (y2+H2))
                H3 = (y2+H2)-y3;
    }else if(y2 > y1){
        if(y2 < (H1+y1))
            y3=y2;
        if (y3 < (y1+H1))
            H3 = (y1+H1)-y3;
    }

    recta3[0]=x3;  //le damos los valores hallados al arreglo que vamos ha devolver
    recta3[1]=y3;
    recta3[2]=A3;
    recta3[3]=H3;
    //cout << interse[0] << " " << interse[1] << " " << interse[2] << " " << interse[3] << endl;

    return recta3;
}
