/*
CPP for Question Blocks
*/

#include "sml_question_blocks.h"
#include "sml_mario.h"
#include "sml_mario_states.h"

#include "bn_fixed.h"
#include "bn_fixed_rect.h"
#include "bn_keypad.h"
#include "bn_sound_items.h"

//Constructor for question mark blocks
QuesBlock::QuesBlock(bn::fixed positionX, bn::fixed positionY) :
Blocks(bn::sprite_items::question_block, positionX, positionY)
{}