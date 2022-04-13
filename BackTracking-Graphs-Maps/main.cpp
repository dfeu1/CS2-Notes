#include "map.hpp"
//////////////////////////////////////////////////////////////////
// PRE :  the map world is assigned
// POST:  Valid four coloring of map
bool MapColor(int country, map& world) {
    if (country >= world.numberOfCountries()) return true; // Done Coloring
    
    bool  aColorRemains = true;
    bool  doneColoring  = false;
    color c             = red;

    while (aColorRemains && !doneColoring) {
        if (world.isValidColoring(country, c)) {
            world.colorCountry(country, c);
            doneColoring = MapColor(country + 1, world);

        }
        c++;
        if (c == none) aColorRemains = false;
    }
    if (!doneColoring) world.uncolor(country); // Backtrack here!
    return doneColoring;
}



//////////////////////////////////////////////////////////////////
int main() {
    map world;

    std::ifstream in("map1.txt");
    in >> world;
    MapColor(0, world);
    std::cout << world;
    std::cout << "Done." << std::endl;
    return 0;
}