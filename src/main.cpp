#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "define.hpp"
#include "player.hpp"
#include "ball.hpp"
#include "game.hpp"

using namespace sf;
using namespace std;

int main() {
    RenderWindow app(VideoMode(WINDOW_X, WINDOW_Y), "Brick Breaker");
    app.setFramerateLimit(60);

    Game game = Game();

    while (app.isOpen()) {
        game.handleMove(app);
        game.draw(app);
    }

    return 0;
}
