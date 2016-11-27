#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include "MenuMine.h"
using namespace std;
using namespace sf;
class Minesweeper
{
public:
    int w=32;
    int grid[14][14];
    int sgrid[14][14];
    int countBomb=0;
    int signed bomb=0;
    sf::Event event;
    sf::Texture t;
    sf::Text show;
    bool reset=false;
    //sf::RenderWindow window;
    void RandomBomb()
    {
        for(int i=2; i<12; i++)
            for(int j=2; j<12; j++)
            {
                sgrid[i][j]=10;
                if(rand()%10==1&&countBomb!=10)
                {
                    grid[i][j]=9;
                    countBomb++;
                }
                else
                {
                    grid[i][j]=0;
                }
            }
    }
    void FindBomb()
    {
        for(int i=2; i<12; i++)
            for(int j=2; j<12; j++)
            {
                int bomb=0;
                if(grid[i][j]!=9)
                {
                    if(grid[i][j-1]==9)
                    {
                        bomb++;
                    }
                    if(grid[i][j+1]==9)
                    {
                        bomb++;
                    }
                    if(grid[i-1][j]==9)
                    {
                        bomb++;
                    }
                    if(grid[i+1][j]==9)
                    {
                        bomb++;
                    }
                    if(grid[i-1][j-1]==9)
                    {
                        bomb++;
                    }
                    if(grid[i-1][j+1]==9)
                    {
                        bomb++;
                    }
                    if(grid[i+1][j-1]==9)
                    {
                        bomb++;
                    }
                    if(grid[i+1][j+1]==9)
                    {
                        bomb++;
                    }
                    grid[i][j]=bomb;
                }
            }
    }
    void PrintBomb()
    {
        for(int i=2; i<12; i++)
        {
            for(int j=2; j<12; j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void locationMouse(int y,int x)
    {

        if(event.type==sf::Event::MouseButtonPressed)
        {
            cout << y << " " << x << endl;
            if(event.key.code==sf::Mouse::Left)
            {
                if(sgrid[y][x]!=11)
                {
                    sgrid[y][x]=grid[y][x];
                }
                if(sgrid[y][x]==sgrid[1][2]||sgrid[y][x]==sgrid[1][3])
                {
                    reset=true;
                }
            }
            else if(event.key.code==sf::Mouse::Right)
            {
                if (sgrid[y][x]==10)
                {
                    sgrid[y][x]=11;
                    if(sgrid[y][x]==11&&grid[y][x]==9)
                    {
                        bomb++;
                    }
                }
                else if(sgrid[y][x]==11)
                {
                    sgrid[y][x]=10;
                    if(sgrid[y][x]==10&&grid[y][x]==9)
                    {
                        bomb--;
                    }
                }
                else if((sgrid[y][x]!=0)&&(sgrid[y][x]!=1)&&(sgrid[y][x]!=2)&&(sgrid[y][x]!=3)&&(sgrid[y][x]!=4))
                {
                    sgrid[y][x]=11;
                }
            }
            cout<<bomb<<" ";
        }
    }
    void lostgame()
    {
        for(int i=2; i<12; i++)
            for(int j=2; j<12; j++)
            {
                sgrid[i][j]=grid[i][j];
            }
    }
    void Wang(int y,int x){
    }

///////
public:
    Minesweeper()
    {
        sf::RenderWindow window(sf::VideoMode(450,400), "SFML Minesweeper");
        srand(time(0));
        MenuMine menu(window.getSize().x,window.getSize().y);
        menu.ClockTime(window.getSize().x,window.getSize().y);
        t.loadFromFile("tiles.jpg");
        sf::Sprite s(t);
        RandomBomb();
        FindBomb();
        PrintBomb();
        int i=0,j=0;
        while(window.isOpen())
        {
            sf::Vector2i location=sf::Mouse::getPosition(window);
            int x=location.x/w;
            int y=location.y/w;
            while(window.pollEvent(event))
            {
                if(event.type==sf::Event::Closed)
                {
                    window.close();
                }
                locationMouse(y,x);
            }
            window.clear(sf::Color::Black);
            for( i=2; i<12; i++)
                for( j=2; j<12; j++)
                {
                    if(sgrid[i][j]==9)
                    {
                        lostgame();
                    }
                    else if(reset)
                    {
                        reset=false;
                        window.close();
                        Minesweeper();
                    }
                    s.setTextureRect(sf::IntRect(sgrid[i][j]*w,0,w,w));
                    s.setPosition(j*w,i*w);
                    window.draw(s);
                }
            menu.draw(window);
            window.display();
        }
    }
};
int main()
{
    Minesweeper s;
    return 0;
}
