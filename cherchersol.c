#include"cherchersol.h"
GameObject initianiliser_objet(cercle_position position , float width,float height,float speed){  
    GameObject objet; 
    objet.position.x=0; 
    objet.position.y=0; 
    objet.width=width;
    objet.speed=speed;
    objet.height=height;
    return objet;
}

void deplacer(SDL_Renderer* renderer){
 
    SDL_Rect rect = { 10, 10, 10, 10 };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);


    // Boucle de jeu
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
                            rect.y -= 10;
                            break;
                        case SDLK_DOWN:
                            rect.y += 10;
                            break;
                        case SDLK_LEFT:
                            rect.x -= 10;
                            break;
                        case SDLK_RIGHT:
                            rect.x += 10;
                            break;
                    }
                    break;
            }
        }
    }
}