#ifndef CS2_BTREE
#define CS2_BTREE
#include <fstream>


template <typename T>
class btree {
public:
    btree()              : left(0), right(0), empty(true) {};
    btree(const T& item) : left(0), right(0), empty(false), data(item) {};
    
    ~btree();
    btree (const btree<T>&);
    void  swap         (btree<T>&);
    btree<T>& operator=(btree<T> rhs)   { swap(rhs); return *this; }
    
    bool isEmpty  () const              { return empty; }
    bool isFull   () const;
    bool find     (const T&) const;
    void binsert  (const T&);
    void inorder  (std::ostream&) const;
    void preorder (std::ostream&) const;
    void postorder(std::ostream&) const;

private:
    btree<T> *left, *right;
    bool empty;
    T data;
};

////////////////////////////////////////////////////////
// REQUIRES: !isFull()
// ENSURES : x is in BST
template<typename T>
void btree<T>::binsert(const T& x) {
    if (empty) {
     data = x;
     empty = false;
    }
    else {
        if (x < data) {
            if (left) left->binsert(x);
            else left = new btree<T>(x);
        } else {
            if (right) right->binsert(x);
            else right = new btree<T>(x);

        }
    }
}

////////////////////////////////////////////////////////
// ENSURES: if key in Tree then RETVAL = true
//          else RETVAL == false
//
template<typename T>
bool btree<T>::find(const T& key) const {
    if (empty) return false;                
    if (key == data) return true;           //* Found!
    if(key < data) {                        
        if (left)  return left->find(key);   //? Look in Left subtree
        else       return false;            // ! Not in tree
    } else {                                
        if (right) return right->find(key); //? Look in Right subtree
        else       return false;            // ! Not in tree
    }
}

////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES :
template<typename T>
void btree<T>::postorder(std::ostream& out) const {
    if (empty) return;
    if (left)  left->postorder(out);
    if (right) right->postorder(out);
    out << data << " ";
}

////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES :
template<typename T>
void btree<T>::inorder(std::ostream& out) const {
    if (empty) return;
    if (left)  left->inorder(out);
    out << data << " ";
    if (right) right->inorder(out);
}

////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES :
template<typename T>
void btree<T>::preorder(std::ostream& out) const {
    if (empty) return;
    out << data << " ";
    if (left)  left->preorder(out);
    if (right) right->preorder(out);
}

////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES :
//* We use POST order here because we want to delete the first node last.
template<typename T>
btree<T>::~btree() {
    if (left)  delete left;  //! recursive because delete calls destructor of object class
    if (right) delete right;

    //* Compiler deallocates object memory (left, right, empty, data) 

}

////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES :
//* We use PRE order here because we want to COPY from the top down!
template<typename T>
btree<T>::btree(const btree<T>& actual): btree<T>() {
    if (actual.empty) return;

    data  = actual.data;
    empty = actual.empty;

    if (actual.left) left   = new btree<T>(*(actual.left));
    if (actual.right) right = new btree<T>(*(actual.right));
    
}


////////////////////////////////////////////////////////
// REQUIRES: 
// ENSURES :
template<typename T>
void  btree<T>::swap(btree<T>& rhs) {

}

////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES :
// template<typename T>


#endif