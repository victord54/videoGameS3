#ifndef MENU_HPP
#define MENU_HPP

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "define.hpp"


class Menu{
    private:
    sf::Texture texturePlay;
    sf::Texture textureQuit;
    sf::Sprite spritePLay;
    sf::Sprite spriteQuit;

    int menuUpdate;
    int choix;
    
    public:
        Menu(){
            texturePlay.loadFromFile("ressources/play.png");
            textureQuit.loadFromFile("ressources/quit.png");
            spritePLay.setPosition(0,0);
            spriteQuit.setPosition(0,100);
            choix = 0;
            menuUpdate = 1;
        }   

        int getMenuUpdate(){
            return menuUpdate;
        }

        void draw(sf::RenderWindow &app) {
            app.clear();
            spritePLay.setTexture(texturePlay);
            spriteQuit.setTexture(textureQuit);
            app.draw(spritePLay);
            app.draw(spriteQuit);
            app.display();
        }

        void handleMoves(sf::RenderWindow &app) {
            sf::Event event;
            while (app.pollEvent(event)) {
                // évènement "fermeture demandée" : on ferme la fenêtre
                if (event.type == sf::Event::Closed)
                    app.close();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    app.close();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    if(choix == 0)          //Si on est sur play
                        menuUpdate = 0;
                    if(choix == 1)          //Si on est sur quit
                        app.close();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    if(choix == 0)
                        choix++;
                    else
                        choix--;
                    printf("%d\n",choix);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    if(choix == 0)
                        choix++;
                    else
                        choix--;
                    printf("%d\n",choix);
            }
        }
};

#endif