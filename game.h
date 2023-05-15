#pragma once

#include<iostream>
#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<cstdlib>
#include<ctime>

class game
{
private:
    bool b;
    SDL_Window *w;
    SDL_Renderer *r;
    SDL_Surface *cyan_surf,*blue_surf,*orange_surf,*yellow_surf,*green_surf,*red_surf,*purple_surf;
    SDL_Texture *cyan_tex,*blue_tex,*orange_tex,*yellow_tex,*green_tex,*red_tex,*purple_tex;
    SDL_Surface *bg_surface,*score_surface;
    SDL_Texture *bg_texture,*score_texture;
    SDL_Color fontcolor = {255,0,0,255};
    SDL_Rect score_rect = {0,0,400,200};
    TTF_Font *score;
    SDL_Event e;

public:
    void CreateGame();
    bool GameSwitch();
    bool NewGame();
    void DisplayGame();
    void DestroyGame();

};
