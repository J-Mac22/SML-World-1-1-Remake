/*
MAIN CPP
*/

#include "bn_core.h"
#include "sml_mario.h"
#include "sml_items.h"
#include "bn_music_items.h" //house eventual music


int main()
{
    //Initialize both the engine and the game
    bn::core::init();

    //WIP for including music

    bn::music_items::birabuto.play(0.1);

    //The main loop
    while(true)
    {

        //Placeholder object for Mario (has now popped up on screen)
        SML_Mario mario;
        //SML_Items mushroom;
        //Find a way to get game updated
        //game->update();
        bn::core::update();
    }
}
