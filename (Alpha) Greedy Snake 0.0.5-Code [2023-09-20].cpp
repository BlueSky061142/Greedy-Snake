/*
(Alpha) Greedy Snake 0.0.5-Code [2023-09-20]
*/
#include<bits/stdc++.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
using namespace std;
bool gameOver,gameExit;
bool judge;
int width;
int height;
int x,y;
int fruitX,fruitY;
int fruit,fruitAll;
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
    fruit=0;
}
void Draw()
{
    system("cls");
    cout<<"(Alpha) Greedy Snake 0.0.5 [2023-09-20]  < "<<characters<<" >"<<endl<<endl;
    cout<<time(NULL)-startTime<<" Seconds"<<endl<<endl;
    cout<<fruit<<" Fruits"<<endl<<endl;
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
            	if(characters=="Snake Shadow Dance")
            	{
            		cout<<"S";
				}
				else if(characters=="Gourmet Dragon")
				{
					cout<<"G";
				}
				else if(characters=="Snake Eating Demon")
				{
					cout<<"S";
				}
				else if(characters=="Greedy Python")
				{
					cout<<"G";
				}
				else if(characters=="Snakes Roam The World")
				{
					cout<<"S";
				}
				else if(characters=="Food World Hegemon")
				{
					cout<<"F";
				}
				else if(characters=="Snake Language Ghost")
				{
					cout<<"S";
				}
				else if(characters=="Incarnation Of The God Of Food")
				{
					cout<<"I";
				}
				else if(characters=="Greedy Snake")
				{
					cout<<"G";
				}
				else if(characters=="Snake Dance Wind And Cloud")
				{
					cout<<"S";
				}
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
    cout<<endl;
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
            	gameExit=true;
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
        fruit++;
        fruitAll++;
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
		cout<<"(Alpha) Greedy Snake 0.0.5 [2023-09-20]"<<endl<<endl;
		cout<<"Loading"<<endl;
		Sleep(1000);
		system("cls");
		cout<<"(Alpha) Greedy Snake 0.0.5 [2023-09-20]"<<endl<<endl;
		cout<<"Loading ."<<endl;
		Sleep(1000);
		system("cls");
		cout<<"(Alpha) Greedy Snake 0.0.5 [2023-09-20]"<<endl<<endl;
		cout<<"Loading .o"<<endl;
		Sleep(1000);
		system("cls");
		cout<<"(Alpha) Greedy Snake 0.0.5 [2023-09-20]"<<endl<<endl;
		cout<<"Loading .o O"<<endl;
		Sleep(1000);
	}
	system("cls");
	cout<<"(Alpha) Greedy Snake 0.0.5 [2023-09-20]"<<endl<<endl;
	cout<<"{ Characters }"<<endl<<endl;
	cout<<"0  Snake Shadow Dance              Soooo"<<endl;
	cout<<"1  Gourmet Dragon                  Goooo"<<endl;
	cout<<"2  Snake Eating Demon              Soooo"<<endl;
	cout<<"3  Greedy Python                   Goooo"<<endl;
	cout<<"4  Snakes Roam The World           Soooo"<<endl;
	cout<<"5  Food World Hegemon              Foooo"<<endl;
	cout<<"6  Snake Language Ghost            Soooo"<<endl;
	cout<<"7  Incarnation Of The God Of Food  Ioooo"<<endl;
	cout<<"8  Greedy Snake                    Goooo"<<endl;
	cout<<"9  Snake Dance Wind And Cloud      Soooo"<<endl;
	while(true)
	{
		switch(_getch())
		{
    		case '0':
    			judge=true;
    			characters="Snake Shadow Dance";
        	    break;
        	case '1':
        		judge=true;
    			characters="Gourmet Dragon";
        	    break;
        	case '2':
        		judge=true;
    			characters="Snake Eating Demon";
        	    break;
        	case '3':
        		judge=true;
    			characters="Greedy Python";
        	    break;
        	case '4':
        		judge=true;
    			characters="Snakes Roam The World";
        	    break;
        	case '5':
        		judge=true;
    			characters="Food World Hegemon";
        	    break;
        	case '6':
        		judge=true;
    			characters="Snake Language Ghost";
        	    break;
        	case '7':
        		judge=true;
    			characters="Incarnation Of The God Of Food";
        	    break;
        	case '8':
        		judge=true;
    			characters="Greedy Snake";
        	    break;
        	case '9':
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
		cout<<"(Alpha) Greedy Snake 0.0.5 [2023-09-20]  < "<<fruitAll<<" Fruits >"<<endl<<endl;
		cout<<"{ Modes }"<<endl<<endl;
		cout<<"0  Simple      ."<<endl;
		cout<<"1  Medium      .o"<<endl;
		cout<<"2  Difficulty  .o O"<<endl;
		while(true)
		{
			switch(_getch())
			{
    			case '0':
    				judge=true;
    				width=60;
    				height=30;
    				speed=75;
            		break;
        		case '1':
        			judge=true;
        			width=50;
    				height=25;
    				speed=50;
            		break;
        		case '2':
        			judge=true;
        			width=40;
    				height=20;
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
		cout<<"(Alpha) Greedy Snake 0.0.5 [2023-09-20]  < "<<characters<<" >"<<endl<<endl;
		cout<<"3"<<endl;
		Sleep(1000);
		system("cls");
		cout<<"(Alpha) Greedy Snake 0.0.5 [2023-09-20]  < "<<characters<<" >"<<endl<<endl;
		cout<<"2"<<endl;
		Sleep(1000);
		system("cls");
		cout<<"(Alpha) Greedy Snake 0.0.5 [2023-09-20]  < "<<characters<<" >"<<endl<<endl;
		cout<<"1"<<endl;
		Sleep(1000);
		system("cls");
		cout<<"(Alpha) Greedy Snake 0.0.5 [2023-09-20]  < "<<characters<<" >"<<endl<<endl;
		cout<<"Start"<<endl;
		Sleep(1000);
    	Setup();
    	while(!gameOver)
		{
    	    Draw();
    	    Input();
    	    Logic();
    	    Sleep(speed);
    	    if(gameExit)
    		{
    			gameExit=false;
    			system("cls");
    			cout<<"(Alpha) Greedy Snake 0.0.5 [2023-09-20]  < "<<characters<<" >"<<endl<<endl;
    			cout<<"The Greedy Snake Stop."<<endl<<endl;
    			cout<<"+ "<<fruit<<" Fruits"<<endl;
    			Sleep(10000);
    			break;
			}
    	}
    	if(gameOver)
    	{
    		gameOver=false;
    		system("cls");
    		cout<<"(Alpha) Greedy Snake 0.0.5 [2023-09-20]  < "<<characters<<" >"<<endl<<endl;
    		cout<<"The Greedy Snake Hit The Wall."<<endl<<endl;
    		cout<<"+ "<<fruit<<" Fruits"<<endl;
    		Sleep(10000);
		}
	}
    return 0;
}
