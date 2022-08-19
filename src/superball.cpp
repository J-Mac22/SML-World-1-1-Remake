/*
CPP for Superball spheres
*/

#include "sml_items.h"
#include "sml_superball.h"
#include "sml_mario.h"
#include "sml_mario_states.h"

#include "bn_fixed.h"
#include "bn_fixed_rect.h"
#include "bn_keypad.h"
#include "bn_sound_items.h"

/*
//Constructor for superball
Superball::Superball(bn::sprite_item sprite_item, bn::fixed positionX,
                            bn::fixed positionY) :

    _body_item(sprite_item),
    _ball_ptr(make_item_sprite(_body_item, positionX, positionY)),
    _position(positionX, positionY)

{}
*/


//Creating the Superball sprite
bn::sprite_ptr Superball::make_superball_sprite (bn::sprite_item _ballSprite, bn::fixed posX, bn::fixed posY) {

    bn::sprite_builder builder(_ballSprite);
    builder.set_position(posX, posY);
    return builder.release_build();

}

//Creating the dimensions for the Superball
bn::fixed_size Superball::make_superball_dims(bn::fixed length, bn::fixed width) {

    bn::fixed_size dim(length, width);
    return dim;

}
 


