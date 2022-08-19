/*
CLASS for Items
*/

#ifndef SML_ITEMS_H
#define SML_ITEMS_H

#include "bn_sprite_builder.h"
#include "bn_sound_item.h"
#include "bn_music_item.h"
#include "bn_music_actions.h"
#include "bn_sprite_animate_actions.h"

#include "bn_fixed_rect.h"
#include "bn_fixed_point.h"
#include "bn_fixed_size.h"

#include "sml_mario.h"

class Items {

protected:
//Information about the sprite
const bn::sprite_item& _body_item;
bn::sprite_ptr _item_ptr;
bn::sprite_cached_animate_action<2> _animate_action;
bn::fixed_point _position;
bn::fixed_size _dimensions;
std::string _name; 
 
public:

/**
 NAME:
 Items
 
 SYNOPSIS:
 Items::Items(bn::sprite_item sprite_item, bn::fixed positionX, bn::fixed positionY, std::string name);
 sprite_item -> The sprite for the item
 positionX  -> Sprite X position
 positionY  -> Sprite Y position
 name  -> String for name of item

 DESCRIPTION:
 A constructor that initializes the sprite, position, and name for each item used in the game.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

Items(bn::sprite_item sprite_item, bn::fixed positionX, bn::fixed positionY);

/**
 NAME:
 ~Items

 SYNOPSIS:
 virtual Items::~Items();

 DESCRIPTION:
 Will call upon the virtual destructor for items.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */
 
virtual ~Items() = default;

/**
  NAME:
  make_item_sprite
 
  SYNOPSIS:
  bn::sprite_ptr Items::make_item_sprite (bn::sprite_item item, bn::fixed xPosition, bn::fixed yPosition);
  item -> The body item for the sprite
  xPosition -> Sprite X position
  yPosition -> Sprite Y position

  DESCRIPTION:
  This will create the sprite for each item.

  AUTHOR:
  Jack Machiaverna

  RETURNS:
  bn::sprite_ptr 
 */

bn::sprite_ptr make_item_sprite (bn::sprite_item _item, bn::fixed posX, bn::fixed posY);

/**
 NAME:
 make_item_animation

 SYNOPSIS:
 bn::sprite_cached_animate_action<2> Items::_make_item_animation();

 DESCRIPTION:
 A helper function that will create an animation for the item.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bn::sprite_cached_animate_action<2> 
 */

bn::sprite_cached_animate_action<2> _make_item_animation();

/**
 NAME:
 make_item_dims
 
 SYNOPSIS:
 bn::fixed_size Items::make_item_dims(bn::fixed length, bn::fixed width);
 length -> Length of sprite
 width -> Width of sprite

 DESCRIPTION:
 A helper function that will define the dimensions for each item.
 This could be used for help with collision detection later.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bn::fixed_size 
 */

bn::fixed_size make_item_dims(bn::fixed length, bn::fixed width);

/**
 NAME:
 make_hitbox

 SYNOPSIS:
 bn::fixed_rect make_hitbox();

 DESCRIPTION:
 This function will create a hitbox for the item
 by utilizing both its' dimensions and position.
 
 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bn::fixed_rect 
 */

bn::fixed_rect make_hitbox();

/**
 NAME:
 getName

 SYNOPSIS:
 std::string getName();

 DESCRIPTION:
 This function will return the item's name.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 std::string
 */

std::string getName() { return _name; }

/**
 NAME:
 update
 
 SYNOPSIS:
 virtual bool update(Mario &);
 Mario & -> A reference to the Mario object

 DESCRIPTION:
 A virtual function that will update the item.
 This will also return whether the item should be
 deleted or not.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bool
 */

virtual bool update(Mario &) { return false; };

};

#endif