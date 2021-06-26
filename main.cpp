#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>
#include <iterator>
#include <iostream>

int main()
{   
    sf::RenderWindow window(sf::VideoMode(), "Learning SFML", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    //Array de vértices
    sf::Vertex triangle_array[] = {
        //Posição                                //Cor
        sf::Vertex(sf::Vector2f( 00.0f, -50.0f), sf::Color::Red),
        sf::Vertex(sf::Vector2f(-50.0f,  50.0f), sf::Color::Blue),
        sf::Vertex(sf::Vector2f( 50.0f,  50.0f), sf::Color::Green)
    };

    //Vertex Buffer
    sf::VertexBuffer triangle(sf::Triangles);
    triangle.create(sizeof(triangle_array)/sizeof(sf::Vertex));
    triangle.update(triangle_array);

    sf::Transform local (1.0f, 0.0f, window.getSize().x/2,
                         0.0f, 1.0f, window.getSize().y/2,
                         0.0f, 0.0f, 1.0f);

    sf::Transform global(1.0f, 0.0f, 0.0f,
                         0.0f, 1.0f, 0.0f,
                         0.0f, 0.0f, 1.0f);

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
            local.translate(sf::Vector2f(velocity, 0.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            local.translate(sf::Vector2f(-velocity, 0.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            local.translate(sf::Vector2f(0.0f, -velocity));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            local.translate(sf::Vector2f(0.0f, velocity));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            local.rotate(-ang_velocity);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            local.rotate(ang_velocity);

        //Renderizar
        window.clear();
        window.draw(triangle, global * local);
        window.display();
    }

    return 0;
}