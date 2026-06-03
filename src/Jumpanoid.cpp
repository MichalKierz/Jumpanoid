#include"GameStates.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
    srand(static_cast<unsigned>(time(0)));

    //Init Game engine
    GameStates maingame;

    //Game Loop//
    while (maingame.running())
    {
        maingame.runningFrame();
    }

    //End of application//
    return 0;
}