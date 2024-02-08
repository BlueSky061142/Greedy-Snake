/*
(Alpha) Greedy Snake 0.0.2-Code [2023-08-16]
*/
#include<bits/stdc++.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
using namespace std;
bool gameOver;
const int width=60;
const int height=30;
int x,y;
int fruitX,fruitY;
int score;
int tailX[100],tailY[100];
int nTail;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
time_t startTime;
void Setup()
{
	gameOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    srand(time(NULL));
    fruitX=rand()%width;
    fruitY=rand()%height;
    startTime=time(NULL);
    score=0;
}
void Draw()
{
    system("cls");
    cout<<"(Alpha) Greedy Snake 0.0.2 [2023-08-16]"<<endl<<endl;
    cout<<"Score  "<<score<<" Points"<<endl<<endl;
    cout<<"Time  "<<time(NULL)-startTime<<" Seconds"<<endl<<endl;
    for(int i=0;i<width+2;i++)
    {
    	cout<<"#";
	}
    cout<<endl;
    for(int i=0;i<height;i++)
	{
        for(int j=0;j<width;j++)
		{
            if(j==0)
            {
            	cout<<"#";
			}
            if(i==y&&j==x)
            {
            	cout<<"O";
			}
            else if(i==fruitY&&j==fruitX)
            {
            	cout<<"*";
			}
            else
			{
                bool printTail=false;
                for(int k=0;k<nTail;k++)
				{
                    if(tailX[k]==j&&tailY[k]==i)
					{
                        cout<<"o";
                        printTail=true;
                    }
                }
                if(!printTail)
                {
                	cout<<" ";
				}
            }
            if(j==width-1)
            {
            	cout<<"#";
			}
        }
        cout<<endl;
    }
    for(int i=0;i<width+2;i++)
    {
    	cout<<"#";
	}
    cout<<endl<<endl;
    cout<<"Press W To Up | Press S To Down | Press A To Left | Press D To Right | Press Esc To End"<<endl;
}
void Input()
{
    if(_kbhit())
	{
        switch(_getch())
		{
        	case 'a':
            	dir=LEFT;
            	break;
            case 'A':
            	dir=LEFT;
            	break;
        	case 'd':
            	dir=RIGHT;
            	break;
            case 'D':
            	dir=RIGHT;
            	break;
        	case 'w':
            	dir=UP;
            	break;
            case 'W':
            	dir=UP;
            	break;
        	case 's':
            	dir=DOWN;
            	break;
            case 'S':
            	dir=DOWN;
            	break;
            case 27:
				gameOver=true;
            	break;
        }
    }
}
void Logic()
{
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<nTail;i++)
	{
		prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    switch(dir)
	{
    	case LEFT:
        	x--;
        	break;
		case RIGHT:
        	x++;
        	break;
    	case UP:
        	y--;
        	break;
    	case DOWN:
        	y++;
        	break;
    	default:
        	break;
    }
    if(x==fruitX&&y==fruitY)
	{
        score++;
        do
		{
        	srand(time(NULL));
        	fruitX=rand()%width;
        	fruitY=rand()%height;
		}while(fruitX==0||fruitX==width-1||fruitY==0||fruitY==height-1);
        nTail++;
    }
    if(x<0||x>width-1||y<0||y>height-1)
	{
		gameOver=true;
	}
}
int main()
{
	MessageBox(NULL,"Press OK To Start The Game.","(Alpha) Greedy Snake 0.0.2 [2023-08-16]",MB_OK);
    Setup();
    while(!gameOver)
	{
        Draw();
        Input();
        Logic();
        Sleep(50);
    }
    if(gameOver)
    {
    	system("cls");
    	cout<<"(Alpha) Greedy Snake 0.0.2 [2023-08-16]"<<endl<<endl;
    	cout<<"Game Is Over."<<endl<<endl;
    	cout<<"Score  "<<score<<" Points"<<endl<<endl;
    	cout<<"Time  "<<time(NULL)-startTime<<" Seconds"<<endl;
    	while(true)
    	{
    		;
		}
	}
    return 0;
}
