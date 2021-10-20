#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 

#define SPRITE_X 285
#define SPRITE_Y 250

using namespace sf;
using namespace std;

int main() {
    RenderWindow app(VideoMode(800, 600), "My window");
    app.setFramerateLimit(60);
    int ballSpeed = 2;
    int n = 0;
    bool deplacementG = false;
    bool deplacementGEncore = false;

    Clock clock;
    float sec;
    Time elapsed;
    Time elapsedR;

    elapsedR = seconds(5.);

    IntRect tabRect[3];
    for (int i = 0; i < 3; i++) {
        tabRect[i] = IntRect(SPRITE_X*i/3, 0, SPRITE_X/3, SPRITE_Y/2);
    }



    Texture t1, t2, t3, t1R, t2R, t3R;
    t1.loadFromFile("ressources/sprite.png", tabRect[0]);
    t2.loadFromFile("ressources/sprite.png", tabRect[1]);
    t3.loadFromFile("ressources/sprite.png", tabRect[2]);

    t1R.loadFromFile("ressources/sprite.png", tabRect[0]);
    t2R.loadFromFile("ressources/sprite.png", tabRect[1]);
    t3R.loadFromFile("ressources/sprite.png", tabRect[2]);

    Sprite player;
    player.setPosition(100, 100);

    float dx = ballSpeed, dy = ballSpeed;
    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (app.isOpen()) {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        Event event;
        while (app.pollEvent(event)) {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == Event::Closed)
                app.close();
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                app.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Z)) {
            if (player.getPosition().y > 0)
                player.move(0, -5);
            if (n%30 == 0)
                player.setTexture(t1);
            else if (n%15 == 0)
                player.setTexture(t3);
        }
        if (Keyboard::isKeyPressed(Keyboard::S)) {
            if (player.getPosition().y + SPRITE_Y/2 < 600)
                player.move(0, 5);
            if (n%30 == 0)
                player.setTexture(t1);
            else if (n%15 == 0)
                player.setTexture(t3);
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            if (player.getPosition().x + SPRITE_X/3 < 800)
                player.move(5, 0);
            if (n%30 == 0)
                player.setTexture(t1);
            else if (n%15 == 0)
                player.setTexture(t3);
        }
        if (Keyboard::isKeyPressed(Keyboard::Q)) {
            if (player.getPosition().x > SPRITE_X/3)
                player.move(-5, 0);
            if (n%30 == 0)
                player.setTexture(t1);
            else if (n%15 == 0)
                player.setTexture(t3);
        }
        if (!(Keyboard::isKeyPressed(Keyboard::Z) || Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Q) || Keyboard::isKeyPressed(Keyboard::D)))
            player.setTexture(t2);
        if (Keyboard::isKeyPressed(Keyboard::Q)) {
            if (deplacementG == false) {
                player.scale(-1, 1);
                player.move(SPRITE_X/3, 0);
                deplacementG = true;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            if (deplacementG == true) {
                player.scale(-1, 1);
                player.move(-SPRITE_X/3, 0);
                deplacementG = false;
            }
        }

        app.clear();
        app.draw(player);
        app.display();

        elapsed = clock.getElapsedTime();

        if (elapsed > elapsedR) {
            clock.restart();
	    cout << "5 sec se sont écoulées" << endl;
        }

        n++;
    }

    return 0;
}
