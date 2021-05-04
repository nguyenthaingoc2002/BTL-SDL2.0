
#include "Pause.h"



void game_pause :: XuLy (SDL_Renderer* screen , SDL_Event event , bool& is_quit , bool& can_restart )
{
    pause_picture.LoadImg ( "img//pause1.png" , screen , SCREEN_WIDTH , SCREEN_HEIGHT );
    bool quit = false ;
    int k = 1 ;
    while ( !quit )
    {
        while ( SDL_PollEvent(&event) )
        {
            if ( event.type == SDL_KEYDOWN  )
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_DOWN :
                    {
                        pause_picture.LoadImg("img//pause2.png" , screen , SCREEN_WIDTH , SCREEN_HEIGHT );
                        k = 2 ;
                        break;
                    }
                    case SDLK_UP :
                    {
                        pause_picture.LoadImg("img//pause1.png" , screen , SCREEN_WIDTH , SCREEN_HEIGHT );
                        k = 1 ;
                        break;
                    }
                    case SDLK_RETURN:
                    {
                        quit = true ;
                        if ( k == 1 )
                        {


                        }
                        if ( k == 2 )
                        {
                            is_quit = true ;
                            can_restart = true;

                        }
                        break;
                    }
                    default: break;

                }
            }
        }
        pause_picture.Render( screen );
        SDL_RenderPresent(screen);
    }

}
