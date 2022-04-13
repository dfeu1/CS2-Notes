#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>
#include <fstream>


const int MAP_SIZE = 10;
enum colorRange {red, blue, green, yellow, none};

///////////////////////////////////////////////////////////////////////////////
class color {
public:
    color()            : c(none)  {};
    color(colorRange x): c(x)     {};

    bool   operator==(colorRange x) { return x == c; };
    color& operator++()             { c = colorRange(c+1); return *this; };

    friend std::ostream& operator<<(std::ostream&, color);

private:
    colorRange c;
};


//////////////////////////////////////////////////////////////////////////////
class map {
public:
    int numberOfCountries() const         { return numOfCountries; };
    bool isValidColoring (int, color) const;                             //Returns true or false when you can color a country :D
    void colorCountry    (int n, color c) { coloring[n] = c; };
    void uncolorCountry  (int n)          {coloring[n] = none; };

    friend std::ostream& operator<<(std::ostream&, const map&);
    friend std::istream& operator>>(std::istream&, map&);

private:
    int   numOfCountries;
    bool  neighbor[MAP_SIZE][MAP_SIZE];
    color coloring[MAP_SIZE];

};

#endif