#include <iostream>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
using namespace std;
//Declaration Part Starts
    bool B1=true,B2=true,B3=true,B4=true,B5=true,B6=true,B7=true,B8=true,B9=true;   //B---Block
    char turn='X';
    int turn_count=0;
    POINT CP;
    char Cursor_Readings[100];
    int B1_W=NULL,B2_W=NULL,B3_W=NULL,B4_W=NULL,B5_W=NULL,B6_W=NULL,B7_W=NULL,B8_W=NULL,B9_W=NULL;     //B--Block, W-Winner
    int Winner=0;
//Declaration Part ends
void Check_For_A_Winner()
{
        if(B1_W==1&&B2_W==1&&B3_W==1)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
            Winner=1;
        }
        if(B4_W==1&&B5_W==1&&B6_W==1)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
            Winner=1;
        }
        if(B7_W==1&&B8_W==1&&B9_W==1)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
            Winner=1;
        }
        if(B1_W==1&&B5_W==1&&B9_W==1)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
            Winner=1;
        }
        if(B3_W==1&&B5_W==1&&B7_W==1)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
            Winner=1;
        }
        if(B1_W==1&&B4_W==1&&B7_W==1)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
            Winner=1;
        }
        if(B2_W==1&&B5_W==1&&B8_W==1)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
            Winner=1;
        }
        if(B3_W==1&&B6_W==1&&B9_W==1)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
            Winner=1;
        }

        if(B1_W==2&&B2_W==2&&B3_W==2)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
            Winner=2;
        }
        if(B4_W==2&&B5_W==2&&B6_W==2)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
            Winner=2;
        }
        if(B7_W==2&&B8_W==2&&B9_W==2)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
            Winner=2;
        }
        if(B1_W==2&&B5_W==2&&B9_W==2)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
            Winner=2;
        }
        if(B3_W==2&&B5_W==2&&B7_W==2)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
            Winner=2;
        }
        if(B1_W==2&&B4_W==2&&B7_W==2)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
            Winner=2;
        }
        if(B2_W==2&&B5_W==2&&B8_W==2)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
            Winner=2;
        }
        if(B3_W==2&&B6_W==2&&B9_W==2)
        {
            outtextxy(10,60,"Game Over...");
            B1=B2=B3=B4=B5=B6=B7=B8=B9=false;Winner=2;
        }
}
void Turn_MessageX()
{
    settextstyle(1,0,1);
    if(turn_count==8)
    outtextxy(10,60,"Game Over...");
    else
    outtextxy(10,60,"O's Turn");
}
void Turn_MessageO()
{
    settextstyle(1,0,1);
    if(turn_count==8)
    outtextxy(10,60,"Game Over...");
    else
    outtextxy(10,60,"X's Turn");
}
void Reset_All()
{
    B1=B2=B3=B4=B5=B6=B7=B8=B9=true;
    turn='X';
    turn_count=0;
    B1_W=B2_W=B3_W=B4_W=B5_W=B6_W=B7_W=B8_W=B9_W=NULL;
    Winner=0;
}
void Allow_Access()
{
    B1=B2=B3=B4=B5=B6=B7=B8=B9=true;
}
void Deny_Access()
{
    B1=B2=B3=B4=B5=B6=B7=B8=B9=false;
}
void OOO(int x,int y)
{
    setcolor(15);
    for(int a=0;a<=2;a++)
    circle(x,y,25+a);
}
void cross(int x,int y)
{
    setcolor(15);
    for(int a=0;a<=2;a++)
    {
        line((x-20)-a,(y-20)+a,(x+20)-a,(y+20)+a);
        line((x+20)+a,(y-20)+a,(x-20)+a,(y+20)+a);
    }
}

void GetStatus(int tempCx,int tempCy)
{
        settextstyle(1,0,1);
        if((tempCx>420&&tempCx<620&&tempCy>280&&tempCy<320))
        {
            outtextxy(460,410,"Exit           ");
        }
        else if((tempCx>420&&tempCx<620&&tempCy>180&&tempCy<220))
        {
            outtextxy(460,410,"New Game        ");
        }
        else if(tempCx>110&&tempCx<210&&tempCy>130&&tempCy<230)
        {
            if(B1)
            outtextxy(460,410,"Block-1         ");
            else
            outtextxy(460,410,"Not Allowed     ");
        }
        else if(tempCx>210&&tempCx<310&&tempCy>130&&tempCy<230)
        {
            if(B2)
            outtextxy(460,410,"Block-2         ");
            else
            outtextxy(460,410,"Not Allowed     ");
        }
        else if(tempCx>310&&tempCx<410&&tempCy>130&&tempCy<230)
        {
            if(B3)
            outtextxy(460,410,"Block-3         ");
            else
            outtextxy(460,410,"Not Allowed     ");
        }
        else if(tempCx>110&&tempCx<210&&tempCy>230&&tempCy<330)
        {
            if(B4)
            outtextxy(460,410,"Block-4         ");
            else
            outtextxy(460,410,"Not Allowed     ");
        }
        else if(tempCx>210&&tempCx<310&&tempCy>230&&tempCy<330)
        {
            if(B5)
            outtextxy(460,410,"Block-5         ");
            else
            outtextxy(460,410,"Not Allowed     ");
        }
        else if(tempCx>310&&tempCx<410&&tempCy>230&&tempCy<330)
        {
            if(B6)
            outtextxy(460,410,"Block-6         ");
            else
            outtextxy(460,410,"Not Allowed     ");
        }
        else if(tempCx>110&&tempCx<210&&tempCy>330&&tempCy<430)
        {
            if(B7)
            outtextxy(460,410,"Block-7         ");
            else
            outtextxy(460,410,"Not Allowed     ");
        }
        else if(tempCx>210&&tempCx<310&&tempCy>330&&tempCy<430)
        {
            if(B8)
            outtextxy(460,410,"Block-8         ");
            else
            outtextxy(460,410,"Not Allowed     ");
        }
        else if(tempCx>310&&tempCx<410&&tempCy>330&&tempCy<430)
        {
            if(B9)
            outtextxy(460,410,"Block-9         ");
            else
            outtextxy(460,410,"Not Allowed     ");
        }
        else if(Winner==1)
        {
            outtextxy(460,410,"X Wins          ");
        }
        else if(Winner==2)
        {
            outtextxy(460,410,"O Wins          ");
        }
        else if(turn_count==9)
        {
            outtextxy(460,410,"Draw            ");
        }
        else
        {
            outtextxy(460,410,"Ready           ");
        }
}
void get_turn()
{
    if(turn_count==0)
        turn='X';
    if(turn_count==1)
        turn='O';
    if(turn_count==2)
        turn='X';
    if(turn_count==3)
        turn='O';
    if(turn_count==4)
        turn='X';
    if(turn_count==5)
        turn='O';
    if(turn_count==6)
        turn='X';
    if(turn_count==7)
        turn='O';
    if(turn_count==8)
        turn='X';
    if(turn_count==9)
        turn='O';
}
void NewGame()
{
    cleardevice();
    Reset_All();
    settextstyle(1,0,1);
    outtextxy(((getmaxx()/2)-textwidth("Loading")/2),((getmaxy()/2)-textheight("Loading")/2),"Loading");
    for(int i=0;i<80;i++)
    {
        outtext(".");
        delay(10);
    }
    cleardevice();
}
void Boards_Titles()
{
    setcolor(15);
        settextstyle(1,0,1);
        outtextxy(10,410,Cursor_Readings);
    setcolor(15);
        settextstyle(1,0,5);
        outtextxy(150,10,"Tic-Tac-Toe");
    setcolor(15);
        rectangle(100,100,400,400);         //Main Board Border
        rectangle(420,150,620,200);         //New Game Board Border
        rectangle(420,250,620,300);         //Exit Board Border
        line(200,100,200,400);              //CL1
        line(300,100,300,400);              //CL2
        line(100,200,400,200);              //RL1
        line(100,300,400,300);              //RL2
    setcolor(15);
        settextstyle(1,0,1);
        outtextxy(450,165,"New Game");
        outtextxy(490,265,"Exit");

}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    settextstyle(1,0,1);
    outtextxy(10,60,"X's Turn");
    while(1)
    {
        GetCursorPos(&CP);
        int Cx=CP.x,Cy=CP.y;
        sprintf(Cursor_Readings,"X : %d Y : %d",Cx,Cy);
        Boards_Titles();
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            get_turn();
            if((Cx>420&&Cx<620&&Cy>280&&Cy<320))        //Exit
            {
                outtextxy(460,410,"Exiting......   ");
                delay(500);
                outtextxy(460,410,"Done.           ");
                exit(0);
            }
            else if(Cx>420&&Cx<620&&Cy>180&&Cy<280)     //New Game
            {
                NewGame();
                settextstyle(1,0,1);
                outtextxy(10,60,"X's Turn");
            }
            else if(Cx>110&&Cx<210&&Cy>130&&Cy<230&&B1)         //Block-1
            {
                if(turn=='X')
                {
                    Turn_MessageX();
                    cross(150,150);
                    B1_W=1;
                }
                if(turn=='O')
                {
                    Turn_MessageO();
                    OOO(150,150);
                    B1_W=2;
                }
                B1=false;
                turn_count++;
            }
            else if(Cx>210&&Cx<310&&Cy>130&&Cy<230&&B2)         //Block-2
            {
                if(turn=='X')
                {
                    Turn_MessageX();
                    cross(250,150);
                    B2_W=1;
                }
                if(turn=='O')
                {
                    Turn_MessageO();
                    OOO(250,150);
                    B2_W=2;
                }
                B2=false;
                turn_count++;

            }
            else if(Cx>310&&Cx<410&&Cy>130&&Cy<230&&B3)         //Block-3
            {
                if(turn=='X')
                {
                    Turn_MessageX();
                    cross(350,150);
                    B3_W=1;
                }
                if(turn=='O')
                {
                    Turn_MessageO();
                    OOO(350,150);
                    B3_W=2;
                }
                B3=false;
                turn_count++;

            }
            else if(Cx>110&&Cx<210&&Cy>230&&Cy<330&&B4)         //Block-4
            {
                if(turn=='X')
                {
                    Turn_MessageX();
                    cross(150,250);
                    B4_W=1;
                }
                if(turn=='O')
                {
                    Turn_MessageO();
                    OOO(150,250);
                    B4_W=2;
                }
                B4=false;
                turn_count++;
            }
            else if(Cx>210&&Cx<310&&Cy>230&&Cy<330&&B5)         //Block-5
            {
                if(turn=='X')
                {
                    Turn_MessageX();
                    cross(250,250);
                    B5_W=1;
                }
                if(turn=='O')
                {
                    Turn_MessageO();
                    OOO(250,250);
                    B5_W=2;
                }
                B5=false;
                turn_count++;
            }
            else if(Cx>310&&Cx<410&&Cy>230&&Cy<330&&B6)         //Block-6
            {
                if(turn=='X')
                {
                    Turn_MessageX();
                    cross(350,250);
                    B6_W=1;
                }
                if(turn=='O')
                {
                    Turn_MessageO();
                    OOO(350,250);
                    B6_W=2;
                }
                B6=false;
                turn_count++;

            }
            else if(Cx>110&&Cx<210&&Cy>330&&Cy<430&&B7)         //Block-7
            {
                if(turn=='X')
                {
                    Turn_MessageX();
                    cross(150,350);
                    B7_W=1;
                }
                if(turn=='O')
                {
                    Turn_MessageO();
                    OOO(150,350);
                    B7_W=2;
                }
                B7=false;
                turn_count++;
            }
            else if(Cx>210&&Cx<310&&Cy>330&&Cy<430&&B8)         //Block-8
            {
                if(turn=='X')
                {
                    Turn_MessageX();
                    cross(250,350);
                    B8_W=1;
                }
                if(turn=='O')
                {
                    Turn_MessageO();
                    OOO(250,350);
                    B8_W=2;
                }
                B8=false;
                turn_count++;
            }
            else if(Cx>310&&Cx<410&&Cy>330&&Cy<430&&B9)         //Block-9
            {
                if(turn=='X')
                {
                    Turn_MessageX();
                    cross(350,350);
                    B9_W=1;
                }
                if(turn=='O')
                {
                    Turn_MessageO();
                    OOO(350,350);
                    B9_W=2;
                }
                B9=false;
                turn_count++;
            }
            Check_For_A_Winner();
        }
        GetStatus(Cx,Cy);
        delay(10);
    }
    getch();
    closegraph();
    return 0;
}