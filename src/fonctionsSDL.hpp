#ifndef FONCTIONS_SDL
#define FONCTIONS_SDL

/**
 * @brief Initialise SDL2, window et renderer
 * 
 * @param window 
 * @param renderer 
 */
void init(SDL_Window **window, SDL_Renderer **renderer);

/**
 * @brief Quitte la SDL2
 * 
 * @param renderer 
 * @param window 
 */
void quit(SDL_Renderer *renderer,SDL_Window *window);

/**
 * @brief Charge une texture à partir d'un fichier BMP
 * 
 * @param path 
 * @param renderer 
 * @return SDL_Texture* 
 */
SDL_Texture* load_image(const char* path, SDL_Renderer* renderer);

/**
 * @brief Définit les rectangles dst et src et envoie la texture au renderer
 * 
 * @param texture 
 * @param renderer 
 * @param x 
 * @param y 
 */
void apply_texture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y);

#endif