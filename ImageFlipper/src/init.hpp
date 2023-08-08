#pragma once
#include <SDL2/SDL_image.h>
#include <iostream>
#include <functional>

#include "button.hpp"

void InitSDL(SDL_Window** window, SDL_Renderer** renderer);

void InitUI(Button* button1, Button* button2, SDL_Renderer* renderer, SDL_Texture** currentImage);
