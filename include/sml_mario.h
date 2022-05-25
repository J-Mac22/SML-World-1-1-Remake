/*
CLASS for Mario
*/

#ifndef SML_MARIO_H
#define SML_MARIO_H

#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_sprite_animate_actions.h"
#include "bn_vector.h"

#include "bn_sprite_builder.h"
#include "bn_sound_item.h"
#include "bn_music_item.h"
#include "bn_music_actions.h"
#include "bn_fixed_rect.h"
#include "bn_sprite_animate_actions.h"

#include "bn_sprite_items_mario.h"
#include "sml_mario_states.h"
#include "sml_enemies.h"
 
 class SML_Mario {

     private:
     //Information about body
     SML_Mario_States _mstates;
     bn::sprite_item _body_sprite_item;
     bn::sprite_ptr _mario;
     bn::sprite_cached_animate_action<4> _animate_action;
     bool _jumpLock;
     bool _moving = false;
     bn::fixed_point _position;
     bn::fixed_size _dimensions;

     //For Mario's gravity
     const bn::fixed HIGH_GRAVITY = 6.0;
     bn::fixed gravity = HIGH_GRAVITY;

     //For Mario's current speed
     bn::fixed moveTemp = 0;

     //For Mario's current level
     int _level = 0;

     //For Mario's X position
     bn::fixed currentX = 0;

     //Other stats will go down here

     bool _invincible = false;
     bool _death = false;

     //Collision wait frames
     const int JUMPING_WAIT_FRAMES = 10;
     int _currJumpWaitFrames = JUMPING_WAIT_FRAMES;
     const int MOVING_WAIT_FRAMES = 10;
     int _currMoveWaitFrames = MOVING_WAIT_FRAMES;

     //Frames for invincibility
     int _inFrames = 0;

     public:

    /**
     NAME:
     SML_Mario

     SYNOPSIS:
     SML_Mario::SML_Mario();

     DESCRIPTION:
     Construct a new sml mario object

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     
     */
     SML_Mario();


    /**
      NAME:
      make_mario_sprite

      SYNOPSIS:
      bn::sprite_ptr SML_Mario::make_mario_sprite (const bn::sprite_item& body_sprite_item);
      body_sprite_item -> The body of Mario's sprite

      DESCRIPTION:
      A function that will create Mario's sprite for use in the final game.

      AUTHOR:
      Jack Machiaverna

      RETURNS:
      bn::sprite_builder builder.release_build()

     */
     
     bn::sprite_ptr make_mario_sprite (const bn::sprite_item& body_sprite_item);

     /**
       NAME:
       make_walk_animation

       SYNOPSIS:
       bn::sprite_cached_animate_action<4> SML_Mario::make_walk_animation(bn::sprite_ptr mario_sprite,
                                                               const bn::sprite_item& body_sprite_item);
        
       mario_sprite -> A pointer that relates to Mario's sprite
       body_sprite_item -> The body of Mario's sprite

       DESCRIPTION:
       A function that will create Mario's walking animation, allowing him to go both left and right.

       AUTHOR:
       Jack Machiaverna

       RETURNS:
       bn::create_sprite_cached_animate_action_forever(
       mario_sprite, 3.2, body_sprite_item.tiles_item(), 1, 2, 3, 2);
      
      */

     bn::sprite_cached_animate_action<4> make_walk_animation(bn::sprite_ptr mario_sprite,
                                                               const bn::sprite_item& body_sprite_item);

     /**
        NAME:
        make_jump_animation

        SYNOPSIS:
        WIP

        DESCRIPTION:
        A function that will create Mario's jumping animation, allowing him to go up and then go down.

        AUTHOR:
        Jack Machiaverna

        RETURNS:
        WIP

      */

    /**
       NAME:
       make_hitbox

       SYNOPSIS:
       bn::fixed_rect SML_Mario::make_hitbox();

       DESCRIPTION:
       A function that creates a hitbox for Mario, allowing him to make contact with enemies.

       AUTHOR:
       Jack Machiaverna

       RETURNS:
       bn::fixed_rect hitbox(_position, _dimensions)
    
     */
 
     bn::fixed_rect make_hitbox();

    /**
      NAME:
      make_bottom

      SYNOPSIS:
      bn::fixed_rect SML_Mario::make_bottom();

      DESCRIPTION:
      A function that will draw the bottom hitbox for Mario.

      AUTHOR:
      Jack Machiaverna

      RETURNS:
      WIP
     */

     bn::fixed_rect make_bottom();

     /**
      NAME:
      move

      SYNOPSIS:
      void SML_Mario::move (bn::camera_ptr &camera, bool xCollide,
                 bn::fixed_rect &collideRect, bn::fixed_rect &standingRect);

      camera-> A pointer that relates to the camera
      xCollide-> Sees if collision detection is working or not
      collideRect-> The rectangles used for collision detection
      standingRect-> So Mario can stand on the ground

      DESCRIPTION:
      A function that gets Mario moving left and right with input from the player.

      AUTHOR:
      Jack Machiaverna

      RETURNS:
      None
      */

     void move (bn::camera_ptr &camera, bool xCollide,
                 bn::fixed_rect &collideRect, bn::fixed_rect &standingRect);

    /**
     NAME:
     determine_enemy_encounter_result

     SYNOPSIS:
     void SML_Mario::determine_enemy_encounter_result(SML_Enemies* &enemy);

     enemy -> The type of enemy that Mario will encounter.

     DESCRIPTION:
     This will decide the result of what happens when Mario
     makes contact with an enemy. To be specific, what happens
     when Mario either defeats an enemy or is defeated by an enemy.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     */

    //void SML_Mario::determine_enemy_encounter_result(SML_Enemies* &enemy);

    /**
     NAME:
     update

     SYNOPSIS:
     void SML_Mario::update();

     DESCRIPTION:
     A function that will update Mario's animations and position.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
    */

     void update();

 };

 #endif