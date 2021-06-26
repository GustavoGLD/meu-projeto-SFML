#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>
#include <iterator>
#include <iostream>

#include "Game/Player.hpp"


class Main : public Player{
public:
    sf::RenderWindow* window;

    void Window(){
        window = new sf::RenderWindow(sf::VideoMode(), "Learning SFML", sf::Style::Fullscreen);
        window->setFramerateLimit(60);
    }

    void AllStart(){
        Start();
    }

    void AllUpdate(){
        Update();
    }

    void Render(){
        triangle->draw(window);
    }
};

int main()
{   
    Main main;
    main.Window();
    main.AllStart();

    while (main.window->isOpen())
    {

        //Input
        sf::Event event;
        while (main.window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                main.window->close();
        }

        float velocity = 7.5f;
        float ang_velocity = 6;

        main.AllUpdate();

        //Renderizar
        main.window->clear();
        main.triangle->draw(main.window);
        main.window->display();
    }

    return 0;
}