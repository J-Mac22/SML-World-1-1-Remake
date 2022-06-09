/*
CLASS for Coin
*/

#ifndef SML_COIN_H
#define SML_COIN_H

#include "bn_sprite_items_coin.h"
#include "bn_sound_item.h"
#include "bn_music_item.h"
#include "bn_music_actions.h"
#include "bn_sprite_animate_actions.h"

#include "bn_fixed_rect.h"
#include "bn_fixed_point.h"
#include "bn_fixed_size.h"

#include "sml_mario.h"

class Coin {

public:

/**
 NAME:
 Coin

 SYNOPSIS:
 Coin::Coin();

 DESCRIPTION:
 A constructor for the coins object.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

Coin();

/**
 NAME:
 ~Coin

 SYNOPSIS:
 virtual Coin::~Coin();

 DESCRIPTION:
 A virtual destructor that will destroy the SML_Coin object.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

virtual ~Coin() = default;

/**
 NAME:
 update

 SYNOPSIS:
 bool update (Mario &mario);

 DESCRIPTION:
 Updates the coin's position. Will return
 whether the coin should be deleted
 or not.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 bool
 */

bool update(Mario &mario);

};

#endif