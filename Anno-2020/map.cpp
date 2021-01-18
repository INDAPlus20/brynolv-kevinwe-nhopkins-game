#include "map.h"
#include <utility>
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
	this->size=size;
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

std::vector<Tile*> Map::getAdjacent(int r, int c){
	//Rotate like the clock from 12-12, nullptr for the non-existant:
	//(This should return tuples or otherwise coordinates, shouldn't it?
	//Maybe...
	std::vector<Tile*> neighburs(8,nullptr);
	bool cm,rp,rm=false;
	if (r>0){
		neighburs[4]=mapVector[r-1][c];
		rm=true;
	}
	if(c>0){
		neighburs[6]=mapVector[r][c-1];
		cm=true;
		if(rm)
			neighburs[5]=mapVector[r-1][c-1];
	}
	if(r<size){
		neighburs[0]=mapVector[r+1][c];
		if(cm)
			neighburs[7]=mapVector[r+1][c-1];
		rp=true;
	}
	if(c<size){
		neighburs[2]=mapVector[r][c+1];
		if(rm)
			neighburs[3]=mapVector[r-1][c+1];
		if(rp)
			neighburs[1]=mapVector[r+1][c+1];
	}

	return neighburs;
}

std::tuple<int,int> Map::getTileCoordinates(Tile* t){
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			if(t==mapVector[i][j])
				return std::make_tuple(i,j);
	//A tile that's not in the map? Something has gonn terribly wrong...
	throw;
}

std::vector<Tile*> Map::getAdjacent(Tile* t){
	auto tCoord=getTileCoordinates(t);
	return getAdjacent(std::get<0>(tCoord),std::get<1>(tCoord));
}

std::map<size_t,Tile*> Map::getAllTilesInRange(Tile* t,int range=1){
	std::map<size_t,Tile*> collection;
	std::hash<Tile*> tileHash;
	auto r1=getAdjacent(t);
	for(auto it=r1.begin();it!=r1.end();it++){
		collection.insert(std::pair<size_t,Tile*>(tileHash(*it),*it));
	}
	if(range==1)
		return collection;
	//The below should be able to be done asynchronus, right?
	//The below is also... not the fastest... As long as we never look more than
	//1 or 2 tiles away, it should be *fine*, further than that rewrite this.
	auto end=collection.end();
	for(auto it=collection.begin();it!=end;it++){
		auto insert=getAllTilesInRange(std::get<1>(*it),range-1);
		for(auto in=insert.begin();in!=insert.end();in++)
			collection.insert(*in);
	}
	return collection;
}
