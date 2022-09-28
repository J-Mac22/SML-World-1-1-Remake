/*
CPP for Goomba
*/

#include "sml_goomba.h"
#include "sml_mario.h"
#include "sml_mario_states.h"  
#include "bn_fixed.h"
#include "bn_fixed_rect.h"
#include "bn_sound_items.h"
#include "bn_keypad.h"

//Constructor for Goomba 
Goomba::Goomba(bn::fixed positionX, bn::fixed positionY) :
Enemies(bn::sprite_items::goomba, positionX, positionY, 16, 16)
{}

//For updating the Goomba
bool Goomba::update(Mario &mario) {

//Have the position become synchronized
bn::fixed moveTemp = mario.getSpeed();

//For checking Mario's collision
Mario_States _mstates;
bn::fixed_rect bodyRectangles(_position, _dimensions);
bn::fixed_rect marioHitbox = mario.make_hitbox();
Enemies* enemy;

//Change to Mario
bool walk = _mstates.isWalking();
bool marioMove = mario.getMove();

//Have the Goomba move 
if (bn::keypad::left_held() && walk && marioMove) {

_enemy_ptr.set_x(_enemy_ptr.x() + moveTemp);
_position.set_x(_enemy_ptr.x() + moveTemp);

}

else if (bn::keypad::right_held() && walk && marioMove) {

_enemy_ptr.set_x(_enemy_ptr.x() - moveTemp);
_position.set_x(_enemy_ptr.x() - moveTemp);

}

else {

if (moveTemp >= 0.1 && marioMove) {

    if (mario.getHorizontalFlip()) {

        _enemy_ptr.set_x(_enemy_ptr.x() + moveTemp);
        _position.set_x(_enemy_ptr.x() + moveTemp);

   }

    else {

        _enemy_ptr.set_x(_enemy_ptr.x() - moveTemp);
        _position.set_x(_enemy_ptr.x() - moveTemp);

    }

  }

}

//Have Mario's collision be checked
if (bodyRectangles.intersects(marioHitbox)) {

//Have Mario interact with Goomba, play the sound, and delete the sprite
mario.decide_enemy_encounter_outcome(enemy);
bn::sound_items::stomp.play(0.5);
return true;

}

else {

  return false;

}

}