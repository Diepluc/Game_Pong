
#include "Paddle.h"
#include "BaseF.h"


void move_paddle (int go, paddle_create* paddle)
{
    if(go == 0) // down
    {
        if(paddle[1].y_pos >= SCREEN_HEIGHT - paddle[1].h_paddle)
        {
            paddle[1].y_pos = SCREEN_HEIGHT - paddle[1].h_paddle ;
        }
        else paddle[1].y_pos += 5 ;
    }
    if(go == 1) // up
    {
        if(paddle[1].y_pos <= 0)
        {
            paddle[1].y_pos = 0 ;
        }
        else paddle[1].y_pos -= 5 ;
    }
}

void move_paddle2 (int go, paddle_create* paddle)
{
    if(go == 0) // down
    {
        if(paddle[0].y_pos >= SCREEN_HEIGHT - paddle[1].h_paddle)
        {
            paddle[0].y_pos = SCREEN_HEIGHT - paddle[1].h_paddle ;
        }
        else paddle[0].y_pos += 5 ;
    }
    if(go == 1) // up
    {
        if(paddle[0].y_pos <= 0)
        {
            paddle[0].y_pos = 0 ;
        }
        else paddle[0].y_pos -= 5 ;
    }
}


