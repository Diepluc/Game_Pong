
#include "Draw.h"


using namespace std ;

void Draw_GameOver(int p, SDL_Surface* gameover, SDL_Surface* screen)
{
    SDL_Rect p1 ;
    SDL_Rect p2 ;
    SDL_Rect computer ;
    SDL_Rect des ;

    p1.x = 0 ;
    p1.y = 0 ;
    p1.w = gameover->w ;
    p1.h = 75 ;

    p2.x = 0;
    p2.y = 75;
    p2.w = gameover->w;
    p2.h = 75;

    computer.x = 0;
    computer.y = 150;
    computer.w = gameover->w;
    computer.h = 75;

    des.x = (SCREEN_WIDTH / 2) - (gameover->w / 2);
    des.y = (SCREEN_HEIGHT/ 2) - (75 / 2);
    des.w = gameover->w ;
    des.h = 75;

    switch(p)
    {
    case 1:
        SDL_BlitSurface(gameover, &p1, screen, &des);
        break;
    case 2:
        SDL_BlitSurface(gameover, &p2, screen, &des);
        break;
    case 3:
        SDL_BlitSurface(gameover, &computer, screen, &des);
    }
}


void Draw_menu(SDL_Surface* title, SDL_Surface* screen)
{
    SDL_Rect menu ;
    SDL_Rect des ;

    menu.x = 0 ;
    menu.y = 0 ;
    menu.h = title->h ;
    menu.w = title->w ;

    des.x = (SCREEN_WIDTH/ 2) - (menu.w / 2);
    des.y = (SCREEN_HEIGHT / 2) - (menu.h / 2);
    des.w = title->w;
    des.h = title->h;

    SDL_BlitSurface(title, &menu, screen, &des);
}

void Draw_net(SDL_Surface* screen)
{
    SDL_Rect net;

    net.x = SCREEN_WIDTH / 2;
    net.y = 20;
    net.w = 5;
    net.h = 15;
    int i,r;
    for(i = 0; i < 15; i++)
    {
        r = SDL_FillRect(screen, &net, 0xffffffff);
        if (r != 0)
        {
            cout << "Fail Draw net" ;
        }
        net.y = net.y + 30 ;
    }
}
void Draw_guide(SDL_Surface* guide, SDL_Surface* screen)
{
    SDL_Rect guide1 ;
    SDL_Rect des ;

    guide1.x = 0 ;
    guide1.y = 0 ;
    guide1.h = guide->h ;
    guide1.w = guide->w ;

    des.x = (SCREEN_WIDTH / 2) - (guide1.w / 2);
    des.y = (SCREEN_HEIGHT / 2) - (guide1.h / 2);
    des.w = guide->w;
    des.h = guide->h;

    SDL_BlitSurface(guide, &guide1, screen, &des);
}

void Draw_pause(SDL_Surface* pause, SDL_Surface* screen)
{
    SDL_Rect pause1 ;
    SDL_Rect des ;

    pause1.x = 0 ;
    pause1.y = 0 ;
    pause1.h = pause->h ;
    pause1.w = pause->w ;

    des.x = (SCREEN_WIDTH / 2) - (pause1.w / 2);
    des.y = (SCREEN_HEIGHT / 2) - (pause1.h / 2);
    des.w = pause->w;
    des.h = pause->h;

     SDL_BlitSurface(pause, &pause1, screen, &des);
}



void Draw_player0_score(int* score, SDL_Surface* numbermap, SDL_Surface* screen)
{

    SDL_Rect src;
    SDL_Rect des;

    src.x = 0;
    src.y = 0;
    src.w = 64;
    src.h = 64;

    des.x = (SCREEN_WIDTH/ 2) - src.w - 12;
    des.y = 0;
    des.w = 64;
    des.h = 64;

    if (score[0] > 0 && score[0] < 10)
    {
        src.x += src.w * score[0];
    }
    SDL_BlitSurface(numbermap, &src, screen, &des);
}

void Draw_player1_score(int* score, SDL_Surface* numbermap, SDL_Surface* screen)
{

    SDL_Rect src;
    SDL_Rect des;

    src.x = 0;
    src.y = 0;
    src.w = 64;
    src.h = 64;

    des.x = (SCREEN_WIDTH / 2) + 12;
    des.y = 0;
    des.w = 64;
    des.h = 64;

    if (score[1] > 0 && score[1] < 10)
    {
        src.x += src.w * score[1];
    }

    SDL_BlitSurface(numbermap, &src, screen, &des);
}



void Draw_ball(ball_create& ball,SDL_Surface* screen)
{
    SDL_Rect src ;

    src.x = ball.x_pos ;
    src.y = ball.y_pos ;
    src.w = ball.w_ball ;
    src.h = ball.h_ball ;

    int r = SDL_FillRect(screen, &src, 0xffffffff);

    if (r !=0) cout << "Fail Draw ball" ;
}

void Draw_paddle(paddle_create* paddle,SDL_Surface* screen)
{
    SDL_Rect src ;
    int i ;

    for(i = 0; i < 2; i++)
    {
        src.x = paddle[i].x_pos ;
        src.y = paddle[i].y_pos ;
        src.h = paddle[i].h_paddle ;
        src.w = paddle[i].w_paddle ;

        int r = SDL_FillRect(screen, &src, 0xffffffff) ;
        if(r != 0) cout << "Fail Draw Paddle" ;
    }
}



