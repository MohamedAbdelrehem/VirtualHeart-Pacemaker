#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

// SDL for graphics
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef struct
{
    int x;
    int y;
    int radius;
} Circle;

int initializeWindow(void);
void ProcessInput(void);
void destroyWindow(void);

#endif // SDL_WINDOW_H