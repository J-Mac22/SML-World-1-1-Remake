/*
DERIVED CLASS FOR REGULAR BLOCKS
*/

#ifndef SML_REGULAR_BLOCKS_H
#define SML_REGULAR_BLOCKS_H

#include "sml_blocks.h"
#include "bn_sprite_items_block.h"
#include "bn_fixed.h"

class RegBlock : public Blocks {

public:

/**
  NAME:
  RegBlock

  SYNOPSIS:
  RegBlock::RegBlock();

  DESCRIPTION:
  A constructor that will initialize the sprite, animation, and name of regular blocks.

  AUTHOR:
  Jack Machiaverna

  RETURNS:
  None
 */

RegBlock(bn::fixed positionX, bn::fixed positionY);

/**
   NAME:
   ~RegBlock

   SYNOPSIS:
   virtual RegBlock::~RegBlock();

   DESCRIPTION:
   A virtual destructor for regular blocks.

   AUTHOR:
   Jack Machiaverna

   RETURNS:
   None
*/

virtual ~RegBlock() = default;

/**
   NAME:
   update

   SYNOPSIS:
   bool RegBlock::update(Mario &mario);

   DESCRIPTION:
   This function will update the regular block's 
   position.  It will return whether the block should  
   be deleted or not.

   AUTHOR:
   Jack Machiaverna

   RETURNS:
   bool
 */

bool update(Mario &mario);

};

#endif