#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "define.hpp"
#include "player.hpp"
#include "ball.hpp"

class Game {
    private:
        Player j1;
        // Player j2;
        Ball balls[5];
    
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
};

#endif