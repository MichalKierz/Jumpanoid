#pragma once
#include<iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player {
private:
	float movementSpeed;
	int playerNumber, groundHeight;
	bool canJump, isJumping, isStanding;
	float jumpStrength, gravity, currGravity;
	int jumpValue, jumpMax;

	sf::Sprite sprite, longer;

	void initVariables(int plyrNumber, int y);

public:
	Player(sf::Sprite sprt, sf::Sprite lngr, int plyrNumber = 1, float x = 432.f, float y = 682.f);
	virtual ~Player();

	//Accessors
	sf::Sprite& getSprite();
	const bool checkIsJumping() const;
	const float getJumpStrength() const;
	const int getGroundHeight() const;
	void changeStanding(bool val);
	void upgradeToLonger();

	void updateInput();
	void updateWinBoundsCol();
	void updatePhysics();
	void update(const sf::RenderTarget* target, float dt);

	void render(sf::RenderTarget* target);

};