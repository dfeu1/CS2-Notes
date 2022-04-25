#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>

class shape { // Abstract Class
public:
    shape(): x(0), y(0) {};

    void move (int nx, int ny) { x = nx; y = ny; };
    virtual void draw () { std::cout << "Shape: " << " at " << x << ", " << y << std::endl; }; // Pure Virtual Method
    virtual ~shape()  {}; 
    virtual bool isRectange() const = 0;
    virtual bool isSquare()   const = 0;
    virtual bool isCircle()   const = 0;
    virtual bool iSTriangle() const = 0;


protected:
    int x, y;

};

class rectange : public shape { // Inhertence normally (same as base class)
public:
    rectange(): shape(), h(0), w(0) {};

    rectangle(int nh, int nw) : rectangle(), h(nh), w(nw) { h = nh; w = nw;};
    virtual void draw () { std::cout << "Rectangle: " << " at " << x << ", " << y << std::endl; };

    virtual bool isRectange() { return true;  };
    virtual bool   isSquare() { return false; };
    virtual bool   isCircle() { return false; };
    virtual bool iSTriangle() { return false; };

protected:
    int h, w;
};


class square : public rectangle {
public:
    square() : rectangle() {};

    square(int nh) : rectangle(nh, nh) { h = nh; w = nh; };
    virtual void draw () { std::cout << "Square: " << " at " << x << ", " << y << std::endl; };

    virtual bool isRectange() { return false;  };
    virtual bool   isSquare() { return true; };
    virtual bool   isCircle() { return false; };
    virtual bool iSTriangle() { return false; };
    
};

class circle : public shape {
public:
    circle() : shape(), r(0) {};
    circle(int nr) : circle(), r(nr) { r = nr; };
    virtual void draw () { std::cout << "Circle: " << " at " << x << ", " << y << std::endl; };

    virtual bool isRectange() { return false; };
    virtual bool   isSquare() { return false; };
    virtual bool   isCircle() { return true;  };
    virtual bool iSTriangle() { return false; };
protected:
    int r;

}

class triangle : public shape {
public:
    triangle() : shape(), b(0), h(0) {};
    triangle(int nb, int nh) : triangle(), b(nb), h(nh) { b = nb; h = nh; };
    virtual void draw() { std::cout << "Triangle at " << x << ", " << y << std::endl; };

    virtual bool isRectange() { return false; };
    virtual bool   isSquare() { return false; };
    virtual bool   isCircle() { return false; };
    virtual bool iSTriangle() { return true;  };
protected:
    int b, h;
}

#endif //fam