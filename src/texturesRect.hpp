#ifndef TEXTURE_RECT_HPP
#define TEXTURE_RECT_HPP

#include <SFML/Graphics.hpp>

class TexturesRect {
    private:
        sf::IntRect playerRect;
        sf::IntRect ballRect;
        sf::IntRect brickRect[7];
    
    public:
        TexturesRect() {
            playerRect = {0, 200, 96, 23};
            ballRect = {160, 200, 16, 16};
            brickRect[0] = {0, 0, 32, 32};
            brickRect[1] = {40, 0, 32, 32};
            brickRect[2] = {80, 0, 32, 32};
            brickRect[3] = {120, 0, 32, 32};
            brickRect[4] = {160, 0, 32, 32};
            brickRect[5] = {200, 0, 32, 32};
            brickRect[6] = {240, 0, 32, 32};
        }

        sf::IntRect getPlayerRect() {
            return playerRect;
        }

        sf::IntRect getBallRect() {
            return ballRect;
        }

        sf::IntRect getBrickRect(int n){
            return brickRect[n];
        }
};

#endif