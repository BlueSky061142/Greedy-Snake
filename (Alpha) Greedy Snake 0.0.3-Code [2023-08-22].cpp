/*
(Alpha) Greedy Snake 0.0.3-Code [2023-08-22]
*/
#include<bits/stdc++.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
using namespace std;
bool gameOver;
bool judge;
const int width=60;
const int height=30;
int x,y;
int fruitX,fruitY;
int score;
int tailX[100],tailY[100];
int nTail;
int speed;
string characters;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
time_t startTime;
void Setup()
{
    dir=STOP;
    x=width/2;
    y=height/2;
    srand(time(NULL));
    fruitX=rand()%width;
    fruitY=rand()%height;
    startTime=time(NULL);
    nTail=0;
    score=0;
}
void Draw()
{
    system("cls");
    cout<<"(Alpha) Greedy Snake 0.0.3 [2023-08-22] | "<<characters<<endl<<endl;
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
	for(int i=0;i<10;i++)
	{
		system("cls");
		cout<<"(Alpha) Greedy Snake 0.0.3 [2023-08-22]"<<endl<<endl;
		cout<<"Loading ";
		for(int j=0;j<3;j++)
		{
			Sleep(1000);
			cout<<".";
		}
		Sleep(1000);
	}
	system("cls");
	cout<<"(Alpha) Greedy Snake 0.0.3 [2023-08-22]"<<endl<<endl;
	cout<<"Game Character"<<endl<<endl;
	cout<<"0  Snake Shadow Dance"<<endl<<endl;
	cout<<"1  Gourmet Dragon"<<endl<<endl;
	cout<<"2  Snake Eating Demon"<<endl<<endl;
	cout<<"3  Greedy Python"<<endl<<endl;
	cout<<"4  Snakes Roam The World"<<endl<<endl;
	cout<<"5  Food World Hegemon"<<endl<<endl;
	cout<<"6  Snake Language Ghost"<<endl<<endl;
	cout<<"7  Incarnation Of The God Of Food"<<endl<<endl;
	cout<<"8  Greedy Snake"<<endl<<endl;
	cout<<"9  Snake Dance Wind And Cloud"<<endl;
	while(true)
	{
		switch(_getch())
		{
    		case '0':
    			Beep(500,500);
    			judge=true;
    			characters="Snake Shadow Dance";
        	    break;
        	case '1':
        		Beep(500,500);
        		judge=true;
    			characters="Gourmet Dragon";
        	    break;
        	case '2':
        		Beep(500,500);
        		judge=true;
    			characters="Snake Eating Demon";
        	    break;
        	case '3':
        		Beep(500,500);
        		judge=true;
    			characters="Greedy Python";
        	    break;
        	case '4':
        		Beep(500,500);
        		judge=true;
    			characters="Snakes Roam The World";
        	    break;
        	case '5':
        		Beep(500,500);
        		judge=true;
    			characters="Food World Hegemon";
        	    break;
        	case '6':
        		Beep(500,500);
        		judge=true;
    			characters="Snake Language Ghost";
        	    break;
        	case '7':
        		Beep(500,500);
        		judge=true;
    			characters="Incarnation Of The God Of Food";
        	    break;
        	case '8':
        		Beep(500,500);
        		judge=true;
    			characters="Greedy Snake";
        	    break;
        	case '9':
        		Beep(500,500);
        		judge=true;
    			characters="Snake Dance Wind And Cloud";
        	    break;
    	}
    	if(judge)
    	{
    		judge=false;
    		break;
		}
	}
	while(true)
	{
		system("cls");
		cout<<"(Alpha) Greedy Snake 0.0.3 [2023-08-22] | "<<characters<<endl<<endl;
		cout<<"Game Mode"<<endl<<endl;
		cout<<"0  Simple"<<endl<<endl;
		cout<<"1  Medium"<<endl<<endl;
		cout<<"2  Difficulty"<<endl;
		while(true)
		{
			switch(_getch())
			{
    			case '0':
    				Beep(500,500);
    				judge=true;
    				speed=75;
            		break;
        		case '1':
        			Beep(500,500);
        			judge=true;
    				speed=50;
            		break;
        		case '2':
        			Beep(500,500);
        			judge=true;
    				speed=25;
            		break;
    		}
    		if(judge)
    		{
    			judge=false;
    			break;
			}
		}
		system("cls");
		cout<<"(Alpha) Greedy Snake 0.0.3 [2023-08-22] | "<<characters<<endl<<endl;
		cout<<"3"<<endl;
		Sleep(1000);
		system("cls");
		cout<<"(Alpha) Greedy Snake 0.0.3 [2023-08-22] | "<<characters<<endl<<endl;
		cout<<"2"<<endl;
		Sleep(1000);
		system("cls");
		cout<<"(Alpha) Greedy Snake 0.0.3 [2023-08-22] | "<<characters<<endl<<endl;
		cout<<"1"<<endl;
		Sleep(1000);
		system("cls");
		cout<<"(Alpha) Greedy Snake 0.0.3 [2023-08-22] | "<<characters<<endl<<endl;
		cout<<"Start"<<endl;
		Sleep(1000);
    	Setup();
    	while(!gameOver)
		{
    	    Draw();
    	    Input();
    	    Logic();
    	    Sleep(speed);
    	}
    	if(gameOver)
    	{
    		gameOver=false;
    		system("cls");
    		cout<<"(Alpha) Greedy Snake 0.0.3 [2023-08-22] | "<<characters<<endl<<endl;
    		cout<<"Score  "<<score<<" Points"<<endl<<endl;
    		cout<<"Time  "<<time(NULL)-startTime<<" Seconds"<<endl;
    		Sleep(5000);
		}
	}
    return 0;
}
