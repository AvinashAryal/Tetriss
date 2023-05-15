#pragma once

#include<iostream>
#include<SDL2/SDL.h>
#include<cstdlib>
#include<ctime>


class tetromino
{
private:
    int matrix[7][4][4] =
    {
        {
            {0,0,0,0},
            {0,0,0,0},
            {1,1,1,1},
            {0,0,0,0}
        },//I

        {
            {0,0,0,0},
            {0,1,0,0},
            {0,1,1,1},
            {0,0,0,0}
        },//L
        {
            {0,0,0,0},
            {0,0,0,1},
            {0,1,1,1},
            {0,0,0,0}
        },//J
        {
            {0,0,0,0},
            {0,1,1,0},
            {0,1,1,0},
            {0,0,0,0}
        },//O
        {
            {0,0,0,0},
            {0,0,1,1},
            {0,1,1,0},
            {0,0,0,0}
        },//S
        {
            {0,0,0,0},
            {0,1,1,0},
            {0,0,1,1},
            {0,0,0,0}
        },//Z
        {
            {0,0,0,0},
            {0,0,1,0},
            {0,1,1,1},
            {0,0,0,0}
        }//T
    } ;
    bool left,right,rotate,down,r_pressed;
    int orientation[7],n,p;
    int temp[4][4];
    SDL_Rect block[1000][4];
    SDL_Rect baserect;

public:
    void SetPosn();
    void BlockEvents(SDL_Event e);
    void MoveLeft(int);
    void MoveRight(int);
    void Rotate(int,bool,bool);
    void MoveDown(int);
    SDL_Rect ReturnBlock(int i,int j);
    int Return_n();
    void UpdatePosn(int );
    bool Restart()
    {
        return r_pressed;
    }

};

