/*
CPP for World 1-1
*/
 
 #include "sml_world1_1.h"
 #include "bn_sprite_ptr.h"
 #include "bn_vector.h"

//Constructor for World 1-1 (WIP)
/*
 World_1_1::World_1_1() :


 {}
*/

//Updating the World 1-1 level
bool World_1_1::update(Mario &mario) {

//Have Mario be updated here
//mario.update(_camera, _levelRectangles, _levelHurtBox, _block, _itemEvents, _enemyEvents, _superball); //WIP

bool deleteObjects = false;

//Updating the items
for (int i = 0; i < _itemEvents.size(); i++) {

    deleteObjects = _itemEvents[i]->update(mario);

    //Getting rid of the item and erase 
    //leftover space that is in the vector
    if (deleteObjects) {

        delete _itemEvents[i];
        _itemEvents.erase(_itemEvents.begin() + i);
        i--;

    }
}

//Updating the enemies 
for (int i = 0; i < _enemyEvents.size(); i++) {

    deleteObjects = _enemyEvents[i]->update(mario);

    //Getting rid of the enemy and erase
    //leftover space that is in the vector
    if (deleteObjects) {

        delete _enemyEvents[i];
        _enemyEvents.erase(_enemyEvents.begin() + i);
        i--;

    }
}


}