/*
CPP for Power Star
*/

#include "sml_power_star.h"
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

//Have the Power Star's animation be continually updated
_animate_action.update();

//Have Butano draw rectangles to check collision
bn::fixed_rect bodyRectangles(_position, _dimensions);
bn::fixed_rect marioHitbox = mario.make_hitbox();

//Will go into game class
return false;

}