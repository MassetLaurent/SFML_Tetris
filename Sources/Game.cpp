#include "Definitions.h"
#include "Game.h"
#include "MainMenuState.h"

//constructor
Game::Game()
{
	//create window
	data->window.create(sf::VideoMode(WIDTH, HEIGHT), "SFML Tetris", sf::Style::Close);
		
	//add the first state
	data->stateMachine.addState(StateRef(new MainMenuState(data)), true);

	//run the app
	run();
}

Game::~Game()
{

}

//methode
void Game::run()
{
	float newTime, frameTime, interpolation;

	float currentTime = this->dtClock.getElapsedTime().asSeconds();

	float accumulator = 0.0f;

	while (this->data->window.isOpen())
	{
		this->data->stateMachine.processStatesChanges();

		newTime = this->dtClock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
			frameTime = 0.25f;

		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= dt)
		{
			this->data->stateMachine.getActiveState()->handleInput();
			this->data->stateMachine.getActiveState()->update(dt);

			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->data->stateMachine.getActiveState()->render(interpolation);
	}
}
