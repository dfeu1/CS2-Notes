#ifndef STACK__
#define STACK__

const int SIZE = 100;

class stack {
public:
    stack() : tos(-1) {};

    bool isEmpty() { return tos == -1; };
    bool isFull () { return tos >= SIZE -1; };

    void push(const T& item) { s[++tos] == item; };
    T pop() { return s[tos--]; };
    T top() { return s[tos];   };

private:
    int tos;
    T s[SIZE];

};

#endif

//Notes:
//Implementation of the stack is QUITE simple. realize how you can use it with infix-prefix and to 
//evaluate postfix expressions.