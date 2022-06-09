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
#include "bn_vector.h"
#include "bn_sprite_items_mario.h"

 
class World_1_1 : public Levels {

private:
bn::fixed backX = 0;
bn::fixed backY = 0;

public:

/**
NAME:
World_1_1

SYNOPSIS:
World_1_1::World_1_1();

DESCRIPTION:
Will call upon the Levels constructor and then passes a background to it.

AUTHOR:
Jack Machiaverna

RETURNS:
None
*/
  
World_1_1();

/**
 NAME:
 ~WORLD_1_1

 SYNOPSIS:
 virtual World_1_1::~World_1_1()
 
 DESCRIPTION:
 Will call upon the virtual destructor for World1_1.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

virtual ~World_1_1() = default;

/**
 NAME:
 adjust_rectangles

 SYNOPSIS:
 void Mario::adjust_rectangles(bn::vector<bn::fixed_rect, 100> &rectangles, Mario &mario);

 DESCRIPTION:
 This will adjust the invisible rectangles into a vector
 with Mario's position in the level.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bn::vector <SML_Items*, 100>
 */

void adjust_rectangles(bn::vector<bn::fixed_rect, 100> &rectangles, Mario &mario);

/**
 NAME:
 populateHitBoxes

 SYNOPSIS:
 bn::vector<bn::fixed_rect, 100> populateHitBoxes();

 DESCRIPTION:
 This will populate the level map with geometry hitboxes
 so Mario will obtain damage when he makes contact with them.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bn::vector<bn::fixed_rect, 100>
 */

bn::vector<bn::fixed_rect, 100> populateHitBoxes();

/**
 NAME:
 populateGeo

 SYNOPSIS:
 bn::vector<bn::fixed_rect, 100> World_1_1::populateGeo();

 DESCRIPTION:
 This will populate the level map with geometry hitboxes
 so that Mario, the items, and the enemies that are not in place
 won't clip through.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bn::vector<bn::fixed_rect, 100>
 */

bn::vector<bn::fixed_rect, 100> populateGeo();

/**
 NAME:
 update
 
 SYNOPSIS:
 bool World_1_1::update (Mario &mario);
 mario -> A reference to player

 DESCRIPTION:
 This function will update the current state of the level.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 A boolean for whether the level is complete or not.
 */

bool update(Mario &mario);

};

#endif