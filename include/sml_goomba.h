/*
DERIVED CLASS FOR GOOMBA
*/

#ifndef SML_GOOMBA_H
#define SML_GOOMBA_H

#include "bn_sprite_items_goomba.h"
#include "bn_fixed.h"
#include "sml_enemies.h"

class SML_Goomba : public SML_Enemies {

    public:
    /**
     NAME:
     SML_Goomba

     SYNOPSIS:
     SML_Goomba::SML_Goomba(bn::fixed positionX, bn::fixed positionY);

     DESCRIPTION:
     A constructor that initializes the Goomba's sprite, animation, and name.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
    */

    SML_Goomba(bn::fixed positionX, bn::fixed positionY);

    /**
     NAME:
     ~SML_Goomba

     SYNOPSIS:
     virtual SML_Goomba::~SML_Goomba();

     DESCRIPTION:
     A destructor that will destroy the Goomba object after it has been defeated by Mario.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
    */

    virtual ~SML_Goomba() = default;

    /**
     NAME:
     update

     SYNOPSIS:
     bool SML_Goomba::update(SML_Mario &mario);

     DESCRIPTION:
     Update the Goomba's animation and position.
     Will return  whether or not the Goomba should
     be deleted.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     bool
    */

   bool update(SML_Mario &mario);

};
#endif