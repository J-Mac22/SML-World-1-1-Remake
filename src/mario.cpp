/*
CPP for Mario
*/

#include "sml_mario.h"
#include "bn_music_item.h"
#include "bn_fixed_size.h"
 
//Constructor
SML_Mario::SML_Mario() :

    _body_sprite_item(bn::sprite_items::mario),
    _mario(make_mario_sprite(_body_sprite_item)),
    _animate_action(make_walk_animation(_mario, _body_sprite_item)),
    _jumpLock(false),
    _position(0, -40),
    _dimensions(16, 16)

{}

//Mario sprite creation
bn::sprite_ptr SML_Mario::make_mario_sprite(const bn::sprite_item& body_sprite_item) {

    bn::sprite_builder builder(body_sprite_item);
    builder.set_position(0, -40);
    return builder.release_build();
    
}

//Mario walking animation
bn::sprite_cached_animate_action<4> SML_Mario::make_walk_animation(bn::sprite_ptr mario_sprite,
                                                                            const bn::sprite_item& body_sprite) 
{

return bn::create_sprite_cached_animate_action_forever(
    mario_sprite, 3.2, body_sprite.tiles_item(), 1, 2, 3, 2);

}

//Jump?
        /*
            if(bn::keypad::up_held())
            {
                blue_sprite.set_y(blue_sprite.y() - 1);
            }
            else if(bn::keypad::down_held())
            {
                blue_sprite.set_y(blue_sprite.y() + 1);
            }

        */

 

//Hit-box for Mario
bn::fixed_rect SML_Mario::make_hitbox() {

bn::fixed_rect hitbox;
return hitbox;

}

//Bottom hit-box for Mario
//bn::fixed_rect SML_Mario::make_bottom() {

//bn::fixed_rect spriteBottom(bn::fixed_point(_position.x(), make_hitbox().bottom() + 10), bn::fixed_size spriteSize;
//return spriteBottom;

//}

 
                            