#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_mixer.h>

#include "BaseF.h"
#include "Ball.h"
#include "Paddle.h"
#include "Paddle_AI.h"
#include "Draw.h"

using namespace std ;

int InitGame()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "Not initialize" <<SDL_GetError() ;
        return 1;
    }

    if(Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096) == -1)
    {
        cout << "Not Audio" ;
        return 1 ;
    }

    sound1 = Mix_LoadWAV("Sound/Gun.wav") ;
    sound2 = Mix_LoadWAV("Sound/Gun2.wav") ;

    if(sound1 == NULL || sound2 == NULL)
    {
        cout << "Not soud1" ;
        return 1 ;
    }
    window = SDL_CreateWindow("Pong",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        cout << "Not create SDL_Error: " << SDL_GetError();
        return 1;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    screen = SDL_CreateRGBSurfaceWithFormat(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_PIXELFORMAT_RGBA32) ;
    if(screen == NULL)
    {
        cout << "Not creat screen" << SDL_GetError() ;
        return 1 ;
    }
    screen_texture = SDL_CreateTextureFromSurface(renderer, screen);
    if (screen_texture == NULL)
    {
        cout << "Not create screen_texture" << SDL_GetError();
        return 1;
    }

    title = SDL_LoadBMP("Image/A2.bmp");
    if (title == NULL)
    {
        cout << "Not load title" << SDL_GetError() ;
        return 1;
    }

    numbermap = SDL_LoadBMP("Image/N.bmp");
    if (numbermap == NULL)
    {
        cout << "Not Load numbermap" << SDL_GetError() ;
        return 1;
    }

    gameover = SDL_LoadBMP("Image/gameover.bmp");
    if (gameover == NULL)
    {
        cout << "Not load gameover" << SDL_GetError();
        return 1;
    }
    guide = SDL_LoadBMP("Image/guide.bmp") ;
    if (guide == NULL)
    {
        cout << "Not load guide" << SDL_GetError();
        return 1;
    }

    pause = SDL_LoadBMP("Image/pause.bmp") ;
    if (pause == NULL)
    {
        cout << "Not load pause" << SDL_GetError();
        return 1;
    }
    return 0;
}

int Check_score(int* score)
{
    int i ;
    for(i=0; i<2; i++)
    {
        if(score[i] == 5)
        {
            score[0] = 0 ;
            score[1] = 0 ;
            if(i == 0) return 1 ; // computew win
            if(i == 1) return 2 ; // player win
        }
    }
    return 0 ;
}


int main(int argc, char* argv[])
{
    ball_create ball ;
    paddle_create paddle[2] ;
    int score[] = {0,0} ;

    if(InitGame() == 1) return 0 ;

    int state = 0 ;
    int winner = 0 ;
    int sleep = 0 ;
    int type = 0 ;
    Uint32 next_game_tick = SDL_GetTicks();

    Start_Game(ball,paddle) ;
    bool quit = true;
    while(quit)
    {
        SDL_PumpEvents() ;
        const Uint8* event = SDL_GetKeyboardState(NULL) ;

        if(event[SDL_SCANCODE_ESCAPE])  quit = false ;
        if(event[SDL_SCANCODE_DOWN]) move_paddle(0, paddle) ;
        if(event[SDL_SCANCODE_UP]) move_paddle(1, paddle) ;

        SDL_RenderClear(renderer) ;
        SDL_FillRect(screen, NULL,0x000000ff) ;


        if (state == 0 )
        {
            if (event[SDL_SCANCODE_1])
            {
                Mix_PlayChannel(-1,sound1,0) ;
                state = 1;
                type = 1 ;
            }

            if (event[SDL_SCANCODE_2])
            {
                Mix_PlayChannel(-1,sound1,0) ;
                state = 1 ;
                type = 2;
            }
            if (event[SDL_SCANCODE_3])
            {
                Mix_PlayChannel(-1,sound1,0) ;
                state = 3 ;
            }

            Draw_menu(title,screen) ;
        }


        if(state == 1) // game
        {
            if (event[SDL_SCANCODE_SPACE]) // open menu in game
            {
                Mix_PlayChannel(-1,sound1,0) ;
                state = 0 ;
                score[0] = 0 ;
                score[1] = 0 ;
            }
            if (event[SDL_SCANCODE_P])  // Pause in game
            {
                Mix_PlayChannel(-1,sound1,0) ;
                state = 4 ;
            }

            winner = Check_score(score) ;
            if(winner == 1 || winner == 2)
            {
                state = 2 ;
            }
            if(type == 1) move_paddle_AI(ball, paddle) ;  // AI
            if(type == 2) // player 1
            {
                if(event[SDL_SCANCODE_S]) move_paddle2(0,paddle) ;
                if(event[SDL_SCANCODE_W]) move_paddle2(1,paddle) ;
            }

            move_ball(ball, paddle, score, sound1, sound2) ;
            Draw_net(screen) ;
            Draw_paddle(paddle, screen) ;
            Draw_ball(ball, screen) ;
            Draw_player0_score(score, numbermap, screen) ;
            Draw_player1_score(score, numbermap, screen) ;
        }
        if (state == 2) // display winner
        {
            if(winner == 1 && type == 1)
            {
                Draw_GameOver(3,gameover,screen) ;
            }
            else if(winner == 1 && type == 2)
            {
                Draw_GameOver(2,gameover,screen) ;
            }
            else Draw_GameOver(1,gameover,screen) ;

            if (event[SDL_SCANCODE_SPACE])  // press space to continue play
            {
                state = 0;
                SDL_Delay(500);
            }
        }

        if(state == 3)  // display guide
        {
            if (event[SDL_SCANCODE_SPACE])
            {
                Mix_PlayChannel(-1,sound1,0) ;
                state = 0 ;
            }
            Draw_guide(guide, screen) ;
        }
        if(state == 4)
        {
            Draw_pause(pause, screen) ;
            if(event[SDL_SCANCODE_C])
            {
                state = 1 ;
            }

        }

        SDL_UpdateTexture(screen_texture, NULL, screen->pixels, SCREEN_WIDTH * sizeof (Uint32));
        SDL_RenderCopy(renderer, screen_texture, NULL, NULL);

//draw to the display
        SDL_RenderPresent(renderer);

        next_game_tick += 1000 / 60;
        sleep = next_game_tick - SDL_GetTicks();
        if( sleep >= 0 )
        {
            SDL_Delay(sleep);
        }
    }

    SDL_FreeSurface(screen);
    SDL_FreeSurface(title);
    SDL_FreeSurface(numbermap);
    SDL_FreeSurface(gameover) ;

    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;

}



