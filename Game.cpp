#include "Game.h

Game :: Game ()
{

}
Game :: ~Game()
{

}
void Game :: Init()
{
    bool success = true ;
    int ret = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO );
    if ( ret == false )
    {
        return false;
    }
    SDL_SetHint (SDL_HINT_RENDER_SCALE_QUALITY , "1" ) ;

    g_window = SDL_CreateWindow( "Nguyen Thai Ngoc 20020208"
                                ,  0
                                ,  0
                                , SCREEN_WIDTH
                                , SCREEN_HEIGHT
                                , SDL_WINDOW_SHOWN);

    if ( g_window == NULL )
    {
        success =  false ;
    }
    else
    {
        g_screen = SDL_CreateRenderer (g_window , -1 , SDL_RENDERER_ACCELERATED ) ;
        if ( g_screen == NULL )
        {
            success = false ;
        }
        else
        {
            SDL_SetRenderDrawColor (g_screen , RENDER_DRAW_COLOR , RENDER_DRAW_COLOR , RENDER_DRAW_COLOR , RENDER_DRAW_COLOR );
            int imgFlags = IMG_INIT_PNG ;
            if ( !(IMG_Init (imgFlags) &&  imgFlags) )
            {
                success = false ;
            }
            if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
            {
                success = false;
            }
            if( TTF_Init() == -1 )
            {
                success = false;
            }
        }
    }

    return success;
}
void Game :: load_media ()
{
    g_background.LoadImg( "img//background.png",g_screen , SCREEN_WIDTH , SCREEN_HEIGHT );
    gFont = TTF_OpenFont( "font//01.ttf", 300 ) ;
    Font = TTF_OpenFont( "font//01.ttf", 30 ) ;
    g_map.Load_Map("img//map.txt");
    exp_enemy.LoadImg("img//exp3.png" , g_screen, MAIN_SIZE , MAIN_SIZE );
    exp_main.LoadImg("img//exp3.png" , g_screen, MAIN_SIZE , MAIN_SIZE );
    exp_enemy.set_clip();
    exp_main.set_clip();
    explosion = Mix_LoadWAV("sound//explosion.wav");
    fire = Mix_LoadWAV("sound//fire.wav");
    game_over.LoadImg("img//gameover.jpg" , g_screen , SCREEN_WIDTH  , SCREEN_HEIGHT);
    game_over.SetRect(0,0);
    back_end_.high_score_read("data//high_score.txt");
    back_end_.LoadImg(g_screen , gFont , Font , color_ );
}
void Game :: clean ()
{
    SDL_DestroyWindow(g_window);
    SDL_DestroyRenderer(g_screen);
    g_window = NULL;
    g_screen = NULL;

    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
    Mix_Quit();
}






















