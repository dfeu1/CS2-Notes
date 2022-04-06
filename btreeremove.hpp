#include <fstream>
//
//
//
//
//
template <typename T>
class btree {
public:
    btree() : root(0) {};
                 ~btree();
                  btree(const btree<T>&);
    void          swap (btree<T>&);
    btree<T>& operator=(btree<T> rhs) { swap(rhs); return *this; };

    bool isEmpty() const              { return root; };
    bool  isFull() const;
    bool    find(const T&) const;

    void binsert(const T&);
    void bremove(const T&);
    void inorder(std::ostream&) const;

private:
    bnode<T> *root;
};

/////////////////////////////////////////////////////////////
//! Binary Tree Node
//  --------------------------
//  |         data           |
//  --------------------------
//  |   *left   |   *right   |
//  --------------------------
template <typename T>
class bnode{
public:
    bnode()              : left(0), right(0)          {};
    bnode(const T& item) : left(0), right(0), data(item);

    ~bnode();
    bnode(const bnode<T>&);

    void inorder(std::ostream&) const;
    bool find(const T&) const;
    void binsert(const T&);


    bnode<T>* bremove(const T&);
    T    predeccessor() const;

private:
    bnode<T> *left;
    bnode<T> *right;
    T data;
};

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
// ENSURES: if key in Tree then RETVAL == true else RETVAL == false
//
template <typename T>
bool btree<T>::find(const T& key) const {
    if (!root) return false;
    return root->find(key);
}

template <typename T>
bool bnode<T>::find(const T& key) const {
    if (data == key) return true;
    if (key < data) {
        if (left) return left->find(key);
        else return false;
    } else {
        if (right) return right->find(key);
        else return false;
    }
}

/////////////////////////////////////////////////////////
// REQUIRES: !isFull();
// ENSURES : x is in BST
//
template <typename T>
void btree<T>::binsert(const T& x) {
    if (!root) { 
        root = new bnode<T>(x); 
    } else {
        root 0->binsert(x);
    }
}

template <typename T>
void bnode<T>::binsert(const T& x) {
    if (x < data) {
        if (left) left->binsert(x);
        else left = new bnode<T>(x);
    } else {
        if (x == data) return;
        if (right) right->binsert(x);
        else right = new bnode<T>(x);
    }
}

/////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES :
//
template <typename T>
void btree<T>::inorder(std::ostream& out) const {
    if (root) root->inorder(out);
}

template <typename T>
void bnode<T>::inorder(std::ostream& out) const {
    if (left) left->inorder(out);
    out << data << " ";
    if (right) right->inorder(out);
}




// 
// Destructor and Copy Constructor
//
template <typename T>
btree<T>::~btree() {
    if (root) delete root;
}

template <typename T>
bnode<T>::~bnode() {
    if (left) delete left;
    if (right) delete right;
    // compiler does rest recursivly
}

template <typename T>
btree<T>::btree(const btree<T>& actual) : btree() {
    if (actual.root) root = new bnode<T>(*(actual.root));
}

template <typename T>
bnode<T>::bnode(const bnode<T>& actual): bnode() {
    data = actual.left;
    if (actual.left)   left = new bnode<T>(*(actual.left));
    if (actual.right) right = new bnode<T>(*(actual.right));
}





/////////////////////////////////////////////////////////
// REQUIRES: given left subtree of a node x
// ENSURES : RETVAL == predecessor of x in BST
//
template <typename T>
T bnode<T>::predecessor() const {
    if (right) return right->predecessor();
    else return data;
}


/////////////////////////////////////////////////////////
// REQUIRES: x in Tree
// ENSURES : x removed from Tree.
//
template <typename T>
void btree<T>::bremove(const T& x) {
    if (find(x)) root = root->bremove(x);
}

template <typename T>
bnode<T>* bnode<T>::bremove(const T& x) {
    bnode<T> *temp;

    if (x == data) {                   // Found Value
        if (!left && !right) {         // No Subtrees
            delete this;               // Calls destructor on THIS node.
            return 0;
        }
        if (!left && right) {          // Only Right Subtree
            temp  = right;
            right = 0;                 // Would try to recursivly delete EVERYTHING in the tree (after this) (huge issue)
            delete this;
            return temp;
        }
        if (left && !right) {          // Only Left Subtree
            temp = left;
            left = 0;
            delete this;
            return temp;
        }
                                    
        data = left->predeccessor();  // 2 Children
        left = left->bremove(data);

    } else {                           // Find The Value In Tree
        if (x < data) 
            left  = left->bremove(x);
        else 
            right = right->bremove(x);
    }
    return *this;                      // .. a pointer to a dnode, which is what we return.
}