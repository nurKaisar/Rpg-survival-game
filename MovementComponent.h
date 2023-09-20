#ifndef  MOVEMENTCOMPONENT_H
#define  MOVEMENTCOMPONENT_H


#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<stack>
#include<vector>
#include<map>

#include"SFML/Graphics.hpp"
#include"SFML/Network.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"

enum movement_stats{ IDLE = 0,MOVING,MOVING_LEFT,MOVING_RIGHT,MOVING_UP,MOVING_DOWN };


class MovementComponent
{
private:
	sf::Sprite& sprite;

	float maxVelocity;
	float acceleration;
	float deceleration;

	sf::Vector2f velocity;

	//Initializer functions

public:
	MovementComponent(sf::Sprite& sprite,float maxVelocity,float accelereation,float decelertion);
	virtual ~MovementComponent();


	//Accessors
	const float& getMaxVelocity()const;
	const sf::Vector2f& getVelocity() const;

	//Functions
	const bool getState(const short unsigned state) const;


	void move(const float x, const float y, const float& dt);
	void update(const float& dt);

};
#endif 

