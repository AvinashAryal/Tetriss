#pragma once

#include"tetromino.h"
#include"game.h"
#include"gamefield.h"

SDL_Rect tetromino::ReturnBlock(int i,int j)
{
    return block[i][j];
}

int tetromino::Return_n()
{
    return n;
}

void tetromino::SetPosn()
{
    left = right = down = rotate = r_pressed = false;
    srand(time(NULL));
    n = rand()%7;
    baserect.x = 60;
    baserect.y = -90;
    baserect.h = 30;
    baserect.w = 30;
}

void tetromino::BlockEvents(SDL_Event e)
{
    switch(e.type)
    {
        case(SDL_KEYDOWN):
            switch(e.key.keysym.scancode)
            {
            case(SDL_SCANCODE_A):
            case(SDL_SCANCODE_LEFT):
                left=true;
                break;
            case(SDL_SCANCODE_D):
            case(SDL_SCANCODE_RIGHT):
                right=true;
                break;
            case(SDL_SCANCODE_S):
            case(SDL_SCANCODE_DOWN):
                down = true;
                break;
            case(SDL_SCANCODE_W):
            case(SDL_SCANCODE_UP):
                rotate = true;
                break;
            case(SDL_SCANCODE_R):
                r_pressed = true;
                break;
            }
            break;
        case(SDL_KEYUP):
            switch(e.key.keysym.scancode)
            {
            case(SDL_SCANCODE_A):
            case(SDL_SCANCODE_LEFT):
                left = false;
                break;
            case(SDL_SCANCODE_D):
            case(SDL_SCANCODE_RIGHT):
                right = false;
                break;
            case(SDL_SCANCODE_W):
            case(SDL_SCANCODE_UP):
                rotate = false;
                break;
            }
            break;
       }
}

void tetromino::MoveRight(int N)
{
    if(right )
    {
        SDL_Delay(25);
        baserect.x += 30;

    }
}


void tetromino::MoveLeft(int N)
{
    if(left )
    {
        SDL_Delay(25);
        baserect.x -= 30;
    }
}

void tetromino::Rotate(int N,bool left_coll,bool right_coll)
{
    for(int i=0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
            temp[i][j] = matrix[n][i][j];
        }
    }

    if(rotate)
    {
    orientation[n] ++;
    SDL_Delay(50);
    for(int i =0;i<4;i++)
    {
        for(int j =0;j<4;j++)
        {
            matrix[n][j][3-i] = temp[i][j];
        }
    }
    if(left_coll)
    {
        switch(orientation[n]%4)
        {
        case 0:
            if(n == 0) baserect.x += 60;
            break;

        case 2:
            if(n == 3) break;
            else baserect.x += 30;
            break;
        default:
            break;
        }

    }
    if(right_coll)
    {
        switch(orientation[n]%4)
        {
        case 0:
            if(n == 3) break;
            else baserect.x -= 30;
            break;
        case 2:
            if(n == 0) baserect.x -= 60;
            break;
        }
    }
    }
}


void tetromino::MoveDown(int N)
{
    if(down) SDL_Delay(10);
    else SDL_Delay(20);
    baserect.y+=5;
}



void tetromino::UpdatePosn(int N)
{
    p = 0;
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
            if(matrix[n][i][j] == 1)
            {
            block[N][p].x = baserect.x + j*30;
            block[N][p].y = baserect.y + i*30;
            block[N][p].h = 30;
            block[N][p].w = 30;
            p++;
            }
        }
    }

}
