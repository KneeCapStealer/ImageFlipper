// -- Custom headers -- //

#include "init.hpp"

int main(int argc, char* args[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;

    InitSDL(&window, &renderer);

    SDL_Texture* currentImage = nullptr;
    Button imageButton1;
    Button imageButton2;

    InitUI(&imageButton1, &imageButton2, renderer, &currentImage);

    Button buttons[] = { imageButton1, imageButton2 };

    bool running = true;
    while (running)
    {
        SDL_SetRenderDrawColor(renderer, 185, 53, 45, 255);
        SDL_RenderClear(renderer);
        DrawButtons(buttons, renderer);
        if (currentImage != nullptr)
            if (SDL_RenderCopy(renderer, currentImage, NULL, NULL) != 0)
                std::cout << "Error with RenderCopy: " << SDL_GetError() << std::endl;

        SDL_RenderPresent(renderer);

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    SDL_Point mousePos = SDL_Point();
                    mousePos.x = event.button.x;
                    mousePos.y = event.button.y;

                    CheckButtonClick(buttons, mousePos);
                }
            }
        }
    }


    SDL_Quit();
    return 0;
}