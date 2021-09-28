#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>

#include "fonctionsSDL.hpp"
#include "defines.hpp"


int main() {
    SDL_Window *window = nullptr; // Déclaration de la fenêtre
	SDL_Renderer *renderer = nullptr; // Déclaration du rendu

    init(&window, &renderer);

    // Chargement de l'image
    SDL_Texture *background = load_image("support/fond.bmp", renderer);

    SDL_RenderClear(renderer);
    apply_texture(background, renderer, 0, 0);

    SDL_RenderPresent(renderer);

    
    SDL_Delay(2000);
    SDL_DestroyTexture(background);
    quit(renderer, window);
}