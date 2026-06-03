#include "Player.h"

//Private Functions
void Player::initVariables(int plyrNumber, int y)
{
	this->movementSpeed = 11.f;
	this->playerNumber = plyrNumber;
	this->groundHeight = y;
	this->isJumping = false;
	this->canJump = true;
	this->isStanding = true;
	this->jumpStrength = 14;
	this->jumpValue = 0;
	this->jumpMax = 7;
	this->gravity = 1;
	this->currGravity = 0;
}

//Constructors Destructors//
Player::Player(sf::Sprite sprt, sf::Sprite lngr, int plyrNumber, float x, float y)
{
	this->sprite = sprt;
	this->longer = lngr;
	this->sprite.setPosition(x, y);
	this->initVariables(plyrNumber, y);
}

Player::~Player()
{

}

//Accessors
sf::Sprite& Player::getSprite()
{
	return this->sprite;
}

const bool Player::checkIsJumping() const
{
	return this->isJumping;
}
const float Player::getJumpStrength() const
{
	return this->jumpStrength;
}
const int Player::getGroundHeight() const
{
	return this->groundHeight;
}
void Player::changeStanding(bool val)
{
	this->isStanding = val;
}
void Player::upgradeToLonger()
{
	this->longer.setPosition(this->sprite.getPosition().x - ((this->longer.getGlobalBounds().width - this->sprite.getGlobalBounds().width) / 2), this->sprite.getPosition().y);
	this->sprite = longer;
}

//Functions
void Player::updateInput()
{
	//keyboard input
	if (this->playerNumber == 1)
	{	//Player One
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			this->sprite.move(-this->movementSpeed, 0.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->sprite.move(this->movementSpeed, 0.f);
		}

		if (this->canJump && this->isStanding && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->isJumping = true;
			this->sprite.move(0.f, -this->jumpStrength);
		}
		else
		{
			this->isJumping = false;
			this->jumpValue = 0;
		}
	}
	else
	{	//Player Two
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			this->sprite.move(-this->movementSpeed, 0.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			this->sprite.move(this->movementSpeed, 0.f);
		}

		if (this->canJump && this->isStanding && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			this->isJumping = true;
			this->sprite.move(0.f, -this->jumpStrength);
		}
		else
		{
			this->isJumping = false;
			this->jumpValue = 0;
		}
	}
}

void Player::updateWinBoundsCol()
{
	//Left
	if (this->sprite.getGlobalBounds().left <= 20.f)
	{
		this->sprite.setPosition(20.f, this->sprite.getGlobalBounds().top);
	}
	//Right
	else if (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= 960.f)
	{
		this->sprite.setPosition(960.f - this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().top);
	}
}


void Player::updatePhysics()
{
	if(this->isJumping)
	{//Jumping
		if (this->jumpValue == this->jumpMax)
		{
			this->isJumping = false;
			this->canJump = false;
			this->jumpValue = 0;
		}
		else
		{
			this->jumpValue++;
		}
	}
	else if(!this->isStanding)
	{//Falling
		if (this->sprite.getGlobalBounds().top < this->groundHeight)
		{
			if (currGravity <= 15)
			{
				this->currGravity += this->gravity;
			}
			this->sprite.move(0, this->currGravity);
		}
	}
	else
	{//Standing
		this->currGravity = 0;
		this->canJump = true;
	}
}

void Player::update(const sf::RenderTarget* target, float dt)
{
	this->updatePhysics();
	this->updateInput();
	this->updateWinBoundsCol();
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}


