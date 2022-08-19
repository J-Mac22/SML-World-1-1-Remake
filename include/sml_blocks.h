/*
CLASS for Blocks
*/

#ifndef SML_BLOCKS_H
#define SML_BLOCKS_H

#include "bn_sound_item.h"
#include "bn_music_item.h"
#include "bn_music_actions.h"
#include "bn_sprite_animate_actions.h"

#include "bn_fixed_rect.h"
#include "bn_fixed_point.h"
#include "bn_fixed_size.h"

#include "sml_mario.h"

class Blocks {

protected:
//Information about the block sprite
const bn::sprite_item& _body_item;
bn::sprite_ptr _block_ptr;
//bn::sprite_cached_animate_action<2> _animate_action;
bn::fixed_point _position;
bn::fixed_size _dimensions;

public:

/**
 NAME:
 Blocks

 SYNOPSIS:
 Blocks::Blocks(bn::sprite_item sprite_item, bn::fixed positionX, bn::fixed positionY);

 DESCRIPTION:
 Constructs a new block object in the level.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

Blocks(bn::sprite_item sprite_item, bn::fixed positionX, bn::fixed positionY);

/**
 NAME:
 ~Blocks

 SYNOPSIS:
 virtual Blocks::~Blocks();

 DESCRIPTION:
 A virtual destructor for the SML_Blocks object.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

virtual ~Blocks() = default;

 /**
  NAME:
  make_block_sprite
 
  SYNOPSIS:
  bn::sprite_ptr Blocks::make_block_sprite (bn::sprite_item block, bn::fixed posX, bn::fixed posY);
  block -> The body item for the sprite
  posX -> Sprite X position
  posY -> Sprite Y position

  DESCRIPTION:
  This will create the sprite for each block.

  AUTHOR:
  Jack Machiaverna

  RETURNS:
  bn::sprite_ptr 
 */
bn::sprite_ptr make_block_sprite (bn::sprite_item _block, bn::fixed posX, bn::fixed posY);

/**
 NAME:
 make_block_dims
 
 SYNOPSIS:
 bn::fixed_size Blocks::make_block_dims(bn::fixed length, bn::fixed width);
 length -> Length of sprite
 width -> Width of sprite

 DESCRIPTION:
 A helper function that will define the dimensions for each block.
 This could be used for help with collision detection later.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bn::fixed_size 
 */
bn::fixed_size make_block_dims(bn::fixed length, bn::fixed width);

/**
 NAME:
 make_hitbox

 SYNOPSIS:
 bn::fixed_rect make_hitbox();

 DESCRIPTION:
 This function will create a hitbox for the block
 by utilizing both its' dimensions and position.
 
 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bn::fixed_rect 
 */

bn::fixed_rect make_hitbox();

//Making top hitbox
bn::fixed_rect make_topHitBox();

/**
 NAME:
 update

 SYNOPSIS:
 bool update(Mario &mario);

 DESCRIPTION:
 Update the block's animation and position.
 Will return whether or not the block should
 be deleted.
 
 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bool
 */

bool update(Mario &mario);

};
#endif