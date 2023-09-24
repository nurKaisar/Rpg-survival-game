#include"stdafx.h"
#include "Tile.h"


Tile::Tile()
{
	this->collision = false;
	this->type = 0;
}

Tile::Tile(int x,int y,float gridSizeF, const sf::Texture& texture, const sf::IntRect& texture_rect,
bool collison ,short type)
{
	this->shape.setSize(sf::Vector2f(gridSizeF, gridSizeF));
	this->shape.setFillColor(sf::Color::White);
	//this->shape.setOutlineThickness(1.f);
	//this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setPosition(static_cast<float>(x) * gridSizeF, static_cast<float>(y) *gridSizeF);
	this->shape.setTexture(&texture);
	this->shape.setTextureRect(texture_rect);

	this->collision = collison;
	this->type = type;
}

Tile::~Tile()
{

}


const short& Tile::getType() const
{
	return this->type;
}

const sf::Vector2f& Tile::getPosition() const
{
	return this->shape.getPosition();
}

const bool& Tile::getCollision() const
{
	return this->collision;
}

const sf::FloatRect Tile::getGlobalBounds() const
{
	return this->shape.getGlobalBounds();
}

const bool Tile::intersects(const sf::FloatRect bounds) const
{
	return this->shape.getGlobalBounds().intersects(bounds);
}

//Functions
const std::string Tile::getAsString() const
{
	std::stringstream ss;

	ss << this->shape.getTextureRect().left << " " << this->shape.getTextureRect().top
		<< " " <<this->collision << " " << this->type;

	return ss.str();
}

void Tile::update()
{

}

void Tile::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

