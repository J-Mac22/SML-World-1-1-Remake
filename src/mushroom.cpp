/*
CPP for Mushroom
*/

#include "sml_mushroom.h"
#include "sml_mario.h"
#include "sml_mario_states.h"

#include "bn_fixed.h"
#include "bn_fixed_rect.h"
#include "bn_keypad.h"
#include "bn_sound_items.h"

//Constructor for mushroom
SML_Mushroom::SML_Mushroom(bn::fixed positionX, bn::fixed positionY) :
SML_Items(bn::sprite_items::mushroom, positionX, positionY, "mushroom")
{}




