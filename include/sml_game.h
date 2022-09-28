/*
CLASS for Game
*/

#ifndef SML_GAME_H
#define SML_GAME_H

#include "sml_mario.h"

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

class Game {

protected:
int _currLevel = 0;
bool _levelClear;

public:

/**
 NAME:
 Game

 SYNOPSIS:
 Game::Game();

 DESCRIPTION:
 A constructor used to initialize the game itself.

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

Game();

/**
 NAME:
 update

 SYNOPSIS:
 void Game::update();

 DESCRIPTION:
 Will update the game once certain conditions are met
 (ex: level isn't completed, Mario dies etc.)

 AUTHOR:
 Jack Machiaverna

 RETURNS:
 None
 */

void update(Mario &mario);

};
#endif