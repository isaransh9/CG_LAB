#include<stdio.h>  
#include<graphics.h>  
#include<bits/stdc++.h>
using namespace std;

void drawline(int x0, int y0, int x1, int y1)  
{  
    int dx, dy, p, x, y;  
    dx=x1-x0;  
    dy=y1-y0;  
    x=x0;  
    y=y0;  
    p=2*dy-dx;  
    while(x<x1)  
    {  
        if(p>=0)  
        {
          cout <<"("<< x << "," << y << ")" << endl;
          putpixel(x, y, 7);
          y = y + 1;
          p = p + 2 * dy - 2 * dx;  
        }  
        else  
        { 
            cout <<"("<< x << "," << y << ")" << endl; 
            putpixel(x,y,7);  
            p=p+2*dy;
        }  
            x=x+1;  

        }  
        delay(5000);
}  
int main()  
{  
    int gd = DETECT, gm;
    int gdriver=DETECT, gmode, error, x0, y0, x1, y1;  
    char path[] = "";
    initgraph(&gd, &gm, path); 
    x0 = 10, y0 = 5;
    x1 = 25, y1 = 30;
    drawline(x0, y0, x1, y1);  
    return 0;  
}  