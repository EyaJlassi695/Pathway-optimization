#ifndef LABRYNTHE_H
#define LABRYNTHE_H
#include "cellule.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
typedef struct labrynthe
{
    int n;
    int m;
    cellule** cells;
}labrynthe;
labrynthe* intialiser_labrynthe( int hauteur , int largeur);
void afficher_lab(labrynthe* lab);
void destruction_mur(labrynthe* lab,position pos ,int i,int j );

 
 
 bool estIsole(labrynthe* lab, int id ); 

 int id_Cellulle(labrynthe* laby,int id,position pos);
 void genererlabrynthe(labrynthe* lab );

#endif