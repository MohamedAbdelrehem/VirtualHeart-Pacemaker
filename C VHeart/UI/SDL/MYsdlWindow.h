#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

// SDL for graphics
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL2_gfxPrimitives.h> // Include SDL_gfx library header for advanced shapes
#include "./../../Settings.h"
#if SCREENSIZE == 0
#define SCREEN_SCALE 1
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 720
#elif SCREENSIZE == 1
#define SCREEN_SCALE 1.6
#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 900
#else
#define SCREEN_SCALE 1.8
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#endif
#define HEART_IMAGE_PATH "D:/github/VirtualHeart&Pacemaker/C VHeart/assets/images/EP.JPG"
#define FONT_PATH0 "D:/github/VirtualHeart&Pacemaker/C VHeart/assets/fonts/Arial.ttf"
#define FONT_PATH1 "D:/github/VirtualHeart&Pacemaker/C VHeart/assets/fonts/Atop-R99O3.ttf"
#define FONT_PATH2 "D:/github/VirtualHeart&Pacemaker/C VHeart/assets/fonts/LoveDays-2v7Oe.ttf"

// heart model
#include "./../../HeartModel/heartModel.h"

// calculate center for image from its width and height
#define CENTER_X(IMAGE_WIDTH, SCREEN_WIDTH) ((SCREEN_WIDTH - IMAGE_WIDTH) / 2)
#define CENTER_Y(IMAGE_HEIGHT, SCREEN_HEIGHT) ((SCREEN_HEIGHT - IMAGE_HEIGHT) / 2)

int initializeWindow(void);
void imageInitialization(void);
void ProcessInput(void);
void destroyWindow(void);
void renderHeartImage(void);
void initializeFont(void);
void addTextToScreen(char *text, int x, int y, int size, int fontNumber);
void mainUI(void);
void initializeUIElements(void);

void addLineToScreen(float startX, float startY, float endX, float endY, int ColorNumber, int thickness);

#endif // SDL_WINDOW_H