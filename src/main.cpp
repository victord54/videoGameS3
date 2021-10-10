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
    // SDL_Texture *obj = load_image("support/obj.bmp", renderer);
    SDL_Texture *obj = load_transparent_image("support/obj.bmp", renderer, 255, 255, 255);

    SDL_Texture *player = load_transparent_image("support/sprites.bmp", renderer, 0, 255, 255);

    SDL_RenderClear(renderer);
    apply_texture(background, renderer, 0, 0);
    apply_texture(obj, renderer, 30, 30);
    apply_tab_texture(player, renderer, 0);

    SDL_RenderPresent(renderer);

    
    SDL_Delay(2000);
    SDL_DestroyTexture(background);
    quit(renderer, window);
}