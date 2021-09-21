#include <iostream>
#include <SDL2/SDL.h>
#include "sprite.h"


int main() {
    int a = 150;

    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "Erreur initialisation SDL: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    if (SDL_CreateWindowAndRenderer(1024, 768, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &window, &renderer)) {
        std::cerr << "Erreur creation fenetre et rendu" << std::endl;
        return -1;
    }

    SDL_SetWindowTitle(window, "pitiProjet SDL2");

    while (1) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    goto stop;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_RIGHT:
                            a+=30;
                            break;
                        case SDLK_LEFT:
                            a-=30;
                            break;
                        
                        default:
                            goto stop;
                            break;
                    }

                default:
                    break;
            }
        }
        SDL_SetRenderDrawColor(renderer, 240, a, 126, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
    stop:
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}