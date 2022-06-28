/*
CPP for Power Star
*/

#include "sml_power_star.h"
#include "sml_mario.h"
#include "sml_mario_states.h"

#include "bn_fixed.h"
#include "bn_fixed_rect.h"
#include "bn_keypad.h"
#include "bn_sound_items.h"

//Constructor for Power Star
Power_Star::Power_Star(bn::fixed positionX, bn::fixed positionY) :
Items(bn::sprite_items::power_star, positionX, positionY)
{}

//Updating the Power Star
bool Power_Star::update(Mario &mario) {

//WIP


}