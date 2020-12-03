//relevant includes

class Unit{
    public:
        //position, maybe? store as tuple
        //string name;
        int attack;             //depletes enemy health
        int health;             //when depleted, should get renoved from play
        int speed;              //as number of moves per turn
        void Upkeep();          
        void Move(Tile);
    private:
        void Attack(Tile);
        int moves = 0; //how many moves it has done this turn

};
/*
should run at the start of every (player?) turn
reset moves, regenerate health?, pay upkeep costs


*/
void Unit::Upkeep() {
    moves = 0;
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
            //actually move
        }
    }
};