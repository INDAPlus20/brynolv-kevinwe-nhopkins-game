#ifndef UNIT_H
#define UNIT_H

#include <map.h>

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

#endif // UNIT_H
