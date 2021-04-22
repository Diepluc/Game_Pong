#include<iostream>
#include<SDL_mixer.h>
#include "Ball.h"
#include "BaseF.h"
#include "Paddle.h"


int Check_collision(ball_create b, paddle_create p1)
{
    int left_b, left_p1, le ;
    int right_b, right_p1 ;
    int top_b, top_p1 ;
    int bottom_b, bottom_p1 ;

    left_b = b.x_pos ;
    right_b = b.x_pos + b.w_ball ;
    top_b = b.y_pos ;
    bottom_b = b.y_pos + b.h_ball ;

    left_p1 = p1.x_pos ;
    right_p1 = p1.x_pos + p1.w_paddle ;
    top_p1 = p1.y_pos ;
    bottom_p1 = p1.y_pos + p1.h_paddle ;


    if (left_b > right_p1) return 0;
    if (right_b < left_p1) return 0;
    if (top_b > bottom_p1) return 0;
    if (bottom_b < top_p1) return 0;

    return 1;
}


void move_ball(ball_create& ball, paddle_create* paddle, int* score,Mix_Chunk* sound1,Mix_Chunk* sound2)
{
    ball.x_pos += ball.x_val ;
    ball.y_pos += ball.y_val ;
    if(ball.x_pos < 0)
    {
        score[1] += 1 ;
        Mix_PlayChannel(-1,sound2,0) ;
        Start_Game(ball, paddle) ;
    }
    if(ball.x_pos > SCREEN_WIDTH - 10)
    {
        score[0] += 1 ;
        Mix_PlayChannel(-1,sound2,0) ;
        Start_Game(ball, paddle) ;
    }

    if(ball.y_pos < 0 || ball.y_pos > SCREEN_HEIGHT - 10)
    {
        ball.y_val *= -1 ;
    }

    int i ;
    for(i = 0; i < 2; i++)
    {
        int c = Check_collision(ball, paddle[i]) ;
        if(c == 1)
        {
            Mix_PlayChannel(-1,sound1,0) ;
            if(ball.x_val < 0)  ball.x_val -= 1 ; // move left
            else ball.x_val += 1 ; // move right

            ball.x_val *= -1 ;

            int hit_pos = (paddle[i].y_pos + paddle[i].h_paddle) - ball.y_pos ;

            if (hit_pos >= 0 && hit_pos < 7) ball.y_val = 4 ;
            if (hit_pos >= 7 && hit_pos < 14) ball.y_val = 3 ;
            if (hit_pos >= 14 && hit_pos < 21) ball.y_val = 2;
            if (hit_pos >= 21 && hit_pos < 28) ball.y_val = 1;
            if (hit_pos >= 28 && hit_pos < 32) ball.y_val = 0;
            if (hit_pos >= 32 && hit_pos < 39) ball.y_val = -1;
            if (hit_pos >= 39 && hit_pos < 46) ball.y_val = -2;
            if (hit_pos >= 46 && hit_pos < 53) ball.y_val = -3;
            if (hit_pos >= 53 && hit_pos <= 60) ball.y_val = -4;

            if(ball.x_val > 0)
            {
                if(ball.x_pos < 30)
                    ball.x_pos = 30 ;
                else if(ball.x_pos > SCREEN_WIDTH - 40)
                    ball.x_pos = SCREEN_WIDTH - 40 ;
            }
        }
    }
}

