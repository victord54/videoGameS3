#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "define.hpp"

class Ball {
   private:
        int spriteW;
        int spriteH;

        int x;
        int y;

        int dx;
        int dy;

        sf::IntRect playerRect;
        sf::Texture texture;
        sf::Sprite sprite;

    public:    
        Ball(Player &player, const std::string filename) {
            spriteW = 16;
            spriteH = 16;

            x = player.getX() + player.getW()/2;
            y = player.getY() - spriteH;

            dx = BALL_SPEED_X;
            dy = BALL_SPEED_Y;

            playerRect = {160, 200, spriteW, spriteH};


            texture.loadFromFile(filename, playerRect);
            setPosition();
        }

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }

        int getDX() {
            return dx;
        }

        int getDY() {
            return dy;
        }

        void setDX(int x) {
            dx = x;
        }

        void setDY(int y) {
            dy = y;
        }

        void setPosition() {
            sprite.setPosition(x, y);
        }

        void draw(sf::RenderWindow &app) {
            sprite.setTexture(texture);
            app.draw(sprite);
        }

        void moving() {
            sprite.move(dx, dy);

            if (sprite.getPosition().x < 0 || sprite.getPosition().x + spriteW > WINDOW_X)
                setDX(-dx);
            if (sprite.getPosition().y < 0 || sprite.getPosition().y + spriteH > WINDOW_Y)
                setDY(-dy);
        }

        void handleMoves(sf::RenderWindow &app) {
            sf::Event event;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                moving();

            sf::Vector2i coords = sf::Mouse::getPosition();
        }
};

#endif