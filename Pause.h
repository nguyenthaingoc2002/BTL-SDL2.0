#ifndef Pause_H_
#define Pause_H_

#include "BaseObject.h"

class game_pause
{
public:
    void XuLy (SDL_Renderer* screen , SDL_Event event , bool& is_quit , bool& can_restart );
private:
    base_object pause_picture ;
};



#endif // Pause_H_
