#include <stdio.h>
#include "MYsdlWindow.h"
#include "constants.h"

//^ SDL window and renderer global variables so that we can use them in the main file
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

/**
 * @brief Initialize the window with the name Virtual Heart, position center, width from #define, height from #define, flags 0
 *
 * @return int TRUE if the window is initialized successfully
 */
int initializeWindow(void)
{
    //~Initialize SDL everything to be able to use the SDL library
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return FALSE;
    }

    //~Create a window with (name: Virtual Heart,window position: center, width: 800, height: 600, flags: 0)
    window = SDL_CreateWindow("Virtual Heart", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!window)
    {
        fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
        return FALSE;
    }
    // Create a renderer for the window (window to attach the renderer to, display index: -1(defult), flags: (0) test:SDL_RENDERER_ACCELERATED)
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
    {
        fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
        return FALSE;
    }
    return TRUE;
}

/**
 * @brief Process the input events
 *
 */
void ProcessInput(void)
{
    extern isWindowInitialized;
    SDL_Event event;       // Create an event
    SDL_PollEvent(&event); // Poll the event

    switch (event.type)
    {
    case SDL_QUIT:
        isWindowInitialized = FALSE;
        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            isWindowInitialized = FALSE;
        }
        break;
    default:
        break;
    }
}

/**
 * @brief Destroy the window and renderer
 *
 */
void destroyWindow(void)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
