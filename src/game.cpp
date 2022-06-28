/*
CPP for the Super Mario Land game
*/

#include "sml_game.h"
#include "sml_world1_1.h"

#include "bn_music_actions.h"
#include "bn_sound_items.h"

//Constructor for the game
Game::Game() :
_currLevel(1),
_levelClear(false)
{}

//Updating the game
void Game::update() {

//If the level has not been finished, continue to update it
if (!_levelClear) {

//_levelClear = (pointer?)->update(_mario);

//If Mario dies, activate death animation and stop having the level be updated.
//if (!_mario.getDie) {

    bn::music::stop();
    bn::sound_items::smb_mariodie.play(0.5);

    //Freeze the game shortly
    for (int i = 0; i < 28; i++) {

        bn::core::update();

    }

    //Setting the data for the animation
    bn::fixed pace = 5.0;
    bn::fixed currY; //have Mario get current Y
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

        // set Mairo position?

        //Updating the frames
        bn::core::update();
    }

    //Reset the core after the animation is done
    bn::core::reset();

//}

}

}