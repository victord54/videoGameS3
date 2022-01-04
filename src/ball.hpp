#ifndef BALL_HPP
#define BALL_HPP

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "player.hpp"
#include "define.hpp"
#include "texturesRect.hpp"

/**
 * @brief Class that represents Ball in the game
 * 
 */
class Ball {
   private:
        int dx;
        int dy;
        float life;

        bool move;

        sf::Texture texture;
        sf::Sprite sprite;

    public:
        /**
         * @brief Construct a new Ball object
         * 
         */
        Ball() {
            TexturesRect textRect = TexturesRect();
            
            dx = 8;
            dy = -6;
            life = 3;

            move = false;
            texture.loadFromFile("ressources/brickBreaker_sprites.png", textRect.getBallRect());
        }

        /**
         * @brief Get the nomber of remaining life
         * 
         * @return int 
         */
        int getLife() {
            return life;
        }

        /**
         * @brief Loose a life
         * 
         */
        void lifeDown(){
            life = life - 0.5;
        }

        /**
         * @brief Get the x coordinate of the Ball
         * 
         * @return int 
         */
        int getX() {
            return sprite.getPosition().x;
        }

        /**
         * @brief Get the y coordinate of the Ball
         * 
         * @return int 
         */
        int getY() {
            return sprite.getPosition().y;
        }

        /**
         * @brief Get the x speed of the Ball
         * 
         * @return int 
         */
        int getDX() {
            return dx;
        }

        /**
         * @brief Get the y speed of the Ball
         * 
         * @return int 
         */
        int getDY() {
            return dy;
        }

        /**
         * @brief Get the width of the Ball
         * 
         * @return int 
         */
        int getW() {
            return sprite.getGlobalBounds().width;
        }

        /**
         * @brief Get the height of the Ball
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
         * @brief Indicate if the ball is moving or not
         * 
         * @return true 
         * @return false 
         */
        bool isMoving() {
            return move;
        }

        /**
         * @brief Set the x speed of the Ball
         * 
         * @param x 
         */
        void setDX(int x) {
            dx = x;
        }

        /**
         * @brief Set the y speed of the Ball
         * 
         * @param y 
         */
        void setDY(int y) {
            dy = y;
        }

        /**
         * @brief Set the Moving object
         * 
         * @param b 
         */
        void setMoving(bool b) {
            move = b;
        }

        /**
         * @brief Show texture of the Ball on screen
         * 
         * @param app 
         */
        void draw(sf::RenderWindow &app) {
            sprite.setTexture(texture);
            app.draw(sprite);
        }

        /**
         * @brief Allow to make move the ball in the game
         * 
         * @param player 
         */
        void movingX(Player &player) {
            if (isMoving() == true) {
                sprite.move(dx, 0);
                collision(player);
            }
            else
                sprite.setPosition(player.getX() + player.getW()/2 - 6, player.getY() - player.getH()/2 - 4);
        }

        /**
         * @brief Allow to make move the ball in the game
         * 
         * @param player 
         */
        void movingY(Player &player) {
            if (isMoving() == true) {
                sprite.move(0, dy);
                collision(player);
            }
            else
                sprite.setPosition(player.getX() + player.getW()/2 - 6, player.getY() - player.getH()/2 - 4);
        }

        /**
         * @brief Handle the ball movement
         * 
         * @param app 
         */
        void handleKeyboard(sf::RenderWindow &app) {
            sf::Event event;
  
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                setMoving(true);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                setMoving(false);
        }

        /**
         * @brief Handle the collisions between Ball and walls/Player
         * 
         * @param player 
         */
        void collision(Player &player) {
            // Collision avec les murs
            if (sprite.getPosition().x < 0 || sprite.getPosition().x + getW() > WINDOW_X)
                setDX(-dx);
            if (sprite.getPosition().y < 0 || sprite.getPosition().y + getH() > WINDOW_Y)
                setDY(-dy);
            if (getY() >= WINDOW_Y - 16) { // Si la balle touche le mur du bas
                    setMoving(false);
                    lifeDown();
                }
            
            // Collision avec la plateforme (player)
            if (sprite.getGlobalBounds().intersects(player.getSprite().getGlobalBounds())) {
                //Si la balle touche le bas de l'écran
                //Il faut : trouver la position de la balle SUR la plateforme
                //Envoyer la balle dans la bonne directio
                    //Puis dans le bon angle
                
                int playerX = player.getX() + (player.getW() / 2);
                int ballX = this->getX();
                int collisionPointX = ballX - playerX;  //Retourne valeur négative si inf à la moitié de la plateforme et positive si plus de la moitiée de la plateforme
                //setDX(colideX - dx / 2); //Formule abandonnée
                if(collisionPointX > 0){    //Balle va à droite
                    if(collisionPointX > 30){
                        setDX(10);
                        setDY(-dy);
                    }
                    else if(collisionPointX > 15){
                        setDX(5);
                        setDY(-dy);
                    }
                    else{
                        setDX(1);
                        setDY(-dy - 1);
                    }
                }
                if(collisionPointX == 0){   //Balle va en haut
                    setDX(0);
                    setDY(-dy);
                }
                if(collisionPointX < 0){    //Balle va à gauche
                    if(collisionPointX < -30){
                        setDX(-10);
                        setDY(-dy);
                    }
                    else if(collisionPointX < -15){
                        setDX(-5);
                        setDY(-dy);
                    }
                    else{
                        setDX(-1);
                        setDY(-dy - 1);
                    }
                }
            }
        }

};

#endif