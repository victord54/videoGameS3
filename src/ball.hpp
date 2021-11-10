#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "define.hpp"
#include "texturesRect.hpp"

class Ball {
   private:
        int points;

        int dx;
        int dy;

        bool move;

        sf::Texture texture;
        sf::Sprite sprite;

    public:    
        Ball(Player &player, const std::string filename) {
            TexturesRect textRect = TexturesRect();
            
            dx = BALL_SPEED_X;
            dy = -BALL_SPEED_Y;

            move = false;
            points = 0;
            texture.loadFromFile(filename, textRect.getBallRect());
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
            return sprite.getGlobalBounds().width;
        }

        int getH() {
            return sprite.getGlobalBounds().height;
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
            if (sprite.getPosition().x < 0 || sprite.getPosition().x + getW() > WINDOW_X)
                setDX(-dx);
            if (sprite.getPosition().y < 0 || sprite.getPosition().y + getH() > WINDOW_Y)
                setDY(-dy);
            
            // Collision avec la plateforme (player)
            if (sprite.getGlobalBounds().intersects(player.getSprite().getGlobalBounds())) {
                setDY(-dy);
                points += 1;
                printf("Nombre de points + 1 : %d \n",points);
            }
            //Si la balle touche le bas de l'écran
            if (getY() == WINDOW_Y - 10){
                points -= 1;
                printf("Nombre de points - 1 : %d \n",points);
                setMoving(false);
            }
        }

};

#endif