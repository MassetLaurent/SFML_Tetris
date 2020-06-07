#include "Definitions.h"
#include "MainMenuState.h"
//#include "PlayState.h"

MainMenuState::MainMenuState(GameDataRef _data) : data(_data)
{
	//textures
	this->data->assetManager.loadTexture("mainMenuBackground", MAIN_MENU_BAKGROUND_FILEPATH);
	this->data->assetManager.loadTexture("title", TITLE_IMAGE_FILEPATH);
	this->data->assetManager.loadTexture("button", "Resources/images/button.png");
	/*
	backgroundT.loadFromFile(MAIN_MENU_BAKGROUND_FILEPATH);
	titleT.loadFromFile(TITLE_IMAGE_FILEPATH);
	buttonT.loadFromFile("Resources/images/button.png");
	*/
	background.setTexture(this->data->assetManager.getTexture("mainMenuBackground"));

	title.setTexture(this->data->assetManager.getTexture("title"));
	title.setPosition((this->data->window.getSize().x / 2) - title.getGlobalBounds().width / 2,
		50);
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::init()
{
	//buttons
	onePlayerButton.setTexture(this->data->assetManager.getTexture("button"));
	onePlayerButton.setScale(0.8f,1.f);
	onePlayerButton.setColor(sf::Color(0, 100, 200, 200));
	onePlayerButton.setPosition((title.getGlobalBounds().left + title.getGlobalBounds().width /2) - (onePlayerButton.getGlobalBounds().width / 2), title.getGlobalBounds().top + 300.f);

	twoPlayersButton = onePlayerButton;
	twoPlayersButton.setPosition(onePlayerButton.getPosition().x, onePlayerButton.getPosition().y + 70.f);
	twoPlayersButton.setColor(sf::Color(230, 15, 20, 200));

	bestScores = onePlayerButton;
	bestScores.setPosition(twoPlayersButton.getPosition().x, twoPlayersButton.getPosition().y + 70.f);
	bestScores.setColor(sf::Color(30, 150, 20, 200));

	quit = onePlayerButton;
	quit.setPosition(twoPlayersButton.getPosition().x, bestScores.getPosition().y + 70.f);
	quit.setColor(sf::Color(120, 15, 100, 200));
	
	selectBorder.setSize(sf::Vector2f(onePlayerButton.getGlobalBounds().width - 20.f, 0.f));
	selectBorder.setPosition(sf::Vector2f(onePlayerButton.getGlobalBounds().left + 10, (onePlayerButton.getGlobalBounds().top)));
	selectBorder.setFillColor(sf::Color::Transparent);
	selectBorder.setOutlineColor(sf::Color::Cyan);
	selectBorder.setOutlineThickness(3.f);

	selected = 1;

	//init music
	//music.openFromFile("Resources/sounds/tetris.ogg");
	//music.play();
}

void MainMenuState::handleInput()
{
	sf::Event sfmlEvents;

	while (this->data->window.pollEvent(sfmlEvents))
	{
		if (sfmlEvents.type == sf::Event::Closed)
			this->data->window.close();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			this->data->window.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			selected++;
			if (selected > 4)
				selected = 1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			selected--;
			if (selected < 1)
				selected = 4;
		}

		//if (startText.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->data->window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			//this->data->stateMachine.addState(StateRef(new PlayState(data)), false);
	}
}


void MainMenuState::update(const float & dt)
{
	switch (selected)
	{
	case 1:
	{
		selectBorder.setPosition(selectBorder.getPosition().x, onePlayerButton.getPosition().y);
		break;
	}
	case 2:
	{
		selectBorder.setPosition(selectBorder.getPosition().x, twoPlayersButton.getPosition().y);
		break;
	}
	case 3:
	{
		selectBorder.setPosition(selectBorder.getPosition().x, bestScores.getPosition().y);
		break;
	}
	case 4:
	{
		selectBorder.setPosition(selectBorder.getPosition().x, quit.getPosition().y);
		break;
	}
	default:
		break;
	}
}

void MainMenuState::render(const float & dt)
{
	data->window.clear();

	data->window.draw(background);
	data->window.draw(title);
	data->window.draw(onePlayerButton);
	data->window.draw(bestScores);
	data->window.draw(twoPlayersButton);
	data->window.draw(quit);
	data->window.draw(selectBorder);

	data->window.display();
}
