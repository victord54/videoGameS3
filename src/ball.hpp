#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "define.hpp"

class Ball {
   private:
        int spriteW;
        int spriteH;

        int dx;
        int dy;

        bool move;

        sf::IntRect playerRect;
        sf::Texture texture;
        sf::Sprite sprite;

    public:    
        Ball(Player &player, const std::string filename) {
            spriteW = 16;
            spriteH = 16;

            dx = BALL_SPEED_X;
            dy = -BALL_SPEED_Y;

            move = false;

            playerRect = {160, 200, spriteW, spriteH};


            texture.loadFromFile(filename, playerRect);
        }

        int getX() {
            return sprite.getPosition().x;
        }

        int getY() {
            return sprite.getPosition().y;
        }

        int getDX() {
            return dx;
        }

        int getDY() {
            return dy;
        }

        int getW() {
            return spriteW;
        }

        int getH() {
            return spriteH;
        }

        bool isMoving() {
            return move;
        }

        void setDX(int x) {
            dx = x;
        }

        void setDY(int y) {
            dy = y;
        }

        void setMoving(bool b) {
            move = b;
        }

        void draw(sf::RenderWindow &app) {
            sprite.setTexture(texture);
            app.draw(sprite);
        }

        void moving(Player &player) {
            if (isMoving() == true) {
                sprite.move(dx, dy);
                collision(player);
            }
            else
                sprite.setPosition(player.getX() + player.getW()/2 - 6, player.getY() - player.getH()/2 - 4);
        }

        void handleKeyboard(sf::RenderWindow &app) {
            sf::Event event;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                setMoving(true);
        }

        void collision(Player &player) {
            // Collision avec les murs
            if (sprite.getPosition().x < 0 || sprite.getPosition().x + spriteW > WINDOW_X)
                setDX(-dx);
            if (sprite.getPosition().y < 0 || sprite.getPosition().y + spriteH > WINDOW_Y)
                setDY(-dy);
            
            // Collision avec la plateforme (player)
            if (getX() >= player.getX() && getX() <= player.getX() + player.getW()) {
                if (getY() >= player.getY() - player.getH()/2)
                    setDY(-dy);
            }
        }

};

#endif