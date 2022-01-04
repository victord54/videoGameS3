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
#include "writeReadFile.hpp"

/**
 * @brief Class that manages what is related to the game itself
 * 
 */
class Game {
    private:
        Player player;

        int score;
        bool scoreWrited;

        Ball ball;

        int nbBricks;
        Brick *bricks;

        bool stateOfGame;
    
    public:
        /**
         * @brief Construct a new Game object
         * 
         */
        Game(std::string s) {
            player = Player(WINDOW_X-200, WINDOW_Y-30);
            ball = Ball();
            player.setName(s);
            score = 0;
            scoreWrited = false;
            stateOfGame = true;

            fileToBricks();
        }

        /**
         * @brief Get the Player object
         * 
         * @param n 
         * @return Player 
         */
        Player getPlayer() {
            return player;
        }

        /**
         * @brief Get the Ball object
         * 
         * @param n 
         * @return Ball 
         */
        Ball getBall() {
            return ball;
        }

        /**
         * @brief Get the Score object
         * 
         * @return int 
         */
        int getScore() {
            return score;
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

        bool getState() {
            return stateOfGame;
        }

        void setState(bool b) {
            stateOfGame = b;
        }

        /**
         * @brief Handles player and ball movements
         * 
         * @param app
         */
        void handleMoves(sf::RenderWindow &app) {
            player.handleMoves(app);

            ball.handleKeyboard(app);
            ball.collision(player);
            
            ball.movingX(player);
            collisionX();

            ball.movingY(player);
            collisionY();
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
            if (stateOfGame) {
                player.draw(app);
                ball.draw(app);
                drawBricks(app);
                printLifeToScreen(app);
            } else {
                sf::Texture textureGameOver;
                textureGameOver.loadFromFile("ressources/gameoverscreen.png");
                sf::Sprite sprite;
                sprite.setTexture(textureGameOver);
                app.draw(sprite);
                printScoreToScreen(app);
            }
            app.display();
        }

        void setScoreToFile() {
            FichierIO fichier = FichierIO("ressources/leaderboard.txt");
            fichier.ecrire(player.getName(), getScore());
            scoreWrited = true;
        }

        std::string getNameAndScore() {
            return "" + player.getName() + " " + std::to_string(score);
        }

        void printScoreToScreen(sf::RenderWindow &app) {
            sf::Font font;

            if (font.loadFromFile("ressources/UniversCondensed.ttf")) {
                sf::Text text;
                FichierIO fichier("ressources/leaderboard.txt");

                text.setFont(font);
                std::string s;
                int nb = fichier.getLineMax();
                for (int i = 0; i < nb; i++) {
                    s.append(fichier.lire(i));
                    s.append("\n");
                }
                text.setString(s);
                text.setCharacterSize(35);
                text.setFillColor(sf::Color::Red);
                text.setStyle(sf::Text::Bold);

                app.draw(text);
            } else {
                std::cout << "Erreur chargement police" << std::endl;
            }
        }

        void printLifeToScreen(sf::RenderWindow &app){
            sf::Font font;
            if (font.loadFromFile("ressources/lettre.TTF")){
                sf::Text text;
                std::string s;

                text.setFont(font);
                int nb = ball.getLife();
                s.append("Vie:");
                s.append(std::to_string(nb));
                text.setString(s);
                text.setCharacterSize(35);
                text.setFillColor(sf::Color::Green);
                text.setStyle(sf::Text::Bold);
                text.setPosition(650,5);
                app.draw(text);
            }
            else{
                std::cout << "Erreur chargement police" << std::endl;
            }
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

        bool collision(sf::Sprite sprite1, sf::Sprite sprite2) {

            if (sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds())) {
                score++;
                return true;
            } else {
                return false;
            }
        }

        /**
         * @brief Handle collisions between ball and bricks
         * 
         */
        void collisionX() {
            for (int i = 0; i <nbBricks; i++) {
                if (collision(bricks[i].getSprite(), ball.getSprite())) {
                    if (i < nbBricks - 1) {
                        if (collision(bricks[i+1].getSprite(), ball.getSprite())) {
                            continue;
                        }
                    } else if (i > 0) {
                        if (collision(bricks[i-1].getSprite(), ball.getSprite())) {
                            continue;
                        }
                    }
                    ball.setDX(-ball.getDX());
                    bricks[i].teleport();
                
                }
            }
        }

        /**
         * @brief Handle collisions between ball and bricks
         * 
         */
        void collisionY() {
            for (int i = 0; i <nbBricks; i++) {
                if (collision(bricks[i].getSprite(), ball.getSprite())) {
                    if (i < nbBricks - 1) {
                        if (collision(bricks[i+1].getSprite(), ball.getSprite())) {
                            continue;
                        }
                    } else if (i > 0) {
                        if (collision(bricks[i-1].getSprite(), ball.getSprite())) {
                            continue;
                        }
                    }
                    ball.setDY(-ball.getDY());
                    bricks[i].teleport();
                
                }
            }
        }

        void endOfGame() {
            if (score == nbBricks) {
                setState(false);
                ball.setMoving(false);
                if (!scoreWrited)
                    setScoreToFile();
            }
            else if(ball.getLife() == 0){
                setState(false);
                ball.setMoving(false);
            }
        }
};

#endif