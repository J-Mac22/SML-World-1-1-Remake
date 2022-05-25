/*
CLASS for Level
*/

#ifndef LEVEL_BN_GRAPHIC
#define LEVEL_BN_GRAPHIC

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_camera_actions.h"
#include "bn_fixed_rect.h"

#include "sml_items.h"
#include "sml_enemies.h"
#include "bn_vector.h"

class SML_Mario;

class SML_Level {

protected:
//Background for the level
bn::regular_bg_ptr _background;

//Camera for the level
bn::camera_ptr _camera;

//Parts of the level
bn::vector <SML_Items*, 100> _itemEvents;
bn::vector<SML_Enemies*, 100> _enemyEvents;
bn::vector<bn::fixed_rect, 100> _levelRect;
bn::vector<bn::fixed_rect, 100> _levelHurtBox;

public:

/**
 NAME:
 SML_Level()

 SYNOPSIS:
 SML_Level::SML_Level(bn::regular _bg_ptr backPicture);
 backPicture -> The image used for the background.

 DESCRIPTION:
 A constructor that will initialize the background and the camera for the game.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

SML_Level(bn::regular_bg_ptr backPicture) {

    _background(backPicture),
    _camera(bn::camera_ptr::create(-1670, 32));

};

/**
 NAME:
 ~SML_Level

 SYNOPSIS:
 virtual SML_Level::~SML_Level();

 DESCRIPTION:
 Will call upon the virtual destructor for the level.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

virtual ~SML_Level() = default;

/**
 NAME:
 placeEnemies

 SYNOPSIS:
 virtual void SML_Level::placeEnemies();

 DESCRIPTION:
 This function will populate the level map with
 enemies who will be in their original spots from the game.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

virtual void placeEnemies() {}

/**
 NAME:
 update

 SYNOPSIS:
 virtual int SML_Levels::update(SML_Mario &mario);

 DESCRIPTION:
 Updates the level and determines whether or not
 it should be reset.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 0
 */

virtual int update (SML_Mario &mario) { return 0; }

};

#endif