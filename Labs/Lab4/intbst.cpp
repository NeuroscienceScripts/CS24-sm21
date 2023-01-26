// intbst.cpp

#include <iostream>
using namespace std;

// constructor sets up empty tree
template <class T> IntBST<T>::IntBST() : root(NULL) { }

// destructor deletes all nodes
template <class T> IntBST<T>::~IntBST() { clear(root); }

// recursive helper for destructor
template <class T>
void IntBST<T>::clear(Node *n) {
    if (n) {
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

// insert value in tree; return false if duplicate
template <class T>
bool IntBST<T>::insert(T value) {
    // handle special case of empty tree first
    if (!root) {
        root = new Node(value);
        return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
template <class T>
bool IntBST<T>::insert(T value, Node *n) {
    if (value == n->info) return false;

    if (value < n->info) {
        if (n->left)        return insert(value, n->left);

        else {
            n->left = new Node(value);
            n->left->parent = n;
            return true;
        }
    }
    else {
        if (n->right)       return insert(value, n->right);

        else {
            n->right = new Node(value);
            n->right->parent = n;
            return true;
        }
    }
}

// print tree data pre-order
template <class T>
void IntBST<T>::printPreOrder() const {
    if(!root)       return;
    else printPreOrder(root);
}

// recursive helper for printPreOrder()
template <class T>
void IntBST<T>::printPreOrder(Node *n) const {
    if (n) {
        cout << n->info << " ";
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
template <class T>
void IntBST<T>::printInOrder() const {
    if(!root)       return;
    else printInOrder(root);
}

template <class T>
void IntBST<T>::printInOrder(Node *n) const {
    if (n) {
        printInOrder(n -> left);
        cout << n -> info << " ";
        printInOrder(n -> right);
    }
}

// prints tree data post-order, with helper
template <class T>
void IntBST<T>::printPostOrder() const {
    if(!root)       return;
    else printPostOrder(root);
}

template <class T>
void IntBST<T>::printPostOrder(Node *n) const {
    if (n) {
        printPostOrder(n -> left);
        printPostOrder(n -> right);
        cout<< n->info << " ";
    }
}

// return sum of values in tree
template <class T>
T IntBST<T>::sum() const {
    return sum(root);
}

// recursive helper for sum
template <class T>
T IntBST<T>::sum(Node *n) const {
    if (n == nullptr)       return 0;
    return ( n->info + sum(n->left) + sum(n->right) );
}

// return count of values
template <class T>
int IntBST<T>::count() const {
    return count(root);
}

// recursive helper for count
template <class T>
int IntBST<T>::count(Node *n) const {
    if (n)      return ( 1 + count(n->left) + count(n->right) );
    return 0;
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
template <class T>
class IntBST<T>::Node*
IntBST<T>::getNodeFor(T value, Node* n) const{

    if (n) {
        if (n -> info == value)         return n;
        else if (n -> info < value)     return (getNodeFor(value, n -> right));
        else if (n -> info > value)     return (getNodeFor(value, n -> left));
    }

    return nullptr;
}

// returns true if value is in the tree; false if not
template <class T>
bool IntBST<T>::contains(T value) const {
    Node* n = root;

    while (n) {
        if (!(getNodeFor(value, n)))        return false;
        else if (value == getNodeFor(value,n) -> info)      return true;
    }

    return false;
}

// returns the Node containing the predecessor of the given value
template <class T>
class IntBST<T>::Node*
IntBST<T>::getPredecessorNode(T value) const{

    Node* n = getNodeFor(value, root);
    Node* temp = n -> left;
    Node* par = n -> parent;

    if (!n)     return nullptr;

    // the rightmost child of the node's left subtree
    // if the node does NOT have a left child, the node's predecessor is its first left ancestor
    if (temp) {
        while (temp -> right)
            temp = temp -> right;
        return temp;
    }

    else {
        while ( ((par -> info) > (n -> info)) && (par != root) )
            par = par -> parent;

        if (par -> info < n -> info)    return par;
    }

    return nullptr;
}

// returns the predecessor value of the given value or 0 if there is none
template <class T>
T IntBST<T>::getPredecessor(T value) const{
    if (getPredecessorNode(value))      return getPredecessorNode(value) -> info;
    else    return NULL;
}

// returns the Node containing the successor of the given value
template <class T>
class IntBST<T>::Node*
IntBST<T>::getSuccessorNode(T value) const{

    Node* n = getNodeFor(value, root);
    Node* temp = n -> right;
    Node* par = n -> parent;

    if (!n)     return NULL;

    // the leftmost child of the node's right subtree
    if (temp) {
        while (temp -> left)
            temp = temp -> left;
        return temp;
    }

    else {
        while ( ((par -> info) < (n -> info)) && (par != root) )
            par = par -> parent;

        if (par -> info > n -> info)        return par;

    }

    return NULL;
}

// returns the successor value of the given value or 0 if there is none
template <class T>
T IntBST<T>::getSuccessor(T value) const{
    if (getSuccessorNode(value))        return getSuccessorNode(value) -> info;
    else    return 0;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
template <class T>
bool IntBST<T>::remove(T value){

    Node* n = getNodeFor(value, root);

    if(!n)      return false

    // Case 1: Remove leaf node
    if (!(n -> left) && !(n -> right)) {
        if (n -> parent == NULL)                root = NULL;
        else if (n -> parent -> left == n)      n -> parent -> left = NULL;
        else                                    n -> parent -> right = NULL;
    }

    // Case 2: Remove node with only LEFT child
    else if (n -> right == NULL) {
        if (n -> parent == NULL)                n = n -> left;
        else if (n -> parent -> left == n)      n -> parent -> left = n -> left;
        else                                    n -> parent -> right = n -> left;
    }

    // Case 3: Remove node with only RIGHT child
    else if (n -> left == NULL) {
        if (n -> parent == NULL)                n = n -> right;
        else if (n -> parent -> left == n)      n -> parent -> left = n -> right;
        else                                    n -> parent -> right = n -> right;
    }

    // Case 4: Remove node with 2 children
    else {

        Node* succ = getSuccessorNode(value);

        while (succ -> left != NULL)
            succ = succ -> left;

        Node* copy = succ;
        remove(succ -> info);
        n -> info = copy -> info;

    }

    return true;
}
