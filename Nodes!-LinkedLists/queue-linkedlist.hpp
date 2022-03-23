
#include <cassert>


//////////////////////////////////////////
//* CLASS INV: beggining -> x1 -> ... -> xN <- ending
//
template <typename T>
class queue {
    public:
                     queue() : beginning(0), ending(0) {};
                     queue(const queue<T>&);
                    ~queue();
        void          swap(queue<T>&);
        queue<T>&operator=(queue<T> rhs) { swap(rhs); return *this; };

        bool       isEmpty() const { return beginning == 0; };
        bool        isFull() const;
        T          dequeue();
        void       enqueue(const T&);
    private:
        node<T> *beginning;
        *ending;
};

//////////////////////////////////////////
//* REQUIRES: beg -> x1 -> ... -> xN <- ending && !isFull()
//* ENSURES : beg -> x1 -> ... -> xN -> item <- ending
template <typename T>
void queue<T>::enqueue(const T& item) {
    assert(!isFull());
    if (ending == 0) {
        ending = new node<T>(item);
        beginning = ending;
    } else {
        ending->next = new node<T>(item);
        ending = ending->next;
    }
}
//
//////////////////////////////////////////
//* REQUIRES: beg -> x1 -> x2 -> ... -> xN <- ending && !isEmpty()
//* ENSURES : beg -> x2 -> ... -> xN <- ending && RETVAL == x1
template <typename T>
T queue<T>::dequeue() {
    assert(!isEmpty());
    node<T> *temp = beginning;
    beginning = beginning->next;
    if (beginning == 0) ending = 0;
    delete temp;
    return result;
}

//////////////////////////////////////////
//? Destructor
template <typename T>
queue<T>::~queue() {
    node <T> *temp;
    while (beginning != 0) {
        temp = beginning;
        beginning = beginning->next;
        delete temp;
    }
}

//////////////////////////////////////////
//? Copy Constructor
//? The default constructor is also called on this!
template <typename T>
queue<T>::queue(const queue<T>& actual) : queue() {
    node<T> *temp = actual.beginning;
    while (temp != 0) {
        if (beginning == 0) {
            beginning = new node<T>(temp->data);
            ending = beginning;
        } else {
            ending->next = new node<T>(temp->data);
            ending = ending->next;
        }
        temp = temp->next;
    }
}

//////////////////////////////////////////
//! CONSTANT TIME SWAP NO MATTER HOW BIG
template <typename T>
void queue<T>::swap(queue<T>& rhs) {
    node<T>* temp = beginning;
    beginning     = rhs.beginning;
    rhs.beginning = temp;
    temp          = ending;
    ending        = rhs.ending;
    rhs.ending    = temp;
}

/////////////////////////////////////////