// Simple Tree Node

template <typename T>
class bnode {
    public:
    bnode() : left(0), right(0) {};
    bnode(bnode<T> x) : data(x), left(0), right(0);
}