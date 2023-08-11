#include <SDL2/SDL_image.h>
#include <iostream>
#include <functional>


#include "button.hpp"
#include "init.hpp"

#define SDL_FLAGS SDL_INIT_VIDEO | SDL_INIT_EVENTS
#define SDL_WINDOW_FLAGS SDL_WINDOW_SHOWN
#define SDL_RENDERER_FLAGS SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
#define IMG_FLAGS IMG_INIT_JPG

void InitSDL(SDL_Window** window , SDL_Renderer** renderer)
{
	if (SDL_Init(SDL_FLAGS) != 0)
        std::cerr << "Error initializing SDL, error: " << SDL_GetError() << '\n';

    if (!(IMG_Init(IMG_FLAGS) & IMG_FLAGS))
        std::cerr << "Error initializing SDL_image, error: " << IMG_GetError() << '\n';

    *window = SDL_CreateWindow("Hej Jeppe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1400, 900, SDL_WINDOW_FLAGS);

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_FLAGS);
    SDL_SetRenderDrawColor(*renderer, 255, 255, 255, 255);

    std::cerr << std::endl;
}

void InitUI(Button (*buttons)[3], SDL_Renderer* renderer, bool* isFlipped, SDL_Texture** currentImage)
{
    SDL_Texture* firstImage = IMG_LoadTexture(renderer, "images/Sus_Jerma.jpg");
    if (firstImage == NULL)
        std::cerr << "Error loading image, Error: " << IMG_GetError() << std::endl;

    SDL_Texture* secondImage = IMG_LoadTexture(renderer, "images/Waltuh.jpg");
    if (secondImage == NULL)
        std::cerr << "Error loading image, Error: " << IMG_GetError() << std::endl;

    // Button 1
    (*buttons)[0].rect.x = 60;
    (*buttons)[0].rect.y = 120;
    (*buttons)[0].rect.w = 420;
    (*buttons)[0].rect.h = 120;

    (*buttons)[0].col.r = 0;
    (*buttons)[0].col.g = 125;
    (*buttons)[0].col.b = 255;
    (*buttons)[0].col.a = 200;

    (*buttons)[0].func = [=]
    {
        *currentImage = firstImage;
        RenderNewImage(renderer, firstImage, *isFlipped);
        DrawButtons(*buttons, renderer);
    };

    // Button 2
    (*buttons)[1].rect.x = 900;
    (*buttons)[1].rect.y = 120;
    (*buttons)[1].rect.w = 420;
    (*buttons)[1].rect.h = 120;

    (*buttons)[1].col.r = 0;
    (*buttons)[1].col.g = 255;
    (*buttons)[1].col.b = 125;
    (*buttons)[1].col.a = 200;

    (*buttons)[1].func = [=]
    {
        *currentImage = secondImage;
        RenderNewImage(renderer, secondImage, *isFlipped);
        DrawButtons(*buttons, renderer);
    };

    // Flip button
    (*buttons)[2].rect.x = 600;
    (*buttons)[2].rect.y = 700;
    (*buttons)[2].rect.w = 200;
    (*buttons)[2].rect.h = 120;

    (*buttons)[2].col.r = 150;
    (*buttons)[2].col.g = 150;
    (*buttons)[2].col.b = 0;
    (*buttons)[2].col.a = 255;

    (*buttons)[2].func = [=]
    {
        *isFlipped = !*isFlipped;
        RenderNewImage(renderer, *currentImage, *isFlipped);
        DrawButtons(*buttons, renderer);
    };
}