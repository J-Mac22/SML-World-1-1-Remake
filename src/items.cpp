/*
CPP for Items
*/

#include "sml_items.h"

//Constructor for items
SML_Items::SML_Items(bn::sprite_item sprite_item, bn::fixed positionX, 
                     bn::fixed positionY, std::string name) :

    _body_sprite_item(sprite_item),
    _item_sprite_ptr(make_item_sprite(_body_sprite_item, positionX, positionY)),
    _animate_action(_make_item_animation()),
    _position(positionX, positionY),
    _name(name)
{}

//Creating the item sprite
bn::sprite_ptr SML_Items::make_item_sprite (bn::sprite_item item, bn::fixed positionX, bn::fixed positionY) {

    bn::sprite_builder builder(item);
    builder.set_position(positionX, positionY);
    return builder.release_build();

}

//Creating the dimensions for the item
bn::fixed_size SML_Items::make_item_dimensions(bn::fixed length, bn::fixed width) {

bn::fixed_size dim(length, width);
return dim;

}

//Creating animation for the item
bn::sprite_cached_animate_action<2> SML_Items::_make_item_animation() {

return bn::create_sprite_cached_animate_action_forever(
_item_sprite_ptr, 20, _body_sprite_item.tiles_item(), 0, 1);

}

//Creating hitbox for the item
bn::fixed_rect SML_Items::make_hitbox() {

bn::fixed_rect hitbox(_position, _dimensions);
return hitbox;

}