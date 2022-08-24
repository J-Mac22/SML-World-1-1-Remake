/*
CPP for Enemies
*/

#include "sml_enemies.h"

//Constructor for enemies (Reorganize if need be)
Enemies::Enemies(bn::sprite_item _sprite_item, bn::fixed positionX, bn::fixed positionY,
                          bn::fixed len, bn::fixed wid) :            
_body_item(_sprite_item),
_enemy_ptr(make_enemy_sprite(_body_item, positionX, positionY)),
_animate_action(make_enemy_animation()),
_position(positionX, positionY),
_dimensions(make_enemy_dims(len, wid))
//_name(name)
{}
                     
//Creating measurements for enemies
bn::fixed_size Enemies::make_enemy_dims(bn::fixed length, bn::fixed width) {
    
bn::fixed_size dim(length, width);
return dim;

}

//Creating enemy sprites
bn::sprite_ptr Enemies::make_enemy_sprite(bn::sprite_item item, bn::fixed positionX, bn::fixed positionY) {

bn::sprite_builder builder(item);
builder.set_position(positionX, positionY);
return builder.release_build();

}

//Creating enemy animations
bn::sprite_cached_animate_action<2> Enemies::make_enemy_animation() {

return bn::create_sprite_cached_animate_action_forever (
_enemy_ptr, 20, _body_item.tiles_item(), 0, 1);

}

//Creating hitbox for the enemies
bn::fixed_rect Enemies::make_hitbox() {

bn::fixed_rect hitbox(_position, _dimensions);
return hitbox;

}

//Creating the top hitbox
bn::fixed_rect Enemies::make_top() {

bn::fixed_rect spriteTop(bn::fixed_point(_position.x(), make_hitbox().top() - 15), bn::fixed_size(8, 8)); //WIP
return spriteTop;

}