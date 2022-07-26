/*
CLASS for Enemies
*/

#ifndef SML_ENEMIES_H
#define SML_ENEMIES_H

#include "bn_sprite_builder.h"
#include "bn_sound_item.h"
#include "bn_music_item.h"
#include "bn_music_actions.h"
#include "bn_sprite_animate_actions.h"
#include "sml_mario.h"

class Enemies {

protected:
const bn::sprite_item& _body_item;
bn::sprite_ptr _enemy_ptr;
bn::sprite_cached_animate_action<2> _animate_action;
bn::fixed_point _position;
bn::fixed_size _dimensions;
std::string _name; 

public:

/**
 NAME:
 Enemies

 SYNOPSIS:
 Enemies::Enemies(bn::sprite_item sprite_item, bn::fixed positionX, bn::fixed positionY,
                          bn::fixed length, bn::fixed width, std::string name);

 sprite_item -> The sprite for the enemy
 positionX  -> Sprite X position
 positionY  -> Sprite Y position
 length -> The length measurements for the enemy
 width -> The width measurements for the enemy
 name  -> String for name of item

 DESCRIPTION:
 A constructor that initializes the sprite, position, measurements and name for each enemy used in the game.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

 Enemies(bn::sprite_item sprite_item, bn::fixed positionX, bn::fixed positionY,
                          bn::fixed len, bn::fixed wid);

/**
 NAME:
 ~Enemies

 SYNOPSIS:
 virtual Enemies::~Enemies();

 DESCRIPTION:
 Will call upon the virtual destructor for enemies.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bool
 */

virtual ~Enemies() = default;

/**
 NAME:
 make_enemy_dims

 SYNOPSIS:
 bn::fixed_size Enemies::make_enemy_dims(bn::fixed length, bn::fixed width);
 length -> The length of the sprite's measurements
 width -> The width of the sprite's measurements

 DESCRIPTION:
 A function that creates the dimensions for the enemies planned to be included in the game.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 dim

 */

bn::fixed_size make_enemy_dims(bn::fixed length, bn::fixed width);

/**
 NAME:
 make_enemy_animation

 SYNOPSIS:
 bn::sprite_cached_animate_action<2> Enemies::make_enemy_animation();

 DESCRIPTION:
 A function that will create a enemy's overall basic movement animations.

 AUTHOR:
 Jack Machiaverna 

 RETURNS:
 bn::create_sprite_cached_animate_action_forever
 */

bn::sprite_cached_animate_action<2> make_enemy_animation();

/**
 NAME:
 make_enemy_sprite

 SYNOPSIS:
 bn::sprite_ptr Enemies::make_enemy_sprite(bn::sprite_item item, bn::fixed positionX, bn::fixed positionY);
 item -> The sprite body item
 positionX -> The sprite's X position
 posiitonY -> The sprite's Y position

 DESCRIPTION:
 A function that creates a sprite for each enemy character.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 builder.release_build()

 */

bn::sprite_ptr  make_enemy_sprite(bn::sprite_item item, bn::fixed positionX, bn::fixed positionY);

/**
 NAME:
 make_hitbox

 SYNOPSIS:
 bn::fixed_rect make_hitbox();

 DESCRIPTION:
 This function will create a hitbox for the item
 by utilizing both its' dimensions and position.
 
 AUTHOR:
 Jack Machiaverma

 RETURNS:
 bn::fixed_rect 
 */

bn::fixed_rect make_hitbox();

/**
 NAME:
 make_tophitBox

 SYNOPSIS:
 bn::fixed_rect Enemies::make_tophitBox();

 DESCRIPTION:
 Function that creates the top hitbox for enemies.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bn::fixed_rect
 */

bn::fixed_rect make_topHitBox();

/**
 NAME:
 getName

 SYNOPSIS:
 std::string getName();

 DESCRIPTION:
 This function will return the enemy's name.

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
 A virtual function that will update the enemy.
 This will also return whether the enemy should be
 deleted or not.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bool
 */

virtual bool update(Mario &) { return false; };

};

#endif