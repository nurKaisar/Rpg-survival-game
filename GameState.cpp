#include "GameState.h"

void GameState::initKeybinds()
{

	std::ifstream ifs("Config/gamestate_keybinds.ini.txt");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();

}

GameState::GameState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys, std::stack<State*>* states)
	: State(window,supportedKeys,states)
{
	this->initKeybinds();
}

GameState::~GameState()
{

}

void GameState::updateInput(const float& dt)
{

	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player.move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player.move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player.move(dt, 0, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player.move(dt, 0, 1.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();

}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target )
{
	if (!target)
		target = this->window;

		this->player.render(target);
	
}
