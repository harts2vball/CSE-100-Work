/*
 * Names: Yejia Zhang and Brian Ng
 * Date: 10/4/16
 * Filename: BSTNode.hpp
 * Description: Declares and implements the BSTNode class with its instance 
 *   variables, methods, and constructor.
 */

#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

/**class BSTNode:
 * Defines a class BSTNode which serves as a BST Node object that takes in
 * generic types.
 */
template<typename Data>
class BSTNode {

public:

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /** Constructor.  
   * Parameters: 
   *   d - pass by reference of the data for the node of type Data
   * Returns: N/A
   * Description: Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d);


  /**successor()
   * Parameters: N/A
   * Returns: A pointer to the successor of this node in a BST.
   * Description: Return the successor of this BSTNode in a BST, or 0 if none.
   *   PRECONDITION: this BSTNode is a node in a BST.
   *   POSTCONDITION:  the BST is unchanged.
   *   RETURNS: the BSTNode that is the successor of this BSTNode,
   *   or 0 if there is none.
   */
  BSTNode<Data>* successor(); 

}; 


// Function definitions
// For a templated class it's easiest to just put them in the same file as the class declaration

/** Constructor.  
   * Parameters: 
   *   d - pass by reference of the data for the node of type Data
   * Returns: N/A
   * Description: Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
template <typename Data>
BSTNode<Data>::BSTNode(const Data & d) : left(0), right(0), parent(0), data(d) {}

/**successor()
   * Parameters: N/A
   * Returns: The a pointer to the successor of this node in a BST.
   * Description: Return the successor of this BSTNode in a BST, or 0 if none.
   *   PRECONDITION: this BSTNode is a node in a BST.
   *   POSTCONDITION:  the BST is unchanged.
   *   RETURNS: the BSTNode that is the successor of this BSTNode,
   *   or 0 if there is none.
   */
template <typename Data>
BSTNode<Data>* BSTNode<Data>::successor()
{
  BSTNode<Data>* curr = right;
  if (curr) {
    /* Check right child */
    while (curr->left) {
      curr = curr->left;
    }
    return curr;
  } else {
    /* No right child, need to traverse up until we find that the parent's left child is the current child */
    curr = this;
    BSTNode* prev = this;
    while (curr->left != prev) {
      if (!(curr->parent)) return NULL;
      prev = curr;
      curr = curr->parent;
    }
    return curr;
  }
}

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
