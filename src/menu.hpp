#ifndef MENU_HPP
#define MENU_HPP

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "define.hpp"


class Menu{
    private:
    sf::Texture texturePlayGrand;
    sf::Texture textureQuitGrand;
    sf::Texture texturePlayTiny;
    sf::Texture textureQuitTiny;
    sf::Sprite spritePlayGrand;
    sf::Sprite spriteQuitGrand;
    sf::Sprite spritePlayTiny;
    sf::Sprite spriteQuitTiny;

    int menuUpdate;
    int choix;
    
    public:
        Menu(){
            texturePlayGrand.loadFromFile("ressources/playGrand.png");
            textureQuitGrand.loadFromFile("ressources/quitGrand.png");
            texturePlayTiny.loadFromFile("ressources/playTiny.png");
            textureQuitTiny.loadFromFile("ressources/quitTiny.png");
            spritePlayGrand.setPosition(120,100);
            spriteQuitGrand.setPosition(130,270);
            spritePlayTiny.setPosition(230,100);
            spriteQuitTiny.setPosition(200,300);
            choix = 0;
            menuUpdate = 1;
        }   

        int getMenuUpdate() {
            return menuUpdate;
        }

        void draw(sf::RenderWindow &app) {
            app.clear();
            spritePlayGrand.setTexture(texturePlayGrand);
            spriteQuitTiny.setTexture(textureQuitTiny);
            spritePlayTiny.setTexture(texturePlayTiny);
            spriteQuitGrand.setTexture(textureQuitGrand);
            if(choix == 0) {
                app.draw(spritePlayGrand);
                app.draw(spriteQuitTiny);
            }
            if(choix == 1) {
                app.draw(spritePlayTiny);
                app.draw(spriteQuitGrand);
            }
            app.display();
        }

        void handleMoves(sf::RenderWindow &app) {
            sf::Event event;
            while (app.pollEvent(event)) {
                // évènement "fermeture demandée" : on ferme la fenêtre
                if (event.type == sf::Event::Closed)
                    app.close();
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    app.close(); 
                    exit(0);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                    if(choix == 0)          //Si on est sur play
                        menuUpdate = 0;
                    if(choix == 1) {         //Si on est sur quit
                        app.close();
                        exit(0);
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                    if(choix == 0)
                        choix++;
                    else
                        choix--;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                    if(choix == 0)
                        choix++;
                    else
                        choix--;
                }
            }
        }
};

#endif