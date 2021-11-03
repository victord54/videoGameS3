#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "ball.hpp"

#define SPRITE_X 285
#define SPRITE_Y 250

using namespace sf;
using namespace std;

int main() {
    RenderWindow app(VideoMode(800, 600), "Brick Breaker");
    app.setFramerateLimit(60);

    Player player = Player("ressources/brickBreaker_sprites.png", 250, 250);

    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (app.isOpen()) {
        player.handleMoves(app);
        app.clear();
        player.draw(app);
        app.display();
    }

    return 0;
}
