#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "define.hpp"
#include "texturesRect.hpp"

class Player {
    private:
        bool deplacementSouris;

        sf::Texture texture;
        sf::Sprite sprite;

    public:
        Player() {
            TexturesRect textRect = TexturesRect();

            deplacementSouris = false;
            sprite.setPosition(0, WINDOW_Y-20);
            texture.loadFromFile("ressources/brickBreaker_sprites.png", textRect.getPlayerRect());
        }

        Player(int coordX, int coordY) {
            TexturesRect textRect = TexturesRect();


            deplacementSouris = false;
            sprite.setPosition(coordX, coordY);
            texture.loadFromFile("ressources/brickBreaker_sprites.png", textRect.getPlayerRect());
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

        bool isSouris() {
            return deplacementSouris;
        }

        sf::Sprite getSprite() {
            return sprite;
        }

        void setX(int mx){
            sprite.setPosition(mx,getY());
        }

        void setDeplacementSouris(bool b) {
            deplacementSouris = b;
        }
        
        void moveX(int mX) {
            sprite.move(mX, 0);
        }

        void draw(sf::RenderWindow &app) {
            sprite.setTexture(texture);
            app.draw(sprite);
        }

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

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                moveX(-PLAYER_SPEED);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
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