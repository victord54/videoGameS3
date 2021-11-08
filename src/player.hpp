#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include "define.hpp"

class Player {
    private:
        int spriteW;
        int spriteH;

        int x;
        int y;

        sf::IntRect playerRect;
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        Player(const std::string filename, int coordX, int coordY) {
            spriteW = 96;
            spriteH = 23;

            x = coordX;
            y = coordY;

            playerRect = {0, 200, spriteW, spriteH};

            texture.loadFromFile(filename, playerRect);
            setPosition();
        }

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }

        int getW() {
            return spriteW;
        }

        int getH() {
            return spriteH;
        }

        void setPosition() {
            sprite.setPosition(x, y);
        }

        void moveX(int mX) {
            sprite.move(mX, 0);
            x += mX;
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
                if (x > 0)
                   moveX(-PLAYER_SPEED);
                printf("player.x = %d\nplayer.y = %d\n", x, y);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                if (x + spriteW < WINDOW_X)
                    moveX(PLAYER_SPEED);
                printf("player.x = %d\nplayer.y = %d\n", x, y);
            }
            sf::Vector2i coords = sf::Mouse::getPosition();
        }

};

#endif