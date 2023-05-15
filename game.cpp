#pragma once
#include"gamefield.cpp"

#include"game.h"
#include"gamefield.h"
#include"tetromino.h"

gamefield *g_f = new gamefield ;

bool game::NewGame()
{
    return g_f->ReturnGameover();
}

void game::CreateGame()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    w = SDL_CreateWindow("Tetris",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,300,600,SDL_WINDOW_ALWAYS_ON_TOP);
    r = SDL_CreateRenderer(w,-1,0);
    g_f->SetValues();

    score = TTF_OpenFont("font/font.otf",20);

    bg_surface = IMG_Load("images/bg.jpg");
    cyan_surf = IMG_Load("images/cyan.png");
    blue_surf = IMG_Load("images/blue.png");
    orange_surf = IMG_Load("images/orange.png");
    yellow_surf = IMG_Load("images/yellow.png");
    green_surf = IMG_Load("images/green.png");
    red_surf = IMG_Load("images/red.png");
    purple_surf = IMG_Load("images/purple.png");
    score_surface = TTF_RenderText_Solid(score,"Gameover!!",fontcolor);

    bg_texture = SDL_CreateTextureFromSurface(r,bg_surface);
    cyan_tex = SDL_CreateTextureFromSurface(r,cyan_surf);
    blue_tex = SDL_CreateTextureFromSurface(r,blue_surf);
    orange_tex = SDL_CreateTextureFromSurface(r,orange_surf);
    yellow_tex = SDL_CreateTextureFromSurface(r,yellow_surf);
    green_tex = SDL_CreateTextureFromSurface(r,green_surf);
    red_tex = SDL_CreateTextureFromSurface(r,red_surf);
    purple_tex = SDL_CreateTextureFromSurface(r,purple_surf);

    score_texture = SDL_CreateTextureFromSurface(r,score_surface);

    SDL_FreeSurface(bg_surface);
    SDL_FreeSurface(cyan_surf);
    SDL_FreeSurface(blue_surf);
    SDL_FreeSurface(orange_surf);
    SDL_FreeSurface(yellow_surf);
    SDL_FreeSurface(green_surf);
    SDL_FreeSurface(red_surf);
    SDL_FreeSurface(purple_surf);

    SDL_FreeSurface(score_surface);
}

bool game::GameSwitch()
{
    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT)
        b = false;
    else
        b = true;
    return b;
}

void game::DisplayGame()
{
    SDL_RenderClear(r);

    g_f->UpdateValues();
    g_f->UpdateGameField(r,e,bg_texture);
    g_f->DestroyTetrominos();
    g_f->DisplayTetrominos(r,cyan_tex,blue_tex,orange_tex,yellow_tex,green_tex,red_tex,purple_tex);
    g_f->DisplayScore(r,score_texture,score_rect);
    SDL_SetRenderDrawColor(r,255,153,255,255);
    SDL_RenderPresent(r);
}


void game::DestroyGame()
{
    delete g_f;
    SDL_DestroyWindow(w);
    SDL_DestroyRenderer(r);
    SDL_DestroyTexture(score_texture);
    SDL_DestroyTexture(bg_texture);
    SDL_DestroyTexture(cyan_tex);
    SDL_DestroyTexture(blue_tex);
    SDL_DestroyTexture(orange_tex);
    SDL_DestroyTexture(yellow_tex);
    SDL_DestroyTexture(green_tex);
    SDL_DestroyTexture(red_tex);
    SDL_DestroyTexture(purple_tex);
    SDL_Quit();
}
