#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <iostream>
#include <fstream>  
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

#include "define.hpp"
#include "player.hpp"
#include "ball.hpp"
#include "brick.hpp"

std::ifstream  fichier;    //Fichier
using namespace std; 

/**
 * @brief Class that manages what is related to the game itself
 * 
 */
class Game {
    private:
        Player players[2];
        Ball balls[5];
        Brick bricks[250];
        char tab[25][10] = {' '};
    
    public:
        /**
         * @brief Construct a new Game object
         * 
         */
        Game() {
            players[0] = Player(WINDOW_X-200, WINDOW_Y-30);

            balls[0] = Ball();
            insererDansTableau();
            strToBricks(tab);
        }

        /**
         * @brief Get the Player object
         * 
         * @param n 
         * @return Player 
         */
        Player getPlayer(int n) {
            return players[n];
        }

        /**
         * @brief Get the Ball object
         * 
         * @param n 
         * @return Ball 
         */
        Ball getBall(int n) {
            return balls[n];
        }

        /**
         * @brief Get the Brick object
         * 
         * @param n 
         * @return Brick 
         */
        Brick getBrick(int n) {
            return bricks[n];
        }

        /**
         * @brief Handles player and ball movements
         * 
         * @param app 
         */
        void handleMoves(sf::RenderWindow &app) {
            players[0].handleMoves(app);

            balls[0].handleKeyboard(app);
            
            balls[0].moving(players[0]);
        }

        /**
         * @brief Draw all the bricks in the game
         * 
         * @param app 
         */
        void drawBricks(sf::RenderWindow &app) {
            for (int i = 0; i < 250; i++) {
                bricks[i].draw(app);
            }
            
        }

        /**
         * @brief Draw all the objects in the game
         * 
         * @param app 
         */
        void draw(sf::RenderWindow &app) {
            app.clear();
            players[0].draw(app);
            // j2.draw(app);

            balls[0].draw(app);
            // balls[1].draw(app);

            drawBricks(app);

            app.display();
        }

        void insererDansTableau(){
            char a;
            int pos = 0;
            int i = 0;
            int j = 0;
            ifstream fichier("ressources/input.txt" );
            if (fichier) { // le fichier peut s'ouvrir
                fichier.seekg(pos,ios::end);
                int taille = fichier.tellg();

                for (pos = 0; pos < taille; pos++) {
                    fichier.seekg(pos,std::ios::beg);
                    fichier.get(a);
                    if ((int)a == 10)
                        j++;
                    else
                        tab[i%25][j] = a;
                    i++;
                }
            }
            else{
                printf("Cheh le fichier s'ouvre pas\n");
            }
        }
        
        void strToBricks(char file[25][10]) {
            int n = 0;
            for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 10; j++) {
                    switch (file[i][j]) {
                        case '0':
                            bricks[n] = Brick(0, 32*i, 32*j); break;
                        case '1':
                            bricks[n] = Brick(1, 32*i, 32*j); break;
                        case '2':
                            bricks[n] = Brick(2, 32*i, 32*j); break;
                        case '3':
                            bricks[n] = Brick(3, 32*i, 32*j); break;
                        case '4':
                            bricks[n] = Brick(4, 32*i, 32*j); break;
                        case '5':
                            bricks[n] = Brick(5, 32*i, 32*j); break;
                        case '6':
                            bricks[n] = Brick(6, 32*i, 32*j); break;
                        case ' ':
                            break;
                        default:
                            break;
                    }
                    n++;
                }
            }
        }
};

#endif