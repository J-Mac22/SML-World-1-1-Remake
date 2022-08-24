/*
CLASS for Level
*/

#ifndef LEVEL_BN_GRAPHIC
#define LEVEL_BN_GRAPHIC

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_camera_ptr.h"
#include "bn_camera_actions.h"
#include "bn_fixed_rect.h"

#include "sml_items.h"
#include "sml_enemies.h"
#include "sml_blocks.h"
#include "sml_power_star.h"
#include "sml_superball.h"
#include "bn_vector.h"

class Mario;

class Level {

protected:

//Background for the level
bn::regular_bg_ptr _background;

//Camera for the level
bn::camera_ptr _camera;

//Parts of the level
bn::vector<Items*, 100> _itemEvents;
bn::vector<Enemies*, 100> _enemyEvents;
bn::vector<bn::fixed_rect, 100> _levelRectangles;
bn::vector<bn::fixed_rect, 5> _levelHurtBox; 
bn::vector<Blocks, 21> _block; //change number after watching gameplay

//Will hold a superball temporarily
bn::vector<Superball, 1> _superball;

public:

/**
 NAME:
 Level()

 SYNOPSIS:
 Level::Level (bn::regular_bg_ptr backPicture, bn::vector<SML_Items*, 100> items, bn::vector<SML_Enemies*, 100> enemies,
 bn::vector<bn::fixed_rect, 100> levelRectangles, bn::vector<bn::fixed_rect, 50> hurtBox, bn::vector<SML_Blocks, 12> levelBlocks,
 bn::fixed cameraX, bn::fixed cameraY);
 backPicture -> The image used for the background.
 cameraX -> Camera X position
 cameraY -> Camera Y position

 DESCRIPTION:
 A constructor that will initialize the background and the camera for the game.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

Level(bn::regular_bg_ptr backPicture, bn::fixed cameraX, bn::fixed cameraY) :
    _background(backPicture),
    _camera(bn::camera_ptr::create(cameraX, cameraY))

{       

    //Add collision boxes to the top of the blocks
    for(int i = 0; i < _block.size(); i++) {

    _levelRectangles.push_back(_block[i].make_topHitBox());

    }

    //For the boxes that have collision, add hurtboxes to them
    for(int i = 0; i < _levelHurtBox.size(); i++) {

    _levelRectangles.push_back(_levelHurtBox[i]);

    }

//Set camera
_background.set_camera(_camera);

}
 
/**
 NAME:
 ~Level

 SYNOPSIS:
 virtual Level::~Level();

 DESCRIPTION:
 Will call upon the virtual destructor for the level.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

virtual ~Level() = default;

 /**
 NAME:
 placeEnemies

 SYNOPSIS:
 virtual void Level::placeEnemies();

 DESCRIPTION:
 This function will populate the level map with
 enemies who will be in their original spots from the game.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

virtual void placeEnemies() {}

//For dynamic loading
//check mario's location each update
//is the camera boundary touching an area where this thing should be?
//yes? create it. no? next thing.
//is mario outside current item/enemy's area?
//yes? delete it. no? next thing.

/**
 NAME:
 update

 SYNOPSIS:
 virtual int Levels::update(Mario &mario);

 DESCRIPTION:
 Updates the level and determines whether or not
 it should be reset.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 0
 */

virtual int update (Mario &mario) { return false; } //Placeholder

};

#endif