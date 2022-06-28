/*
MAIN CPP
*/

#include "bn_core.h"
#include "sml_game.h"

#include "sml_mario.h"
#include "sml_goomba.h"
#include "sml_mushroom.h"
#include "sml_flower.h"
#include "sml_coin.h"
#include "sml_power_star.h"

#include "bn_music_items.h" //house eventual music


int main()
{
    //Initialize both the engine and the game
    bn::core::init();
    bn::unique_ptr<Game> game(new Game());

    //WIP for including music

    //bn::music_items::birabuto.play(0.1); //game crashes when music tries to play

    //The main loop
    while(true)
    {

        //Placeholder object for Mario (has now popped up on screen)
        Mario mario;
        Goomba goomba(0, 0);
        Flower flower(10, 10);
         
        
        //Mushroom mushroom(0,0); //Ask Butano Discord for help
        //game->update();
        bn::core::update();
    }
}
