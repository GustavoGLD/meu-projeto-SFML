#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>
#include <iterator>
#include <iostream>

class Object{
public:
    std::vector<sf::Vertex> array;
    sf::VertexBuffer* vertexBuffer;
    sf::Transform* local;
    sf::Transform* global;

    Object();

    Object(std::vector<sf::Vertex> array,
           sf::PrimitiveType       primitive,
           sf::Window*             window);

    Object(std::vector<sf::Vertex> array, 
           std::vector<float>      local,
           sf::PrimitiveType       primitive,
           sf::Window*             window);

    Object(std::vector<sf::Vertex> array, 
           std::vector<float>      local, 
           std::vector<float>      global,
           sf::PrimitiveType       primitive,
           sf::Window*             window);

    void draw(sf::RenderWindow* window);
};