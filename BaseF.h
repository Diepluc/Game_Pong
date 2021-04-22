#ifndef BaseF_H
#define BaseF_H

#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_mixer.h>
#include "Ball.h"


static SDL_Window* window = NULL ;
static SDL_Renderer* renderer = NULL ;
static SDL_Texture* screen_texture ;
static SDL_Surface* screen ;
static SDL_Surface* title;
static SDL_Surface* numbermap;
static SDL_Surface* gameover ;
static SDL_Surface* guide ;
static SDL_Surface* pause ;
static Mix_Chunk* sound1 ;
static Mix_Chunk* sound2 ;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void Start_Game(ball_create &ball, paddle_create* paddle) ;

#endif // BaseF_H
