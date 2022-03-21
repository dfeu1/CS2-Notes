#ifndef NODE_CS2
#define NODE_CS2

////////////////
//Linked Lists
////////////////

#include <iostream>

template <typename T>
class node {
public:
    // Methods of the Node
            node()           : next(0) {};
            node(const T& x) : next(), data(x) {};

    // Two Elements of the Node
    node<T> *next;
    T        data;
};




int main() {
    node<int> *ptr;
    ptr = new node<int>(10);  

    // ! The below is archaic and can just use the ->
    std::cout << (*ptr).data; 
    // *The second *list , this is why they're called a link list
    //* ptr->next = new node(6);
    //* ptr->next->next = new node(7); // Now 5 node, to 6 node, to 7 node (values represent the data element.)

    //**** Removing a Node
    //! delete ptr; // deletes first node... memory leak
    //* Need to remove last node added first!

    //* delete ptr->next->next; // this would deallocate that 7 node
    //* delete ptr->next;       // this would deallocate that 6 node
    //* delete ptr;             // this would deallocate that 5 node

    ///////////////////////////////
    // Deleting an Internal Node //
    ///////////////////////////////
    //ptr->next = temp->next;
    // so you can go from 5 to 7.
    //delete temp;

    ptr->next = new node<int>(20);
    ptr->next->next = new node<int>(20);

    node<int> *temp, *temp2;

    
    temp = ptr;
    while (temp != 0) {
        std::cout << temp->next;
        temp2 = temp;
        temp = temp->next;
        delete temp2;
    }
    return 0;
}

#endif