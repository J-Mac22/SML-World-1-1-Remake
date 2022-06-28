/*
CLASS for Coin
*/

#ifndef SML_COIN_H
#define SML_COIN_H

#include "sml_items.h"
#include "bn_sprite_items_coin.h"
#include "bn_fixed.h"

class Coin : public Items {

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

Coin(bn::fixed positionX, bn::fixed positionY);

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