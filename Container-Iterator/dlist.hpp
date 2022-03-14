#ifndef DLIST_CS2
#define DLIST_CS2
//////////////////////////////////////////////////
// REQUIRES: assignable(T)
//
//  data
//
//  
//
//  
//

//////////////////////////////////////////////////
//
//
//
template<typename T>
class dnode {
public:
        dnode()           : next(0), prev(0) {};
        dnode(const T& x) : data(x), next(0), prev(0) {};
    T   data;
    dnode<T> *next;
             *prev;

};

template <typename T> class List;
/////////////////////////////////////////////////
// Iterator for List.
// CLASS INV: current == 0 || current->dnode<T>()
// REQUIRES : assignable(T) && copyconstructable(T)
template <typename T>
class Itr {
public:
    Itr               () : current(0) {};
    Itr               (dnode<T>* ptr) : current(ptr) {};
    Itr<T>&   operator++()    { };  // pre  ++i
    Itr<T>    operator++(int) { };  // post i++ dummy parameter
    Itr<T>&   operator--()    { };  // pre --i
    Itr<T>    operator--(int) { };  // post i-- dummy parameter
    T         operator* () const { return current->data };
    T&        operator* ()       { return current->data };
    dnode<T>*operator-> () const { return current; };
    dnode<T>*operator-> ()       { return current; };

    friend class List;

private:
    dnode<T> *current;
};

/////////////////////////////////////////////////
// CLASS INV: (beginning == 0 && ending == 0) ||
//             beginning -> X[0] <-> X[1] <-> ...
//                  <-> X[length() - 1] <- ending
// REQUIRES :
//
template<typename T>
class List {
public:
    List : begining(0), ending(0) {};
    ~List             ();
    List              (const List<T>&);
    void swap         (List<T>&);
    List<T>& operator=(List<T> rhs) { swap(rhs); return *this; };

    bool       isEmpty() const { return beginning == 0; };
    bool       isFull () const;
    int        length () const;
    void  insertBefore(const T&, Itr<T>);
    void   insertAfter(const T&, Itr<T>);
    void        remove(Itr<T>);

    Itr<T>       begin() const { return Itr<T>(beginning); };
    Itr<T>         end() const { return Itr<T>(ending);    };
    T            front() const { return beginning->data;   };
    T             back() const { return ending->data;      };
    Itr<T>&      begin() { return Itr<T>(beginning); };
    Itr<T>&        end() { return Itr<T>(ending);    };
    T&           front() { return beginning->data;   };
    T&            back() { return ending->data;      };

    Itr<T>  operator[](int) const;
    Itr<T>& operator[](int);

private:
    dnode<T> *beginning, *ending;
};






#endif