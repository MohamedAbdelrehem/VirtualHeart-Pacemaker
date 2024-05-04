#include <stdio.h>
#include "MYsdlWindow.h"
#include "constants.h"

// include the structs file the node and path structs
#include "dataStructure.h"

//^ SDL window and renderer global variables so that we can use them in the main file
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Surface *imageHeart = NULL;
SDL_Texture *image_texture = NULL;
TTF_Font *font = NULL;

int isWindowInitialized = FALSE;
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
    //~Initialize image loading for PNG and JPG
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        fprintf(stderr, "Error initializing SDL_image PNG: %s\n", IMG_GetError());
        return FALSE;
    }
    if (!(IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG))
    {
        fprintf(stderr, "Error initializing SDL_image JPG: %s\n", IMG_GetError());
        return FALSE;
    }

    //~Create a window with (name: Virtual Heart,window position: center, width: 800, height: 600, flags: 0)
    window = SDL_CreateWindow("Virtual Heart", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!window)
    {
        fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
        return FALSE;
    }
    //~ Create a renderer for the window (window to attach the renderer to, display index: -1(default), flags: (0) test:SDL_RENDERER_ACCELERATED)
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
        return FALSE;
    }
    //~ Initialize the image
    imageInitialization();
    //~ Initialize the font
    initializeFont();

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

void imageInitialization(void)
{
    imageHeart = IMG_Load(HEART_IMAGE_PATH);
    if (!imageHeart)
    {
        fprintf(stderr, "Error creating image: %s\n", IMG_GetError());
        return;
    }
    image_texture = SDL_CreateTextureFromSurface(renderer, imageHeart);
    if (!image_texture)
    {
        fprintf(stderr, "Error creating texture: %s\n", SDL_GetError());
        return;
    }
}

/**
 * @brief Destroy the window and renderer
 *
 */
void destroyWindow(void)
{
    // SDL_destroyTexture(image_texture);
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// initialize font

void initializeFont(void)
{
    if (TTF_Init() != 0)
    {
        fprintf(stderr, "Error initializing TTF: %s\n", TTF_GetError());
        return;
    }
}

// add text to the screen

void addTextToScreen(char *text, int x, int y, int size, int fontNumber)
{
    switch (fontNumber)
    {
    case 1:
        font = TTF_OpenFont(FONT_PATH1, size);
        break;
    case 2:
        font = TTF_OpenFont(FONT_PATH2, size);
        break;
    default:
        font = TTF_OpenFont(FONT_PATH0, size);
    }

    if (!font)
    {
        fprintf(stderr, "Error opening font: %s\n", TTF_GetError());
        return;
    }
    SDL_Color color = {32, 178, 170};
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dest = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &dest);
    SDL_RenderPresent(renderer);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}

/**
 * @brief Add circle to the screen
 *
 * @param x x position of the circle
 * @param y y position of the circle
 * @param radius radius of the circle
 * @param ColorNumber color of the circle
 */
void addCircleToScreen(float x, float y, int radius, int ColorNumber)
{
    // set the color of the circle based on the ColorNumber % 3 to get 3 colors only
    switch (ColorNumber % 3)
    {
    case 0:
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        break;
    case 1:
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        break;
    case 2:
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        break;
    default:
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }

    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
    SDL_RenderPresent(renderer);
}

/**
 * @brief Render the heart image
 * contains the image texture and the destination rectangle
 * dest = {x, y, width, height} and calculate the center of the screen
 */
void renderHeartImage(void)
{
    SDL_Rect dest = {CENTER_X(imageHeart->w * SCREEN_SCALE, SCREEN_WIDTH), CENTER_Y(imageHeart->h * SCREEN_SCALE, SCREEN_HEIGHT), imageHeart->w * SCREEN_SCALE, imageHeart->h * SCREEN_SCALE};
    SDL_RenderCopy(renderer, image_texture, NULL, &dest);
    SDL_RenderPresent(renderer);
}
void mainUI(void)
{
    isWindowInitialized = initializeWindow();

    initializeUIElements();
    extern node_location nodeLocationTable[100];
    extern int numberofnodesLocation;

    extern node_def nodeTable[100];
    extern int numberofnodes;

    // use path table to draw the lines between the nodes
    extern node_path nodePathtable[100];
    extern int numberofnodesPathes;

    // the center
    float CenterX = CENTER_X(imageHeart->w * SCREEN_SCALE, SCREEN_WIDTH);
    float CenterY = CENTER_Y(imageHeart->h * SCREEN_SCALE, SCREEN_HEIGHT);
    // TODO: remove this x just for testing
    int randomNumberForColors = 0;

    while (isWindowInitialized)
    {
        ProcessInput();
        // draw a line from left top to right bottom

        // go throw nodes position and add circle to the screen
        for (int i = 0; i < numberofnodesLocation; i++)
        {
            addCircleToScreen(CenterX + nodeLocationTable[i].x * SCREEN_SCALE, (CenterY + -1 * (nodeLocationTable[i].y - imageHeart->h) * SCREEN_SCALE), 5 * SCREEN_SCALE, randomNumberForColors);
            randomNumberForColors++;
        }
        // go throw pathes and add lines to the screen
        for (int i = 0; i < numberofnodesPathes; i++)
        {
            int entryIndex = nodePathtable[i].entry_node_index - 1;
            int exitIndex = nodePathtable[i].exit_node_index - 1;
            addLineToScreen(CenterX + nodeLocationTable[entryIndex].x * SCREEN_SCALE,
                            (CenterY + -1 * (nodeLocationTable[entryIndex].y - imageHeart->h) * SCREEN_SCALE),
                            CenterX + nodeLocationTable[exitIndex].x * SCREEN_SCALE,
                            (CenterY + -1 * (nodeLocationTable[exitIndex].y - imageHeart->h) * SCREEN_SCALE),
                            randomNumberForColors, 5 * SCREEN_SCALE);
            randomNumberForColors++;
        }

        randomNumberForColors++;

        // delay to see the window
        SDL_Delay(200);
    }

    destroyWindow();
}

void addLineToScreen(float startX, float startY, float endX, float endY, int ColorNumber, int thickness)
{
    // Set the color of the line based on the ColorNumber % 5 to get 5 colors only
    switch (ColorNumber % 5)
    {
        // Draw a line with variable thickness using SDL_gfx
    case 0:
        thickLineRGBA(renderer, startX, startY, endX, endY, thickness, 255, 0, 0, 255);

        break;
    case 1:
        thickLineRGBA(renderer, startX, startY, endX, endY, thickness, 0, 255, 0, 255);
        break;
    case 2:
        thickLineRGBA(renderer, startX, startY, endX, endY, thickness, 0, 0, 255, 255);
        break;
    case 3:
        thickLineRGBA(renderer, startX, startY, endX, endY, thickness, 0, 255, 255, 255);
        break;
    case 4:
        thickLineRGBA(renderer, startX, startY, endX, endY, thickness, 255, 0, 255, 255);
        break;
    default:
        thickLineRGBA(renderer, startX, startY, endX, endY, thickness, 0, 0, 0, 255);
    }
}

void initializeUIElements(void)
{
    // Clear the renderer
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Render the background image
    renderHeartImage();

    // Add Title to the screen
    addTextToScreen("Virtual Heart", 30, 30, 50, 1);

    // Add team members names
    addTextToScreen("Team Members:", SCREEN_WIDTH - 250, SCREEN_HEIGHT - 128, 24, 1);
    addTextToScreen("Mohamed Abdelrehem", SCREEN_WIDTH - 230, SCREEN_HEIGHT - 98, 20, 0);
    addTextToScreen("Ahmed Hassan", SCREEN_WIDTH - 230, SCREEN_HEIGHT - 78, 20, 0);
    addTextToScreen("Ahmed Ali Ragab", SCREEN_WIDTH - 230, SCREEN_HEIGHT - 58, 20, 0);

    // Add supervisor name
    addTextToScreen("Supervisor:", 50, SCREEN_HEIGHT - 128, 24, 1);
    addTextToScreen("Dr. Ahmed Mahmoud", 80, SCREEN_HEIGHT - 98, 25, 0);

    // Present the renderer
    SDL_RenderPresent(renderer);
}