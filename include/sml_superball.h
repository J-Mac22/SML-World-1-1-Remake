/*
Class for the Superball spheres
*/

#ifndef SML_SUPERBALL_H
#define SML_SUPERBALL_H

#include "bn_sprite_items_superball.h"
#include "bn_sound_item.h"
#include "bn_music_item.h"
#include "bn_music_actions.h"
#include "bn_sprite_animate_actions.h"

#include "bn_fixed_rect.h"
#include "bn_fixed_point.h"
#include "bn_fixed_size.h"

#include "sml_mario.h"
#include "sml_flower.h"

class Superball : public Flower {

protected:
//Information about the superball
const bn::sprite_item& _body_item;
bn::sprite_ptr _ball_ptr;
bn::fixed_point _position;
bn::fixed_size _dimensions;
 
public:

/**
 NAME:
 Superball

 SYNOPSIS:
 Superball::Superball();

 DESCRIPTION:
 A constructor for the Superball object.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None

 */

Superball(bn::sprite_item sprite_item, bn::fixed positionX, bn::fixed positionY); 

/**
 NAME:
 ~Superball

 SYNOPSIS:
 Superball::~Superball();

 DESCRIPTION:
 A virtual destructor for the Superball object.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

virtual ~Superball() = default;

//Creating superball sprite
bn::sprite_ptr make_superball_sprite (bn::sprite_item _ballSprite, bn::fixed posX, bn::fixed posY);

//Creating superball dimensions
bn::fixed_size make_superball_dims(bn::fixed length, bn::fixed width);

/**
 NAME:
 update

 SYNOPSIS:
 bool update(Mario &mario);

 DESCRIPTION:
 Update the Superball sphere's animation
 and position. Will return whether it should
 be deleted or not.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bool
 */

bool update (Mario &mario);

};

#endif