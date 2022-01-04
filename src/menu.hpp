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
    sf::Texture textureRules;
    sf::Texture textureRulesTiny;
    sf::Texture textureRulesDisplay;
    sf::Sprite spritePlayGrand;
    sf::Sprite spriteQuitGrand;
    sf::Sprite spritePlayTiny;
    sf::Sprite spriteQuitTiny;
    sf::Sprite spriteRules;
    sf::Sprite spriteRulesTiny;
    sf::Sprite spriteRulesScreen;
    int ruleOpen = 0;

    int menuUpdate;
    int choix;
    
    public:
        Menu(){
            texturePlayGrand.loadFromFile("ressources/playGrand.png");
            textureQuitGrand.loadFromFile("ressources/quitGrand.png");
            texturePlayTiny.loadFromFile("ressources/playTiny.png");
            textureQuitTiny.loadFromFile("ressources/quitTiny.png");
            textureRules.loadFromFile("ressources/rules.png");
            textureRulesTiny.loadFromFile("ressources/ruleTiny.png");
            textureRulesDisplay.loadFromFile("ressources/rulesScreen.png");

            spritePlayGrand.setPosition(120,100);
            spriteQuitGrand.setPosition(130,220);
            spriteRules.setPosition(150,350);

            spritePlayTiny.setPosition(230,100);
            spriteQuitTiny.setPosition(200,280);
            spriteRulesTiny.setPosition(200,430);

            spriteRulesScreen.setPosition(0,0);
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
            spriteRules.setTexture(textureRules);
            spriteRulesTiny.setTexture(textureRulesTiny);
            spriteRulesScreen.setTexture(textureRulesDisplay);

            if(choix == 0) {
                app.draw(spritePlayGrand);
                app.draw(spriteQuitTiny);
                app.draw(spriteRulesTiny);
            }
            else if(choix == 1) {
                app.draw(spritePlayTiny);
                app.draw(spriteQuitGrand);
                app.draw(spriteRulesTiny);
            }
            else if(choix == 2) {
                if(ruleOpen % 2 == 0){
                    app.draw(spriteRulesScreen);
                }
                else{
                    app.draw(spritePlayTiny);
                    app.draw(spriteQuitTiny);
                    app.draw(spriteRules);
                }
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

                    else if(choix == 1) {         //Si on est sur quit
                        app.close();
                        exit(0);
                    }

                    else if(choix == 2) {        //Si on est sur rules
                        ruleOpen++;
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
                    if(choix == 0 || choix == 1){
                        choix++;
                    }
                    else{
                        choix = 0;
                    }
                }

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)|| sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                    if(choix == 2 || choix == 1){
                        choix --;
                    }
                    else{
                        choix = 2;
                    }
                }
            }
        }
};

#endif