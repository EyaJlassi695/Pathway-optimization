#ifndef __cellule_h
#define __cellule_h
#include<stdbool.h>
#include<stdlib.h>
typedef enum position{ 
    HAUT,BAS,DROITE,GUAUCHE

}position;
typedef struct cellule
{
    int id ;
    bool mur[4];
    
}cellule;


cellule creer_cellule(int id );


#endif
