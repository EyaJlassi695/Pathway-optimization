#include <SDL.h>
#include<stdbool.h>

typedef struct {
    int x, y;   // Position du carré
    int size;   // Taille du carré
} Square;

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Carré déplaçable", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    Square square1 = { 100, 100, 50 };
    Square square2 = { 150, 150, 50 };

    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            square1.y -= 10;
                            square2.y -= 10;
                            break;
                        case SDLK_DOWN:
                            square1.y += 10;
                            square2.y += 10;
                            break;
                        case SDLK_LEFT:
                            square1.x -= 10;
                            square2.x -= 10;
                            break;
                        case SDLK_RIGHT:
                            square1.x += 10;
                            square2.x += 10;
                            break;
                    }
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect rect1 = { square1.x, square1.y, square1.size, square1.size };
        SDL_RenderFillRect(renderer, &rect1);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_Rect rect2 = { square2.x + 50, square2.y + 50, square2.size, square2.size };
        SDL_RenderFillRect(renderer, &rect2);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
