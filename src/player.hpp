#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include "define.hpp"

/**
 * 
 * Modifier les attributs x et y (delete it) pour les remplacer par seulement des getter avec méthode getPosition() de l'objet Sprite
 * 
 **/

class Player {
    private:
        int spriteW;
        int spriteH;

        sf::IntRect playerRect;
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        Player(const std::string filename, int coordX, int coordY) {
            spriteW = 96;
            spriteH = 23;

            sprite.setPosition(coordX, coordY);

            playerRect = {0, 200, spriteW, spriteH};

            texture.loadFromFile(filename, playerRect);
        }

        int getX() {
            return sprite.getPosition().x;
        }

        int getY() {
            return sprite.getPosition().y;
        }

        int getW() {
            return spriteW;
        }

        int getH() {
            return spriteH;
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
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                if (getX() > 0)
                   moveX(-PLAYER_SPEED);
                printf("player.x = %d\nplayer.y = %d\n", getX(), getY());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                if (getX() + spriteW < WINDOW_X)
                    moveX(PLAYER_SPEED);
                printf("player.x = %d\nplayer.y = %d\n", getX(), getY());
            }
            sf::Vector2i coords = sf::Mouse::getPosition();
        }

};

#endif