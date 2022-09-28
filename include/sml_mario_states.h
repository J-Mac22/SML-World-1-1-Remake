/*
CLASS for Mario's states
*/

#ifndef SML_MARIO_STATES_H
#define SML_MARIO_STATES_H

#include "sml_mario.h"
 
 
class Mario_States {

    private:
    enum stateEnums {
        Idle = 0,
        Walking = 1,
        Jumping = 2,
        Falling = 3
    };

    bool mStates[4] = {true, false, false, false};

    public:
    /**
     NAME:
     States

     SYNOPSIS:
     Mario_States();

     DESCRIPTION:
     An empty constructor for Mario's state map.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
    */

    Mario_States() {
      

    };

    /**
    NAME:
    ~Mario_States

    SYNOPSIS:
    Mario_States::~Mario_States();

    DESCRIPTION:
    A virtual destructor used for Mario's states.

    AUTHOR:
    Jack Machiaverna

    RETURNS:
     None
    */

    virtual ~Mario_States() = default;

    /**
     NAME:
     isWalking

     SYNOPSIS:
     bool isWalking();

     DESCRIPTION:
     A helper function that will retrieve the value for the 
     walking state.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     bool
     */

    bool isWalking() {
    return mStates[Walking];
    }

    /**
     NAME:
     flipWalking

     SYNOPSIS:
     void flipWalking();

     DESCRIPTION:
     This will flip Mario's walking state from false
     to true once he begins to move.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     */

    void flipWalking() {
        mStates[Walking] = !mStates[Walking];
    }

     /**
     NAME:
     updateWalking

     SYNOPSIS:
     void updateWalking(bool newState);

     DESCRIPTION:
     This will update Mario's walking state by mapping 
     his original state to a new boolean state.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     */

    void updateWalking(bool newState) {
        mStates[Walking] = newState; 
    }

    /**
     NAME:
     isJumping

     SYNOPSIS:
     bool isJumping();

     DESCRIPTION:
     A helper function that will retrieve the value for the 
     jumping state.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     bool
     */

    bool isJumping() {
    return mStates[Jumping];
    }

    /**
     NAME:
     flipJumping

     SYNOPSIS:
     void flipJumping();

     DESCRIPTION:
     This will flip Mario's jumping state from false
     to true once he begins to jump.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     */

    void flipJumping() {
        mStates[Jumping] = !mStates[Jumping];
    }

    /**
     NAME:
     updateJumping

     SYNOPSIS:
     void updateJumping(bool newState);

     DESCRIPTION:
     This will update Mario's jumping state by mapping 
     his original state to a new boolean state.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     */

    void updateJumping(bool newState) {
        mStates[Jumping] = newState;
    }

    /**
     NAME:
     isStanding

     SYNOPSIS:
     bool isStanding();

     DESCRIPTION:
     A helper function that will retrieve the value for the 
     standing state.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     bool
     */

    bool isStanding() {
    return mStates[Idle];
    }

    /**
      NAME:
      flipStanding

      SYNOPSIS:
      void flipStanding();

      DESCRIPTION:
      This will flip Mario's idle state from true
      to false once he either moves or jumps.

      AUTHOR:
      Jack Machiaverna

      RETURNS:
      None
     */

    void flipStanding() {
        mStates[Idle] = !mStates[Idle];
    }

    /**
     NAME:
     updateStanding

     SYNOPSIS:
     void updateStanding(bool newState);

     DESCRIPTION:
     This will update Mario's idle state by mapping 
     his original state to a new boolean state.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     */

    void updateStanding(bool newState) {
        mStates[Idle] = newState;
    }

    /**
     NAME:
     isFalling

     SYNOPSIS:
     bool isFalling();

     DESCRIPTION:
     A helper function that will retrieve the value for the 
     falling state.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     bool
     */

    bool isFalling() {
    return mStates[Falling];
    }

    /**
     NAME:
     flipFalling

     SYNOPSIS:
     void flipFalling();

     DESCRIPTION:
     This will flip Mario's falling state from false
     to true once he begins to fall.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     */

    void flipFalling() {
        mStates[Falling] = !mStates[Falling];
    }

    /**
     NAME:
     updateFalling

     SYNOPSIS:
     void updateFalling(bool newState);

     DESCRIPTION:
     This will update Mario's falling state by mapping 
     his original state to a new boolean state.

     AUTHOR:
     Jack Machiaverna

     RETURNS:
     None
     */

    void updateFalling(bool newState) {
        mStates[Falling] = newState;
    }

};

#endif