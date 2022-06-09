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

public:

/**
 NAME:
 Blocks

 SYNOPSIS:
 Blocks::Blocks();

 DESCRIPTION:
 Constructs a new block object in the level.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

Blocks();

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