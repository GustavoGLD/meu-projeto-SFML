#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>
#include <iterator>
#include <iostream>

#include "Object.cpp"


class MonoBehaviour : public Object{
    virtual void Start(sf::Window* window){

    };

    virtual void Update(sf::Window* window){
        
    };
};