#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>
#include <iterator>
#include <iostream>

#include "Engine/Object.cpp"

int main()
{   
    sf::RenderWindow window(sf::VideoMode(), "Learning SFML", sf::Style::Fullscreen);
    window.setFramerateLimit(60);


    Object triangle(

        /*vertices*/
       {sf::Vertex(sf::Vector2f( 00.0f, -50.0f), sf::Color::Red),
        sf::Vertex(sf::Vector2f(-50.0f,  50.0f), sf::Color::Blue),
        sf::Vertex(sf::Vector2f( 50.0f,  50.0f), sf::Color::Green)},

        /*local matrix*/
       {1.0f, 0.0f, (float)window.getSize().x/2,
        0.0f, 1.0f, (float)window.getSize().y/2,
        0.0f, 0.0f, 1.0f},

        /*global matrix*/
       {1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f},

        /*primitive type*/
        sf::Triangles
        
    );


    while (window.isOpen())
    {

        //Input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float velocity = 7.5f;
        float ang_velocity = 6;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            triangle.local->translate(sf::Vector2f(velocity, 0.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            triangle.local->translate(sf::Vector2f(-velocity, 0.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            triangle.local->translate(sf::Vector2f(0.0f, -velocity));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            triangle.local->translate(sf::Vector2f(0.0f, velocity));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            triangle.local->rotate(-ang_velocity);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            triangle.local->rotate(ang_velocity);

        //Renderizar
        window.clear();
        triangle.draw(&window);
        window.display();
    }

    return 0;
}