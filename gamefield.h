#pragma once

#include<SDL2/SDL.h>
#include<cstdlib>
#include<ctime>

class gamefield
{
private:
    int field_val[22][12];
    SDL_Rect field[22][12];
    SDL_Rect background = {0,0,300,600};
    SDL_Rect block_copy[1000][4],temp;
    bool left_coll,right_coll,down_coll,gameover;
    int N=0;
    int same_row_n;
    int tetro_id[1000];
    bool row_full[20];
public:
    void SetValues();
    void UpdateValues();
    void UpdateGameField(SDL_Renderer*,SDL_Event,SDL_Texture *);
    void DestroyTetrominos();
    void DisplayTetrominos(SDL_Renderer*,SDL_Texture*,SDL_Texture*,SDL_Texture*,SDL_Texture*,SDL_Texture*,SDL_Texture*,SDL_Texture*);
    void DisplayScore(SDL_Renderer*,SDL_Texture*,SDL_Rect);
    bool ReturnGameover();
};
