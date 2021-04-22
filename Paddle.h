
#ifndef Paddle_H
#define Paddle_H

#include<SDL.h>

struct paddle_create
{
    int x_pos, y_pos ;
    int w_paddle, h_paddle ;
} ;


void move_paddle (int go, paddle_create* paddle) ;
void move_paddle2 (int go, paddle_create* paddle) ;



#endif // Paddle_H
