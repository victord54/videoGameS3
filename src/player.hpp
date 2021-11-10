#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include "define.hpp"

class Player {
    private:
        int spriteW;
        int spriteH;

        bool deplacementSouris;

        sf::IntRect playerRect;
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        Player(const std::string filename, int coordX, int coordY) {
            spriteW = 96;
            spriteH = 23;

            deplacementSouris = false;

            sprite.setPosition(coordX, coordY);

            playerRect = {0, 200, spriteW, spriteH};

            texture.loadFromFile(filename, playerRect);
        }

        int getX() {
            return sprite.getPosition().x;
        }

        int getY() {
            return sprite.getPosition().y;
        }

        int getW() {
            return spriteW;
        }

        int getH() {
            return spriteH;
        }

        bool isSouris() {
            return deplacementSouris;
        }

        void setX(int mx){
            sprite.setPosition(mx,getY());
        }

        void setDeplacementSouris(bool b) {
            deplacementSouris = b;
        }
        
        void moveX(int mX) {
            sprite.move(mX, 0);
        }

        void draw(sf::RenderWindow &app) {
            sprite.setTexture(texture);
            app.draw(sprite);
        }

        void handleMoves(sf::RenderWindow &app) {
            sf::Event event;
            while (app.pollEvent(event)) {
                // évènement "fermeture demandée" : on ferme la fenêtre
                if (event.type == sf::Event::Closed)
                    app.close();
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    app.close();
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
                    setDeplacementSouris(true);

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
                    setDeplacementSouris(false);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                moveX(-PLAYER_SPEED);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                moveX(PLAYER_SPEED);
            
            if (isSouris() == true) {
                sf::Vector2i coords = sf::Mouse::getPosition(app);
                setX(coords.x);
            }
            
            if (getX() < 0)
                setX(0);
            
            if (getX() + spriteW > WINDOW_X)
                setX(WINDOW_X - spriteW);

            //printf("player.x = %d\nplayer.y = %d\n", getX(), getY());
        }

};

#endif