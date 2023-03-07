#include <iostream>
#include <vector>
#include <memory>



namespace DataStructures {


template <typename T>
class BinarySearchTree {

private:

    struct Node {
        T value;
        // We don't need to specify this as a smart pointer because this node
        // doesn't "own" the pointer to parent.
        Node* parent; 
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        explicit Node(const T v = 0) : value(v) {}
    };
    
    std::unique_ptr<Node> root;

    /*
    The successor of node n is the NEXT element in sorted order after n.

    If the node we are finding the successor of has a right subtree,
    we simply return the smallest node in the right subtree which is `min(n->right)`

    If the node does not have a right subtree, we traverse up the tree to the node's
    parent and keep recursing until the node is a LEFT child of the parent node. 
    In other words, we are trying to find the node that has n as its predecessor
    */
    Node* successor(Node* n, T value) {
        if (n->right != nullptr) {  // If we have a right subtree
            return min(n->right);   // return the minimum value in the right subtree   
        }
        else { // If there is no right subtree
            Node* p = n->parent.get();
            while ( (p != nullptr) && (p = n->right) ) {
                n = p;
                p = p->parent;
            }
            return p;
        }
    }

    /*
    The predecessor of node n is the PREVIOUS element in sorted order after n.

    If the node we are finding the successor of has a left subtree,
    we simply return the largest node in the left subtree which is `max(n->left)`

    If the node does not have a left subtree, we traverse up the tree to the node's
    parent and keep recursing until the node is a RIGHT child of the parent node. 
    In other words, we are trying to find the node that has n as its successor
    */
    Node* predecessor(Node* n, T value) {
        if (n->left != nullptr) {   // If we have a right subtree
            return max(n->left);    // return the minimum value in the right subtree   
        }
        else { // If there is no left subtree
            BinaryNode* p = n->parent;
            while ( (p != nullptr) && (p = n->left) ) {
                n = p;
                p = p->parent;
            }
            return p;
        }
    }

    /*
    Replaces node u with node v in the binary tree and deletes node u
    This operation also rewires the parent/children connections of u with v
    */
    Node* transplant(Node* u, Node* v) {
        if (u->parent == nullptr) { // If u is the root
            root = v;               // replace the root with v
        }
        else if (u == u->parent->left) {    // If u is a left child
            u->parent->left = v;            // Replace the left child with v         
        }
        else {                              // If u is a right child
            u->parent->right = v;           // replace the right child with v
        }
        if (v != nullptr) {
            v->parent = u->parent;          // Set v's parent to u's parent
        }
        //delete u;                           // Delete node u from memory
    }

public:
    BinarySearchTree(const int v) {
        root = std::make_unique<Node>(v);
    }

    void insert_node(Node* n) {

    }

    /*
    Case 1: n has are no children
    Just delete the node

    Case 2: n has one child
    "splice" out the node. Set the nodes value to the childs value

    Case 2: n has two children
    main goal: Replace n with its succesor.
    1. If the successor is NOT a direct decendant of n, meaning its not a direct left or right child,
       we can't just transplant n and the successor. This is because the successors children will be dragged up the tree with it. 
       to mitigate this, we first need to link the successors right child (it only has a right child because its a leaf)
       to the successors parent. This leaves the successor as a floating clean node with no left or right children. The successor 
       now needs to prepare for the transplant with n. We first link the successors right child with n's right child,
       and we set the right child's parent to the successor so it doesnt point to n anymore. This right child assignment doesn't apply
       if the successor is a direct decandant because the successor IS the right child. Once it gets moved up to n's position. the right child
       of the sucessor will already be in the right place
    2. The final part is to transplant n with the successor and link n's left child to the successors left child
    */
    void delete_node(Node* n) {
        if (n->left == nullptr) {       // If node n only has a right child
            transplant(n, n->right);    // Set n to n's right child
        }
        else if (n->right == nullptr) { // If node n only has a left child
            transplant(n, n->left);     // Set n to n's left child
        }
        else {
            Node* succ = min(n->right);   // Get the successor of n
            if (succ->parent != n) {            // If the successor is NOT a direct decendant of n
                transplant(succ, succ->right);  // Replace the successor node with its right child
                succ->right = n->right;         // assign the new parent's (successor) right child with the previous parent's right child
                succ->right->parent = succ;     // Reassign the right child's parent to the new parent
            }
            transplant(n, succ);                // Replace old parent with new parent
            succ->left = n->left;               // Set new left to old left
            succ->left->parent = succ;          // Reassign the left child's parent to the new parent
        }
    }
    Node* find(Node* n, T value) {

    }
    Node* find_iter(Node* n, T value) {

    }
    Node* max(Node* n) {

    }
    Node* min(Node* n) {

    }
};


template <typename T>
Node* BinarySearchTree<T>::successor(Node* n, T value) {
    if (n->right != nullptr) {  // If we have a right subtree
        return min(n->right);   // return the minimum value in the right subtree   
    }
    else { // If there is no right subtree
        BinaryNode* p = n->parent;
        while ( (p != nullptr) && (p = n->right) ) {
            n = p;
            p = p->parent;
        }
        return p;
    }
}


/*
The successor of node n is the PREVIOUS element in sorted order after n.

If the node we are finding the successor of has a left subtree,
we simply return the largest node in the left subtree which is `max(n->left)`

If the node does not have a left subtree, we traverse up the tree to the node's
parent and keep recursing until the node is a RIGHT child of the parent node. 
In other words, we are trying to find the node that has n as its successor
*/
BinaryNode* BinarySearchTree::predecessor(BinaryNode* n, int value) {
    if (n->left != nullptr) {   // If we have a right subtree
        return max(n->left);    // return the minimum value in the right subtree   
    }
    else { // If there is no left subtree
        BinaryNode* p = n->parent;
        while ( (p != nullptr) && (p = n->left) ) {
            n = p;
            p = p->parent;
        }
        return p;
    }
}

/*
replaces node u with node v in the binary tree
*/
BinaryNode* BinarySearchTree::transplant(BinaryNode* u, BinaryNode* v) {
    if (u->parent == nullptr) { // If u is the root
        root = v;               // replace the root with v
    }
    else if (u == u->parent->left) {    // If u is a left child
        u->parent->left = v;            // Replace the left child with v         
    }
    else {                              // If u is a right child
        u->parent->right = v;           // replace the right child with v
    }
    if (v != nullptr) {
        v->parent = u->parent;          // Set v's parent to u's parent
    }
    //delete u;                           // Delete node u from memory
}

void BinarySearchTree::insert_node(BinaryNode* n) {

}

/*
--------------------------------------------------------------------------------
Case 1: n has are no children
--------------------------------------------------------------------------------
Just delete the node!


--------------------------------------------------------------------------------
Case 2: n has one child
--------------------------------------------------------------------------------
"splice" out the node. Set the nodes value to the childs value

--------------------------------------------------------------------------------
Case 2: n has two children
--------------------------------------------------------------------------------
Replace n with its succesor

*/
void BinarySearchTree::delete_node(BinaryNode* n) {
    if (n->left == nullptr) {       // If node n only has a right child
        transplant(n, n->right);    // Set n to n's right child
    }
    else if (n->right == nullptr) { // If node n only has a left child
        transplant(n, n->left);     // Set n to n's left child
    }
    else {
        BinaryNode* succ = min(n->right); // Get the successor of n
        if (succ->parent != n) { // If the successor is NOT a direct decendant of n
            transplant(succ, succ->right);  // Replace the successor node with its right child
            succ->right = n->right;         // assign the new parent's (successor) right child with the previous parent's right child
            succ->right->parent = succ;     // Reassign the right child's parent to the new parent
        }
        transplant(n, succ);                // Replace old parent with new parent
        succ->left = n->left;               // Set new left to old left
        succ->left->parent = succ;          // Reassign the left child's parent to the new parent
    }
}

/*
Searches the binary tree from node n for the value `value`
Uses a RECURSIVE approach

Worst case  - O(height)
Avg case    - O(height)
Best case   - O(1)
*/
BinaryNode* BinarySearchTree::find(BinaryNode* n, int value) {
    if (n == nullptr || value == n->value) {
        return n;
    }
    else if (value < n->value) {
        return find(n->left, value);
    }
    else {
        return find(n->right, value);
    }
}

/*
Searches the binary tree from node n for the value `value`
Uses an ITERATIVE approach

Worst case  - O(height)
Avg case    - O(height)
Best case   - O(1)
*/
BinaryNode* BinarySearchTree::find_iter(BinaryNode* n, int value) {
    while (n != nullptr || n->value != value) {
        if (value < n->value) {
            n = n->left;
        }
        else {
            n = n->right;
        }
    }
    return n;
}

/*
Returns the max element in the binary search tree.
The max element is located at the RIGHTMOST leaf node so we traverse
over each right node starting at node n until we hit a leaf node
*/
BinaryNode* BinarySearchTree::max(BinaryNode* n) {
    while (n->right != nullptr) {
        n = n->right;
    }
    return n;
}

/*
Returns the min element in the binary search tree.
The min element is located at the LEFTMOST leaf node so we traverse
over each left node starting at node n until we hit a leaf node
*/
BinaryNode* BinarySearchTree::min(BinaryNode* n) {
    while (n->left != nullptr) {
        n = n->left;
    }
    return n;
}












}