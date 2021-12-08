#ifndef BRICK_HPP
#define BRICK_HPP

#include <SFML/Graphics.hpp>
#include "define.hpp"
#include "texturesRect.hpp"

class Brick {
    private:
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        Brick() {
            TexturesRect textRect = TexturesRect();

            texture.loadFromFile("ressources/brickBreaker_sprites.png", textRect.getBrickRect(0));
            sprite.setPosition(0,0);
        }

        Brick(int n, int x, int y){
            TexturesRect textRect = TexturesRect();

            texture.loadFromFile("ressources/brickBreaker_sprites.png", textRect.getBrickRect(n));
            sprite.setPosition(x,y);
        }

        int getX() {
            return sprite.getPosition().x;
        }

        int getY() {
            return sprite.getPosition().y;
        }

        int getW() {
            return sprite.getGlobalBounds().width;
        }

        int getH() {
            return sprite.getGlobalBounds().height;
        }

        sf::Sprite getSprite() {
            return sprite;
        }

        void draw(sf::RenderWindow &app) {
            sprite.setTexture(texture);
            app.draw(sprite);
        }

        void teleport() {
            sprite.setPosition(-100, -100);
        }
};

#endif