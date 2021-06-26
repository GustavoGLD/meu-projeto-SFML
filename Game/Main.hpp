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
        window = new sf::RenderWindow(sf::VideoMode(800, 600), "Learning SFML");
        window->setFramerateLimit(60);
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