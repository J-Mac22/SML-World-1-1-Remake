/*
CPP for Mario
*/

#include "sml_mario.h"
#include "sml_coin.h"
#include "bn_sprite_items_super_mario.h"
#include "bn_music_item.h"
#include "bn_sound_items.h"
#include "bn_fixed_size.h"
 
//Constructor
Mario::Mario() :

    _body_sprite_item(bn::sprite_items::mario),
    _mario(make_mario_sprite(_body_sprite_item)),
    _animate_action(make_walk_animation(_mario, _body_sprite_item)),
    _jumpLock(false),
    _position(0, -40),
    _dimensions(16, 16)
{}

//Mario sprite creation
bn::sprite_ptr Mario::make_mario_sprite(const bn::sprite_item& body_sprite_item) {

    bn::sprite_builder builder(body_sprite_item);
    builder.set_position(0, -40);
    return builder.release_build();
}

//Mario walking animation
bn::sprite_cached_animate_action<4> Mario::make_walk_animation(bn::sprite_ptr mario_sprite,
                                                                            const bn::sprite_item& body_sprite) 
{

    return bn::create_sprite_cached_animate_action_forever(
        mario_sprite, 3.2, body_sprite.tiles_item(), 1, 2, 3, 2);
}

//Mario jumping animation 
bn::sprite_cached_animate_action<3> make_jump_animation(bn::sprite_ptr mario_sprite,
                                                                  const bn::sprite_item& body_sprite)
{

    return bn::create_sprite_cached_animate_action_forever( 
        mario_sprite, 3.2, body_sprite.tiles_item(), 0, 4, 0);
}


//Hit-box for Mario
bn::fixed_rect Mario::make_hitbox() {

    bn::fixed_rect hitbox;
    return hitbox;
}

//Top hit-box for Mario
bn::fixed_rect Mario::make_top() {

    bn::fixed_rect spriteTop(bn::fixed_point(_position.x(), make_hitbox().top() - 15), bn::fixed_size(16, 16));
    return spriteTop;
}

//Bottom hit-box for Mario
bn::fixed_rect Mario::make_bottom() {

    bn::fixed_rect spriteBottom(bn::fixed_point(_position.x(), make_hitbox().bottom() + 10), bn::fixed_size(16, 16)); 
    return spriteBottom;
}

//Have Mario move next to the Power Star upon collecting
void Mario::move_next_to_star(bn::fixed_point starPos) {

    bn::fixed pos = starPos.x() - 30;
    _mario.set_x(pos);

}

//Get Mario moving (walking wise)
void Mario::move(bool xCollide, bn::fixed_rect &collisionRect, bn::fixed_rect &standingRect) {

    if(bn::keypad::left_held() && _mstates.isWalking()) {

        _animate_action.update();
        _moving = true;

        //If no collision, move normally
        if(xCollide) {
        
        if(moveTemp <= 1.5) moveTemp += 0.05;

        _mario.set_horizontal_flip(true);
        _mario.set_x(_mario.x() - moveTemp);
        currentX -= moveTemp;

        }

        //If the detected rectangle is the same as the one
        //Mario is on, he will continue to walk. Else, he will stop.
        else {

            if (collisionRect == standingRect) {

                if(moveTemp <= 1.5) moveTemp += 0.05;

                _mario.set_horizontal_flip(true);
                _mario.set_x(_mario.x() - moveTemp);
                currentX -= moveTemp;
            }

            else {

                _moving = false;

            }
        }
    }

    else if(bn::keypad::right_held() && _mstates.isWalking()) {

        _animate_action.update();
        _moving = true;

        //If no collision, move normally
        if (xCollide) {

        if(moveTemp <= 1.5) moveTemp += 0.05;

        _mario.set_horizontal_flip(false);
        _mario.set_x(_mario.x() + moveTemp);
        currentX += moveTemp;

        }

        //If the detected rectangle is the same as the one
        //Mario is on, he will continue to walk. Else, he will stop.
        else {

            if (collisionRect == standingRect) {

                if(moveTemp <= 1.5) moveTemp += 0.05;

                _mario.set_horizontal_flip(false);
                _mario.set_x(_mario.x() + moveTemp);
                currentX += moveTemp;

            }

            else {

                _moving = false;

            }
        }
    }

    //Deceleration
    else {

         //Continue as normal
         if(!xCollide) {

            //Start to decelerate until a point is reached
            //Either add or subtract wherever Mario is looking
            if (moveTemp >= 0.1) {

                moveTemp -= 0.2;

                if(_mario.horizontal_flip()) {

                    _mario.set_x(_mario.x() - moveTemp);
                    currentX -= moveTemp;

                }

                else {

                    _mario.set_x(_mario.x() + moveTemp);
                    currentX += moveTemp;

                }

                _animate_action.update();
                _moving = true;

            }

            else {

                _moving = false;

            }

         }

         //If Mario collides, he will not move 
         else {

            _moving = false;

         }

         //Sprite changes back to standing
         _mario.set_tiles(bn::sprite_items::mario.tiles_item().create_tiles(0));

    }

    //If Mario turns around, restart his speed
    if(bn::keypad::left_pressed() || bn::keypad::right_pressed()) {

        moveTemp = 0.1;

    }
     
}

//Get Mario to jump
void Mario::jump(bool yCollide) {

    if (_mstates.isJumping()) {

    //Set the conditions for the jump
    _jumpLock = true;
    _mario.set_tiles(bn::sprite_items::mario.tiles_item().create_tiles(4));
    _mario.set_y(_mario.y() - gravity);
    _position.set_y(_mario.y());
    gravity -= 0.25;

    if (gravity <= 0.0) {

        _mstates.updateJumping(true);
        _mstates.updateFalling(false);

    }

    }

    //For falling
    else if (_mstates.isFalling() && gravity < TOP_GRAV) {

        //Getting gravity to increase
        _mario.set_tiles(bn::sprite_items::mario.tiles_item().create_tiles(4));
        _mario.set_y(_mario.y() + gravity);
        gravity += 0.25;

        //Extra oomph when falling
        if (gravity == TOP_GRAV) _mario.set_y(_mario.y() + TOP_GRAV);

        //Sprite changes back to standing
        if (_mario.y() >= 40) {

        _mario.set_tiles(bn::sprite_items::mario.tiles_item().create_tiles(0));
        _jumpLock = false;

        }
    }
}

//For Mario's encounter with a Goomba
void Mario::decide_enemy_encounter_outcome(Enemies* &enemies) {

std::string enemyTitle;

if (enemyTitle == "goomba") {

    //For when Mario falls or makes collision with the ground
    if (_mstates.isFalling()) {

        if (_jumpLock) {

            bn::fixed_rect goombaTop = make_top();
            bn::fixed_rect marioBox = make_hitbox();

            //After Mario stomps on Goomba, he will hop off it
            if (marioBox.intersects(goombaTop)) {

                _mstates.updateJumping(true);
                _mstates.isFalling();
                gravity = 2;
                return;

            }

        }

        //If Mario touches the Goomba without stomping, he will take damage
        else {

            if (!enemies) {

                _level--;
                _inFrames = 120;
                if (_level != -1) bn::sound_items::powerdown.play(0.5);
                change_level_sprites();

            }
        }
    }
}
}

//To look out for block collisions
bool Mario::inspect_block_collision(bn::vector<Blocks, 21> &block) {

    std::string blockTitle;
    bn::fixed_rect hitBox = make_hitbox();

    //WIP
    if (blockTitle == "regular") {

        //For when Mario jumps and hits the block
        if (_mstates.isJumping()) {

            if (_jumpLock) {

                bn::fixed_rect marioBox;

                //If Mario makes contact with the block, it will dissappear
                if (marioBox.intersects(hitBox)) {

                    _mstates.updateJumping(true);

                }

            }

        }

    }

}

//Change sprites and (depending on certain conditions) level from item obtained
void Mario::change_level_sprites() {

    switch (_level) {

        //Small Mario
        case 0:
            _body_sprite_item = bn::sprite_items::mario;
            _mario.set_item(_body_sprite_item);
            break;

        //Super Mario
        case 1:
            _body_sprite_item = bn::sprite_items::super_mario;
            _mario.set_item(_body_sprite_item);
            break;

        //Superball Mario
        case 2:
            _body_sprite_item = bn::sprite_items::super_mario; //Same sprite as Super Mario
            _mario.set_item(_body_sprite_item);
            break;

        //For when Mario dies and loses a life
        default:
            _lostLife = true;
            _mario.set_tiles(bn::sprite_items::mario.tiles_item().create_tiles(5));
            break;
    }
    }

//Based on the item collection, change the sprites and/or the level
void Mario::change_item_sprites(Items* &item) {

    std::string itemTitle;

    //Turn into Super Mario after eating Super Mushroom
    if (itemTitle == "mushroom") {

        if (_level <= 1) _level = 1;
        change_level_sprites();

    }

    //Turn into Superball Mario after eating Superball Flower
    else if (itemTitle == "flower") {

        if (_level <= 2) _level = 2;
        change_level_sprites();

    }
}

//Checking for Mario's X collision
bool Mario::checkX(bn::vector<bn::fixed_rect, 100> _levelRectangles) {

    bn::fixed_rect marioBox = make_hitbox();

    //Check to see if Mario is colliding with the X axis
    for (int i = 0; i < _levelRectangles.size(); i++) {

        if (marioBox.intersects(_levelRectangles[i])) {

            return true;

        }

        else {

            return false;

        }

    }

}

//Getting Mario's X position
bn::fixed Mario::getX() {

    return currentX;

}

//Setting Mario's X position
void Mario::setX(bn::fixed currX) {

    currX = currentX;

}

//Checking for Mario's Y collision
bool Mario::checkY(bn::vector<bn::fixed_rect, 100> _levelRectangles) {

    bn::fixed_rect marioBox = make_hitbox();

    //Check to see if Mario is colliding with the Y axis
    for (int i = 0; i < _levelRectangles.size(); i++) {

        if(marioBox.intersects(_levelRectangles[i])) {

            return true;

        }

        else {

            return false;

        }

    }

}

//Getting Mario's Y position
bn::fixed Mario::getY() {

    return currentY;

}

//Setting Mario's Y position
void Mario::setY(bn::fixed currY) {

    currY = currentY;

}

void Mario::update() {

    //Updating the states
    //For moving
    if (bn::keypad::left_held() || bn::keypad::right_held()) {
        
        _mstates.updateStanding(false);
        _mstates.updateWalking(true);

    }

    else {
    
        _mstates.updateStanding(true);
        _mstates.updateWalking(false);

    }

    //For jumping
    if (bn::keypad::a_pressed() && !_mstates.isJumping() && !_jumpLock) {

        _mstates.updateJumping(true);
        _mstates.updateFalling(false);
        _currJumpWaitFrames = 0;
        bn::sound_items::jump.play(0.5);

    }

    bool yColliding = false;
    bool xColliding = true;
    bn::fixed_rect walkRect;
    bn::fixed_rect standRect;

    //Moving
    move(xColliding, walkRect, standRect);

    //Jumping
    jump(yColliding);
    yColliding = false;


}