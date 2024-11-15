#include"cellule.h"
cellule creer_cellule(int id ){
    cellule cel;
    cel.id=id;
    for(int i=0;i<4;i++){ 
        cel.mur[i]=true;
        
    }
    
    
   
    return cel;}

