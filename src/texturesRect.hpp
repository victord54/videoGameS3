#ifndef TEXTURE_RECT_HPP
#define TEXTURE_RECT_HPP

#include <SFML/Graphics.hpp>

class TexturesRect {
    private:
        sf::IntRect playerRect;
        sf::IntRect ballRect;
    
    public:
        TexturesRect() {
            playerRect = {0, 200, 96, 23};
            ballRect = {160, 200, 16, 16};
        }

        sf::IntRect getPlayerRect() {
            return playerRect;
        }

        sf::IntRect getBallRect() {
            return ballRect;
        }
};

#endif