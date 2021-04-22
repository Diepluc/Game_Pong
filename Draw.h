#ifndef Draw_H
#define Draw_H

#include<SDL.h>
#include<iostream>
#include "BaseF.h"
#include "Ball.h"


void Draw_GameOver(int p, SDL_Surface* gameover, SDL_Surface* screen) ;
void Draw_menu(SDL_Surface* title, SDL_Surface* screen) ;
void Draw_guide(SDL_Surface* guide, SDL_Surface* screen) ;
void Draw_pause(SDL_Surface* pause, SDL_Surface* screen) ;
void Draw_net(SDL_Surface* screen) ;
void Draw_player0_score(int* score, SDL_Surface* numbermap, SDL_Surface* screen) ;
void Draw_player1_score(int* score, SDL_Surface* numbermap, SDL_Surface* screen) ;
void Draw_ball(ball_create& ball,SDL_Surface* screen) ;
void Draw_paddle(paddle_create* paddle,SDL_Surface* screen) ;

#endif // Draw_H
