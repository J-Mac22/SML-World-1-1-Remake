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

 class Items;
 class Enemies;
 class Superball;
 class Blocks;
 
 class Mario {

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

     //For Mario's Y position
     bn::fixed currentY = 0; 

     //Other stats will go down here
     bool _invincibility = false;
     bool _die = false;

     //Losing a life
     bool _lostLife = false; 

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
      bn::sprite_cached_animate_action<3> make_jump_animation(bn::sprite_ptr mario_sprite,
                                                                  const bn::sprite_item& body_sprite_item);

      mario_sprite -> A pointer that relates to Mario's sprite
      body_sprite_item -> The body of Mario's sprite

      DESCRIPTION:
      A function that will create Mario's jumping animation, allowing him to go up and then go down.

      AUTHOR:
      Jack Machiaverna

      RETURNS:
      bn::create_sprite_cached_animate_action_forever
    */
      bn::sprite_cached_animate_action<3> make_jump_animation(bn::sprite_ptr mario_sprite,
                                                                  const bn::sprite_item& body_sprite_item);

     
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
      make_top

      SYNOPSIS:
      bn::fixed_rect Mario::make_top();

      DESCRIPTION:
      A function that will draw the top hitbox for Mario.

      AUTHOR:
      Jack Machiaverna

      RETURNS:
      bn::fixed_rect
      */

     bn::fixed_rect make_top();

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
      bn::fixed_rect
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

     void move(bool xCollide, bn::fixed_rect &collisionRect, bn::fixed_rect &standingRect);

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

    void jump(bool yCollide);

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

    void decide_enemy_encounter_outcome(Enemies* &enemies);  

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
     change_item_sprites

     SYNOPSIS:
     void Mario::change_item_sprites(Items* &item);
     item -> The item to have its' sprite changed.

     DESCRIPTION:
     Will read what powerup Mario has once he
     makes contact with an item.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     */

    void change_item_sprites(Items* &item); 

    /**
     NAME:
     inspect_block_collision

     SYNOPSIS:
     bool Mario::inspect_block_collision(bn::vector<Block, 21> &block);
     block -> The block to be checked.

     DESCRIPTION:
     This function will check each block's collision
     for Mario to interact with.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     bool
     */

    bool inspect_block_collision(bn::vector<Blocks, 21> &block);

    /**
     NAME:
     change_level_sprites

     SYNOPSIS:
     void Mario::change_level_sprites();

     DESCRIPTION:
     Will read Mario's transformation once he
     obtains an item.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     */

    void change_level_sprites();

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
    getMove

    SYNOPSIS:
    bool Mario::getMove();

    DESCRIPTION:
    Getter function to get Mario fully moving.

    AUTHOR:
    Jack Machiaverna

    RETURNS:
    _moving
    */

    bool getMove() {return _moving;};

    /**
     NAME:
     getHorizontalFlip

     SYNOPSIS:
     int Mario::getHorizontalFlip();

     DESCRIPTION:
     Getter function to obtain the horizontal flip for Mario.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     _mario.horizontal_flip()
     */

    int getHorizontalFlip() {return _mario.horizontal_flip();};

    /**
     NAME:
     getDie

     SYNOPSIS:
     bool Mario::getDie();

     DESCRIPTION:
     Getter function for having Mario die in the game.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     _die
     */

    bool getDie() {return _die;};

/**
     NAME:
     checkX

     SYNOPSIS:
     bool Mario::checkX (bn::vector<bn::fixed_rect, 100> _levelRectangles);

     _levelRectangles -> the collision rectangles to be checked

     DESCRIPTION:
     Will check to see if Mario's X position collides or not.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     bool
     */
    
    bool checkX (bn::vector<bn::fixed_rect, 100> _levelRectangles);

    /**
     NAME:
     getX

     SYNOPSIS:
     bn::fixed Mario::getX();

     DESCRIPTION:
     This function will get Mario's x position.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     bn::fixed
     */

    bn::fixed getX();

     /**
     NAME:
     setX

     SYNOPSIS:
     void Mario::setX(bn::fixed currX);

     currX -> where Mario's x position currently is

     DESCRIPTION:
     This function will set where Mario's current X position is.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     */

    void setX(bn::fixed currX);

  /**
     NAME:
     checkY

     SYNOPSIS:
     bool Mario::checkY (bn::vector<bn::fixed_rect, 100> _levelRectangles);

     _levelRectangles -> the collision rectangles to be checked

     DESCRIPTION:
     Will check to see if Mario's Y position collides or not.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     bool
     */

    bool checkY (bn::vector<bn::fixed_rect, 100> _levelRectangles);

     /**
     NAME:
     getY

     SYNOPSIS:
     bool Mario::getY();

     DESCRIPTION:
     This function will get Mario's y position.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     bn::fixed
     */

    bn::fixed getY();

    /**
     NAME:
     setY

     SYNOPSIS:
     void Mario::setY(bn::fixed currY);

     currY -> where Mario's y position currently is

     DESCRIPTION:
     This function will set where Mario's current Y position is.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     */

    void setY (bn::fixed currY);

    /**
     NAME:
     update

     SYNOPSIS:
     void Mario::update();

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