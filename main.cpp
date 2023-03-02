#include <iostream>
#include <graphics.h>

using namespace std;

class pesawatsimple{
public:
    float x=200,y=200,s=7; //x & y menunjukan posisi tinggi, s menunjukan skala
    float vx,vy;
    float xp,yp;
    int counter=0;
    int color;


void drawpeluru()
{
    if(ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            counter=20;
            xp=mousex();
            yp=mousey();

        }
    if(counter==20)
    {
        circle(xp-15,yp-5,10);
        xp-=vx;

    if(yp<=0)
    {
    counter=0;
}
    }
}

void drawpeluru1()
{
    if(ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            counter=20;
            xp=x;
            yp=y;

        }
    if(counter==20)
    {
        circle(xp-15,yp-5,10);
        xp-=vx;

    if(yp<=0)
    {
    counter=0;
}
    }
}

void drawgamer()
{
    x=mousex();
    y=mousey();
    line(x,y, x+7*s, y);
    line(x+11*s, y, x+22*s, y);
    line(x+22*s, y, x+27*s, y-5*s);
    line(x+27*s,y-5*s,x+27*s,y-8*s);
    line(x+27*s,y-8*s,x+24*s,y-8*s);
    line(x+22*s, y-5*s, x+3*s, y-5*s);
    line(x+22*s,y-5*s,x+24*s,y-8*s);
//Jendela pilot
    line(x+6*s, y-2*s, x, y-2*s);
    line(x+6*s, y-5*s, x+6*s, y-2*s);

   //ini adalah koordinat dari bentuk bagian kepala
    line(x,y,x,y-2*s);
    line(x,y-2*s,x+3*s,y-5*s);
    //ini adalah koordinat dari sayap bagian atas atau kanan
    line(x+7*s, y-5*s, x+16*s, y-11*s);
    line(x+16*s,y-11*s, x+20*s, y-11*s);
    line(x+20*s, y-11*s, x+12*s, y-5*s);
    //ini adalah koordinat dari sayap bagian bawah atau kiri
    line(x+5.5*s,y-2*s,x+12.5*s,y+8*s);
    line(x+12.5*s,y+8*s,x+16*s,y+8*s);
    line(x+16*s,y+8*s,x+9.5*s,y-2*s);
}

void picture()
{ //ini adalah rangka dari koordinat bentuk badan pesawat, dan ekor pesawat
    setcolor(color);
    line(x,y, x+7*s, y);
    line(x+11*s, y, x+22*s, y);
    line(x+22*s, y, x+27*s, y-5*s);
    line(x+27*s,y-5*s,x+27*s,y-8*s);
    line(x+27*s,y-8*s,x+24*s,y-8*s);
    line(x+22*s, y-5*s, x+3*s, y-5*s);
    line(x+22*s,y-5*s,x+24*s,y-8*s);
    //jendela pilot
    line(x+6*s, y-2*s, x, y-2*s);
    line(x+6*s, y-5*s, x+6*s, y-2*s);

   //ini adalah koordinat dari bentuk bagian kepala
    line(x,y,x,y-2*s);
    line(x,y-2*s,x+3*s,y-5*s);
    //ini adalah koordinat dari sayap bagian atas atau kanan
    line(x+7*s, y-5*s, x+16*s, y-11*s);
    line(x+16*s,y-11*s, x+20*s, y-11*s);
    line(x+20*s, y-11*s, x+12*s, y-5*s);
    //ini adalah koordinat dari sayap bagian bawah atau kiri
    line(x+5.5*s,y-2*s,x+12.5*s,y+8*s);
    line(x+12.5*s,y+8*s,x+16*s,y+8*s);
    line(x+16*s,y+8*s,x+9.5*s,y-2*s);
}

void posisi()
{// fungsi if ini untuk mengatur gerakan pesawat yang ditambah oleh v
    //fungsi if ini juga untuk membatasi screen area komputer
    if (y<100 || y>768) vy*=-1;
    if (x<0 || x>1280) vx*=-1;
    y-=vy;
    x-=vx;
}

};

int main()
{
    initwindow(1280,768); // fungsinya ini untuk mengatur resolusi layar
    pesawatsimple p[20];
    pesawatsimple mouse;
    mouse.vx=10;
    for(int i=0;i<20;i++)
    {
        p[i].x=rand()%1200+100;
        p[i].y=rand()%700+200;
        p[i].color=rand()%15;
        p[i].vx=rand()%20;
        p[i].vy=rand()%20;
        p[i].counter=20;
    }
    while(!kbhit())
    {
        cleardevice();
        mouse.drawgamer();
        mouse.drawpeluru();
        for (int i=0;i<20;i++)
        {
            p[i].picture();
            p[i].posisi();
            p[i].drawpeluru();
        }
        delay(50);
    }
    return 0;
}
