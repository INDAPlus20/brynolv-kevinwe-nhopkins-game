//
// Created by Noah on 03/12/2020.
//

#ifndef BRYNOLV_KEVINWE_NHOPKINS_GAME_PLAYER_H
#define BRYNOLV_KEVINWE_NHOPKINS_GAME_PLAYER_H


class Player{
public:
		int number // player number, corresponds with <owner> in unit and building classes
		// int faction / team ?

		// Resources
		int gold
		int food
		int population

		// How to we want to link the player to her buildings and units?
		// Do we want to store a list/struct of all the owned units and buildings under the player?
};


#endif //BRYNOLV_KEVINWE_NHOPKINS_GAME_PLAYER_H
