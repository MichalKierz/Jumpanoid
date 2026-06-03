#include "Ball.h"

//Private Functions
void Ball::initVariables(float start_speed, float start_angle)
{
	this->base_speed = start_speed;
	this->oc_speed = this->base_speed;
	this->base_angle = start_angle;
	this->oc_angle = this->base_angle;
	this->base_velocity = 1.f;
	this->lastTouchedPlayer = 0;
}

//Constructors Destructors//
Ball::Ball(sf::Sprite sprt, sf::Sound sound, float start_speed, float start_angle, float x, float y)
{
	this->sprite = sprt;
	this->sprite.setPosition(x, y);
	this->sound_hit = sound;
	this->collider = sprt;
	this->collider.setPosition(x, y);
	this->initVariables(start_speed, start_angle);
}

Ball::~Ball()
{

}

//Accessors
sf::Sprite& Ball::getSprite()
{
	return this->sprite;
}

sf::Sprite& Ball::getCollider()
{
	return this->sprite;
}

void Ball::changeMovement(float x, float y)
{
	this->base_angle = x;
	this->base_speed = y;
}

void Ball::changeVelocity(float v)
{
	this->base_velocity = v;
}

void Ball::changeLastTouched(size_t pid)
{
	this->lastTouchedPlayer = pid;
}

const float Ball::getBaseSpeed() const
{
	return this->base_speed;
}

const float Ball::getBaseAngle() const
{
	return this->base_angle;
}
const float Ball::getBaseVelocity() const
{
	return this->base_velocity;
}
const size_t Ball::getLastTouched() const
{
	return this->lastTouchedPlayer;
}

//Functions
void Ball::updateCollider()
{
	this->collider.setPosition(this->sprite.getPosition().x + this->base_angle, this->sprite.getPosition().y + this->base_speed * this->base_velocity);
}

void Ball::updateMovement()
{
	this->sprite.move(this->base_angle, this->base_speed * this->base_velocity);
	if (this->base_velocity > 1) { this->base_velocity -= 0.02; }
}

void Ball::hitSound()
{
	if (this->oc_speed / abs(this->oc_speed) != this->base_speed / abs(this->base_speed)
		|| this->oc_angle / abs(this->oc_angle) != this->base_angle / abs(this->base_angle))
	{
		std::cout << "hit!" << std::endl;
		sound_hit.play();
	}

	oc_speed = base_speed;
	oc_angle = base_angle;
}

void Ball::updateWinBoundsCol(const sf::RenderTarget* target)
{
	//Left
	if (this->sprite.getGlobalBounds().left <= 20.f)
	{
		this->sprite.setPosition(20.f, this->sprite.getGlobalBounds().top);
		changeMovement(-base_angle, base_speed);
	}

	//Right
	else if (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= 960.f)
	{
		this->sprite.setPosition(960.f - this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().top);
		changeMovement(-base_angle, base_speed);
	}

	//Top
	if (this->sprite.getGlobalBounds().top <= 20.f)
	{
		this->sprite.setPosition(this->sprite.getGlobalBounds().left, 20.f);
		changeMovement(base_angle, -base_speed);
	}
}

void Ball::update(const sf::RenderTarget* target, float dt)
{
	this->updateMovement();
	this->updateWinBoundsCol(target);
	this->updateCollider();
	this->hitSound();
}

void Ball::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}