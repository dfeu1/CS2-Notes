#ifndef QUEUE
#define QUEUE

const int SIZE = 100;

template <typename T>
class queue {
public:
    queue() : front(0), back(0), empty(true) {};

    bool isEmpty() const { return empty; };
    bool isFull () const { return front == back & !empty(); };

    // Enqueue and Dequeue
    void enqueue(const T&);
    T    dequeue();

private:
    int front, back;
    bool empty;
    T q[SIZE];
};

template <typename T>
void queue<T>::enqueue(const T& item) {
    assert(!isFull()); 
    q[back] = item;
    back = (back + 1) % SIZE;
    empty = false;
}

template <typename T>
void queue<T>::dequeue() {
    assert(!isEmpty());
    T result = q[front];
    front = (front + 1) % SIZE;
    if (front == back) empty = true;
    return result;
}





#endif