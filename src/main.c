#include <stdio.h>
#include <SDL2/SDL.h>
#include "constants.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
int game_is_running = FALSE;
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

void setup() {
    // TODO
}

void process_input()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    //Check type of the event
    switch (event.type)
    {
    case SDL_QUIT:
        game_is_running = FALSE;
        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
            game_is_running = FALSE;
        break;

    default:
        break;
    }
}
void update()
{
    //TODO:
}
void render()
{
    //TODO:
}
void destroy_window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main()
{
    game_is_running = initialize_window();

    setup();

    while (game_is_running)
    {
        process_input();
        update();
        render();
    }

    destroy_window();

    return 0;
}
