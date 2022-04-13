#include "map.hpp"
///////////////////////////////////////////////////////
map::map() {
    for (int i = 0; i < MAP_SIZE; ++i) {
        coloring[i] = none;
        for (int j = 0; j < MAP_SIZE; ++j) {
            neighbor[i][j] = false;
        }
    }
}

///////////////////////////////////////////////////////
// PRE : <none>
// POST: Retval TRUE if no adjacent country is the same country
bool map::isValidColoring(int country, color c) const {
    for (int i = 0; i < numOfCountries; ++i) {
        if (neighbor[country][i] && (c == coloring[i]))
            return false;
    return true;
    }
}


///////////////////////////////////////////////////////
std::ostream& operator<< (std::ostream& out, color x) {
    switch(x,c) {
        case red:    out << "red"; break;
        case blue:   out << "blue"; break;
        case green:  out << "green"; break;
        case yellow: out << "yellow"; break;
        case none:   out << "none";
    }
    return out;
}