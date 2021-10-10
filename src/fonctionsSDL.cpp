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

SDL_Texture* load_transparent_image(const char *path, SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b) {
    SDL_Surface *surfaceTmp = nullptr;
    SDL_Texture *texture = nullptr;
    surfaceTmp = SDL_LoadBMP(path);

    if (surfaceTmp == nullptr) {
        std::cerr << "Erreur chargement image BMP : " << SDL_GetError() << std::endl;
		SDL_Quit();
        exit(1);
    }

    SDL_SetColorKey(surfaceTmp, SDL_TRUE, SDL_MapRGB(surfaceTmp->format, r, g, b));
    texture = SDL_CreateTextureFromSurface(renderer, surfaceTmp);
    SDL_FreeSurface(surfaceTmp);

    if (texture == nullptr) {
        fprintf(stderr, "Erreur pendant creation de la texture liee a l'image chargee: %s", SDL_GetError());
        return NULL;
    }

    return texture;
}

void apply_texture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y){
    SDL_Rect dst = {0, 0, 0, 0};
    
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    dst.x = x; dst.y=y;
    
    SDL_RenderCopy(renderer, texture, NULL, &dst);
    
}

void apply_tab_texture(SDL_Texture *texture, SDL_Renderer *renderer, int n) {

    SDL_Rect SrcR_sprite[6];
    SDL_Rect srcWH = {0, 0, 0, 0};
    SDL_QueryTexture(texture, nullptr, nullptr, &srcWH.w, &srcWH.h);
    srcWH.w /= 3;
    srcWH.h /= 2;
    

    SDL_Rect DestR_sprite[6];
    SDL_Rect dstWH = {0, 0, 0, 0};
    SDL_QueryTexture(texture, nullptr, nullptr, &dstWH.w, &dstWH.h);
    for (int i=0; i<6; i++) {
        DestR_sprite[i].x = i > 2 ? 60*(i+1)+100 : 60*(i+1);
        DestR_sprite[i].y = i > 2 ? 60 : 120;
        DestR_sprite[i].w = dstWH.w; // Largeur du sprite
        DestR_sprite[i].h = dstWH.h; // Hauteur du sprite
    }

     SDL_RenderCopy(renderer, texture, NULL, &DestR_sprite[n]);
}