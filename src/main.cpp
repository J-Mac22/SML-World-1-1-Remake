/*
MAIN CPP
*/

#include "bn_core.h"
#include "sml_game.h"

#include "sml_mario.h"
#include "sml_goomba.h"
#include "sml_mushroom.h"
#include "sml_flower.h"
#include "sml_superball.h"
#include "sml_coin.h"
#include "sml_power_star.h"
#include "sml_regular_blocks.h"
#include "sml_question_blocks.h"
#include "sml_world1_1.h"

#include "bn_music_items.h"  

int main()
{
    //Initialize both the engine and the game
    bn::core::init();
    bn::unique_ptr<Game> game(new Game());
    bn::music_items::supermarioland.play(0.1);  
  
    Mario mario;
    Goomba goomba(40, -10);
    Flower flower(116, -75);
    Superball superball();
    Mushroom mushroom(20, -51);  
    Coin coin (-50, -50);
    RegBlock block(20, -43);
    Power_Star star(90, -40);
    QuesBlock question(116, -67);
    World_1_1* w1_1 = new World_1_1();

    //The main loop
    while(true)
    {
         
        game->update(mario);
        mario.update();
        goomba.update(mario);
        mushroom.update(mario);
        flower.update(mario);
        coin.update(mario);
        block.update(mario);
        question.update(mario);
        bn::core::update();

    }
}
