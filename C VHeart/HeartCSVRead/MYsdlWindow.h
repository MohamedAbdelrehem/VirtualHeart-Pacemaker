#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

// SDL for graphics
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_render.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define HEART_IMAGE_PATH "D:/github/VirtualHeart&Pacemaker/C VHeart/assets/images/EP.JPG"
#define FONT_PATH0 "D:/github/VirtualHeart&Pacemaker/C VHeart/assets/fonts/Arial.ttf"
#define FONT_PATH1 "D:/github/VirtualHeart&Pacemaker/C VHeart/assets/fonts/Atop-R99O3.ttf"
#define FONT_PATH2 "D:/github/VirtualHeart&Pacemaker/C VHeart/assets/fonts/LoveDays-2v7Oe.ttf"

// calculate center for image from its width and height
#define CENTER_X(IMAGE_WIDTH, SCREEN_WIDTH) ((SCREEN_WIDTH - IMAGE_WIDTH) / 2)
#define CENTER_Y(IMAGE_HEIGHT, SCREEN_HEIGHT) ((SCREEN_HEIGHT - IMAGE_HEIGHT) / 2)

// typedef struct
// {
//     int x;
//     int y;
//     int w;
//     int h;
// } Rectangle;

int initializeWindow(void);
void imageInitialization(void);
void ProcessInput(void);
void destroyWindow(void);
void renderHeartImage(void);
void initializeFont(void);
void addTextToScreen(char *text, int x, int y, int size, int fontNumber);
void UI(void);

#endif // SDL_WINDOW_H