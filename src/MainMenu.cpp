#include "MainMenu.h"

//Private Functions
void MainMenu::initVariables()
{
    this->clickCooldown = 15;

    //Menu Blocks Ini
    for (int i = 0; i < 4; i++)
    {
        this->menu_blocks.push_back(sf::RectangleShape());
        this->menu_blocks[i].setFillColor(sf::Color::Blue);
        this->menu_blocks[i].setSize(sf::Vector2f(350.f, 80.f));
        this->menu_blocks[i].setOrigin(this->menu_blocks[i].getGlobalBounds().getSize() / 2.f + this->menu_blocks[i].getLocalBounds().getPosition());
        this->menu_blocks[i].setPosition(600.f, 300.f + (i * 80.f));
    }
}

void MainMenu::initText()
{
    float wwidth = 1280;

    //Fonts
    if (!this->font_title.loadFromFile("fonts/pdark.ttf"))
    {
        std::cout << "ERROR::GAME::INITFONTS::COULD NOT LOAD A FONT pdark.ttf" << std::endl;
    }

    if (!this->font_buttons.loadFromFile("fonts/ethnocentric.otf"))
    {
        std::cout << "ERROR::GAME::INITFONTS::COULD NOT LOAD A FONT ethnocentric.otf" << std::endl;
    }

    //Menu Text
    for (int i = 0; i < 4; i++)
    {
        this->menu_texts.push_back(sf::Text());
        this->menu_texts[i].setFont(this->font_buttons);
        this->menu_texts[i].setFillColor(sf::Color::White);
        this->menu_texts[i].setCharacterSize(24);
    }

    this->menu_texts[0].setString("Single Player");
    this->menu_texts[1].setString("Cooperation");
    this->menu_texts[2].setString("Versus");
    this->menu_texts[3].setString("Exit");

    for (int i = 0; i < 4; i++)
    {
        this->menu_texts[i].setOrigin(this->menu_texts[i].getGlobalBounds().getSize() / 2.f + this->menu_texts[i].getLocalBounds().getPosition());
        this->menu_texts[i].setPosition(wwidth / 2, 300.f + (i * 80.f));
    }

    //Title

    this->text_title.setFont(this->font_title);
    this->text_title.setFillColor(sf::Color::White);
    this->text_title.setCharacterSize(148);
    this->text_title.setString("Jumpanoid");
    this->text_title.setOrigin(this->text_title.getGlobalBounds().getSize() / 2.f + this->text_title.getLocalBounds().getPosition());
    this->text_title.setPosition(wwidth / 2, 140.f);
}

void MainMenu::initSound()
{
    if (!buffer_select.loadFromFile("sounds/menu_select.mp3"))
    {
        std::cout << "ERROR::GAME::INITSOUND::COULD NOT LOAD A SOUND menu_select.mp3" << std::endl;
    }

    sound_select.setBuffer(buffer_select);
}

//Constructor Destructors
MainMenu::MainMenu(sf::RenderWindow* window) : State(window)
{
	this->initVariables();
    this->initText();
    this->initSound();
}

MainMenu::~MainMenu()
{

}

//Functions//
void MainMenu::hoverDetection(sf::RenderWindow* window)
{
    for (int i = 0; i < this->menu_blocks.size(); i++)
    {
        if (menu_blocks[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))))
        { 
            this->menu_texts[i].setFillColor(sf::Color::Yellow);
        }
        else
        {
            this->menu_texts[i].setFillColor(sf::Color::White);
        }
    }
}
void MainMenu::clickDetection(sf::RenderWindow* window)
{
    if(this->clickCooldown == 0)
    {
        //Single Player
        if (menu_blocks[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sound_select.play();
            this->endState(3);
        }

        //Cooperation
        if (menu_blocks[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sound_select.play();
            this->changeGameMode(1);
            this->endState(3);
        }

        //Versus
        if (menu_blocks[2].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sound_select.play();
            this->changeGameMode(2);
            this->endState(3);
        }

        //Exit
        if (menu_blocks[3].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sound_select.play();
            this->endState(99);
        }
    }
    else
    {
        this->clickCooldown -= 1;
    }
}


void MainMenu::update(sf::RenderWindow* window, float dt)
{
    this->hoverDetection(window);
    this->clickDetection(window);
}

void MainMenu::renderGui(sf::RenderTarget* target)
{
    //Text
    for (int i = 0; i < this->menu_texts.size(); i++)
    {
        target->draw(this->menu_texts[i]);
    }
    target->draw(this->text_title);
}


void MainMenu::render(sf::RenderTarget* target)
{
    target->clear(sf::Color(0,0,20));
    this->renderGui(target);
}
