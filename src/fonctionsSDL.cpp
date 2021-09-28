#include <SDL2/SDL.h>
#include <iostream>

#include "fonctions_SDL.h"
#include "defines.hpp"

void init(SDL_Window **window, SDL_Renderer **renderer) {
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) // Initialisation de la SDL
	{
		std::cerr << "Erreur initialisation de SDL2 : " << SDL_GetError() << std::endl;
		SDL_Quit();
        exit(1);
	}

    if (SDL_CreateWindowAndRenderer(WIN_WIDTH, WIN_HEIGHT, 0, window, renderer)) {
        std::cerr << "Erreur création window et renderer : " << SDL_GetError() << std::endl;
		SDL_Quit();
        exit(1);
    }
    SDL_SetWindowTitle(*window, "videoGame");
}

void quit(SDL_Renderer *renderer,SDL_Window *window) {
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();    
}

SDL_Texture* load_image(const char* path, SDL_Renderer* renderer) {
	SDL_Surface *surfaceTmp = nullptr;
    SDL_Texture *texture = nullptr;
    surfaceTmp = SDL_LoadBMP(path);

    if (surfaceTmp == nullptr) {
        std::cerr << "Erreur chargement image BMP : " << SDL_GetError() << std::endl;
		SDL_Quit();
        exit(1);
    }

    texture = SDL_CreateTextureFromSurface(renderer, surfaceTmp);
    SDL_FreeSurface(surfaceTmp);

    if (texture == nullptr) {
        std::cerr << "Erreur création texture from surface : " << SDL_GetError() << std::endl;
		SDL_Quit();
        exit(1);
    }

    return texture;
}

void apply_texture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y){
    SDL_Rect dst = {0, 0, 0, 0};
    
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    dst.x = x; dst.y=y;
    
    SDL_RenderCopy(renderer, texture, NULL, &dst);
    
}