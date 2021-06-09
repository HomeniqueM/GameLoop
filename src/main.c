#include <stdio.h>
#include <SDL2/SDL.h>
#include "constants.h"

/**
 * Will be responsible for starting the SDL
 * 
 *  If there is any error it will return FALSE,
 *  otherwise TRUE
 */
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
int game_is_running = FALSE;

struct ball
{
    float x;
    float y;
    float width;
    float height;
} ball;

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

void setup()
{
    ball.x = 20;
    ball.y = 20;
    ball.width = 15;
    ball.height = 15;
}

void update()
{
    //TODO:
}
void render()
{
    SDL_SetRenderDrawColor(renderer, 30, 35, 41, 255);
    SDL_RenderClear(renderer);

    // Here Is where we can start drawing our game objects

    // Draw
    SDL_Rect ball_rect = {ball.x, ball.y, ball.width, ball.height};
    SDL_SetRenderDrawColor(renderer, 255, 255, 225, 255);
    SDL_RenderFillRect(renderer, &ball_rect);

    SDL_RenderPresent(renderer); //Swap buffer
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
