#pragma once
#include <SDL2/SDL.h>
#include <functional>

struct Button
{
    SDL_Rect rect = SDL_Rect();
    SDL_Color col = SDL_Color();
    std::function<void()> func;
};

void CheckButtonClick(Button(&buttons)[2], SDL_Point point);

void DrawButtons(Button(&buttons)[2], SDL_Renderer* renderer);