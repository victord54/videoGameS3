#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "define.hpp"
#include "texturesRect.hpp"

/**
 * @brief Class that represents the platform that player controls
 * 
 */
class Player {
    private:
        bool deplacementSouris;

        sf::Texture texture;
        sf::Sprite sprite;

    public:
        /**
         * @brief Construct a new Player object
         * 
         */
        Player() {
        }

        /**
         * @brief Construct a new Player object
         * 
         * @param coordX Coordinate to place Player in x
         * @param coordY Coordinate to place Player in y
         */
        Player(int coordX, int coordY) {
            TexturesRect textRect = TexturesRect();


            deplacementSouris = false;
            sprite.setPosition(coordX, coordY);
            texture.loadFromFile("ressources/brickBreaker_sprites.png", textRect.getPlayerRect());
        }

        /**
         * @brief Get the x coordinate of the Player
         * 
         * @return int 
         */
        int getX() {
            return sprite.getPosition().x;
        }

        /**
         * @brief Get the y coordinate of the Player
         * 
         * @return int 
         */
        int getY() {
            return sprite.getPosition().y;
        }

        /**
         * @brief Get the width of the Player
         * 
         * @return int 
         */
        int getW() {
            return sprite.getGlobalBounds().width;
        }

        /**
         * @brief Get the height of the Player
         * 
         * @return int 
         */
        int getH() {
            return sprite.getGlobalBounds().height;
        }

        /**
         * @brief Indicates if we use the mouse or not
         * 
         * @return true 
         * @return false 
         */
        bool isSouris() {
            return deplacementSouris;
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
         * @brief Set the x coordinate of the Player
         * 
         * @param mx 
         */
        void setX(int mx) {
            sprite.setPosition(mx,getY());
        }

        /**
         * @brief Set the Deplacement Souris object
         * 
         * @param b 
         */
        void setDeplacementSouris(bool b) {
            deplacementSouris = b;
        }
        
        /**
         * @brief Move the Player
         * 
         * @param mX 
         */
        void moveX(int mX) {
            sprite.move(mX, 0);
        }

        /**
         * @brief Show texture of the Player on screen
         * 
         * @param app 
         */
        void draw(sf::RenderWindow &app) {
            sprite.setTexture(texture);
            app.draw(sprite);
        }

        /**
         * @brief Handle the moves of the Player
         * 
         * @param app 
         */
        void handleMoves(sf::RenderWindow &app) {
            sf::Event event;
            while (app.pollEvent(event)) {
                // évènement "fermeture demandée" : on ferme la fenêtre
                if (event.type == sf::Event::Closed)
                    app.close();
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    app.close();
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
                    setDeplacementSouris(true);

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
                    setDeplacementSouris(false);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                moveX(-PLAYER_SPEED);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                moveX(PLAYER_SPEED);
            
            if (isSouris() == true) {
                sf::Vector2i coords = sf::Mouse::getPosition(app);
                setX(coords.x);
            }
            
            if (getX() < 0)
                setX(0);
            
            if (getX() + getW() > WINDOW_X)
                setX(WINDOW_X - getW());

            //printf("player.x = %d\nplayer.y = %d\n", getX(), getY());
        }

};

#endif