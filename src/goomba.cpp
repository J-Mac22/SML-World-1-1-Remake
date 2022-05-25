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
SML_Goomba::SML_Goomba(bn::fixed positionX, bn::fixed positionY) :
SML_Enemies(bn::sprite_items::goomba, positionX, positionY, 16, 16)
{}

//For updating the Goomba
//bool SML_Goomba::update(SML_Mario &mario);

//Will put more functions once I figure states out