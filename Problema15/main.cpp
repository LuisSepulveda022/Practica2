#include <iostream>

using namespace std;

void interseccion( int * , int * , int *);  //Funcion que halla la interseccion de dos rectangulos(los valores de cada rectangulo deben ser positivos)


int main()
{
    int rectangulo1[] ={0,0,8,4},rectangulo2[]={5,2,6,7}; /*Los primeros 2 datos corresponden a las coordenadas de la esquina superior izquierda del rectángulo (x,y)
                                                            Los siguientes 2 datos representan el ancho(A) y la altura(H) del rectángulo.*/

    int *rectangulo3 = new int[4]; //en rectangulo3 se guardan los valores de la interseccion de los rectangulos dados

     interseccion(rectangulo1,rectangulo2,rectangulo3); //utilizamos la funcion para hallar la interseccion respectiva

    //mostramos los valores hallados en la funcion
    cout <<"La interseccion del rectangulo1={"<<rectangulo1[0]<<","<<rectangulo1[1]<<","<<rectangulo1[2]<<","<<rectangulo1[3]<<"} y el rectangulo2={"<<rectangulo2[0]<<","<<rectangulo2[1]<<","<<rectangulo2[2]<<","<<rectangulo2[3]<<"}\n";
    cout <<"Es={"<<rectangulo3[0]<<","<<rectangulo3[1]<<","<<rectangulo3[2]<<","<<rectangulo3[3]<<"}\n";
    return 0;
}

void interseccion(int *recta1 , int *recta2, int *recta3){
    //int *recta3 = new int[4];                   //Creamos el arreglo que vamos ha devolver con los datos
    int x1,y1,A1,H1,x2,y2,A2,H2;    //Definimos las variables de cada aspecto del rectangulo,sus coordenadas(x,y),ancho(A) y altura(H)

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
            recta3[0] = x1;
        if(recta3[0] < (x2+A2))
             recta3[2] = (x2+A2)-recta3[0];

    }else if(x2 > x1){
        if(x2 < (A1+x1))
            recta3[0]=x2;
        if (recta3[0] < (x1+A1))
            recta3[2] = (x1+A1)-recta3[0];
    }

    if(y1 > y2){
        if(y1 < (H2+y2))
            recta3[1] = y1;
        if(recta3[1] < (y2+H2))
                recta3[3] = (y2+H2)-recta3[1];
    }else if(y2 > y1){
        if(y2 < (H1+y1))
            recta3[1]=y2;
        if (recta3[1] < (y1+H1))
            recta3[3] = (y1+H1)-recta3[1];
    }

}
