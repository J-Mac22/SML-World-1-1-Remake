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

 class Superball;
 
 class Mario {

     //My friend helped me with structuring the private for this class

     private:
     //Information about body
     Mario_States _mstates;
     bn::sprite_item _body_sprite_item;
     bn::sprite_ptr _mario;
     bn::sprite_cached_animate_action<4> _animate_action;
     bool _jumpLock;
     bool _moving = false;
     bn::fixed_point _position;
     bn::fixed_size _dimensions;

     //For Mario's current speed
     bn::fixed moveTemp = 0;

     //For Mario's current level
     int _level = 0;

     //For Mario's gravity
     const bn::fixed TOP_GRAV = 6.0;
     bn::fixed gravity = TOP_GRAV;

      //Collision wait frames
     const int JUMP_WAIT_FRAMES = 10;
     int _currJumpWaitFrames = JUMP_WAIT_FRAMES;
     const int MOVE_WAIT_FRAMES = 10;
     int _currMoveWaitFrames = MOVE_WAIT_FRAMES;

     //For Mario's X position
     bn::fixed currentX = 0;

     //Other stats will go down here

     bool _invincibility = false;
     bool _die = false;

     //Frames for invincibility
     int _inFrames = 0;

     public:

    /**
     NAME:
     Mario

     SYNOPSIS:
     Mario::Mario();

     DESCRIPTION:
     Construct a new sml mario object

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     
     */
     Mario();

    /**
      NAME:
      make_mario_sprite

      SYNOPSIS:
      bn::sprite_ptr Mario::make_mario_sprite (const bn::sprite_item& body_sprite_item);
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
       bn::sprite_cached_animate_action<4> Mario::make_walk_animation(bn::sprite_ptr mario_sprite,
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
       bn::fixed_rect Mario::make_hitbox();

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
      bn::fixed_rect Mario::make_bottom();

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
      void Mario::move (bn::camera_ptr &camera, bool xCollide,
                 bn::fixed_rect &collideRect, bn::fixed_rect &standRect);

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
                 bn::fixed_rect &collideRect, bn::fixed_rect &standRect);

    /**
     NAME:
     jump

     SYNOPSIS:
     void Mario::jump(bool collide);

     collide -> Determines if Mario makes contact while jumping

     DESCRIPTION:
     A function that allows Mario to jump with input from the player.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     */

    void jump(bool collide);

    /**
     NAME:
     decide_enemy_encounter_outcome

     SYNOPSIS:
     void Mario::decide_enemy_encounter_outcome(Enemies* &enemy);

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

    //void decide_enemy_encounter_outcome(Enemies* &enemy); //remember this

    /**
     NAME:
     move_next_to_star

     SYNOPSIS:
     void Mario::move_next_to_star(bn::fixed_point starPos);

     starPos -> The position of the Power Star.

     DESCRIPTION:
     Will have Mario move next to the Power Star when it's collected.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     */

    void move_next_to_star(bn::fixed_point starPos);

    /**
     NAME:
     getSpeed

     SYNOPSIS:
     bn::fixed getSpeed();

     DESCRIPTION:
     Getter function that returns the movement of Mario's speed.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     bn::fixed
     */

    bn::fixed getSpeed() {return moveTemp;}

     
    /**
     NAME:
     update

     SYNOPSIS:
     void SMario::update();

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