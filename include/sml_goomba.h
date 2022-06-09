/*
DERIVED CLASS FOR GOOMBA
*/

#ifndef SML_GOOMBA_H
#define SML_GOOMBA_H

#include "bn_sprite_items_goomba.h"
#include "bn_fixed.h"
#include "sml_enemies.h"

class Goomba : public Enemies {

    public:
    /**
     NAME:
     Goomba

     SYNOPSIS:
     Goomba::Goomba(bn::fixed positionX, bn::fixed positionY);

     DESCRIPTION:
     A constructor that initializes the Goomba's sprite, animation, and name.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
    */

    Goomba(bn::fixed positionX, bn::fixed positionY);

    /**
     NAME:
     ~Goomba

     SYNOPSIS:
     virtual Goomba::~Goomba();

     DESCRIPTION:
     A destructor that will destroy the Goomba object after it has been defeated by Mario.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
    */

    virtual ~Goomba() = default;

    /**
     NAME:
     update

     SYNOPSIS:
     bool Goomba::update(Mario &mario);

     DESCRIPTION:
     Update the Goomba's animation and position.
     Will return  whether or not the Goomba should
     be deleted.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     bool
    */

   bool update(Mario &mario);

};
#endif