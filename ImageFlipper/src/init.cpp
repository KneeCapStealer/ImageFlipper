#include "init.hpp"

#define SDL_FLAGS SDL_INIT_VIDEO | SDL_INIT_EVENTS
#define SDL_WINDOW_FLAGS SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
#define SDL_RENDERER_FLAGS SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
#define IMG_FLAGS IMG_INIT_JPG

void InitSDL(SDL_Window** window , SDL_Renderer** renderer)
{
	if (SDL_Init(SDL_FLAGS) != 0)
        std::cout << "Error initializing SDL, error: " << SDL_GetError() << '\n';

    if (!(IMG_Init(IMG_FLAGS) & IMG_FLAGS))
        std::cout << "Error initializing SDL_image, error: " << IMG_GetError() << '\n';

    *window = SDL_CreateWindow("Hej Jeppe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1092, 720, SDL_WINDOW_FLAGS);

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_FLAGS);
    SDL_SetRenderDrawColor(*renderer, 255, 255, 255, 255);

    std::cout << std::endl;
}

void InitUI(Button* button1, Button* button2, SDL_Renderer* renderer, SDL_Texture** currentImage)
{
    SDL_Texture* firstImage = IMG_LoadTexture(renderer, "images/Sus_Jerma.jpg");
    if (firstImage == NULL)
        std::cout << "Error loading image, Error: " << IMG_GetError() << std::endl;

    SDL_Texture* secondImage = IMG_LoadTexture(renderer, "images/Waltuh.jpg");
    if (secondImage == NULL)
        std::cout << "Error loading image, Error: " << IMG_GetError() << std::endl;

    // Button 1
    button1->rect.x = 60;
    button1->rect.y = 120;
    button1->rect.w = 420;
    button1->rect.h = 120;

    button1->col.r = 0;
    button1->col.g = 125;
    button1->col.b = 255;
    button1->col.a = 200;

    button1->func = [&currentImage, &firstImage]
    {
        *currentImage = firstImage;
        std::cout << "Current Image Null? " << (*currentImage == nullptr) << std::endl;
    };
    // Button 2
    button2->rect.x = 1000;
    button2->rect.y = 120;
    button2->rect.w = 420;
    button2->rect.h = 120;

    button2->col.r = 0;
    button2->col.g = 255;
    button2->col.b = 125;
    button2->col.a = 200;

    button2->func = [&currentImage, &secondImage]
    {
        *currentImage = secondImage;
        std::cout << "Current Image Null? " << (*currentImage == nullptr) << std::endl;
    };
}