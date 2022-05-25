/*
DERIVED CLASS for World 1-1
*/

#ifndef SML_WORLD_1_1_H
#define SML_WORLD_1_1_H

#include "bn_core.h"
#include "sml_levels.h"

#include "bn_regular_bg_ptr.h"
//#include "bn_regular_bg_items_world1_1.h"
#include "bn_fixed.h"
#include "bn_sprite_items_mario.h"
 

class SML_World_1_1 : public SML_Levels {

private:
bn::fixed backX = 0;
bn::fixed backY = 0;

public:

/**
NAME:
SML_World_1_1

SYNOPSIS:
SML_World_1_1::SML_World_1_1();

DESCRIPTION:
Will call upon the Levels constructor and then passes a background to it.

AUTHOR:
Jack Machiaverna

RETURNS:
None
*/
  
SML_World_1_1();

/**
 NAME:
 ~SML_WORLD_1_1

 SYNOPSIS:
 virtual SML_World_1_1::~SML_World_1_1()
 
 DESCRIPTION:
 Will call upon the virtual destructor for World1_1.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

virtual ~SML_World_1_1() = default;

/**
 NAME:
 update
 
 SYNOPSIS:
 bool SML_World_1_1::update (SML_Mario &mario);
 mario -> A reference to the player

 DESCRIPTION:
 This function will update the current state of the level.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 A boolean for whether the level is complete or not.
 */

bool update(SML_Mario &mario);

};

#endif