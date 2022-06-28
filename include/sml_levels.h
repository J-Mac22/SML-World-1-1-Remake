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
#include "sml_blocks.h"
#include "sml_power_star.h"
#include "sml_superball.h"
#include "bn_vector.h"

class Mario;

class Level {

protected:

//Background for the level
bn::regular_bg_ptr _background;

//Parts of the level
bn::vector <Items*, 100> _itemEvents;
bn::vector<Enemies*, 100> _enemyEvents;
bn::vector<bn::fixed_rect, 100> _levelRectangles;
bn::vector<bn::fixed_rect, 5> _levelHurtBox; 
bn::vector<Blocks, 21> _block; //change number after watching gameplay

//Camera for the level
bn::camera_ptr _camera;

//Will hold a superball temporarily
bn::vector<Superball, 1> _superball;

//Power Star collectible
Power_Star _star;

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

Level(bn::regular_bg_ptr backPicture, bn::vector<Items*, 100> items, bn::vector<Enemies*, 100> enemies,
bn::vector<bn::fixed_rect, 100> levelRectangles, bn::vector<bn::fixed_rect, 5> hurtBox, bn::vector<Blocks, 21> levelBlocks,
Power_Star star, bn::fixed cameraX, bn::fixed cameraY) :

    _background(backPicture),
    _itemEvents(items),
    _enemyEvents(enemies),
    _levelRectangles(levelRectangles),
    _levelHurtBox(hurtBox),
    _block(levelBlocks),
    _camera(bn::camera_ptr::create(cameraX, cameraY)),
    _star(star)

{
    //Add collision boxes later (if statement) (maybe hurtboxes?)
    for(int i = 0; i < _block.size(); i++) {

    //_levelRectangles.push_back(_block[i])

    }

    for(int i = 0; i < _levelHurtBox.size(); i++) {

   //_levelRectangles.push_back(_levelHurtbox[i]);

    }

    //Set the camera
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

virtual bool update (Mario &mario) { return false; } //Placeholder

};

#endif