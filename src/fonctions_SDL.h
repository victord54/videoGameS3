#ifndef FONCTION_SDL_H
#define FONCTION_SDL_H
/**
 * @brief Fonction qui charge une image et retourne la texture
 * 
 * @param nomFichier 
 * @param renderer 
 * @return SDL_Texture* 
 */
SDL_Texture* charger_image(const char* nomFichier, SDL_Renderer* renderer);

#endif