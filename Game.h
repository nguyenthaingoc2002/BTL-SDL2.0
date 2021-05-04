#ifndef Game_H_
#define Game_H_

#include"CommonFunction.h"
#include "BaseObject.h"
#include "GameMap.h"
#include "MainObject.h"
#include "Time_FPS.h"
#include "TheatsObject.h"
#include "Explosion.h"
#include "TextObject.h"
#include "Menu.h"
#include "Others.h"
#include "Bonus_object.h"
#include "Pause.h"

class Game
{
public:
    Game();
    ~Game();
    void Init ();
    void load_media ();
    void handle_event ();
    void handle_game ();
    void clean ();

private:
    back_end back_end_;
    base_object game_over;
    gift bonus;
    explosion_object exp_enemy ;
    explosion_object exp_main ;
    base_object g_background;
    TheatsObject tank_enemy1( PlayWindow_X  , PlayWindow_Y , DOWN , 0 , STEP_H , 2 );
    TheatsObject tank_enemy2( PlayWindow_X + PlayWindow_SIZE - MAIN_SIZE  , PlayWindow_Y , LEFT , -STEP_H , 0 , 3 ) ;
    TheatsObject tank_enemy3( PlayWindow_X + PlayWindow_SIZE - MAIN_SIZE  ,PlayWindow_Y + PlayWindow_SIZE - MAIN_SIZE , UP , 0 , -STEP_H , 5 ) ;
    TheatsObject tank_enemy4( PlayWindow_X ,PlayWindow_Y + PlayWindow_SIZE - MAIN_SIZE , RIGHT , STEP_H , 0 , 4 ) ;
    TileMap g_map ;
    main_object tank;
    ImpTimer fps_timer ;
    SDL_Window* g_window = NULL ;
    SDL_Renderer* g_screen = NULL ;
    SDL_Event g_event ;
    Mix_Chunk *explosion = NULL ;
    Mix_Chunk *fire = NULL;
    TTF_Font *gFont = NULL;
    TTF_Font *Font = NULL;
    Menu gMenu ;
    game_pause gPause;
    SDL_Color color_ = { 0,0,0 } ;
    int score = 0 ;
    int timeRestart = 0 ;
};

#endif // Game_H_
