/*
DERIVED CLASS FOR MUSHROOM
*/

#ifndef SML_MUSHROOM_H
#define SML_MUSHROOM_H

#include "bn_sprite_items_mushroom.h"
#include "bn_fixed.h"
#include "sml_items.h"

class Mushroom : public Items {

    public:

        /**
         NAME:
         Mushroom

         SYNOPSIS:
         Mushroom::Mushroom(bn::fixed positionX, bn::fixed positionY)

         DESCRIPTION:
         A constructor that initializes the mushroom's sprite, animation, and name.

         AUTHOR:
         Jack Machiaverna

         RETURNS:
         None
        */

        Mushroom(bn::fixed positionX, bn::fixed positionY);

        /**
         NAME:
         ~Mushroom

         SYNOPSIS:
         virtual Mushroom::~Mushroom()

         DESCRIPTION:
         A virtual destructor for the mushroom.

         AUTHOR:
         Jack Machiaverna

         RETURNS:
         None
        */

        virtual ~Mushroom() = default;

        /**
         NAME:
         update

         SYNOPSIS:
         bool Mushroom::update(Mario &mario);

         DESCRIPTION:
         Update the mushroom's animation and position.
         Returns whether or not the mushroom should be
         deleted from the game.

         AUTHOR:
         Jack Machiaverna

         RETURNS:
         bool
       */

      bool update(Mario &mario);

};

#endif