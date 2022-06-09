/*
DERIVED CLASS FOR SUPERBALL FLOWER
*/

#ifndef SML_FLOWER_H
#define SML_FLOWER_H

#include "sml_items.h"
#include "bn_sprite_items_superball_flower.h"
#include "bn_fixed.h"

class Flower : public Items {

public:
/**
  NAME:
  Flower

  SYNOPSIS:
  Flower::Flower();

  DESCRIPTION:
  A constructor that will initialize the sprite, animation, and name of the Superball Flower.

  AUTHOR:
  Jack Machiaverna

  RETURNS:
  None
 */

  Flower(bn::fixed positionX, bn::fixed positionY);

/**
   NAME:
   ~Flower

   SYNOPSIS:
   virtual Flower::~Flower();

   DESCRIPTION:
   A virtual destructor for the Superball Flower.

   AUTHOR:
   Jack Machiaverna

   RETURNS:
   None
*/

   virtual ~Flower() = default;

/**
   NAME:
   update

   SYNOPSIS:
   bool Flower::update(Mario &mario);

   DESCRIPTION:
   This function will update both the Superball Flower's 
   animation and position.  It will return whether the flower should  
   be deleted or not.

   AUTHOR:
   Jack Machiaverna

   RETURNS:
   bool
 */

   bool update(Mario &mario);

}

#endif