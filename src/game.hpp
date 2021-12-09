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
#include "menu.hpp"

/**
 * @brief Class that manages what is related to the game itself
 * 
 */
class Game {
    private:
        int nbPlayers;
        Player players;

        int nbBalls;
        Ball balls;

        int nbBricks;
        Brick *bricks;
    
    public:
        /**
         * @brief Construct a new Game object
         * 
         */
        Game() {
            players = Player(WINDOW_X-200, WINDOW_Y-30);
            balls = Ball();

            fileToBricks();
        }

        /**
         * @brief Get the Player object
         * 
         * @param n 
         * @return Player 
         */
        Player getPlayer(int n) {
            return players;
        }

        /**
         * @brief Get the Ball object
         * 
         * @param n 
         * @return Ball 
         */
        Ball getBall(int n) {
            return balls;
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
            players.handleMoves(app);

            balls.handleKeyboard(app);
            
            balls.moving(players);

            collision();
        }

        /**
         * @brief Show texture of all Bricks on screen
         * 
         * @param app 
         */
        void drawBricks(sf::RenderWindow &app) {
            for (int i = 0; i < nbBricks; i++) {
                bricks[i].draw(app);
            }
        }

        /**
         * @brief Show texture of all the objects on screen
         * 
         * @param app
         */
        void draw(sf::RenderWindow &app) {
            app.clear();
            players.draw(app);

            balls.draw(app);

            drawBricks(app);

            app.display();
        }

        /**
         * @brief Allow to generate Bricks from a text file
         * 
         */
        void fileToBricks() {
            char c;
            std::ifstream fichier("ressources/input.txt");
            if (fichier) {
                fichier.seekg(0, std::ios::end);
                int size = fichier.tellg();
                nbBricks = size;

                char* tab= (char*)malloc(size * sizeof(char));

                for (int i = 0; i < size; i++) {
                    fichier.seekg(i, std::ios::beg);
                    fichier.get(c);
                    if (c == 10)
                        nbBricks--;
                    tab[i] = c;
                }

                bricks = new Brick[size];

                std::cout << "size=" << size << std::endl;
                std::cout << "nbBricks=" << nbBricks << std::endl;
                int w = 0;
                int h = 0;
                int n = 0;
                for (int i = 0; i < size; i++) {
                    switch (tab[i]) {
                        case '0':
                            bricks[n] = Brick(0, 32*(w), 32*h);
                            n++;
                            break;
                        case '1':
                            bricks[n] = Brick(1, 32*(w), 32*h);
                            n++; 
                            break;
                        case '2':
                            bricks[n] = Brick(2, 32*(w), 32*h);
                            n++; 
                            break;
                        case '3':
                            bricks[n] = Brick(3, 32*(w), 32*h);
                            n++; 
                            break;
                        case '4':
                            bricks[n] = Brick(4, 32*(w), 32*h);
                            n++;
                            break;
                        case '5':
                            bricks[n] = Brick(5, 32*(w), 32*h);
                            n++; 
                            break;
                        case '6':
                            bricks[n] = Brick(6, 32*(w), 32*h);
                            n++; 
                            break;
                        case '_':
                            bricks[n] = Brick(0,32*(w), 32*h);
                            bricks[n].teleport();
                            n++; 
                            break;
                        default:
                            h++;
                            w = -1;
                            break;
                    }
                    w++;
                }
                if (n != nbBricks)
                    exit(0);
            }
        }

        /**
         * @brief Handle collisions between ball and bricks
         * 
         */
        void collision() {
            for (int i = 0; i <nbBricks; i++) {
                if (balls.getSprite().getGlobalBounds().intersects(bricks[i].getSprite().getGlobalBounds())) {
                    bricks[i].teleport();

                }

            }
        }
};

#endif