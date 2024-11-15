#ifndef _cherchersol_h
#define _cherchersol_h
#include<SDL.h>
#include<stdbool.h>
typedef struct  cercle_position{ 
    float x ; 
    float y ; 
}cercle_position;
typedef struct {
    cercle_position position; // position de l'objet
    float width;       // largeur de l'objet
    float height;      // hauteur de l'objet
    float speed;       // vitesse de l'objet
} GameObject;
GameObject initianiliser_objet(cercle_position position , float width,float height,float speed);


void deplacer(SDL_Renderer* renderer); 


#endif
