#include <iostream>
#include <graphics.h>
#include <stdio.h>
using namespace std;
int xb=500,yb=310,dir=2;
int s1=0,s2=0;
void make_board(int s1,int s2)
{
    setfillstyle(SOLID_FILL,YELLOW);
    bar(0,0,1000,40);
    bar(0,580,1000,600);
    setfillstyle(SOLID_FILL,BLUE);
    bar(0,40,20,580);
    setfillstyle(SOLID_FILL,RED);
    bar(980,40,1000,580);
    setfillstyle(SOLID_FILL,WHITE);
    for(int j=40;j<580;j=j+20)
    {
        if(j%40)
            continue;
        bar(495,j,505,j+20);
    }
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    char sc1[2],sc2[2];
    sprintf(sc1,"%d",s1);
    sprintf(sc2,"%d",s2);
    outtextxy(450,5,sc1);
    outtextxy(540,5,sc2);
}
void rpad(int y1)
{
    setfillstyle(SOLID_FILL,BLUE);
    bar(930,y1,955,y1+80);
}
void lpad(int y1)
{
    setfillstyle(SOLID_FILL,RED);
    bar(45,y1,70,y1+80);
}
void make_ball()
{
    setfillstyle(SOLID_FILL,WHITE);
    if(dir==0)
    {
        if(getpixel(xb-15,yb-15)==YELLOW)
        {
            dir=3;
            make_ball();
        }
        else if(getpixel(xb-15,yb-15)==RED)
        {
            dir=1;
            make_ball();
        }
        else if(getpixel(xb-15,yb-15)==BLUE)
        {
            dir=rand()%4;
            s2++;
            xb=500;
            yb=rand()%540+40;
        }
        else
        {
            xb=xb-15;
            yb=yb-15;
        }


    }
    else if(dir==1)
    {
        if(getpixel(xb+15,yb-15)==YELLOW)
        {
            dir=2;
            make_ball();
        }
        else if(getpixel(xb+15,yb-15)==BLUE)
        {
            dir=0;
            make_ball();
        }
        else if(getpixel(xb+15,yb-15)==RED)
        {
            dir=rand()%4;
            s1++;
            xb=500;
            yb=rand()%540+40;
        }
        else
        {
            xb=xb+15;
            yb=yb-15;
        }
    }
    else if(dir==2)
    {
       if(getpixel(xb+15,yb+15)==YELLOW)
        {
            dir=1;
            make_ball();
        }
        else if(getpixel(xb+15,yb+15)==BLUE)
        {
            dir=3;
            xb=xb-15;
            yb=yb+15;
            make_ball();
        }
        else if(getpixel(xb+15,yb+15)==RED)
        {
            dir=rand()%4;
            s1++;
            xb=500;
            yb=rand()%540+40;
        }
        else
        {
            xb=xb+15;
            yb=yb+15;
        }
    }
    else
    {
        if(getpixel(xb+15,yb+15)==YELLOW)
        {
            dir=0;
            make_ball();
        }
        else if(getpixel(xb-15,yb+10)==RED)
        {
            dir=2;
            xb=xb+15;
            yb=yb+15;
            make_ball();
        }
        else if(getpixel(xb+15,yb+15)==BLUE)
        {
            dir=rand()%4;
            s2++;
            xb=500;
            yb=rand()%540+40;
        }
        else
        {
            xb=xb-15;
            yb=yb+15;
        }
    }
    fillellipse(xb,yb,10,10);
}
int main()
{
    initwindow(1000,600,"\t\t\tULTIMATE PONG\t\t\t",200,50,NULL,true);
    int y1=280,y2=280;
    int page=0;
    long int s=0;
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        page=1-page;
        if(GetAsyncKeyState(VK_UP)&&(y1-30)>=40)
            y1=y1-30;
        if(GetAsyncKeyState(VK_TAB)&&(y2-30)>=40)
            y2=y2-30;
        if(GetAsyncKeyState(VK_DOWN)&&(y1+30+80)<=580)
            y1=y1+30;
        if(GetAsyncKeyState(VK_LCONTROL)&&(y2+30+80)<=580)
            y2=y2+30;
        delay(50);
        //cleardevice();
        make_board(s1,s2);
        rpad(y1);
        lpad(y2);
        make_ball();
        s++;
    }
    outtextxy(100,100,"THE GAME IS OVER!!!!!");
    getch();
    getch();

}
