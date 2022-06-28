/*
CPP for Superball Flower
*/

#include "sml_flower.h"
#include "sml_mario.h"
#include "sml_mario_states.h"

#include "bn_fixed.h"
#include "bn_fixed_rect.h"
#include "bn_keypad.h"
#include "bn_sound_items.h"

//Constructor for flower
Flower::Flower(bn::fixed positionX, bn::fixed positionY) :
Items(bn::sprite_items::superball_flower, positionX, positionY)
{}

//Updating the flower
bool Flower::update(Mario &mario) {

//Have the item's animation be continually updated
_animate_action.update();

//Have Butano draw rectangles to check collision
bn::fixed_rect bodyRectangles(_position, _dimensions);
bn::fixed_rect marioHitbox = mario.make_hitbox();

//Have Mario's collision be checked 
if(bodyRectangles.intersects(marioHitbox)) {


//WIP


}

}