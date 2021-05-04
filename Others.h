#ifndef Others_H_
#define Others_H_


#include "CommonFunction.h"
#include "BaseObject.h"
#include "TextObject.h"


class back_end
{
public:
    void LoadImg (SDL_Renderer* screen , TTF_Font* gFont , TTF_Font* Font , SDL_Color textColor );
    void LIVE ( string live , TTF_Font* gFont , SDL_Color textColor , SDL_Renderer* screen  );
    void TIME (  int time_game , TTF_Font* gFont , SDL_Color textColor , SDL_Renderer* screen  );
    void SCORE ( string score, TTF_Font* gFont , SDL_Color textColor , SDL_Renderer* screen   );
    void NUMBER_BULLET ( string number_bullet , TTF_Font* gFont , SDL_Color textColor , SDL_Renderer* screen   ) ;
    void high_score_read ( string path  );
    void high_score_update ( string path , int now_score );
    void high_score_render (SDL_Renderer* screen );
    int high_score;
private:
    base_object picture_live;
    base_object picture_oclock;
    TextObject score_text;
    TextObject number_bullet_text;
    TextObject high_score_text1;
    TextObject high_score_text2;
    TextObject game_advise1;
    TextObject game_advise2;
};
#endif // Others_H_
