/*
CPP for Goomba
*/

#include "sml_goomba.h"
#include "sml_mario.h"
#include "sml_mario_states.h"  
#include "bn_fixed.h"
#include "bn_fixed_rect.h"
#include "bn_sound_items.h"
#include "bn_keypad.h"

//Constructor for Goomba
Goomba::Goomba(bn::fixed positionX, bn::fixed positionY) :
Enemies(bn::sprite_items::goomba, positionX, positionY, 16, 16)
{}


/*
//For updating the Goomba
bool Goomba::update(Mario &mario) {

//Have the position become synchronized
bn::fixed moveTemp = mario.getSpeed();
//bool walk = mario.isWalking();





};
*/

//Will put more functions once I figure states out