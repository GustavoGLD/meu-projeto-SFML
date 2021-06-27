#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>
#include <iterator>
#include <iostream>

#include "../Engine/MonoBehaviour.hpp"

class Player : public MonoBehaviour{
public:

    Object* player;
    float velocity = 100.0f;
    float ang_velocity = 6;
    sf::Texture* texture = new sf::Texture();

    void Start(sf::Window* window){

        if (!texture->loadFromFile("Assets/Plane.png")){
            std::cout << "erro ao carregar File" << std::endl;
        };

        float tx = (float)texture->getSize().x;
        float ty = (float)texture->getSize().y;

        player = new Object(
            
            /*vertices*/
           {sf::Vertex(sf::Vector2f( 1.0f, -1.0f), sf::Vector2f(0.0f, 0.0f)),
            sf::Vertex(sf::Vector2f(-1.0f, -1.0f), sf::Vector2f(  tx, 0.0f)),
            sf::Vertex(sf::Vector2f( 1.0f,  1.0f), sf::Vector2f(0.0f, ty  )),
            sf::Vertex(sf::Vector2f(-1.0f,  1.0f), sf::Vector2f(  tx, ty  ))},

            /*local matrix*/
           {0.1f, 0.0f, (float)window->getSize().x/2,
            0.0f, 0.1f, (float)window->getSize().y/2,
            0.0f, 0.0f, 1.0f},

            /*global matrix*/
            {1.0f, 0.0f, 0.0f,
             0.0f, 1.0f, 0.0f,
             0.0f, 0.0f, 1.0f},

            /*primitive type*/
            sf::TrianglesStrip,

            window
        );

        player->renderStates->texture = texture;

    }

    void Update(sf::Window* window){
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
