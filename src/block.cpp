/*
CPP for Blocks
*/

#include "sml_blocks.h"
#include "sml_mario.h"
#include "sml_mario_states.h"

#include "bn_fixed.h"
#include "bn_fixed_rect.h"
#include "bn_keypad.h"
#include "bn_sound_items.h"

//Constructor
Blocks::Blocks(bn::sprite_item sprite_item, bn::fixed positionX, 
                bn::fixed positionY) :

    _body_item(sprite_item),
    _block_ptr(make_block_sprite(_body_item, positionX, positionY)),
    _position(positionX, positionY)
{}

//Creating the block sprite
bn::sprite_ptr Blocks::make_block_sprite (bn::sprite_item _block, bn::fixed posX, bn::fixed posY) {

    bn::sprite_builder builder(_block);
    builder.set_position(posX, posY);
    return builder.release_build();

}

//Creating the dimensions for the block
bn::fixed_size Blocks::make_block_dims(bn::fixed length, bn::fixed width) {

    bn::fixed_size dim(length, width);
    return dim;

}

//Creating the hitbox for the block
bn::fixed_rect Blocks::make_hitbox() {

    bn::fixed_rect hitbox(_position, _dimensions);
    return hitbox;

}

bn::fixed_rect Blocks::make_topHitBox() {

bn::fixed_rect spriteTop(bn::fixed_point(_position.x(), make_hitbox().top() - 15), bn::fixed_size(8, 8)); //WIP
return spriteTop;

}