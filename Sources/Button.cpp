#include "Definitions.h"
#include "Button.h"

Button::Button()
{
	
}

Button::~Button()
{
}

void Button::setColor(sf::Color _color)
{
	bottomBar.setFillColor(_color);
}

void Button::setPosition(sf::Vector2f _pos)
{
	background.setPosition(_pos);

	bottomBar.setPosition(background.getPosition().x, // X axis
		background.getPosition().y + background.getGlobalBounds().height - bottomBar.getGlobalBounds().height
	);

}

sf::FloatRect Button::getGlobalBounds()
{
	return background.getGlobalBounds();
}

void Button::draw(sf::RenderTarget & _target)
{
	_target.draw(background);
	_target.draw(bottomBar);
}
