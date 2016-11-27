#include "MenuMine.h"
#include <iostream>
using namespace std;
MenuMine::MenuMine(float w,float h)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		cout<<"Error"<<endl;
	}
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Blue);
	menu[0].setString("Reset");
	menu[0].setCharacterSize(18);
	menu[0].setPosition(sf::Vector2f(w / 7, h / (MAX_NUMBER_OF_ITEMS + 8) * 1));
}
MenuMine::MenuMine(){
}
void MenuMine::draw(sf::RenderWindow &window){
    	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void MenuMine::MouseClik(){
    	if (selectionMenu - 1 >= 0);
	{
		menu[selectionMenu].setColor(sf::Color::White);
		selectionMenu--;
		menu[selectionMenu].setColor(sf::Color::Red);
	}
}
void MenuMine::ClockTime(float w,float h){
    	if (!font.loadFromFile("arial.ttf"))
	{
		cout<<"Error"<<endl;
	}
	menu[1].setFont(font);
	menu[1].setColor(sf::Color::Blue);

	menu[1].setString("00:00");
	menu[1].setCharacterSize(18);
	menu[1].setPosition(sf::Vector2f((w / 2)+115, h / (MAX_NUMBER_OF_ITEMS + 8) * 1));
}

