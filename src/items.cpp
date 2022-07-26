/*
CPP for Items
*/

#include "sml_items.h"

//Constructor for items

Items::Items(bn::sprite_item sprite_item, bn::fixed positionX, 
                     bn::fixed positionY) :

    _body_item(sprite_item),
    _item_ptr(make_item_sprite(_body_item, positionX, positionY)),
    _animate_action(_make_item_animation()),
    _position(positionX, positionY)
    //_name(name)
{}


//Creating the item sprite
bn::sprite_ptr Items::make_item_sprite (bn::sprite_item _item, bn::fixed posX, bn::fixed posY) {

    bn::sprite_builder builder(_item);
    builder.set_position(posX, posY);
    return builder.release_build();

}

//Creating the dimensions for the item
bn::fixed_size Items::make_item_dims(bn::fixed length, bn::fixed width) {

bn::fixed_size dim(length, width);
return dim;

}

//Creating animation for the item
bn::sprite_cached_animate_action<2> Items::_make_item_animation() {

return bn::create_sprite_cached_animate_action_forever(
_item_ptr, 20, _body_item.tiles_item(), 0, 0);

}

//Creating hitbox for the item
bn::fixed_rect Items::make_hitbox() {

bn::fixed_rect hitbox(_position, _dimensions);
return hitbox;

}