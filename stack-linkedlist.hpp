// Stack ADT - Implemented Using Linked - List
// FILO First in Last Out

//Top you can add and remove
//Bottom you can only add.

#ifndef STACK_LL_CS2
#define STACK_LL_CS2

#include <new>
#include <cassert>

//Node Class
template <typename T> 
class node {
public:
             node()              : next(0) {};
             node(const T& item) : data(item), next(0) {};

    T        data;
    node<T> *next;
};
/////////////////////////////////
//*CLASS INV: tos -> x1 -> x2 -> ... -> xN -> 0
template <typename T>
class stack {
public:
    stack           () : tos(0) {};
    
    //Dynamic Memory
    ~stack          ();
    stack           (const stack&);
    stack& operator=(stack rhs) { swap(rhs); return *this; }
    void swap       (stack&); 

    //Methods
    bool isEmpty    () const { return tos == 0; };
    bool isFull     () const;
    T    pop        ();
    T    top        () const { assert(!isEmpty()); return tos->data; }
    void push       (const T&);
private:
    node<T> *tos;
};
/////////////////////////////////
//? This pushes the item onto the top of the stack
//*REQUIRES: tos -> x1 -> ... -> xN -> 0
//*ENSURES : tos -> item -> x1 -> ... -> xN -> 0
template <typename T>
void stack<T>::push(const T& item) {
    assert(!isFull());
    node<T> *temp = new node<T>(item);
    temp->next    = tos;
    tos = temp;
}

/////////////////////////////////
//*REQUIRES: 
//*ENSURES :
template <typename T>
T stack<T>::pop() {
    assert(!isEmpty());
    T result = tos->data;
    node<T> *temp = tos;
    tos = tos->next;
    delete temp;
    return result; 
}

/////////////////////////////////
template <typename T>
stack<T>::~stack() {
    if (isEmpty()) return;
    node<T>* temp;
    while (top != 0) {
        temp = tos;
        tos = tos->next;
        delete temp;
    }
}

/////////////////////////////////
template <typename T>
stack<T>::stack(const stack<T>& actual) : stack() {
    node<T>* temp = actual.tos;
    node<T>* last;
    while (temp != 0) {
        if (tos == 0) {
            tos = new node<T>(temp->data);
            bottom = tos;
        } else {
            bottom->next = new node<T>(temp->data);
        }
    }
    temp = temp->next;
}

/////////////////////////////////
template <typename T>
void stack<T>::swap(stack<T>& rhs) {
    node<T> *temp = rhs.tos;
    rhs.tos = tos;
    tos = temp;
}

/////////////////////////////////
template <typename T>
stack<T>& stack<T>::operator=(stack<T> rhs) {
    swap(rhs);
    return *this;
}

/////////////////////////////////
template <typename T>
bool stack<T>::isFull() const {
    node<T> *temp = new(std::nothrow) node<T>();
    if (temp == 0) return true; //?No more memory |||||| Deallocate what you allocated
    delete temp;
    return false;
}


#endif