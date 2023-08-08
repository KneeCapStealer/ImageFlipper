#include "Button.hpp"

void CheckButtonClick(Button(&buttons)[2], SDL_Point point)
{
    for (Button& button : buttons)
    {
        if (SDL_PointInRect(&point, &button.rect))
            button.func();
    }
}

void DrawButtons(Button(&buttons)[2], SDL_Renderer* renderer)
{
    for (Button& button : buttons)
    {
        SDL_SetRenderDrawColor(renderer, button.col.r, button.col.g, button.col.b, button.col.a);
        SDL_RenderFillRect(renderer, &button.rect);
    }
}
