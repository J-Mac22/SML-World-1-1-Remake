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

//Have the mushroom move
//First, have the position be synchronized
bn::fixed moveTemp = mario.getSpeed();
Mario_States _mstates;

//Change back to Mario
bool walk = _mstates.isWalking();
bool marioMove = mario.getMove();

//Now initiate movement
if (bn::keypad::left_held() && walk && marioMove) {

    _item_ptr.set_x(_item_ptr.x() + moveTemp);
    _position.set_x(_item_ptr.x() + moveTemp);

}

else if (bn::keypad::right_held() && walk && marioMove) {

    _item_ptr.set_x(_item_ptr.x() - moveTemp);
    _position.set_x(_item_ptr.x() - moveTemp);

}

else {

if (moveTemp >= 0.1 && marioMove) {

    if (mario.getHorizontalFlip()) {

        _item_ptr.set_x(_item_ptr.x() + moveTemp);
        _position.set_x(_item_ptr.x() + moveTemp);

    }

    else {

        _item_ptr.set_x(_item_ptr.x() - moveTemp);
        _position.set_x(_item_ptr.x() - moveTemp);

    }

  }

}

//Have Mario's collision be checked
if (bodyRectangles.intersects(marioHitbox)) {

//Have Mario change his form, play the sound, and delete the item
mario.change_item_sprites(item);
bn::sound_items::powerup.play(0.5);
return true;
 
}

else {

return false;

}
 
}