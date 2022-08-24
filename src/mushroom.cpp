/*
CPP for Mushroom
*/

#include "sml_mushroom.h"
#include "sml_mario.h"
#include "sml_mario_states.h"

#include "bn_fixed.h"
#include "bn_fixed_rect.h"
#include "bn_keypad.h"
#include "bn_sound_items.h"

//Constructor for mushroom
Mushroom::Mushroom(bn::fixed positionX, bn::fixed positionY) :
Items(bn::sprite_items::mushroom, positionX, positionY)
{}

//Updating the mushroom
bool Mushroom::update(Mario &mario) {

//Have Butano draw rectangles to check collision
bn::fixed_rect bodyRectangles(_position, _dimensions);
bn::fixed_rect marioHitbox = mario.make_hitbox();
Items* item;

//Have Mario's collision be checked
if (bodyRectangles.intersects(marioHitbox)) {

mario.change_item_sprites(item);
 
}

else {

//Deleting mushroom
 

}

return true;

}