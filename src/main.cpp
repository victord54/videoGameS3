#include <iostream>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH    640
#define SCREEN_HEIGHT   480

using namespace std;

int main(int argc, char **argv)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *sprite;
    SDL_Texture *texture;
    SDL_Rect player;
    SDL_Event event;
    int spriteWidth, spriteHeight;
    int cont = 0;
    bool keys[322] = {false};

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Test du deplacement d'un personnage", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    sprite = SDL_LoadBMP("../shield.bmp");
    SDL_SetColorKey(sprite, SDL_TRUE, SDL_MapRGB(sprite->format, 255, 0, 255));

    texture = SDL_CreateTextureFromSurface(renderer, sprite);

    SDL_QueryTexture(texture, NULL, NULL, &spriteWidth, &spriteHeight);

    player.x = (SCREEN_WIDTH / 2) - (spriteWidth);
    player.y = (SCREEN_HEIGHT / 2) - (spriteHeight);
    player.w = spriteWidth;
    player.h = spriteHeight;

    SDL_RenderCopy(renderer, texture, NULL, &player);

    // SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);

    SDL_RenderPresent(renderer);

    while(cont == 0)
    {
        if(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    cont = 1;
                break;
                case SDL_KEYDOWN:
                    keys[event.key.keysym.scancode] = true;
                break;
                case SDL_KEYUP:
                    keys[event.key.keysym.scancode] = false;
                break;
            }
        }

        if(keys[SDL_SCANCODE_ESCAPE])
        {
            cont = 1;
        }

        if(keys[SDL_SCANCODE_DOWN])
        {
            if (player.y + player.h < SCREEN_HEIGHT)
                player.y += 8;
        }

        if(keys[SDL_SCANCODE_UP])
        {
            if (player.y >= 0)
                player.y -= 8;
        }

        if(keys[SDL_SCANCODE_LEFT])
        {
            if (player.x >= 0)
                player.x -= 8;
        }

        if(keys[SDL_SCANCODE_RIGHT])
        {
            if (player.x + player.w < SCREEN_WIDTH)
                player.x += 8;
        }

        SDL_Delay(16);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, &player);
        SDL_RenderPresent(renderer);
    }

    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
} 