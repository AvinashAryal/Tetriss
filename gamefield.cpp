#pragma once

#include"tetromino.cpp"

#include"gamefield.h"
#include"tetromino.h"
#include"game.h"

tetromino *t = new tetromino;

bool gamefield::ReturnGameover()
{
    return gameover;
}

void gamefield::SetValues()
{
    gameover = false;
    t->SetPosn();
    for(int i = 1;i<21;i++)
    {
        for(int j = 1;j<11;j++)
        {
            field_val[i][j] = 0;
            field[i][j].x = (j-1)*30;
            field[i][j].y = (i-1)*30;
            field[i][j].w = 30;
            field[i][j].h = 30;
        }
    }
}

void gamefield::UpdateValues()
{
    left_coll = right_coll = down_coll = false;
    t->UpdatePosn(N);

    tetro_id[N] = t->Return_n();

    for(int i =0;i<4;i++)
    {
        block_copy[N][i] = t->ReturnBlock(N,i);
    }

    for(int i = 0;i<4;i++)
    {
        if((field_val[(block_copy[N][i].y+30+30)/30][block_copy[N][i].x/30]) == 1 )
            left_coll = true;
        if((field_val[(block_copy[N][i].y+30+30)/30][(block_copy[N][i].x+30+30)/30]) == 1 )
            right_coll = true;
        if((field_val[(block_copy[N][i].y+30+30)/30][(block_copy[N][i].x+30)/30]) == 1 )
            down_coll= true;
    }
    for(int i = 1; i<11;i++)
    {
        if(field_val[1][i]==1)
        {
            gameover = true;
        }
    }

    for(int i = 0;i<22;i++)
    {
        for(int j = 0;j<12;j++)
        {
            if( ( i == 21|| j == 0|| j == 11) )
                field_val[i][j]= 1;
            else if( i == 0)
                field_val[i][j] = -1;

            for(int k=0;k<4;k++)
            {
                if((SDL_HasIntersection(&block_copy[N][k],&field[i][j])) && (down_coll))
                {
                    field_val[i][j]=1;
                }

            }


        }
    }

    if(down_coll)
    {
        N++;
        t->SetPosn();
    }

}

void gamefield::UpdateGameField(SDL_Renderer *r,SDL_Event e,SDL_Texture *bg)
{
    SDL_RenderCopy(r,bg,NULL,&background);
    t->BlockEvents(e);
    if(!left_coll && !down_coll) t->MoveLeft(N);
    if(!right_coll && !down_coll) t->MoveRight(N);
    if(!down_coll ) t->Rotate(N,left_coll,right_coll);
    if(!down_coll) t->MoveDown(N);

}

void gamefield::DestroyTetrominos()
{
   for(int i = 0;i<20;i++) row_full[i] = false;
   for(int i = 1;i<21;i++)
   {
       same_row_n = 0;
       for(int j = 1;j<11;j++)
       {
           if(field_val[i][j] == 1)
           {
                same_row_n++;
           }
           if(same_row_n == 10)
           {
               row_full[i-1] = true;
           }

       }
   }
   for(int k = 0;k<20;k++)
   {
       if(row_full[k])
       {
        for(int i = k+1;i>1;i--)
       {
           for(int j = 1;j<11;j++)
           {
               field_val[i][j] = field_val[i-1][j];
           }
       }


       for(int i = 0;i<=N;i++)
       {
           for(int j = 0;j<4;j++)
           {
               if( (block_copy[i][j].y) == (k*30) ) block_copy[i][j].h = 0;
               else if(block_copy[i][j].y < k*30) block_copy[i][j].y += 30;
           }
       }
       }
   }

}

void gamefield::DisplayTetrominos(SDL_Renderer *r,SDL_Texture *cyan,SDL_Texture *blue,SDL_Texture *orange,SDL_Texture *yellow,SDL_Texture *green,SDL_Texture *red,SDL_Texture *purple)
{
    for(int i = 0;i<=N;i++)
    {
        for(int j= 0;j<4;j++)
        {
            switch(tetro_id[i])
            {
            case 0:
                SDL_RenderCopy(r,cyan,NULL,&block_copy[i][j]);
                break;
            case 1:
                SDL_RenderCopy(r,blue,NULL,&block_copy[i][j]);
                break;
            case 2:
                SDL_RenderCopy(r,orange,NULL,&block_copy[i][j]);
                break;
            case 3:
                SDL_RenderCopy(r,yellow,NULL,&block_copy[i][j]);
                break;
            case 4:
                SDL_RenderCopy(r,green,NULL,&block_copy[i][j]);
                break;
            case 5:
                SDL_RenderCopy(r,red,NULL,&block_copy[i][j]);
                break;
            case 6:
                SDL_RenderCopy(r,purple,NULL,&block_copy[i][j]);
                break;
            default:
                break;
            }
        }
    }
}

void gamefield::DisplayScore(SDL_Renderer *r,SDL_Texture *score,SDL_Rect score_rect)
{

}


