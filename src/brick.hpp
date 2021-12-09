#ifndef BRICK_HPP
#define BRICK_HPP

#include <SFML/Graphics.hpp>
#include "define.hpp"
#include "texturesRect.hpp"

/**
 * @brief Class that represents Brick of the game
 * 
 */
class Brick {
    private:
        sf::Texture texture;
        sf::Sprite sprite;
    
    public:
        /**
         * @brief Construct a new Brick object
         * 
         */
        Brick() {
            TexturesRect textRect = TexturesRect();

            texture.loadFromFile("ressources/brickBreaker_sprites.png", textRect.getBrickRect(0));
            sprite.setPosition(0,0);
        }

        /**
         * @brief Construct a new Brick object
         * 
         * @param n 
         * @param x 
         * @param y 
         */
        Brick(int n, int x, int y){
            TexturesRect textRect = TexturesRect();

            texture.loadFromFile("ressources/brickBreaker_sprites.png", textRect.getBrickRect(n));
            sprite.setPosition(x,y);
        }

        /**
         * @brief Get the x coordinate of the Brick
         * 
         * @return int 
         */
        int getX() {
            return sprite.getPosition().x;
        }

        /**
         * @brief Get the y coordinate of the Brick
         * 
         * @return int 
         */
        int getY() {
            return sprite.getPosition().y;
        }

        /**
         * @brief Get the width of the Brick
         * 
         * @return int 
         */
        int getW() {
            return sprite.getGlobalBounds().width;
        }

        /**
         * @brief Get the height of the Brick
         * 
         * @return int 
         */
        int getH() {
            return sprite.getGlobalBounds().height;
        }

        /**
         * @brief Get the Sprite object
         * 
         * @return sf::Sprite 
         */
        sf::Sprite getSprite() {
            return sprite;
        }

        /**
         * @brief Show texture of the Brick on screen
         * 
         * @param app 
         */
        void draw(sf::RenderWindow &app) {
            sprite.setTexture(texture);
            app.draw(sprite);
        }

        /**
         * @brief In case of collision, teleports the Brick to make it disappear
         * 
         */
        void teleport() {
            sprite.setPosition(-100, -100);
        }
};

#endif