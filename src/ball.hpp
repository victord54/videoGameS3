#include <SFML/Graphics.hpp>

class Ball {
    private:

        int spriteW;
        int spriteH;

        double x;
        double y;

        double xSpeed;
        double ySpeed;

    public:
    
        Ball() {
            spriteW = 32;
            spriteH = 32;

            x = 10;
            y = 10;
            xSpeed = 5;
            ySpeed = 5;
        }
};