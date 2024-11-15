#ifndef __DESSINER_h
#define __DESSINER_h
#include <SDL.h>
#include "labrynthe.h"
#define cell_size 15
void dessiner_labyrnthe(SDL_Renderer* renderer, labrynthe* lab ); 
#endif