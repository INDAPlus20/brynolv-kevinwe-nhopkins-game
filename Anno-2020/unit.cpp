//relevant includes

#include <unit.h>
/*
should run at the start of every (player?) turn
reset moves, regenerate health?, pay upkeep costs


*/
void Unit::Upkeep() {
    moves = 0;
    if health < 1 {
        //remove this unit, how do?
    }
    //payUpkeep(upkeep)
};

/*
moves if tile empty, attacks if tile enemy
*/
void Unit::Move(Tile tile) {
    if tile.IsAdjacent(){ //sanity check for legality of move
        
        if tile.HasEnemy(){
            Attack(tile);
        }
        if tile.IsEmpty(){
            //actually move, call a tile function for this?
        }
    }
};

void Unit::Attack(Tile tile) {
    tile.unit.health -= attack
}