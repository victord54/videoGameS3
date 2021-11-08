#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "define.hpp"
#include "player.hpp"
#include "ball.hpp"

using namespace sf;
using namespace std;

int main() {
    RenderWindow app(VideoMode(WINDOW_X, WINDOW_Y), "Brick Breaker");
    app.setFramerateLimit(60);

    Player player = Player("ressources/brickBreaker_sprites.png", WINDOW_X-200, WINDOW_Y-23);
    Ball ball = Ball(player, "ressources/brickBreaker_sprites.png");

    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (app.isOpen()) {
        player.handleMoves(app);
        // ball.handleMoves(app);
        ball.moving();
        app.clear();
        player.draw(app);
        ball.draw(app);
        app.display();
    }

    return 0;
}
