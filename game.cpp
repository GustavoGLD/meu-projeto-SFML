#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>
#include <iterator>
#include <iostream>

#include "Game/Main.hpp"

int main()
{   
    Main main;
    main.Window();
    main.AllStart();

    while (main.window->isOpen())
    {
        sf::Event event;
        while (main.window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                main.window->close();
        }
        main.AllUpdate();
        main.Render();
    }

    return 0;
}