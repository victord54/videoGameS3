#include <SFML/Graphics.hpp>

class Player {
    private:
        int spriteW;
        int spriteH;

        double x;
        double y;

        sf::Texture texture;
        sf::Sprite sprite;

    public:
        Player(const std::string filename, int coordX, int coordY) {
            spriteW = 64;
            spriteH = 16;

            x = coordX;
            y = coordY;

            texture.loadFromFile(filename);
            setPosition();
        }

        void setPosition() {
            sprite.setPosition(x, y);
        }

        void moveX(double mX) {
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
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                moveX(-3);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                moveX(3);
        }

};