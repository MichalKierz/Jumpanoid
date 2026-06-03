#include "GameStates.h"
//Private Functions//
void GameStates::initVariables()
{
    this->window = nullptr;
}

void GameStates::initWindow()
{
    this->videoMode.width = 1280;
    this->videoMode.height = 720;
    this->window = new sf::RenderWindow(this->videoMode, "Jumpanoid", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
}

void GameStates::initStates()
{
    this->states.push(new MainMenu(this->window));
}

void GameStates::initMusic()
{
    if (!buffer_music.loadFromFile("sounds/music.mp3"))
    {
        std::cout << "ERROR::GAME::INITSOUND::COULD NOT LOAD A MUSIC music.mp3" << std::endl;
    }

    music.setBuffer(buffer_music);
}

//Constructors Destructors//
GameStates::GameStates()
{
    this->initVariables();
    this->initWindow();
    this->initStates();
    this->initMusic();
}

GameStates::~GameStates()
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}


//Accessors
const bool GameStates::running() const
{
    return this->window->isOpen();
}

//Functions//
void GameStates::pollEvents()
{
    while (this->window->pollEvent(this->sfmlEvent))
    {
        switch (this->sfmlEvent.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        }
    }
}

void GameStates::checkEndState()
{
    //Main Menu
    if (this->states.top()->checkEnd() == 1)
    {
        this->states.pop();
        this->states.push(new MainMenu(this->window));
    }

    //Game
    if (this->states.top()->checkEnd() == 3)
    {
        int gameMode = this->states.top()->checkGameMode();
        int level = this->states.top()->checkLevel();
        int lives = this->states.top()->lives;
        int scorep1 = this->states.top()->scorep1;
        int scorep2 = this->states.top()->scorep2;
        this->states.pop();
        if (level != 0)
        {
            this->states.push(new Game(this->window, gameMode, level + 1, lives, scorep1, scorep2));
        }
        else
        {
            this->states.push(new Game(this->window, gameMode, level + 1));
        }
    }

    //Exit
    if (this->states.top()->checkEnd() == 99)
    {
        this->states.pop();
        this->window->close();
    }
}

void GameStates::update()
{
    if (music.getStatus() != sf::SoundSource::Playing)
    {
        music.play();
    }

    this->pollEvents();
    this->checkEndState();

    if (!this->states.empty())
    {
        this->states.top()->update(this->window, this->frameClock.restart().asSeconds());
    }
}

void GameStates::render()
{
    if (!this->states.empty())
    {
        this->states.top()->render(this->window);
    }
    this->window->display();
}

void GameStates::runningFrame()
{
    this->update();
    this->render();
}