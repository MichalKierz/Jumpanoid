#pragma once

#include<iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Ball {
private:
	float base_speed, base_angle, base_velocity;
	size_t lastTouchedPlayer;

	sf::Texture texture;
	sf::Sprite sprite, collider;
	sf::Sound sound_hit;

	float oc_speed, oc_angle;


	void initVariables(float start_speed, float start_angle);

public:
	Ball(sf::Sprite sprt, sf::Sound sound, float start_speed = -5.f, float start_angle = 4.f, float x = 483.f, float y = 650.f);
	virtual ~Ball();

	//Accessors
	sf::Sprite& getSprite();
	sf::Sprite& getCollider();
	void changeMovement(float x, float y);
	void changeVelocity(float v);
	void changeLastTouched(size_t pid);
	const float getBaseSpeed() const;
	const float getBaseAngle() const;
	const float getBaseVelocity() const;
	const size_t getLastTouched() const;

	void updateMovement();
	void updateCollider();
	void hitSound();
	void updateWinBoundsCol(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target, float dt);
	void render(sf::RenderTarget* target);
};

