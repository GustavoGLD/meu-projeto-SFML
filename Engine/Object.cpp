#include "Object.hpp"

Object::Object(){

}

Object::Object(std::vector<sf::Vertex> array,
               sf::PrimitiveType       primitive)
{
    this->array = array;

    this->local = new sf::Transform(
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    );

    this->global = new sf::Transform(
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    );

    vertexBuffer = new sf::VertexBuffer(primitive);
    vertexBuffer->create(array.size());
    vertexBuffer->update(&array[0]);

};


Object::Object(std::vector<sf::Vertex> array, 
               std::vector<float>      local,
               sf::PrimitiveType       primitive)
{
    this->array = array;

    this->local = new sf::Transform(
        local[0], local[1], local[2],
        local[3], local[4], local[5],
        local[6], local[7], local[8]
    );

    this->global = new sf::Transform(
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    );

    vertexBuffer = new sf::VertexBuffer(primitive);
    vertexBuffer->create(array.size());
    vertexBuffer->update(&array[0]);
};


Object::Object(std::vector<sf::Vertex> array, 
               std::vector<float>      local, 
               std::vector<float>      global,
               sf::PrimitiveType       primitive)
{
    for (int x=0; x < array.size(); x++){

        this->array.push_back(
            sf::Vertex(sf::Vector2f(array[x].position.x, array[x].position.y), array[x].color)
        );

    }

    this->local = new sf::Transform(
        local[0], local[1], local[2],
        local[3], local[4], local[5],
        local[6], local[7], local[8]
    );

    this->global = new sf::Transform(
        global[0], global[1], global[2],
        global[3], global[4], global[5],
        global[6], global[7], global[8]
    );

    vertexBuffer = new sf::VertexBuffer(primitive);
    vertexBuffer->create(array.size());
    vertexBuffer->update(&array[0]);
};

void Object::draw(sf::RenderWindow* window){
    window->draw(*vertexBuffer, *global * *local);
};