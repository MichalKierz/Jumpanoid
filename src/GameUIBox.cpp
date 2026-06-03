#include "GameUIBox.h"

//Private Functions
void GameUIBox::initVariables(int t, int lvl)
{
    //Variables init
    this->type = t;
    this->endWith = 0;
    this->currLevel = lvl;

    //Menu Blocks Ini
    for (int i = 0; i < 2; i++)
    {
        this->box_blocks.push_back(sf::RectangleShape());
        this->box_blocks[i].setFillColor(sf::Color::Blue);
        this->box_blocks[i].setSize(sf::Vector2f(160.f, 40.f));
        this->box_blocks[i].setOrigin(this->box_blocks[i].getGlobalBounds().getSize() / 2.f + this->box_blocks[i].getLocalBounds().getPosition());
        this->box_blocks[i].setPosition(640.f, 360.f + (i * 80.f));
    }
}

void GameUIBox::initText()
{
    float wwidth = 1280;

    //Fonts
    if (!this->font.loadFromFile("fonts/ethnocentric.otf"))
    {
        std::cout << "ERROR::GAME::INITFONTS::COULD NOT LOAD A FONT ethnocentric.otf" << std::endl;
    }

    //title
    this->title.setFont(this->font);
    this->title.setFillColor(sf::Color::White);
    this->title.setCharacterSize(32);

    std::string levelName = "levels/level_" + std::to_string(this->currLevel + 1) + ".txt";
    std::ifstream file(levelName);

    switch (type) {
    case 0: this->title.setString("Pause"); break;
    case 1: 
        if(file.good())
        {
            this->title.setString("You Win!");
        }
        else
        {
            this->title.setString(" You Won\nThe Game!");
        }
    break;
    case 2: this->title.setString("You Lose!"); break;
    }
    this->title.setOrigin(this->title.getGlobalBounds().getSize() / 2.f + this->title.getLocalBounds().getPosition());
    this->title.setPosition(wwidth / 2, 250.f);

    //options
    for (int i = 0; i < 2; i++)
    {
        this->box_texts.push_back(sf::Text());
        this->box_texts[i].setFont(this->font);
        this->box_texts[i].setFillColor(sf::Color::White);
        this->box_texts[i].setCharacterSize(24);
    }
    switch (type) {
        case 0: this->box_texts[0].setString("Resume"); break;
        case 1: 
            if (file.good())
            {
                this->box_texts[0].setString("Next Level");
            }
            else
            {
                this->box_texts[0].setString("Restart");
            }
        break;
        case 2: this->box_texts[0].setString("Restart"); break;
    }
    this->box_texts[1].setString("Exit");

    for (int i = 0; i < 2; i++)
    {
        this->box_texts[i].setOrigin(this->box_texts[i].getGlobalBounds().getSize() / 2.f + this->box_texts[i].getLocalBounds().getPosition());
        this->box_texts[i].setPosition(wwidth / 2, 360.f + (i * 80.f));
    }
}

//Constructor Destructor
GameUIBox::GameUIBox(int t, sf::Sprite sprite, sf::Sound sound, int lvl)
{
    this->sound_select = sound;
    this->boxSprite = sprite;
    this->boxSprite.setPosition((1280.f / 2) - (boxSprite.getGlobalBounds().width / 2), (720.f / 2) - (boxSprite.getGlobalBounds().height / 2));
    this->initVariables(t, lvl);
    this->initText();
}

GameUIBox::~GameUIBox()
{

}

//Accessors
int GameUIBox::checkEnd()
{
    return this->endWith;
}

//Functions//
void GameUIBox::hoverDetection(sf::RenderWindow* window)
{
    for (int i = 0; i < this->box_blocks.size(); i++)
    {
        if (box_blocks[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))))
        {
            this->box_texts[i].setFillColor(sf::Color::Yellow);
        }
        else
        {
            this->box_texts[i].setFillColor(sf::Color::White);
        }
    }
}
void GameUIBox::clickDetection(sf::RenderWindow* window)
{

    if (box_blocks[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && type == 0)
    {
        std::cout << "select" << std::endl;
        sound_select.play();
        this->endWith = 2;
    }

    std::string levelName = "levels/level_" + std::to_string(this->currLevel + 1) + ".txt";
    std::ifstream file(levelName);

    //Next Level Or Win Game
    if (box_blocks[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && type == 1)
    {
        sound_select.play();
        if (file.good())
        {
            this->endWith = 3;
        }
        else
        {
            this->endWith = 4;
        }
    }

    //Restart
    if (box_blocks[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && type == 2)
    {
        sound_select.play();
        this->endWith = 4;
    }

    //Exit
    if (box_blocks[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sound_select.play();
        this->endWith = 1;
    }
}


void GameUIBox::update(sf::RenderWindow* window, float dt)
{
    this->hoverDetection(window);
    this->clickDetection(window);
}

void GameUIBox::render(sf::RenderTarget* target)
{
    //Background
    target->draw(this->boxSprite);

    //Text
    for (int i = 0; i < this->box_texts.size(); i++)
    {
        target->draw(this->box_texts[i]);
    }
    target->draw(this->title);
}