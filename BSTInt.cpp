/*
 * Names: Yejia Zhang and Brian Ng
 * Date: 10/4/16
 * Filename: BSTInt.cpp
 * Description: Implements the functionality of BSTInt from the class defined in
 *   BSTInt.h.
 */

#include "BSTInt.h"

/* Function definitions for a int-based BST class */


/** Destructor.
  *  Parameters: N/A
  *  Returns: N/A
  *  Description: Deletes every node in BST.
  */
BSTInt::~BSTInt() {
  //reset height and size
  iheight = 0;
  isize = 0;
  
  //free node mem
  deleteAll(root);
}

/* insert(int item)
 * Parameter:
 *   item - integer data to insert into the BST
 * Returns: True if insert successful, False if item already in BST.
 * Description: Given a reference to a Data item, insert a copy of it in this 
 *   BST. Return  true if the item was added to this BST
 *   as a result of this call to insert,
 *   false if an item equal to this one was already in this BST.
 *   Note: This function should use only the '<' operator when comparing
 *   Data items. (should not use ==, >, <=, >=)  For the reasoning
 *   behind this, see the assignment writeup.
 */
bool BSTInt::insert(int item)
{
  /** To keep track of the height of the node being inserted */
  unsigned int currHeight = 0;

  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    return true;
  }

  BSTNodeInt* curr = root;
  
  while (curr->left || curr->right) {
    if (item < curr->data) {
      if (curr->left) {
        curr = curr->left;
        currHeight++;
      }
      else break;
    }
    else if (curr->data < item) {
      if (curr->right) {
        curr = curr->right;
        currHeight++;
      } 
      else break;
    }
    else {
      return false;
    }
  }

  // Ready to insert
  if (item < curr->data) {
    BSTNodeInt* newNode = new BSTNodeInt(item);
    curr->left = newNode;
    newNode->parent = curr;
  }
  else if (curr->data < item) {
    BSTNodeInt* newNode = new BSTNodeInt(item);
    curr->right = newNode;
    newNode->parent = curr;
  } else {
    return false;
  }

  if (iheight < ++currHeight) iheight = currHeight;

  ++isize;
  return true;

}


/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{
  BSTNodeInt* curr = root;
  while (curr) {
    if (curr->data < item) {
      curr = curr->right;
    }
    else if (item < curr->data) {
      curr = curr->left;
    }
    else {
      return true;
    }
  }
  return false;
}

  
/** Return the number of items currently in the BST.
 */
unsigned int BSTInt::size() const 
{
  return isize;
}

  
/** Return the height of the BST.
    Height of tree with just root node is 0
 */
unsigned int BSTInt::height() const
{
  return iheight;
}


/** Return true if the BST is empty, else false. 
 */
bool BSTInt::empty() const 
{
  return (size() == 0) ? true : false;
}




/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{
  if (n->left) BSTInt::deleteAll(n->left);
  if (n->right) BSTInt::deleteAll(n->right);
  delete n;
}
