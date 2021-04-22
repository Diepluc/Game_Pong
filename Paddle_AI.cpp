
#include <iostream>
#include "Paddle_AI.h"

void move_paddle_AI(ball_create& ball, paddle_create* paddle)
{
    int mid_paddle = paddle[0].y_pos + 25 ;
    int mid_screen = SCREEN_HEIGHT / 2  ;
    int ball_speed = ball.y_val ;

    if(ball.y_pos <= 0) ball.y_pos = 0 ;

    if(ball_speed < 0)  ball_speed *= -1 ;

    if(ball.x_val > 0) // ball move right
    {
        // move paddle to mid screen
        if(mid_paddle < mid_screen) paddle[0].y_pos += ball_speed ;
        else paddle[0].y_pos -= ball_speed ;
    }
    else // ball move left
    {

        if(ball.y_val > 0) // ball move down
        {
            if(ball.y_pos > mid_paddle) paddle[0].y_pos += ball_speed ;
            else paddle[0].y_pos -= ball_speed ;
        }

        if(ball.y_val < 0) // ball move up
        {
            if(ball.y_pos > mid_paddle) paddle[0].y_pos += ball_speed ;
            else paddle[0].y_pos -= ball_speed ;
        }

    }

    if(ball.y_val == 0) // move stright
    {
        if(ball.y_pos < mid_paddle) paddle[0].y_pos -= 5 ;
        else paddle[0].y_pos += 5 ;
    }
}

