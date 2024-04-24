




#include <graphics.h>
#include<bits/stdc++.h>
using namespace std;


void bresnam(int x1,int y1, int x2,int y2){
  int dx=abs(x2-x1);
  int dy=abs(y2-y1);
  int steps=dx;
  int x=x1,y=y1;
  int p=2*dy-dx;

  for(int i=0;i<steps;i++){
    if(p>=0){
        putpixel(floor(x),floor(y),GREEN);
        y+=1;
        p=p+2*dy-2*dx;
        delay(100);
    }
    else{
        putpixel(floor(x),floor(y),GREEN);
        p=p+2*dy;
        delay(100);
    }
    x+=1;
  }
}

int main(){
  int gd=DETECT,gm;
  int x1,x2,y1,y2;
  cout<<"Enter x1 and y1: ";
  cin>>x1>>y1;
  cout<<"Enter x2 and y2: ";
  cin>>x2>>y2;

  initgraph(&gd,&gm,NULL);
  bresnam(x1,x2,y1,y2);
  getch();
  closegraph();
}
