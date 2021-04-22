#ifndef BALL_H
#define BALL_H

#include<SDL.h>
#include<SDL_mixer.h>
#include "Paddle.h"

struct ball_create
{
    int x_pos, y_pos ;
    int w_ball, h_ball;
    int x_val, y_val ;
};


void Start_Game(ball_create &ball, paddle_create* paddle) ;
int Check_collision(ball_create b, paddle_create p1) ;
void move_ball(ball_create& ball, paddle_create* paddle, int* score,Mix_Chunk* sound1, Mix_Chunk* sound2) ;

#endif // BALL_H

