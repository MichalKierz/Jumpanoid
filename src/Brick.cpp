#include "Brick.h"

//Private Functions
void Brick::initVariables(int lf, int pu)
{
	this->life = lf;
	this->powerup = pu;
}

void Brick::initGraphics(float x, float y, sf::Sprite pwrup, sf::Sprite sprt1, sf::Sprite sprt2, sf::Sprite sprt3, sf::Sprite sprt4, sf::Sprite sprt5)
{
	this->sprite1 = sprt1;
	this->sprite2 = sprt2;
	this->sprite3 = sprt3;
	this->sprite4 = sprt4;
	this->sprite5 = sprt5;

	switch (life)
	{
		case 1: this->mainSprite = this->sprite1; break;
		case 2: this->mainSprite = this->sprite2; break;
		case 3: this->mainSprite = this->sprite3; break;
		case 4: this->mainSprite = this->sprite4; break;
		case 5: this->mainSprite = this->sprite5; break;
		default: this->mainSprite = this->sprite5; break;
	}

	this->mainSprite.setPosition(x, y);

	if (this->powerup > 0)
	{
		this->powerupSprite = pwrup;
		float pu_x, pu_y;
		pu_x = this->mainSprite.getGlobalBounds().left + (this->mainSprite.getGlobalBounds().width / 2) - (powerupSprite.getGlobalBounds().width / 2);
		pu_y = this->mainSprite.getGlobalBounds().top + (this->mainSprite.getGlobalBounds().height / 2) - (powerupSprite.getGlobalBounds().height / 2);
		this->powerupSprite.setPosition(pu_x, pu_y);
	}
}

//Constructors Destructors//
Brick::Brick(float x, float y, int lf, int pu, sf::Sprite pwrup, sf::Sprite sprt1, sf::Sprite sprt2, sf::Sprite sprt3, sf::Sprite sprt4, sf::Sprite sprt5)
{
	this->initVariables(lf, pu);
	this->initGraphics(x, y, pwrup, sprt1, sprt2, sprt3, sprt4, sprt5);
	
}

Brick::~Brick()
{

}

//Accessors
const sf::Sprite& Brick::getSprite() const
{
	return this->mainSprite;
}
void Brick::substrLife()
{
	this->life -= 1;
	switch (life)
	{
		case 1: this->sprite1.setPosition(this->mainSprite.getPosition().x, this->mainSprite.getPosition().y); this->mainSprite = this->sprite1; break;
		case 2: this->sprite2.setPosition(this->mainSprite.getPosition().x, this->mainSprite.getPosition().y); this->mainSprite = this->sprite2; break;
		case 3: this->sprite3.setPosition(this->mainSprite.getPosition().x, this->mainSprite.getPosition().y); this->mainSprite = this->sprite3; break;
		case 4: this->sprite4.setPosition(this->mainSprite.getPosition().x, this->mainSprite.getPosition().y); this->mainSprite = this->sprite4; break;
		case 5: this->sprite5.setPosition(this->mainSprite.getPosition().x, this->mainSprite.getPosition().y); this->mainSprite = this->sprite5; break;
	}
}

const int Brick::checkLife() const
{
	return this->life;
}

const int Brick::checkPowerup() const
{
	return this->powerup;
}

//Functions
void Brick::update(const sf::RenderTarget* target, float dt)
{

}

void Brick::render(sf::RenderTarget* target)
{
	target->draw(this->mainSprite);
	target->draw(this->powerupSprite);
}