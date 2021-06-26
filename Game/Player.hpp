#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>
#include <iterator>
#include <iostream>

#include "../Engine/MonoBehaviour.hpp"

class Player : public MonoBehaviour{
public:

    Object* player;

    void Start(sf::Window* window){

        player = new Object(

        /*
       {sf::Vertex(sf::Vector2f( 00.0f , -50.0f), sf::Color::Red),
        sf::Vertex(sf::Vector2f(-50.0f,  50.0f), sf::Color::Blue),
        sf::Vertex(sf::Vector2f( 50.0f,  50.0f), sf::Color::Green)},
        */

        /*vertices*/
        {sf::Vertex(sf::Vector2f( 0.0f, -0.2f), sf::Color::Red),
         sf::Vertex(sf::Vector2f(-0.2f,  0.2f), sf::Color::Blue),
         sf::Vertex(sf::Vector2f( 0.2f,  0.2f), sf::Color::Green)},

        /*local matrix*/
       {1.0f, 0.0f, (float)window->getSize().x/2,
        0.0f, 1.0f, (float)window->getSize().y/2,
        0.0f, 0.0f, 1.0f},

        /*global matrix*/
       {1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f},

        /*primitive type*/
        sf::Triangles,

        window        
    );
    }

    void Update(sf::Window* window){
        float velocity = 7.5f;
        float ang_velocity = 6;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            player->local->translate(sf::Vector2f(velocity, 0.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            player->local->translate(sf::Vector2f(-velocity, 0.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            player->local->translate(sf::Vector2f(0.0f, -velocity));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            player->local->translate(sf::Vector2f(0.0f, velocity));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            player->local->rotate(-ang_velocity);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            player->local->rotate(ang_velocity);

    }
};
