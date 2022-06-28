/*
CPP for Coin
*/

#include "sml_coin.h"
#include "sml_mario.h"
#include "sml_mario_states.h"

#include "bn_fixed.h"
#include "bn_fixed_rect.h"
#include "bn_keypad.h"
#include "bn_sound_items.h"

//Constructor for Coin
Coin::Coin(bn::fixed positionX, bn::fixed positionY) :
Items(bn::sprite_items::coin, positionX, positionY)
{}
/*
//Updating the coin
bool Coin::update(Mario &mario) {



}
/*