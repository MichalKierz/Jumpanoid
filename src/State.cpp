#include "State.h"

State::State(sf::RenderWindow* window, int gm)
{
	this->window = window;
	this->endFrame = 0;
	this->gameMode = gm;
	this->currLevel = 0;
}

State::~State()
{
	delete this->window;
}


//Accessors
void State::endState(int nextFrame)
{
	this->endFrame = nextFrame;
}

const int State::checkEnd() const
{
	return this->endFrame;
}

const int State::checkGameMode() const
{
	return this->gameMode;
}

void State::changeGameMode(int gm)
{
	this->gameMode = gm;
}

const int State::checkLevel() const
{
	return this->currLevel;
}

void State::changeLevel(int lvl)
{
	this->currLevel = lvl;
}

const int State::checkLives() const
{
	return this->lives;
}
const int State::checkScoreP1() const
{
	return this->scorep1;
}
const int State::checkScoreP2() const
{
	return this->scorep2;
}