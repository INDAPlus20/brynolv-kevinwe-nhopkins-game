#include "map.h"
//#include <vector>

/*Map::Tile{

}*/

/**
 * @brief Map::Map
 * A map made of tiles
 * @param size
 * Grid size (NxN)
 * @author brynolv
 */
Map::Map(int size){
	std::vector<std::vector<Tile*>> map(size, std::vector<Tile*>(size, new Tile()));
	mapVector = map;
}
/**
 * @brief Map::getTile
 * Get a specific tile of the map
 * @param r
 * Row
 * @param c
 * Column
 * @return
 * pointer to the tile at [r][c].
 */
Tile* Map::getTile(int r, int c){
	return mapVector[r][c];
}

/**
 * @brief Tile::Tile
 * A tile of the map, containing it's information.
 */
Tile::Tile(){
	this->building=new int(0);
	this->unit=new int(0);
}

/**
 * @brief Tile::getDisplay
 * How to represent the tile as a string
 * @return
 * returns a QString "<unit>|<building>" of the tile
 */
QString Tile::getDisplay(){
	return QString("%1|%2").arg(*unit).arg(*building);
}
