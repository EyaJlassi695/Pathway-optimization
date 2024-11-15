#include <SDL.h>
#include<stdio.h>
#include"labrynthe.h"
#include"dessiner.h"
#include"cherchersol.h"
int main (int argc ,char** argv){ 
  printf("Your message here\n");
  labrynthe* lab; 
  lab=intialiser_labrynthe(30,30);
  genererlabrynthe(lab);
  
  SDL_Init(SDL_INIT_VIDEO);
SDL_Window* window = SDL_CreateWindow("Labyrinthe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
 
   // SDL_Renderer *renderer1 = SDL_CreateRenderer(window, -1, 0);
     // deplacer(renderer);
bool continuer = true;
dessiner_labyrnthe(renderer,lab);

while (continuer)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            continuer = false;
        }
    }
}

return 0;

}



//gcc src\fichier.c -o bin\prog -I include -L lib -lmingw32 -lSDL2main -lSDL2