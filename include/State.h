#pragma once
#include<iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class State {
private:
	sf::RenderWindow* window;
	int endFrame, gameMode, currLevel;

public:
	int lives, scorep1, scorep2;

	//Constructor Desctructor
	State(sf::RenderWindow* window, int gm = 0);
	virtual ~State();

	//Accessors
	void endState(int nextFrame);
	const int checkEnd() const;
	const int checkGameMode() const;
	void changeGameMode(int gm);
	const int checkLevel() const;
	void changeLevel(int lvl);
	const int checkLives() const;
	const int checkScoreP1() const;
	const int checkScoreP2() const;

	//Functions
	virtual void update(sf::RenderWindow* window, float dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
