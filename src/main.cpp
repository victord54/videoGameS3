#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "define.hpp"
#include "game.hpp"
#include "menu.hpp"

int main() {
    std::string s;
    std::cout << "Saisissez votre nom : ";
    std::cin >> s;
    sf::RenderWindow app(sf::VideoMode(WINDOW_X, WINDOW_Y), "Brick Breaker");
    app.setFramerateLimit(60);

    Game game = Game(s);
    Menu menu = Menu();

    while (app.isOpen()) {
        while(menu.getMenuUpdate() == 1) {
            menu.handleMoves(app);
            menu.draw(app);
        }

        game.handleMoves(app);
        game.draw(app);
        game.endOfGame();
    }

    return 0;
}
