#pragma once
#include<iostream>
#include<vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "State.h"

//Id: 1

class MainMenu: public State{
private:
	int clickCooldown;

	sf::Font font_title, font_buttons;
	sf::Text text_title;
	std::vector<sf::Text> menu_texts;
	std::vector<sf::RectangleShape> menu_blocks;
	sf::SoundBuffer buffer_select;
	sf::Sound sound_select;

	void initVariables();
	void initText();
	void initSound();

public:
	//Constructors Destructors
	MainMenu(sf::RenderWindow* window = nullptr);
	virtual ~MainMenu();

	//Functions
	void hoverDetection(sf::RenderWindow* window);
	void clickDetection(sf::RenderWindow* window);
	void update(sf::RenderWindow* window, float dt);

	void renderGui(sf::RenderTarget* target);
	void render(sf::RenderTarget* target = nullptr);
};

