/*
CLASS for Power Star
*/

#ifndef SML_POWER_STAR_H
#define SML_POWER_STAR_H

#include "sml_items.h"
#include "bn_sprite_items_power_star.h"
#include "bn_fixed.h"

class Power_Star : public Items {

public:
/**
 NAME:
 Power_Star

 SYNOPSIS:
 Power_Star::Power_Star();

 DESCRIPTION:
 A constructor that will initialize the sprite, animation, and name of the Power Star.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

Power_Star(bn::fixed positionX, bn::fixed positionY);

/**
 NAME:
 ~Power_Star

 SYNOPSIS:
 virtual Power_Star::~Power_Star();

 DESCRIPTION:
 A virtual destructor for the Superball Flower.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

virtual ~Power_Star() = default;

/**
 NAME:
 update

 SYNOPSIS:
 bool Power_Star::update(Mario &mario);

 DESCRIPTION:
 This function will update both the Power Star's
 animation and position.  It will return whether the Power Star should  
 be deleted or not.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bool
 */

 bool update(Mario &mario);

};

#endif