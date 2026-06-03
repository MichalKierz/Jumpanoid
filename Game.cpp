#include "Game.h"

//Private Functions//
void Game::initVariables(int gamemode, int lvl, int lvs, int scrp1, int scrp2)
{
    this->scorep1 = scrp1;
    this->scorep2 = scrp2;
    this->lives = lvs;
    this->pauseCooldown = 0;
    this->gameMode = gamemode;
    this->changeLevel(lvl);
    this->gameStarted == 0;

    if (this->gameMode > 0)
    {
        this->players.push_back(Player(player_sprite, player_longer_sprite, 1, 202));
        this->players.push_back(Player(player_sprite, player_longer_sprite, 2, 602));
    }
    else
    {
        this->players.push_back(Player(player_sprite, player_longer_sprite));
    }
    this->balls.push_back(Ball(this->ball_sprite, this->sound_hit));
}

void Game::initGraphics()
{
    //init UI Box Graphics
    if (!this->box_texture.loadFromFile("sprites/game_ui_box.png"))
    {
        std::cout << "ERROR::GAME::INITEXTURE::COULD NOT LOAD A game_ui_box.png" << std::endl;
    }
    this->box_sprite.setTexture(this->box_texture);

    //init Background Graphics
    if (!this->bg_texture.loadFromFile("sprites/background_window.png"))
    {
        std::cout << "ERROR::GAME::INITEXTURE::COULD NOT LOAD A background_window.png" << std::endl;
    }
    this->bg_sprite.setTexture(this->bg_texture);

    if (!this->ui_texture.loadFromFile("sprites/gameplay_window.png"))
    {
        std::cout << "ERROR::GAME::INITEXTURE::COULD NOT LOAD A gameplay_window.png" << std::endl;
    }
    this->ui_sprite.setTexture(this->ui_texture);

    //init Player Graphics
    if (!this->player_texture.loadFromFile("sprites/player.png"))
    {
        std::cout << "ERROR::GAME::INITEXTURE::COULD NOT LOAD A player.png" << std::endl;
    }
    this->player_sprite.setTexture(this->player_texture);

    if (!this->player_longer_texture.loadFromFile("sprites/player_longer.png"))
    {
        std::cout << "ERROR::GAME::INITEXTURE::COULD NOT LOAD A player_longer.png" << std::endl;
    }
    this->player_longer_sprite.setTexture(this->player_longer_texture);

    //Init Ball Graphics
    if (!this->ball_texture.loadFromFile("sprites/ball.png"))
    {
        std::cout << "ERROR::GAME::INITEXTURE::COULD NOT LOAD A ball.png" << std::endl;
    }
    this->ball_sprite.setTexture(this->ball_texture);


    //Init Bricks Graphics
    if (!this->brick1_texture.loadFromFile("sprites/brick_1.png"))
    {
        std::cout << "ERROR::GAME::INITEXTURE::COULD NOT LOAD A brick_1.png" << std::endl;
    }
    this->brick1_sprite.setTexture(this->brick1_texture);

    if (!this->brick2_texture.loadFromFile("sprites/brick_2.png"))
    {
        std::cout << "ERROR::GAME::INITEXTURE::COULD NOT LOAD A brick_2.png" << std::endl;
    }
    this->brick2_sprite.setTexture(this->brick2_texture);

    if (!this->brick3_texture.loadFromFile("sprites/brick_3.png"))
    {
        std::cout << "ERROR::GAME::INITEXTURE::COULD NOT LOAD A brick_3.png" << std::endl;
    }
    this->brick3_sprite.setTexture(this->brick3_texture);

    if (!this->brick4_texture.loadFromFile("sprites/brick_4.png"))
    {
        std::cout << "ERROR::GAME::INITEXTURE::COULD NOT LOAD A brick_4.png" << std::endl;
    }
    this->brick4_sprite.setTexture(this->brick4_texture);

    if (!this->brick5_texture.loadFromFile("sprites/brick_5.png"))
    {
        std::cout << "ERROR::GAME::INITEXTURE::COULD NOT LOAD A brick_5.png" << std::endl;
    }
    this->brick5_sprite.setTexture(this->brick5_texture);

    //Init Powerups Graphics
    if (!this->powerup1_texture.loadFromFile("sprites/powerup_ball.png"))
    {
        std::cout << "ERROR::GAME::INITEXTURE::COULD NOT LOAD A powerup_ball.png" << std::endl;
    }
    this->powerup1_sprite.setTexture(this->powerup1_texture);

    if (!this->powerup2_texture.loadFromFile("sprites/powerup_balls.png"))
    {
        std::cout << "ERROR::GAME::INITEXTURE::COULD NOT LOAD A powerup_balls.png" << std::endl;
    }
    this->powerup2_sprite.setTexture(this->powerup2_texture);

    if (!this->powerup3_texture.loadFromFile("sprites/powerup_longer.png"))
    {
        std::cout << "ERROR::GAME::INITEXTURE::COULD NOT LOAD A powerup_longer.png" << std::endl;
    }
    this->powerup3_sprite.setTexture(this->powerup3_texture);

}

void Game::initText()
{
    if (!this->font.loadFromFile("fonts/ethnocentric.otf"))
    {
        std::cout << "ERROR::GAME::INITFONTS::COULD NOT LOAD A FONT ethnocentric.otf" << std::endl;
    }

    this->text_gamemode.setFont(this->font);
    this->text_gamemode.setFillColor(sf::Color::White);
    this->text_gamemode.setCharacterSize(24);
    this->text_gamemode.setString("Single Player");
    if (this->gameMode == 0) this->text_gamemode.setString("Single Player");
    else if (this->gameMode == 1) this->text_gamemode.setString("Cooperation");
    else if (this->gameMode == 2) this->text_gamemode.setString("Versus");
    this->text_gamemode.setOrigin(this->text_gamemode.getGlobalBounds().getSize() / 2.f + this->text_gamemode.getLocalBounds().getPosition());
    this->text_gamemode.setPosition(1120.f, 30.f);

    this->text_lives.setFont(this->font);
    this->text_lives.setFillColor(sf::Color::White);
    this->text_lives.setCharacterSize(24);
    this->text_lives.setString("Lives: " + std::to_string(lives));
    this->text_lives.setPosition(985.f, 150.f);

    if(gameMode == 2)
    {
        this->text_scorep1.setFont(this->font);
        this->text_scorep1.setFillColor(sf::Color::White);
        this->text_scorep1.setCharacterSize(18);
        this->text_scorep1.setString("P1 Score: " + std::to_string(scorep1));
        this->text_scorep1.setPosition(985.f, 220.f);

        this->text_scorep2.setFont(this->font);
        this->text_scorep2.setFillColor(sf::Color::White);
        this->text_scorep2.setCharacterSize(18);
        this->text_scorep2.setString("P2 Score: " + std::to_string(scorep2));
        this->text_scorep2.setPosition(985.f, 270.f);
    }
    else
    {
        this->text_scorep1.setFont(this->font);
        this->text_scorep1.setFillColor(sf::Color::White);
        this->text_scorep1.setCharacterSize(18);
        this->text_scorep1.setString("Score: " + std::to_string(scorep1));
        this->text_scorep1.setPosition(985.f, 220.f);
    }


}

void Game::initSound()
{
    if (!buffer_select.loadFromFile("sounds/menu_select.mp3"))
    {
        std::cout << "ERROR::GAME::INITSOUND::COULD NOT LOAD A SOUND menu_select.mp3" << std::endl;
    }
    sound_select.setBuffer(buffer_select);

    if (!buffer_hit.loadFromFile("sounds/ball_hit.mp3"))
    {
        std::cout << "ERROR::GAME::INITSOUND::COULD NOT LOAD A SOUND ball_hit.mp3" << std::endl;
    }
    sound_hit.setBuffer(buffer_hit);
}

void Game::initBricks()
{
    //Loading level
    std::string levelName = "levels/level_" + std::to_string(this->checkLevel()) + ".txt";
    level.open(levelName);
    if (level.is_open())
    {
        std::string line;
        int i = 0;
        float x_brick = 54;
        float y_brick = 24;
        int b_health = 0, b_powerup = 0;
        sf::Sprite b_powerup_sprite;
        while (getline(level, line))//spawning bricks
        {
            if(line.substr(0,1) != "-")
            {
                if (i % 13 == 0)
                {
                    y_brick += 27;
                    x_brick = 54;
                }

                int pos_f = line.find(":");
                int pos_s = line.find(",");
                b_health = std::stoi(line.substr(pos_f + 2, pos_s - pos_f - 2));
                b_powerup = std::stoi(line.substr(pos_s + 2));
                switch(b_powerup)
                {
                    case 1: b_powerup_sprite = this->powerup1_sprite; break;
                    case 2: b_powerup_sprite = this->powerup2_sprite; break;
                    case 3: b_powerup_sprite = this->powerup3_sprite; break;
                }

                if (b_health != 0) { this->bricks.push_back(Brick(x_brick, y_brick, b_health, b_powerup, b_powerup_sprite, this->brick1_sprite, this->brick2_sprite, this->brick3_sprite, this->brick4_sprite, this->brick5_sprite)); }


                x_brick += 67;
                i++;
                if (i == 117) { break; }
            }
        }
        level.close();
    }
}


//Constructors Destructors//
Game::Game(sf::RenderWindow* window, int gamemode, int lvl, int lvs, int scrp1, int scrp2) : State(window)
{
    this->initSound();
    this->initGraphics();
    this->initVariables(gamemode, lvl, lvs, scrp1, scrp2);
    this->initText();
    this->initBricks();
}

Game::~Game()
{
    while (!this->box.empty())
    {
        delete this->box.top();
        this->box.pop();
    }
}

//Collision Help Functions
float Game::overlapLeft(sf::Sprite object1, sf::Sprite object2)
{ 
    return object1.getPosition().x + object1.getGlobalBounds().width - object2.getPosition().x;
}

float Game::overlapRight(sf::Sprite object1, sf::Sprite object2)
{
    return object2.getPosition().x + object2.getGlobalBounds().width - object1.getPosition().x;
}

float Game::overlapTop(sf::Sprite object1, sf::Sprite object2)
{
    return object1.getPosition().y + object1.getGlobalBounds().height - object2.getPosition().y;
}

float Game::overlapBottom(sf::Sprite object1, sf::Sprite object2)
{
    return object2.getPosition().y + object2.getGlobalBounds().height - object1.getPosition().y;
}


//Collisions
void Game::colBallPlayer(size_t i)
{
    for (size_t j = 0; j < this->players.size(); j++)
    {
        if (this->balls[i].getSprite().getGlobalBounds().intersects(this->players[j].getSprite().getGlobalBounds()))
        {
            bool ballFromLeft(abs(this->overlapLeft(this->balls[i].getSprite(), this->players[j].getSprite()) < this->overlapRight(this->balls[i].getSprite(), this->players[j].getSprite())));
            bool ballFromTop(abs(this->overlapTop(this->balls[i].getSprite(), this->players[j].getSprite()) < this->overlapBottom(this->balls[i].getSprite(), this->players[j].getSprite())));

            float minOverlapX{ ballFromLeft ? this->overlapLeft(this->balls[i].getSprite(), this->players[j].getSprite()) : this->overlapRight(this->balls[i].getSprite(), this->players[j].getSprite()) };
            float minOverlapY{ ballFromTop ? this->overlapTop(this->balls[i].getSprite(), this->players[j].getSprite()) : this->overlapBottom(this->balls[i].getSprite(), this->players[j].getSprite()) };

            if (abs(minOverlapX) < abs(minOverlapY))
            {
                if (abs(this->overlapLeft(this->players[j].getSprite(), this->balls[i].getSprite())) > abs(this->overlapRight(this->players[j].getSprite(), this->balls[i].getSprite())))
                {
                    this->balls[i].getSprite().setPosition(this->players[j].getSprite().getGlobalBounds().left - this->balls[i].getSprite().getGlobalBounds().width - 20, this->balls[i].getSprite().getGlobalBounds().top);
                    this->balls[i].changeMovement(-abs(balls[i].getBaseAngle()), balls[i].getBaseSpeed());
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { this->balls[i].changeVelocity(2.5); }
                }
                else
                {
                    this->balls[i].getSprite().setPosition(this->players[j].getSprite().getGlobalBounds().left + this->players[j].getSprite().getGlobalBounds().width + 20, this->balls[i].getSprite().getGlobalBounds().top);
                    this->balls[i].changeMovement(abs(balls[i].getBaseAngle()), balls[i].getBaseSpeed());
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { this->balls[i].changeVelocity(2.5); } 
                }
            }
            else
            {
                if (abs(this->overlapTop(this->players[j].getSprite(), this->balls[i].getSprite())) > abs(this->overlapBottom(this->players[j].getSprite(), this->balls[i].getSprite())))
                {
                    this->balls[i].getSprite().setPosition(this->balls[i].getSprite().getGlobalBounds().left, this->players[j].getSprite().getGlobalBounds().top - this->balls[i].getSprite().getGlobalBounds().height);
                    this->balls[i].changeMovement(balls[i].getBaseAngle(), -abs(balls[i].getBaseAngle()));
                    if (this->players[j].checkIsJumping()) { this->balls[i].changeVelocity(3); }
                }
                else
                {
                    this->balls[i].getSprite().setPosition(this->balls[i].getSprite().getGlobalBounds().left, this->players[j].getSprite().getGlobalBounds().top + this->players[j].getSprite().getGlobalBounds().height);
                    this->balls[i].changeMovement(balls[i].getBaseAngle(), abs(balls[i].getBaseAngle()));
                    this->balls[i].changeVelocity(3);
                }
            }
            this->balls[i].changeLastTouched(j);

        }
    }
}

void Game::colBallBrick(size_t i)
{
    for (size_t j = 0; j < this->bricks.size(); j++)
    {
        if (this->balls[i].getSprite().getGlobalBounds().intersects(this->bricks[j].getSprite().getGlobalBounds()))
        {
            this->bricks[j].substrLife();

            bool ballFromLeft(abs(this->overlapLeft(this->balls[i].getSprite(), this->bricks[j].getSprite()) < this->overlapRight(this->balls[i].getSprite(), this->bricks[j].getSprite())));
            bool ballFromTop(abs(this->overlapTop(this->balls[i].getSprite(), this->bricks[j].getSprite()) < this->overlapBottom(this->balls[i].getSprite(), this->bricks[j].getSprite())));

            float minOverlapX{ ballFromLeft ? this->overlapLeft(this->balls[i].getSprite(), this->bricks[j].getSprite()) : this->overlapRight(this->balls[i].getSprite(), this->bricks[j].getSprite()) };
            float minOverlapY{ ballFromTop ? this->overlapTop(this->balls[i].getSprite(), this->bricks[j].getSprite()) : this->overlapBottom(this->balls[i].getSprite(), this->bricks[j].getSprite()) };

            if (abs(minOverlapX) < abs(minOverlapY))
            {
                this->balls[i].changeMovement(-balls[i].getBaseAngle(), balls[i].getBaseSpeed());
            }
            else
            {
                this->balls[i].changeMovement(balls[i].getBaseAngle(), -balls[i].getBaseSpeed());
            }

            if (this->bricks[j].checkLife() <= 0)
            {
                this->powerupLogic(j, i);
                this->scoringEvaluation(this->balls[i], this->bricks[j]);
                auto it = this->bricks.begin() + j;
                this->bricks.erase(it);
            }
        }
    }
}

void Game::checkIfBallFutureCol(size_t i)
{
    for (size_t j = 0; j < this->players.size(); j++)
    {
        if (this->balls[i].getCollider().getGlobalBounds().intersects(this->players[j].getSprite().getGlobalBounds()))
        {
            bool ballFromLeft(abs(this->overlapLeft(this->balls[i].getSprite(), this->players[j].getSprite()) < this->overlapRight(this->balls[i].getSprite(), this->players[j].getSprite())));
            bool ballFromTop(abs(this->overlapTop(this->balls[i].getSprite(), this->players[j].getSprite()) < this->overlapBottom(this->balls[i].getSprite(), this->players[j].getSprite())));

            float minOverlapX{ ballFromLeft ? this->overlapLeft(this->balls[i].getSprite(), this->players[j].getSprite()) : this->overlapRight(this->balls[i].getSprite(), this->players[j].getSprite()) };
            float minOverlapY{ ballFromTop ? this->overlapTop(this->balls[i].getSprite(), this->players[j].getSprite()) : this->overlapBottom(this->balls[i].getSprite(), this->players[j].getSprite()) };
            if (abs(minOverlapX) < abs(minOverlapY))
            {
                if (abs(this->overlapLeft(this->players[j].getSprite(), this->balls[i].getSprite())) > abs(this->overlapRight(this->players[j].getSprite(), this->balls[i].getSprite())))
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    {
                        this->balls[i].changeMovement(-abs(balls[i].getBaseAngle()), balls[i].getBaseSpeed());
                        this->balls[i].changeVelocity(2.5);
                    }
                }
                else
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    {
                        this->balls[i].changeMovement(abs(balls[i].getBaseAngle()), balls[i].getBaseSpeed());
                        this->balls[i].changeVelocity(2.5);
                    }
                }
            }
            else
            {
                if (abs(this->overlapTop(this->players[j].getSprite(), this->balls[i].getSprite())) > abs(this->overlapBottom(this->players[j].getSprite(), this->balls[i].getSprite())))
                {
                    if (this->players[j].checkIsJumping())
                    {
                        this->balls[i].changeMovement(balls[i].getBaseAngle(), -abs(balls[i].getBaseAngle()));
                        this->balls[i].changeVelocity(3);
                    }
                }
                else
                {
                    this->balls[i].changeMovement(balls[i].getBaseAngle(), abs(balls[i].getBaseAngle()));
                    this->balls[i].changeVelocity(3);
                }
            }
            this->balls[i].changeLastTouched(j);
        }
    }
}

void Game::playerPlayer(size_t i)
{
    for (size_t j = 0; j < this->players.size(); j++)
    {
        if (i != j)
        {
            if (this->players[i].getSprite().getGlobalBounds().intersects(this->players[j].getSprite().getGlobalBounds()))
            {
                bool playerFromLeft(abs(this->overlapLeft(this->players[i].getSprite(), this->players[j].getSprite()) < this->overlapRight(this->players[i].getSprite(), this->players[j].getSprite())));
                bool playerFromTop(abs(this->overlapTop(this->players[i].getSprite(), this->players[j].getSprite()) < this->overlapBottom(this->players[i].getSprite(), this->players[j].getSprite())));

                float minOverlapX{ playerFromLeft ? this->overlapLeft(this->players[i].getSprite(), this->players[j].getSprite()) : this->overlapRight(this->players[i].getSprite(), this->players[j].getSprite()) };
                float minOverlapY{ playerFromTop ? this->overlapTop(this->players[i].getSprite(), this->players[j].getSprite()) : this->overlapBottom(this->players[i].getSprite(), this->players[j].getSprite()) };


                if (abs(minOverlapX) < abs(minOverlapY))
                {
                    if (abs(this->overlapLeft(this->players[j].getSprite(), this->players[i].getSprite())) > abs(this->overlapRight(this->players[j].getSprite(), this->players[i].getSprite())))
                    {
                        this->players[i].getSprite().setPosition(this->players[j].getSprite().getGlobalBounds().left - this->players[i].getSprite().getGlobalBounds().width, this->players[i].getSprite().getGlobalBounds().top);
                    }
                    else
                    {
                        this->players[i].getSprite().setPosition(this->players[j].getSprite().getGlobalBounds().left + this->players[j].getSprite().getGlobalBounds().width, this->players[i].getSprite().getGlobalBounds().top);
                    }
                }
            }
        }
    }
}

void Game::playerStanding(size_t i)
{
    //Ground
    if (this->players[i].getSprite().getGlobalBounds().top > this->players[i].getGroundHeight())
    {
        this->players[i].getSprite().setPosition(this->players[i].getSprite().getGlobalBounds().left, this->players[i].getGroundHeight());
    }

    //Standing on the ground
    if (!this->players[i].checkIsJumping() && this->players[i].getSprite().getGlobalBounds().top < this->players[i].getGroundHeight())
    {
        this->players[i].changeStanding(false);
    }
    else
    {
        this->players[i].changeStanding(true);
    }

    //Player on Player
    for (size_t j = 0; j < this->players.size(); j++)
    {
        if (i != j)
        {
            if (this->players[i].getSprite().getGlobalBounds().intersects(this->players[j].getSprite().getGlobalBounds()))
            {
                if (abs(this->overlapTop(this->players[j].getSprite(), this->players[i].getSprite())) > abs(this->overlapBottom(this->players[j].getSprite(), this->players[i].getSprite())))
                {
                    if (this->players[i].getSprite().getGlobalBounds().top <= this->players[j].getSprite().getGlobalBounds().top)
                    {
                        this->players[i].getSprite().setPosition(this->players[i].getSprite().getGlobalBounds().left, this->players[j].getSprite().getGlobalBounds().top - this->players[i].getSprite().getGlobalBounds().height);
                        this->players[i].changeStanding(true);
                    }
                }
            }
        }
    }
}

//Functions
void Game::powerupLogic(size_t i_br, size_t i_bl)
{
    switch (this->bricks[i_br].checkPowerup())
    {
    case 1: 
        this->balls.push_back(Ball(this->ball_sprite, this->sound_hit, 6.f, 5.f, this->bricks[i_br].getSprite().getGlobalBounds().left + (this->bricks[i_br].getSprite().getGlobalBounds().width / 2), this->bricks[i_br].getSprite().getGlobalBounds().top + (this->bricks[i_br].getSprite().getGlobalBounds().height / 2)));
    break;
    case 2:
        this->balls.push_back(Ball(this->ball_sprite, this->sound_hit, 6.f, 5.f, this->bricks[i_br].getSprite().getGlobalBounds().left + (this->bricks[i_br].getSprite().getGlobalBounds().width / 2), this->bricks[i_br].getSprite().getGlobalBounds().top + (this->bricks[i_br].getSprite().getGlobalBounds().height / 2)));
        this->balls.push_back(Ball(this->ball_sprite, this->sound_hit, 6.f, -5.f, this->bricks[i_br].getSprite().getGlobalBounds().left + (this->bricks[i_br].getSprite().getGlobalBounds().width / 2), this->bricks[i_br].getSprite().getGlobalBounds().top + (this->bricks[i_br].getSprite().getGlobalBounds().height / 2)));
    break;
    case 3:
        this->players[this->balls[i_bl].getLastTouched()].upgradeToLonger();
    break;
    }
}

void Game::updateInput()
{
    if(this->pauseCooldown == 0)
    {
        //Init Box
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->box.empty()) 
        {
            this->box.push(new GameUIBox(0, this->box_sprite, this->sound_select, this->checkLevel()));
            this->pauseCooldown = 10;
            return;
        }

        //Delete Box
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !this->box.empty())
        {
            delete this->box.top();
            this->box.pop();
            this->pauseCooldown = 10;
            return;
        }
    }
    else
    {
        this->pauseCooldown -= 1;
    }

}


void Game::checkBoxEnd()
{
    switch (this->box.top()->checkEnd())
    {
        case 1: this->endState(1); break; //Exit
        case 2: delete this->box.top(); this->box.pop(); break; //Resume
        case 3: this->changeGameMode(this->gameMode); this->endState(3); break; //Next Level
        case 4: this->changeLevel(0), this->changeGameMode(this->gameMode); this->endState(3); break; //Restart
    }
}

void Game::gameProgressionLogic()
{
    //Win Condition
    if (this->bricks.empty())
    {
        this->box.push(new GameUIBox(1, this->box_sprite, this->sound_select, this->checkLevel()));
        this->pauseCooldown = 10;
        return;
    }

    //Losing a Ball
    for (size_t i = 0; i < this->balls.size(); i++)
    {
        if (this->balls[i].getSprite().getPosition().y >= 800)
        {
            auto it = this->balls.begin() + i;
            this->balls.erase(it);
        }
    }

    //Losing a Live
    if (this->balls.empty())
    {
        lives -= 1;
        this->gameStarted = false;
        this->balls.push_back(Ball(this->ball_sprite, this->sound_hit));
    }

    //Lose Condition
    if (lives == 0)
    {
        this->box.push(new GameUIBox(2, this->box_sprite, this->sound_select, this->checkLevel()));
        this->pauseCooldown = 10;
        return;
    }
}

void Game::scoringEvaluation(Ball ball, Brick brick)
{
    if (ball.getLastTouched() == 0)
    {
        this->scorep1 += 100 * ball.getBaseVelocity();
    }
    else if(ball.getLastTouched() == 1)
    {
        if (this->gameMode == 2)
        {
            scorep2 += 100 * ball.getBaseVelocity();
        }
        else
        {
            this->scorep1 += 100 * ball.getBaseVelocity();
        }
    }
}

void Game::gameStart()
{
    for (size_t i = 0; i < this->players.size(); i++)
    {
        for (size_t j = 0; j < this->balls.size(); j++)
        {

            if ((this->balls[j].getSprite().getPosition().x + this->balls[j].getSprite().getGlobalBounds().width) >= this->players[i].getSprite().getPosition().x &&
            this->balls[j].getSprite().getPosition().x <= (this->players[i].getSprite().getPosition().x + this->players[i].getSprite().getGlobalBounds().width) &&
            ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) && i == 0) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && i == 1)) &&
            this->balls[j].getSprite().getPosition().y <= this->players[i].getSprite().getPosition().y)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    this->balls[0].changeMovement(this->balls[0].getBaseSpeed(), -this->balls[0].getBaseAngle());
                }

                this->gameStarted = true;
            }
        }
    }
}
    
void Game::update(sf::RenderWindow* window, float dt)
{
    this->updateInput();

    if (!this->box.empty())
    {
        this->box.top()->update(window, dt);
        this->checkBoxEnd();
    }
    else
    {
        if (!this->gameStarted) { this->gameStart(); }

        for (size_t i = 0; i < this->players.size(); i++)
        {
            this->players[i].update(window, dt);
            this->playerStanding(i);
            this->playerPlayer(i);
        }
        if(this->gameStarted)
        {
            for (size_t i = 0; i < this->balls.size(); i++)
            {
                this->checkIfBallFutureCol(i);
                this->balls[i].update(window, dt);
                this->colBallPlayer(i);
                this->colBallBrick(i);
            }
        }
        for (size_t i = 0; i < this->bricks.size(); i++)
        {
            this->bricks[i].update(window, dt);
        }
        this->gameProgressionLogic();
    }
}

void Game::renderGui(sf::RenderTarget* target)
{
    target->draw(this->text_gamemode);

    this->text_lives.setString("Lives: " + std::to_string(lives));
    target->draw(this->text_lives);

    if (this->gameMode == 2)
    {
        this->text_scorep1.setString("P1 Score: " + std::to_string(scorep1));
        target->draw(this->text_scorep1);

        this->text_scorep2.setString("P2 Score: " + std::to_string(scorep2));
        target->draw(this->text_scorep2);
    }
    else
    {
        this->text_scorep1.setString("Score: " + std::to_string(scorep1));
        target->draw(this->text_scorep1);
    }
}


void Game::render(sf::RenderTarget* target)
{
    //Draw background
    target->clear(sf::Color::White);
    target->draw(this->bg_sprite);


    //Draw game objects
    for (int i = 0; i < this->players.size(); i++)
    {
        this->players[i].render(target);
    }
    for (size_t j = 0; j < this->balls.size(); j++)
    {
        this->balls[j].render(target);
    }
    for (int i = 0; i < this->bricks.size(); i++)
    {
        this->bricks[i].render(target);
    }

    //Render gui
    target->draw(this->ui_sprite);
    this->renderGui(target);

    //Render Pause Box
    if(!this->box.empty())
    {
        this->box.top()->render(target);
    }
}