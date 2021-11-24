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
        char tab[25][10];
    
    public:
        /**
         * @brief Construct a new Game object
         * 
         */
        Game() {
            char str[25][10];

            for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 10; j++) {
                    if (j % 2 == 0)
                        str[i][j] = '1';
                    else
                        str[i][j] = '_';
                }
            }
            str[0][0] = '1';

            players[0] = Player(WINDOW_X-200, WINDOW_Y-30);

            balls[0] = Ball();

            strToBricks(str);
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
            int position;
            int n = 0;
            ifstream  fichier( "ressources/input.txt" );
            fichier.seekg(0, ios::beg);
            if (fichier) {                        //le fichier peut s'ouvrir ouvert
                for(int i = 0; i < 25; i++){
                    for(int y = 0; i < 10; y++){
                        fichier.get(a);
                        if (a == 10){
                            break;
                        }
                        printf("Valeur de a : %d\n",a);
                        tab[i][y] = a;
                        position = fichier.tellg();
                        position--;
                        printf("Le curseur est en position %d et capte le characère %c \n", position, a);   
                        //fichier.seekg(n, ios::beg);
                        n++;
                   }
                }
            }
            else{
                printf("Cheh le fichier s'ouvre pas\n");
            }
            for (int k = 0; k < 25; k++ ) {
                for (int l = 0; l < 10; l++ ) {
                    printf("%c", tab[k][l]);
                }
                printf("\n");
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
                        case '_':
                            break;
                        default:
                            bricks[n] = Brick(0, 32*i, 32*j); break;
                    }
                    n++;
                }
            }
        }
};

#endif