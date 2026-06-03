#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Player.h"
#include "Ball.h"
#include "Brick.h"
#include "State.h"
#include "GameUIBox.h"

//Id: 3

class Game: public State {
private:
	int gameMode, pauseCooldown;
	bool gameStarted;

	sf::Font font;
	sf::Text text_gamemode, text_scorep1, text_scorep2, text_lives;

	//Box
	sf::Texture box_texture;
	sf::Sprite box_sprite;
	sf::SoundBuffer buffer_select;
	sf::Sound sound_select;
	std::stack<GameUIBox*> box;

	//Background Graphics
	sf::Texture bg_texture, ui_texture;
	sf::Sprite bg_sprite, ui_sprite;


	//Players Graphics
	sf::Texture player_texture, player_longer_texture;
	sf::Sprite player_sprite, player_longer_sprite;

	//Balls Graphics
	sf::Texture ball_texture;
	sf::Sprite ball_sprite;
	sf::SoundBuffer buffer_hit;
	sf::Sound sound_hit;

	//Bricks Graphics
	sf::Texture brick1_texture, brick2_texture, brick3_texture, brick4_texture, brick5_texture;
	sf::Sprite brick1_sprite, brick2_sprite, brick3_sprite, brick4_sprite, brick5_sprite;

	//Powerups
	sf::Texture powerup1_texture, powerup2_texture, powerup3_texture;
	sf::Sprite powerup1_sprite, powerup2_sprite, powerup3_sprite;

	std::vector<Player> players;
	std::vector<Ball> balls;
	std::vector<Brick> bricks;

	std::fstream level;

	void initVariables(int gamemode, int lvl, int lvs, int scrp1, int scrp2);
	void initGraphics();
	void initText();
	void initSound();
	void initBricks();

public:
	//Constructors Destructors
	Game(sf::RenderWindow* window, int gamemode, int lvl = 0,int lvs = 3, int scrp1 = 0, int scrp2 = 0);
	virtual ~Game();

	//Collision Help Functions
	float overlapLeft(sf::Sprite object1, sf::Sprite object2);
	float overlapRight(sf::Sprite object1, sf::Sprite object2);
	float overlapTop(sf::Sprite object1, sf::Sprite object2);
	float overlapBottom(sf::Sprite object1, sf::Sprite object2);

	//Collisions
	void playerPlayer(size_t i);
	void colBallPlayer(size_t i);
	void colBallBrick(size_t i);
	void checkIfBallFutureCol(size_t i);
	void playerStanding(size_t i);

	//Functions
	void powerupLogic(size_t i_br, size_t i_bl);
	void updateInput();
	void checkBoxEnd();
	void gameProgressionLogic();
	void gameStart();

	void scoringEvaluation(Ball ball, Brick brick);
	void update(sf::RenderWindow* window, float dt);
	void renderGui(sf::RenderTarget* target);
	void render(sf::RenderTarget* target = nullptr);

};
