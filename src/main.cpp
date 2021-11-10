#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "define.hpp"
#include "player.hpp"
#include "ball.hpp"
#include <fstream>
#include <vector>

using namespace sf;
using namespace std;

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;

int main() {
    string filename("ressources/input.txt");
    vector<string> lines;
    string line;

    ifstream input_file(filename);
    // if (!input_file.is_open()) {
    //     cerr << "Could not open the file - '"
    //          << filename << "'" << endl;
    //     return EXIT_FAILURE;
    // }
// lien code https://www.delftstack.com/fr/howto/cpp/how-to-read-a-file-line-by-line-cpp/#utilisez-la-fonction-stdgetline-pour-lire-un-fichier-ligne-par-ligne
    while (getline(input_file, line)){
        lines.push_back(line);
    }

    for (const auto &i : lines)
        cout << i << endl;

//    input_file.close();


    RenderWindow app(VideoMode(WINDOW_X, WINDOW_Y), "Brick Breaker");
    app.setFramerateLimit(60);

    Player player = Player("ressources/brickBreaker_sprites.png", WINDOW_X-200, WINDOW_Y-30);
    Ball ball = Ball(player, "ressources/brickBreaker_sprites.png");

    while (app.isOpen()) {
        player.handleMoves(app);
        ball.handleKeyboard(app);
        ball.moving(player);
        app.clear();
        player.draw(app);
        ball.draw(app);
        app.display();
    }

    return 0;
}
