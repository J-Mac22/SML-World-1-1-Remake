/*
DERIVED CLASS FOR QUESTION MARK BLOCKS
*/

#ifndef SML_QUESTION_BLOCKS_H
#define SML_QUESTION_BLOCKS_H

#include "sml_blocks.h"
#include "bn_sprite_items_question_block.h"
#include "bn_fixed.h"

class QuesBlock : public Blocks {

public:
/**
  NAME:
  QuesBlock

  SYNOPSIS:
  QuesBlock::QuesBlock();

  DESCRIPTION:
  A constructor that will initialize the sprite, animation, and name of question mark blocks.

  AUTHOR:
  Jack Machiaverna

  RETURNS:
  None
 */

QuesBlock(bn::fixed positionX, bn::fixed positionY);

/**
   NAME:
   ~QuesBlock

   SYNOPSIS:
   virtual QuesBlock::~QuesBlock();

   DESCRIPTION:
   A virtual destructor for question mark blocks.

   AUTHOR:
   Jack Machiaverna

   RETURNS:
   None
*/

virtual ~QuesBlock() = default;

/**
   NAME:
   update

   SYNOPSIS:
   bool QuesBlock::update(Mario &mario);

   DESCRIPTION:
   This function will update the question mark block's 
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