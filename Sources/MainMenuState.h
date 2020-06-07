#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "Game.h"
#include "State.h"
#include "Button.h"

class MainMenuState : public State
{
private:
	GameDataRef data;	
	sf::Texture backgroundT, titleT, buttonT;
	sf::RectangleShape selectBorder;
	sf::Music music;
	sf::Text play;	
	sf::Sprite background, title, onePlayerButton, twoPlayersButton, bestScores, quit;

	int selected;

public:
	MainMenuState(GameDataRef _data);
	virtual ~MainMenuState();

	
	void init();

	void handleInput();
	void update(const float &dt);
	void render(const float &dt);
};

#endif // !MAINMENUSTATE_H
