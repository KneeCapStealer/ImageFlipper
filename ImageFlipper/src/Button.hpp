#pragma once
#include <SDL2/SDL.h>
#include <functional>

struct Button
{
    SDL_Rect rect = SDL_Rect();
    SDL_Color col = SDL_Color();
    std::function<void()> func;
};

void CheckButtonClick(Button (&buttons)[3], SDL_Point point);

void DrawButtons(Button(&buttons)[3], SDL_Renderer* renderer);

void RenderNewImage(SDL_Renderer* renderer, SDL_Texture* texture, bool isFlipped);