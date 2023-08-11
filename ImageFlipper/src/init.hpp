#pragma once
#include <SDL2/SDL_image.h>
#include <iostream>
#include <functional>

#include "button.hpp"

void InitSDL(SDL_Window** window, SDL_Renderer** renderer);

void InitUI(Button(*buttons)[3], SDL_Renderer* renderer, bool* isFlipped, SDL_Texture** currentImage);
