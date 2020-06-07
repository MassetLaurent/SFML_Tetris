#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include "Game.h"

class Button
{
private:
	sf::RectangleShape background;
	sf::RectangleShape bottomBar;

	sf::Text label;

public:
	Button();
	virtual ~Button();

	void setColor(sf::Color _color);
	void setPosition(sf::Vector2f _pos);

	sf::FloatRect getGlobalBounds();

	void draw(sf::RenderTarget& _target);
};
#endif // !BUTTON_H
