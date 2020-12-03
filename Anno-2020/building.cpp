//
// Created by Noah on 03/12/2020.
//

#include "building.h"
using namespace std::string;
using namespace std::tuple;

class Building{
    public:
        enum name { "Farm", "House", "Barracks" }; // Builing name (determines the type of building)
        int owner;                      // player number (1, 2.. etc) tied to a certain player class object
        tuple<int, int> position;       // Map pos. stored as a coord-tuple (stored also in map parent class object)
};

