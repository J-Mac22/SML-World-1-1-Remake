/*
DERIVED CLASS FOR MUSHROOM
*/

#ifndef SML_MUSHROOM_H
#define SML_MUSHROOM_H

#include "bn_sprite_items_mushroom.h"
#include "bn_fixed.h"
#include "sml_items.h"

class SML_Mushroom : public SML_Items {

    public:

        /**
         NAME:
         SML_Mushroom

         SYNOPSIS:
         SML_Mushroom::SML_Mushroom(bn::fixed positionX, bn::fixed positionY)

         DESCRIPTION:
         A constructor that initializes the mushroom's sprite, animation, and name.

         AUTHOR:
         Jack Machiaverna

         RETURNS:
         None
        */

        SML_Mushroom(bn::fixed positionX, bn::fixed positionY);

        /**
         NAME:
         ~SML_Mushroom

         SYNOPSIS:
         virtual SML_Mushroom::~SML_Mushroom()

         DESCRIPTION:
         A virtual destructor for the mushroom.

         AUTHOR:
         Jack Machiaverna

         RETURNS:
         None
        */

        virtual ~SML_Mushroom() = default;

        /**
         NAME:
         update

         SYNOPSIS:
         bool SML_Mushroom::update(SML_Mario &mario);

         DESCRIPTION:
         Update the mushroom's animation and position.
         Returns whether or not the mushroom should be
         deleted from the game.

         AUTHOR:
         Jack Machiaverna

         RETURNS:
         bool
       */

      bool update(SML_Mario &mario);

};

#endif