#include <iostream>
#include <SDL2/SDL.h>
#include <functional>


#include "Button.hpp"

void CheckButtonClick(Button(&buttons)[3], SDL_Point point)
{
    for (Button& button : buttons)
    {
        if (SDL_PointInRect(&point, &button.rect))
            button.func();
    }
}

void DrawButtons(Button(&buttons)[3], SDL_Renderer* renderer)
{
    for (Button& button : buttons)
    {
        SDL_SetRenderDrawColor(renderer, button.col.r, button.col.g, button.col.b, button.col.a);
        SDL_RenderFillRect(renderer, &button.rect);
    }
}

void RenderNewImage(SDL_Renderer* renderer, SDL_Texture* texture, bool isFlipped)
{
    SDL_RendererFlip flip = isFlipped ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    if (SDL_RenderCopyEx(renderer, texture, NULL, NULL, NULL, NULL, flip))
        std::cerr << SDL_GetError() << std::endl;
}
