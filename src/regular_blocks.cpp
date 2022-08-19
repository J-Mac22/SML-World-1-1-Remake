/*
CPP for Regular Blocks
*/

#include "sml_regular_blocks.h"
#include "sml_mario.h"
#include "sml_mario_states.h"

#include "bn_fixed.h"
#include "bn_fixed_rect.h"
#include "bn_keypad.h"
#include "bn_sound_items.h"

//Constructor for regular blocks
RegBlock::RegBlock(bn::fixed positionX, bn::fixed positionY) :
Blocks(bn::sprite_items::block, positionX, positionY)
{}