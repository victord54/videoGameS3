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
SDL_Texture* load_image(const char *path, SDL_Renderer *renderer);

/**
 * @brief Charge une texture avec une couleur transparente à partir d'un fichier BMP
 * 
 * @param path 
 * @param renderer 
 * @param r 
 * @param g 
 * @param b 
 * @return SDL_Texture* 
 */
SDL_Texture* load_transparent_image(const char *path, SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b);

/**
 * @brief Définit les rectangles dst et src et envoie la texture au renderer
 * 
 * @param texture 
 * @param renderer 
 * @param x 
 * @param y 
 */
void apply_texture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y);

/**
 * @brief Définit quelle sprite est à afficher et l'envoie au renderer
 * 
 * @param texture 
 * @param renderer 
 * @param n 
 */
void apply_tab_texture(SDL_Texture *texture, SDL_Renderer *renderer, int n);

#endif