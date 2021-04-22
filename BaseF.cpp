
#include "BaseF.h"

void Start_Game(ball_create &ball, paddle_create* paddle)
{
    int val_x[] = {-2,2} ;
    ball.x_pos = SCREEN_WIDTH / 2 + 5 ;
    ball.y_pos = SCREEN_HEIGHT / 2 + 5 ;
    ball.w_ball = 10 ;
    ball.h_ball = 10 ;

    srand((int)time(0)) ;
    int temp1 = rand() % 2 - 0 ;
    ball.x_val = val_x[temp1] ;
    int temp = rand() % 8 - 4 ;
    ball.y_val = temp ;

    paddle[0].x_pos = 20 ;
    paddle[0].y_pos = SCREEN_HEIGHT / 2 - 25 ;
    paddle[0].w_paddle = 10 ;
    paddle[0].h_paddle = 50 ;

    paddle[1].x_pos = SCREEN_WIDTH - 20 - 10 ;
    paddle[1].y_pos = SCREEN_HEIGHT / 2 - 25 ;
    paddle[1].w_paddle = 10 ;
    paddle[1].h_paddle = 50 ;
}
