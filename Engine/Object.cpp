#include "Object.hpp"

Object::Object(){

}

Object::Object(std::vector<sf::Vertex> array,
               sf::PrimitiveType       primitive,
               sf::Window*             window)
{
    float aspect = (float)window->getSize().x / (float)window->getSize().y;
    for (int x=0; x < array.size(); x++){
        //normalizar array
        this->array.push_back(sf::Vertex(
            sf::Vector2f((float)array[x].position.x * (float)window->getSize().x, 
                         (float)array[x].position.y * (float)window->getSize().y * aspect),
            array[x].color,
            sf::Vector2f(array[x].texCoords.x, array[x].texCoords.y))
        );
    }

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
               sf::PrimitiveType       primitive,
               sf::Window*             window)
{
    float aspect = (float)window->getSize().x / (float)window->getSize().y;
    for (int x=0; x < array.size(); x++){
        //normalizar array
        this->array.push_back(sf::Vertex(
            sf::Vector2f((float)array[x].position.x * (float)window->getSize().x, 
                         (float)array[x].position.y * (float)window->getSize().y * aspect * (-1.0f)),
            array[x].color,
            sf::Vector2f(array[x].texCoords.x, array[x].texCoords.y))
        );
    }

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
               sf::PrimitiveType       primitive,
               sf::Window*             window)
{
    float aspect = (float)window->getSize().x / (float)window->getSize().y;
    for (int x=0; x < array.size(); x++){
        //normalizar array
        this->array.push_back(sf::Vertex(
            sf::Vector2f((float)array[x].position.x * (float)window->getSize().x, 
                         (float)array[x].position.y * (float)window->getSize().y * aspect),
            array[x].color,
            sf::Vector2f(array[x].texCoords.x, array[x].texCoords.y))
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
    vertexBuffer->create(this->array.size());
    vertexBuffer->update(&this->array[0]);
};

void Object::draw(sf::RenderWindow* window){
    renderStates->transform = *local * *global;
    window->draw(*vertexBuffer, *renderStates);
};