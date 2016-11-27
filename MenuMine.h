#ifndef MENUMINE_H_INCLUDED
#define MENUMINE_H_INCLUDED
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3
class MenuMine{
private:
    int selectionMenu;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Clock timeClock;

public:
    MenuMine();
    MenuMine(float w,float h);
	void draw(sf::RenderWindow &window);
	void MouseClik();
	void ClockTime(float w,float h);
	int GetPressedItem() { return selectionMenu;}
};



#endif // MENUMINE_H_INCLUDED
