#ifndef BRICK_HPP
#define BRICK_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "define.hpp"
#include "texturesRect.hpp"

class Brick {
    private:
    char c;
    sf::Texture texture;
    sf::Sprite sprite;

    public:
    Brick(char c){
        TexturesRect textRect = TexturesRect();
        c = c;
        texture.loadFromFile("ressources/brickBreaker_sprites.png", textRect.getBrickRect(0));
    }
};

#endif