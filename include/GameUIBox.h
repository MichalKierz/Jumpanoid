#pragma once

#include<iostream>
#include <fstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class GameUIBox
{
private:
	int type, endWith, currLevel;

	sf::Sprite boxSprite;

	sf::Font font;
	sf::Text title;
	std::vector<sf::Text> box_texts;
	std::vector<sf::RectangleShape> box_blocks;
	sf::Sound sound_select;

	void initVariables(int t, int lvl);
	void initText();

public:
	//Constructors Destructors
	GameUIBox(int t, sf::Sprite sprite, sf::Sound sound, int lvl);
	virtual ~GameUIBox();

	//Accessors
	int checkEnd();

	//Functions
	void hoverDetection(sf::RenderWindow* window);
	void clickDetection(sf::RenderWindow* window);
	void update(sf::RenderWindow* window, float dt);

	void render(sf::RenderTarget* target = nullptr);
};

