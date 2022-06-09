/*
CPP for Mario
*/

#include "sml_mario.h"
#include "bn_music_item.h"
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

//Have Mario move next to the Power Star upon collecting
void Mario::move_next_to_star(bn::fixed_point starPos) {

    bn::fixed pos = starPos.x() - 30;
    _mario.set_x(pos);

}

//Get Mario to jump
void Mario::jump(bool collide) {

//For jumping
if (_mstates.isJumping()) {

//Get jump to lock, have the sprite tile change, move Mario, and get gravity to decrease
_jumpLock = true;
_mario.set_tiles(bn::sprite_items::mario.tiles_item().create_tiles(4));
_mario.set_y(_mario.y() - gravity);
_position.set_y(_mario.y());
gravity -= 0.25;

if (gravity <= 0.0) {


//WIP



}


}

}

//Hit-box for Mario
bn::fixed_rect Mario::make_hitbox() {

bn::fixed_rect hitbox;
return hitbox;

}

//Bottom hit-box for Mario
//bn::fixed_rect SML_Mario::make_bottom() {

//bn::fixed_rect spriteBottom(bn::fixed_point(_position.x(), make_hitbox().bottom() + 10), bn::fixed_size spriteSize;
//return spriteBottom;

//}

//Get Mario moving (walking wise)
void Mario::move(bn::camera_ptr &camera, bool xCollide,
                     bn::fixed_rect &collideRect, bn::fixed_rect &standRect) {

    //To move left   
    if (bn::keypad::left_held() && _mstates.isWalking()) {

       //_mstates.flipWalking(); WIP
        _animate_action.update();
        _moving = true;

        //This will prevent the engine from crashing from moving 
        //the camera past left background boundary
        if(currentX - (moveTemp + 0.05) < 0) {
        _moving = false;
        return;
        }

        //Continue as normal only if not colliding with anything
        if(!xCollide) {

        if(moveTemp <= 1.5) moveTemp += 0.05;

        _mario.set_horizontal_flip(true);
        camera.set_x(camera.x() - moveTemp);
        currentX -= moveTemp;
        }

        //Else, if the detected rectangle is alike to the one Mario
        //is on top of, continue as normal. Else, he will not move.
        else {

            if(collideRect == standRect) {

                if(moveTemp <= 1.5) moveTemp += 0.05;

                _mario.set_horizontal_flip(true);
                camera.set_x(camera.x() - moveTemp);
                currentX -= moveTemp;
            }

            else {
                 _moving = false;
            }
        }
    }

    //To move right
    else if (bn::keypad::right_held() &&  _mstates.isWalking())   {

        //_mstates.flipWalking(); WIP
        _animate_action.update();
        _moving = true;

        //Continue as normal if not colliding with anything
        if(!xCollide) {

        if(moveTemp <= 1.5) moveTemp += 0.05;

        _mario.set_horizontal_flip(false);
        camera.set_x(camera.x() + moveTemp);
        currentX += moveTemp;
        }

        //Else, if the detected rectangle is alike to the one Mario
        //is on top of, continue as normal. Else, he will not move.
        else {

            if(collideRect == standRect) {

                if(moveTemp <= 1.5) moveTemp += 0.05;

                _mario.set_horizontal_flip(false);
                camera.set_x(camera.x() + moveTemp);
                currentX += moveTemp;
            }

            else {
                 _moving = false;
            }
        }
     }     

     //Handling deceleration
     else {

         //This will prevent the engine from crashing from the camera moving
         //past the left background boundary and will restart Mario's sprite
         //right back to standing.
         if(currentX - (moveTemp - 0.2) < 0) {

             _moving = false;
             _mario.set_tiles(bn::sprite_items::mario.tiles_item().create_tiles(0));
             return;

         }

         //If not making contact with anything, continue as normal
         if(!xCollide) {

             //Continue to decelerate and move until a certain point
             //Depending on which way Mario is looking, either add or subtract
             if(moveTemp >= 0.1) {

                 moveTemp -= 0.2;
                 if(_mario.horizontal_flip()) {

                     camera.set_x(camera.x() - moveTemp);
                     currentX -= moveTemp;

                 }

                 else{

                     camera.set_x(camera.x() + moveTemp);
                     currentX += moveTemp;

                 }

                 _animate_action.update();
                 _moving = true;
             }

             else {

                 _moving = false;

             }
         }

         //Mario will not move if he collides
         else{

             _moving = false;

         }

         //Change Mario's sprite back to standing
         _mario.set_tiles(bn::sprite_items::mario.tiles_item().create_tiles(0));

     }     

        //Restart Mario's speed if he turns around
        if(bn::keypad::left_pressed() || bn::keypad::right_pressed()) {

            moveTemp = 0.1;
            
        }

     }
