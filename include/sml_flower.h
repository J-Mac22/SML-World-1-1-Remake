/*
DERIVED CLASS FOR SUPERBALL FLOWER
*/

#ifndef SML_FLOWER_H
#define SML_FLOWER_H

#include "sml_items.h"
#include "bn_sprite_items_superball_flower.h"
#include "bn_fixed.h"

class SML_Flower : public SML_Items {

public:
/**
  NAME:
  SML_Flower

  SYNOPSIS:
  SML_Flower::SML_Flower();

  DESCRIPTION:
  A constructor that will initialize the sprite, animation, and name of the Superball Flower.

  AUTHOR:
  Jack Machiaverna

  RETURNS:
  None
 */

  SML_Flower(bn::fixed positionX, bn::fixed positionY);

/**
   NAME:
   ~SML_Flower

   SYNOPSIS:
   virtual SML_Flower::~SML_Flower();

   DESCRIPTION:
   A virtual destructor for the Superball Flower.

   AUTHOR:
   Jack Machiaverna

   RETURNS:
   None
*/

   virtual ~SML_Flower() = default;

/**
   NAME:
   update

   SYNOPSIS:
   bool SML_Flower::update(SML_Mario &mario);

   DESCRIPTION:
   This function will update both the Superball Flower's 
   animation and position.  It will return whether the flower should  
   be deleted or not.

   AUTHOR:
   Jack Machiaverna

   RETURNS:
   bool
 */

   bool update(SML_Mario &mario);

}

#endif