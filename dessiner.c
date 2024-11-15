#include"dessiner.h"
void dessiner_labyrnthe(SDL_Renderer* renderer, labrynthe* lab ){   
    int n=lab->n ; 
    int m=lab->m; 
    int j=0;
    int x0=0;
    int x1;
    while(j<m){
         x1=x0+cell_size;
         SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawLine(renderer, x0, 0, x1, 0);
        x0=x1;
        j++;
    }
    int i=0;
    int y0=0;
    int y1;
    while(i<n){
        y1=y0+cell_size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawLine(renderer, 0, y0, 0, y1);
        y0=y1;
        i++;
        }
    
    for(int i=0;i<n;i++){
         
        for(int k=0;k<lab->m;k++){ 
            if(lab->cells[i][k].mur[BAS]){   
                int x0=k*cell_size;
                int x1=(k+1)*cell_size;
                int y=(i+1)*cell_size;
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderDrawLine(renderer, x0, y, x1, y);
                
            }
            if(lab->cells[i][k].mur[DROITE]){   
                int x=(k+1)*cell_size;
                int y0=i*cell_size;
                int y1=(i+1)*cell_size;
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderDrawLine(renderer, x, y0, x, y1);

            }  
            
            
            
        }
        
     }
     SDL_RenderPresent(renderer);}

