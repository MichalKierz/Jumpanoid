#pragma once

#include<iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Brick {
private:
	int life, powerup;
	sf::Sprite mainSprite, powerupSprite, sprite1, sprite2, sprite3, sprite4, sprite5;

	void initGraphics(float x, float y, sf::Sprite pwrup, sf::Sprite sprt1, sf::Sprite sprt2, sf::Sprite sprt3, sf::Sprite sprt4, sf::Sprite sprt5);
	void initVariables(int lf, int pu);
public:
	Brick(float x, float y, int lf, int pu, sf::Sprite pwrup, sf::Sprite sprt1, sf::Sprite sprt2, sf::Sprite sprt3, sf::Sprite sprt4, sf::Sprite sprt5);
	virtual ~Brick();

	//Accessors
	const sf::Sprite& getSprite() const;
	void substrLife();
	const int checkLife() const;
	const int checkPowerup() const;

	//Functions
	void update(const sf::RenderTarget* target, float dt);
	void render(sf::RenderTarget* target);
};

