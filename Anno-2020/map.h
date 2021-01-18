#ifndef MAP_H
#define MAP_H
#include <vector>
#include <Qt>
#include <QString>
#include <tuple>
#include <map>

class Tile{
private:
	//TODO: Replace int with the appropiate class, once made
	int* building;
	int* unit;
public:
	Tile();
	QString getDisplay();
};

class Map{
private:
	std::vector<std::vector<Tile*>> mapVector;
	int size;
public:
	Map(int);
	Tile* getTile(int,int);
	std::vector<Tile*> getAdjacent(int, int);
	std::vector<Tile*> getAdjacent(Tile*);
	std::tuple<int,int> getTileCoordinates(Tile*);
	std::map<size_t,Tile*> getAllTilesInRange(Tile*,int);
};

#endif // MAP_H
