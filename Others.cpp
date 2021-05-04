#include "Others.h"


void back_end :: LoadImg (SDL_Renderer* screen , TTF_Font* gFont , TTF_Font* Font , SDL_Color textColor )
{
    picture_live.LoadImg( "img//tank_up.png" , screen , MAIN_SIZE* 3 , MAIN_SIZE * 3 );
    picture_live.SetRect(130 + MAIN_SIZE* 3 , 100);

    score_text.loadFromRenderedText( "SCORE" , gFont , textColor , screen , 120 , 100 );

    number_bullet_text.loadFromRenderedText("NUMBER BULLET" , gFont , textColor , screen , 350 , 100 );

    picture_oclock.LoadImg("img//oclock.png" , screen , 100 , 100 );
    picture_oclock.SetRect( 140 , 475);

    high_score_text1.loadFromRenderedText("HIGH SCORE" , gFont , textColor , screen , 200 , 130 );
    high_score_text2.loadFromRenderedText(to_string(high_score) , gFont , textColor , screen , 150 , 120 );
    game_advise1.loadFromRenderedText("Choi game qua 180 phut moi ngay se anh huong den suc khoe!!!"
                                     , Font , textColor , screen , 1366 , 50 ) ;
    game_advise2.loadFromRenderedText("Chuc moi nguoi choi game vui ve "
                                     , Font , textColor , screen , 1366 , 50 ) ;

}


void back_end :: LIVE ( string live, TTF_Font* gFont , SDL_Color textColor , SDL_Renderer* screen   )
{
    TextObject live_;
    live_.loadFromRenderedText( live + "x" , gFont , textColor , screen , 120 , 100 );
    live_.render(screen , 90 , 100 );
    picture_live.Render(screen);
}

void back_end :: SCORE ( string score, TTF_Font* gFont , SDL_Color textColor , SDL_Renderer* screen   )
{
    TextObject score_;
    score_.loadFromRenderedText(score , gFont , textColor , screen , 120 , 100 );
    score_text.render(screen , 1100 , 100 );
    score_.render(screen , 1100 , 200 );
}

void back_end :: NUMBER_BULLET ( string number_bullet , TTF_Font* gFont , SDL_Color textColor , SDL_Renderer* screen   )
{
    TextObject number_bullet_;

    number_bullet_.loadFromRenderedText(number_bullet , gFont , textColor , screen , 200 , 100 );
    number_bullet_text.render(screen , 30  , 250 );
    number_bullet_.render(screen , 110  , 350 );

}


void back_end :: TIME ( int time_game , TTF_Font* gFont , SDL_Color textColor , SDL_Renderer* screen  )
{
    int second = time_game / 1000 ;
    int minutes = second / 60 ;
    second = second % 60 ;

    string second_;
    string minutes_;
    if ( second < 10 )  second_ = "0" + to_string (second);
    else  second_ = to_string (second);
    if ( minutes < 10 )  minutes_ = "0" + to_string (minutes);
    else  minutes_ = to_string (minutes);
    string res = minutes_  + " : " + second_ ;

    TextObject oclock;
    oclock.loadFromRenderedText(res , gFont , textColor , screen , 150 , 100 );
    oclock.render ( screen , 120 , 580 );

    picture_oclock.Render(screen);
}

void back_end :: high_score_read ( string path  )
{
    ifstream ifs ;
    ifs.open(path , std::ios::in );
    ifs >> high_score ;
    ifs.close();
}


void back_end :: high_score_update ( string path , int now_score )
{
    ofstream ofs ;
    ofs.open(path , std::ios::out );
    ofs << now_score ;
    ofs.close();
}


void back_end :: high_score_render (SDL_Renderer* screen )
{
    high_score_text1.render(screen , 1080 , 400 );
    high_score_text2.render(screen , 1100 , 550 );
    game_advise1.render(screen , 0 , 700 );
    game_advise2.render(screen , 0 , 20  );
}


