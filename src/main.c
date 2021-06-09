#include <stdio.h>
#include <SDL2/SDL.h>
#include "constants.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
/**
 * Will be responsible for starting the SDL
 * 
 *  If there is any error it will return FALSE,
 *  otherwise TRUE
 */
int initialize_window(void)
{
    // Initialize
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        return FALSE;
    }
    // Create
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS);

    if (!window)
    {
        fprintf(stderr, "Eror Creating SDL window.\n");
        return FALSE;
    }

    // Renderer
    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer)
    {
        fprintf(stderr, "Eoor Creating SDL Renderer.\n");
        return FALSE;
    }

    return TRUE;
}

int main(int argc, char const *argv[])
{
    initialize_window();

    return 0;
}
