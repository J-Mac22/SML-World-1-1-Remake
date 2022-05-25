/*
CPP for Enemies
*/

#include "sml_enemies.h"

//Constructor for enemies (Reorganize if need be)
SML_Enemies::SML_Enemies(bn::sprite_item _sprite_item, bn::fixed positionX, bn::fixed positionY,
                          bn::fixed length, bn::fixed width) :            
_body_sprite_item(_sprite_item),
_enemy_sprite_ptr(make_enemy_sprite(_body_sprite_item, positionX, positionY)),
_animate_action(make_enemy_animation()),
_position(positionX, positionY),
_dimensions(make_enemy_dimensions(length, width))
//_name(name)
{}
                     
//Creating measurements for enemies
bn::fixed_size make_enemy_dimensions(bn::fixed length, bn::fixed width) {
    
bn::fixed_size dim(length, width);
return dim;

}

//Creating enemy sprites
bn::sprite_ptr  make_enemy_sprite(bn::sprite_item item, bn::fixed positionX, bn::fixed positionY) {

bn::sprite_builder builder(item);
builder.set_position(positionX, positionY);
return builder.release_build();

}

//Creating enemy animations
bn::sprite_cached_animate_action<2> SML_Enemies::make_enemy_animation() {

return bn::create_sprite_cached_animate_action_forever (
_enemy_sprite_ptr, 20, _body_sprite_item.tiles_item(), 0, 1);

}

//Creating hitbox for the enemies
bn::fixed_rect SML_Enemies::make_hitbox() {

bn::fixed_rect hitbox(_position, _dimensions);
return hitbox;

}

//Continue sometime later either today or tomorrow