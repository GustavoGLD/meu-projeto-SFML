#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>
#include <iterator>
#include <iostream>

#include "Player.hpp"


class Main{
public:
    sf::RenderWindow* window;
    Player player;

    void Window(){
        window = new sf::RenderWindow(sf::VideoMode(), "Learning SFML", sf::Style::Fullscreen);
        window->setFramerateLimit(60);
        std::cout << "foi" << std::endl;
    }

    void AllStart(){
        player.Start(window);
    }

    void AllUpdate(){
        player.Update(window);
    }

    void Render(){
        window->clear();

        player.player->draw(window);

        window->display();
    }
};