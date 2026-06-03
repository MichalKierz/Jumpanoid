#pragma once

#include<iostream>
#include<ctime>
#include<vector>
#include<stack>
#include<memory>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Game.h"
#include "MainMenu.h"

class GameStates {
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event sfmlEvent;
	sf::Clock frameClock;

	sf::SoundBuffer buffer_music;
	sf::Sound music;

	std::stack<State*> states;

	void initWindow();
	void initVariables();
	void initStates();
	void initMusic();

public:
	//Constructors Destructors
	GameStates();
	virtual ~GameStates();

	//Accessors
	const bool running() const;

	//Functions
	void pollEvents();
	void checkEndState();

	void update();
	void render();
	void runningFrame();
};