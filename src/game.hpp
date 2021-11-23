#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <iostream>
#include <fstream>  
#include <SFML/Graphics.hpp>
#include <vector>

#include "define.hpp"
#include "player.hpp"
#include "ball.hpp"

std::ifstream  fichier;    //Fichier
using namespace std; 

class Game {
    private:
        Player j1;
        // Player j2;
        Ball balls[5];
        char tab[25][10];
        
    
    public:
        Game() {
            j1 = Player(WINDOW_X-200, WINDOW_Y-30);
            // j2 = Player(100, WINDOW_Y-30);

            balls[0] = Ball();
            // balls[1] = Ball();
        }

        void handleMove(sf::RenderWindow &app) {
            j1.handleMoves(app);
            // j2.handleMoves(app);
            balls[0].handleKeyboard(app);
            // balls[1].handleKeyboard(app);
            balls[0].moving(j1);
            // balls[1].moving(j2);
        }

        void draw(sf::RenderWindow &app) {
            app.clear();
            j1.draw(app);
            // j2.draw(app);
            balls[0].draw(app);
            // balls[1].draw(app);
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
};

#endif