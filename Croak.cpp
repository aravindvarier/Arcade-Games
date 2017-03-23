#include <iostream>
#include <graphics.h>
int dir =0;
int x=500,y=575;
using namespace std;
inline int fshift(int shift,int val)
{
    if(val-shift+150>0)
        return val-shift;

        return 1000-(shift-val)%1000-150;
}
void make_lvl(int shift)
{
    setbkcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL,BROWN);
    setcolor(BROWN);
    int land1_c[]={0,500,1000,500,1000,600,0,600};
    fillpoly(4,land1_c);
    int land2_c[]={0,0,1000,0,1000,100,0,100};
    fillpoly(4,land2_c);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
    outtextxy(300,25,"FINISH LINE");

    //**************************************************************************************
    setfillstyle(SOLID_FILL,RED);
    setcolor(RED);
    int block1[]={fshift(shift,100),100,fshift(shift,100)+150,100,fshift(shift,100)+150,150,fshift(shift,100),150};
    int block2[]={(shift+350)%1000,150,(shift+350)%1000+150,150,(shift+350)%1000+150,200,(shift+350)%1000,200};
    int block3[]={fshift(shift,700),200,fshift(shift,700)+150,200,fshift(shift,700)+150,250,fshift(shift,700),250};
    int block4[]={(shift+900)%1000,250,(shift+900)%1000+150,250,(shift+900)%1000+150,300,(shift+900)%1000,300};
    int block5[]={fshift(shift,400),300,fshift(shift,400)+150,300,fshift(shift,400)+150,350,fshift(shift,400),350};
    int block6[]={(shift)%1000,350,(shift)%1000+150,350,(shift)%1000+150,400,(shift)%1000,400};
    int block7[]={fshift(shift,800),400,fshift(shift,800)+150,400,fshift(shift,800)+150,450,fshift(shift,800),450};
    int block8[]={(shift+600)%1000,450,(shift+600)%1000+150,450,(shift+600)%1000+150,500,(shift+600)%1000,500};
    fillpoly(4,block1);
    setfillstyle(SOLID_FILL,LIGHTRED);
    setcolor(LIGHTRED);
    fillpoly(4,block2);
    setfillstyle(SOLID_FILL,RED);
    setcolor(RED);
    fillpoly(4,block3);
    setfillstyle(SOLID_FILL,LIGHTRED);
    setcolor(LIGHTRED);
    fillpoly(4,block4);
    setfillstyle(SOLID_FILL,RED);
    setcolor(RED);
    fillpoly(4,block5);
    setfillstyle(SOLID_FILL,LIGHTRED);
    setcolor(LIGHTRED);
    fillpoly(4,block6);
    setfillstyle(SOLID_FILL,RED);
    setcolor(RED);
    fillpoly(4,block7);
    setfillstyle(SOLID_FILL,LIGHTRED);
    setcolor(LIGHTRED);
    fillpoly(4,block8);

}
void endgame()
{
    cleardevice();
    make_lvl(0);
    setcolor(BLACK);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,9);
    outtextxy(50,250,"GAMEOVER! #_# ");
    outtextxy(200,350,"ESC TO QUIT");
   // outtextxy(200,410,"BCK TO RePLY ");
    while(1)
    {
    if(GetAsyncKeyState(VK_ESCAPE))
        {closegraph();
        exit(0);}
    else if(GetAsyncKeyState(VK_BACK))
    {
        x=500;
        y=575;
        make_lvl(0);
        break;
    }
    }
}
void wingame()
{
    cleardevice();
    make_lvl(0);
    setcolor(MAGENTA);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,9);
    outtextxy(50,250,"YOU WIN! xD ");
    outtextxy(200,350,"ESC TO QUIT ");
    outtextxy(200,400,"BCK TO RePLY ");

    while(1)
    {
    if(GetAsyncKeyState(VK_ESCAPE))
        closegraph();
    else if(GetAsyncKeyState(VK_BACK))
    {
        x=500;
        y=575;
        make_lvl(0);
        break;
    }
    }
}
int make_frog(int x,int y)
{
     if(getpixel(x,y)==RED)
        x=x-25;
    else if(getpixel(x,y)==LIGHTRED)
        x=x+25;
    else if (getpixel(x,y)==LIGHTBLUE)
        endgame();
    else if(y<100)
        wingame();
    setfillstyle(SOLID_FILL,GREEN);
    setcolor(GREEN);
    fillellipse(x,y,10,25);
    setlinestyle(SOLID_LINE,NULL,3);
    line(x,y,x+22,y-25);
    line(x,y,x-22,y-25);
    line(x,y+20,x+22,y+20-25);
    line(x,y+20,x-22,y+20-25);
    line(x+22,y+20-25,x+22,y+25);
    line(x-22,y+20-25,x-22,y+25);
    setlinestyle(SOLID_LINE,NULL,1);
    return x;
}

int main()
{
   initwindow(1000,600,"FROG JUMP",0,50,NULL,TRUE);
   int shift=0;
   setbkcolor(LIGHTBLUE);
   delay(1000);
   make_lvl(shift);
   make_frog(x,y);
   while(1)
   {
       shift=(shift+25);
   if(GetAsyncKeyState(VK_UP))
   {
       //if(getpixel(x+25,y-35)!=YELLOW&&getpixel(x-25,y-35)!=YELLOW)
       if(y-50>0)
        y=y-50;
   }
   else if(GetAsyncKeyState((VK_DOWN)))
   {
       //if(getpixel(x+25,y+41)!=YELLOW&&getpixel(x-25,y+41)!=YELLOW)
       if(y+50<600)
       y=y+50;

   }
   else if(GetAsyncKeyState(VK_RIGHT))
   {
       //if(getpixel(x+42,y+25)!=YELLOW&&getpixel(x+42,y-25)!=YELLOW)
       if(x+25<1000)
       x=x+25;

   }
   else if(GetAsyncKeyState(VK_LEFT))
   {
       //if(getpixel(x-35,y+25)!=YELLOW&&getpixel(x-35,y-25)!=YELLOW)
       if(x-25>0)
       x=x-25;

   }

   delay(100);
   cleardevice();
   make_lvl(shift);
   x=make_frog(x,y);
   delay(50);
   }


   getch();
}
