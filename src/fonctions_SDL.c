#include <SDL2/SDL.h>
#include "fonctions_SDL.h"

SDL_Texture* charger_image(const char* nomFichier, SDL_Renderer* renderer) {
	SDL_Surface* surface = SDL_LoadBMP(nomFichier);
	return SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}