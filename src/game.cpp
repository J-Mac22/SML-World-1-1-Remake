/*
CPP for the Super Mario Land game
*/

#include "sml_game.h"
#include "sml_world1_1.h"
#include "bn_regular_bg_items_world1_1.h"

#include "bn_music_actions.h"
#include "bn_sound_items.h"

//Constructor for the game
Game::Game() :
_currLevel(1),
_levelClear(false)
{}


 //Updating the game
void Game::update(Mario &mario) {

//If the level has not been finished, continue to update it
if (!_levelClear) {

//If Mario dies, activate death animation and stop having the level be updated.
if (mario.getDie()) {

    bn::music::stop();
    bn::sound_items::smb_mariodie.play(0.5);

    //Freeze the game shortly
    for (int i = 0; i < 28; i++) {

        bn::core::update();

    }

    //Setting the data for the animation
    bn::fixed pace = 5.0;
    bn::fixed currY = mario.getY();
    bool jumpUp = true;

    //Have function go through animation
    for (int i = 0; i < 360; i++) {

        if (jumpUp) {

            currY -= pace;
            pace -= 0.2;

            if (pace == 0) jumpUp = false;

        }

        else {

            currY += pace;
            pace += 0.5;

        }

        mario.setY(currY);

        //Updating the frames
        bn::core::update();
    }

    //Reset the core after the animation is done
    bn::core::reset();

    }
}

//If the level is completed, do the level completed animation
else {

    //Have Mario move next to star
    //mario.move_next_to_star();

    //Play the level complete music
    bn::music::stop();
    bn::sound_items::star_get.play(0.5);

    for (int i = 0; i < 30; i++) {

        //Freeze the game  
        bn::core::update();

    }

    //Move both Mario and the Power Star upwards
    bn::fixed currY = mario.getY();
    //Power_Star pStar;

    for (int i = 0; i < 360; i++) {

        currY -= 1;
        mario.setY(currY);
        //star will also go here

        //Update the frame
        bn::core::update();

    }

    bn::core::reset();
}

}