#ifndef _TILES_h 
#define _TILES_h 
#include<SDL.h>
#include<stdbool.h>
typedef enum direction{
UP,DOWN,LEFT,RIGHT
}direction;

typedef enum TileId {
    ZLIZ,MUR,ZLIZMUR,EMPTY,EXIT
} TileID;

typedef struct Tile{
    TileID tileID;
    bool* info;
    SDL_Texture* texture;
} Tile;

Tile* createTile(TileID tileID,SDL_Texture*spriteTile);
void drawTile(SDL_Renderer* window,Tile* tile,int i,int j);
void destroyTile(Tile* tile);
#endif