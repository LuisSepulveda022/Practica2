#include <iostream>

using namespace std;

int main()
{
    int recta1[] ={0,0,8,4},recta2[]={5,2,6,7};
    int interse[4];
    int x1,y1,a1,h1,x2,y2,a2,h2,x3,y3,a3,h3;

    x1 = recta1[0];
    y1 = recta1[1];
    a1 = recta1[2];
    h1 = recta1[3];

    x2 = recta2[0];
    y2 = recta2[1];
    a2 = recta2[2];
    h2 = recta2[3];

    if(x1 > x2){
        if(x1 < (a2+x2))
            x3 = x1;
        if(x3 < (x2+a2))
             a3 = (x2+a2)-x3;

    }else if(x2 > x1){
        if(x2 < (a1+x1))
            x3=x2;
        if (x3 < (x1+a1))
            a3 = (x1+a1)-x3;
    }
    //cout << x3 << endl;
    if(y1 > y2){
        if(y1 < (h2+y2))
            y3 = y1;
        if(y3 < (y2+h2))
                h3 = (y2+h2)-y3;
    }else if(y2 > y1){
        if(y2 < (h1+y1))
            y3=y2;
        if (y3 < (y1+h1))
            h3 = (y1+h1)-y3;
    }
    //cout << y3 << endl;

    interse[0]=x3;
    interse[1]=y3;
    interse[2]=a3;
    interse[3]=h3;
    cout << interse[0] << " " << interse[1] << " " << interse[2] << " " << interse[3] << endl;
    return 0;
}
