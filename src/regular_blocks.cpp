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

//Update function
bool RegBlock::update(Mario &mario) {

//Have Butano draw rectangles to check collision
bn::fixed_rect bodyRectangles(_position, _dimensions);
bn::fixed_rect marioHitbox = mario.make_hitbox();
bn::vector<Blocks, 21> block;

//Have Mario's collision be checked
if (bodyRectangles.intersects(marioHitbox)) {

mario.inspect_block_collision(block);
 
}

//Deleting block once hit
block.clear();

return true;

}