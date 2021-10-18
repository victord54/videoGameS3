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
    bool direction = false;

    Clock clock;
    float sec;
    Time elapsed;
    Time elapsedR;

    elapsedR = seconds(5.);

    IntRect tabRect[3];
    for (int i = 0; i < 3; i++) {
        tabRect[i] = IntRect(SPRITE_X*i/3, 0, SPRITE_X/3, SPRITE_Y/2);
    }



    Texture t1, t2, t3;
    t1.loadFromFile("ressources/sprite.png", tabRect[0]);
    t2.loadFromFile("ressources/sprite.png", tabRect[1]);
    t3.loadFromFile("ressources/sprite.png", tabRect[2]);

    Sprite ball;
    ball.setPosition(100, 100);

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

        if (Keyboard::isKeyPressed(Keyboard::Z))
            ball.move(0, -5);
        if (Keyboard::isKeyPressed(Keyboard::S))
            ball.move(0, 5);
        if (Keyboard::isKeyPressed(Keyboard::Q))
            ball.move(-5, 0);
        if (Keyboard::isKeyPressed(Keyboard::D))
            ball.move(5, 0);
        else
            ball.setTexture(t2);
        if (Keyboard::isKeyPressed(Keyboard::D)) { // Expérimental ne marche pas bcp^^
            if (n%30 == 0)
                ball.setTexture(t1);
            else if (n%15 == 0)
                ball.setTexture(t3);
            direction = false;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Q)) { // Expérimental ne marche pas bcp^^
            if (n%30 == 0)
                ball.setTexture(t1);
            else if (n%15 == 0)
                ball.setTexture(t3);
            direction = true;
        }

        if (direction)
            ball.scale(-1, 1);
        else
            ball.scale(-1, 1);

        /*                      Idée
         * Ce qu'il faudrait c'est avec un booléen, tant qu'on appuie sur la touche,
         * on définit la texture avec t1 et t3 à intervalle régulier (n%30) et (n%15)
         * et surtout on fait un bool pour que si il se déplace à gauche on flip l'image avec scale(-1, 1)
         */

        // ball.move(dx, dy);
        // Vector2f b = ball.getPosition();
        // if (b.x < 0 || b.x > 800 - SPRITE_X/3) {
        //     dx = -dx;
        //     ball.scale(-1, 1); // A optimiser
        // }
        // if (b.y < 0 || b.y > 600 - SPRITE_Y/2)
        //     dy = -dy;

        app.clear();
        app.draw(ball);
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
