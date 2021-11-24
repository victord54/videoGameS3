#ifndef BALL_HPP
#define BALL_HPP

#include <cstdlib>
#include <iostream>
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
        Ball() {
            TexturesRect textRect = TexturesRect();
            
            dx = BALL_SPEED_X;
            dy = -BALL_SPEED_Y;

            move = false;
            points = 0;
            texture.loadFromFile("ressources/brickBreaker_sprites.png", textRect.getBallRect());
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
                //Il faut : trouver la position de la balle SUR la plateforme
                //Envoyer la balle dans la bonne directio
                    //Puis dans le bon angle
                
                int playerX = player.getX() + (player.getW() / 2);
                int ballX = this->getX();
                int collisionPointX = ballX - playerX;  //Retourne valeur négative si inf à la moitié de la plateforme et positive si plus de la moitier de la plateforme
                //setDX(colideX - dx / 2); //Formule abandonnée 
                if(collisionPointX > 0){    //Balle va à droite
                    setDX(8);
                    setDY(-dy);
                }
                if(collisionPointX < 0){    //Balle va à gauche
                    setDX(-8);
                    setDY(-dy);
                }
                // //Affichage pour reglage :
                // printf("colideX valeur = %d \n",collisionPointX);
                // printf("DX : %d \n",dx);
                // printf("Dy : %d \n",dy);
                
                //setDY(FORMULE DU TURFU)    
                points += 1;
            }
            //Si la balle touche le bas de l'écran
            if (getY() == WINDOW_Y - 10) {
                points -= 1;
                printf("Nombre de points - 1 : %d \n",points);
                setMoving(false);
            }
        }

};

#endif