/*
 * Names: Yejia Zhang and Brian Ng
 * Date: 10/4/16
 * Filename: BST.hpp
 * Description: Declares and implements a BST object with its instance 
 *   variables, methods, constructor, and destructor.
 */

#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

/**class BST:
 * Defines a class BST which serves as a BST object that takes in
 * generic types as data.
 */
template<typename Data>
class BST {

public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
   *  Parameters: N/A
   *  Returns: N/A
   *  Description: Initialize an empty BST.
   */
  BST() : root(nullptr), isize(0) {}


  /** Destructor.
   *  Parameters: N/A
   *  Returns: N/A
   *  Description: Deletes every node in BST.
   */
  ~BST();

  /** insert(const Data & item)
   *  Parameters: 
   *    item - reference to the data to be inserted of type Data
   *  Returns:
   *    std::pair<iterator, bool> - a pair object that contains a boolean var
   *      that indicates whether the insertion was successful or not and also
   *      an iterator object that points either to the newly inserted node or an
   *      existing node with the same data.
   *  Description: Given a reference to a Data item, insert a copy of it in 
   *    this BST. Return a pair where the first element is an iterator 
   *    pointing to either the newly inserted element or the element 
   *    that was already in the BST, and the second element is true if the 
   *    element was newly inserted or false if it was already in the BST.
   * 
   *    Note: This function should use only the '<' operator when comparing
   *    Data items. (should not use ==, >, <=, >=)  
   */
  std::pair<iterator, bool> insert(const Data& item);

  /** find( const Data & item )
   *  Parameters: 
   *    item - reference to data of type Data to find in the BST
   *  Returns:
   *    std::pair<iterator, bool> - a pair object that contains a boolean var
   *      that indicates whether item was found and an iterator object that 
   *      points to either the found node or a nullptr
   *  Description: Find a Data item in the BST.
   *    Return an iterator pointing to the item, or pointing past
   *    the last node in the BST if not found.
   *    Note: This function should use only the '<' operator when comparing
   *    Data items. (should not use ==, >, <=, >=).  For the reasoning
   *    behind this, see the assignment writeup.
   */
  iterator find(const Data& item) const;

  /** size()
   *  Parameters: N/A
   *  Returns: 
   *    unsigned int - indicates the number of nodes currently in BST
   *  Description: Return the number of items currently in the BST.
   */ 
  unsigned int size() const;
  
  /** height()
   *  Parameters: N/A
   *  Returns: 
   *    unsigned int - Height of tree.
   *  Description: Return the height of the BST - starts with root at height 0
   */ 
  unsigned int height() const;

  /** empty()
   *  Parameters: N/A
   *  Returns:
   *    bool - indicates if BST is empty or not
   *  Description: Return true if the BST is empty, else false.
   */ 
  bool empty() const;

  /** begin()
   *  Parameters: N/A
   *  Returns:
   *    iterator - iterator object pointing to the smallest item in BST
   *  Description: Return an iterator pointing to the first (smallest) item in
   *   the BST.
   */ 
  iterator begin() const;

  /** end()
   *  Parameters: N/A
   *  Returns:
   *    iterator - iterator object pointing past the last item in the BST.
   *  Description: Return an iterator pointing past the last item in the BST.
   */
  iterator end() const;


private:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;
  
  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** Height of the tree */
  unsigned int iheight = 0;

  /** first(BSTNode<Data> * root)
   *  Parameters:
   *    root - a pointer to the root node of the BST
   *  Returns: 
   *    BSTNode<Data>* - pointer to the node with smallest element of the BST
   *  Description: Find the first element of the BST
   *    Helper function for the begin method above.
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root);

  /** deleteAll(BSTNode<Data>* n)
   *  Parameters:
   *    n - pointer to a node to delete on the heap
   *  Returns: N/A
   *  Description: Do a postorder traversal, deleting nodes
   */
  static void deleteAll(BSTNode<Data>* n);
 };


// =============================================================================
// ********** IMPLEMENTATION OF ABOVE FUNCTIONS ****************
// =============================================================================


/** Default destructor.
  *  Parameters: N/A
  *  Returns: N/A
  *  Description: Deletes every node in BST.
  */
template <typename Data>
BST<Data>::~BST() {
  //reset size and height
  iheight = 0;
  isize = 0;

  //delete nodes
  deleteAll(root);
}


/** insert(const Data & item)
  *  Parameters: 
  *    item - reference to the data to be inserted of type Data
  *  Returns:
  *    std::pair<iterator, bool> - a pair object that contains a boolean var
  *      that indicates whether the insertion was successful or not and also
  *      an iterator object that points either to the newly inserted node or an
  *      existing node with the same data.
  *  Description: Given a reference to a Data item, insert a copy of it in 
  *    this BST. Return a pair where the first element is an iterator 
  *    pointing to either the newly inserted element or the element 
  *    that was already in the BST, and the second element is true if the 
  *    element was newly inserted or false if it was already in the BST.
  * 
  *    Note: This function should use only the '<' operator when comparing
  *    Data items. (should not use ==, >, <=, >=)  
  */
template <typename Data>
std::pair<BSTIterator<Data>, bool> BST<Data>::insert(const Data& item) {
  // HINT: Copy code from your BSTInt class and change the return value
    /** To keep track of the height of the node being inserted */
  unsigned int currHeight = 0;

  if (!root) {
    root = new BSTNode<Data>(item);
    ++isize;
    return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(root), true);
  }

  BSTNode<Data>* curr = root;
  
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
      return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(curr), false);
    }
  }

  // Ready to insert
  BSTNode<Data>* newNode = NULL;
  if (item < curr->data) {
    newNode = new BSTNode<Data>(item);
    curr->left = newNode;
    newNode->parent = curr;
  }
  else if (curr->data < item) {
    newNode = new BSTNode<Data>(item);
    curr->right = newNode;
    newNode->parent = curr;
  } else {
    return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(curr), false);
  }

  if (iheight < ++currHeight) iheight = currHeight;

  ++isize;

  return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(newNode), true);

}


/** find( const Data & item )
  *  Parameters: 
  *    item - reference to data of type Data to find in the BST
  *  Returns:
  *    std::pair<iterator, bool> - a pair object that contains a boolean var
  *      that indicates whether item was found and an iterator object that 
  *      points to either the found node or a nullptr
  *  Description: Find a Data item in the BST.
  *    Return an iterator pointing to the item, or pointing past
  *    the last node in the BST if not found.
  *    Note: This function should use only the '<' operator when comparing
  *    Data items. (should not use ==, >, <=, >=).  For the reasoning
  *    behind this, see the assignment writeup.
  */
template <typename Data>
BSTIterator<Data> BST<Data>::find(const Data& item) const
{
  BSTNode<Data>* curr = root;
  while (curr) {
    if (curr->data < item) {
      curr = curr->right;
    }
    else if (item < curr->data) {
      curr = curr->left;
    }
    else {
      return BSTIterator<Data>(curr);
    }
  }
  return BSTIterator<Data>(nullptr);

}

  
/** size()
  *  Parameters: N/A
  *  Returns: 
  *    unsigned int - indicates the number of nodes currently in BST
  *  Description: Return the number of items currently in the BST.
  */ 
template <typename Data>
unsigned int BST<Data>::size() const
{
  return isize;
}

/** height()
  *  Parameters: N/A
  *  Returns: 
  *    unsigned int - Height of tree.
  *  Description: Return the height of the BST - starts with root at height 0
  */ 
template <typename Data> 
unsigned int BST<Data>::height() const
{
  return iheight;
}


/** empty()
  *  Parameters: N/A
  *  Returns:
  *    bool - indicates if BST is empty or not
  *  Description: Return true if the BST is empty, else false.
  */ 
template <typename Data>
bool BST<Data>::empty() const
{
  return (isize == 0) ? true : false;
}

/** begin()
 *  Parameters: N/A
 *  Returns:
 *    iterator - iterator object pointing to the smallest item in BST
 *  Description: Return an iterator pointing to the first (smallest) item in
 *   the BST.
 */ 
template <typename Data>
BSTIterator<Data> BST<Data>::begin() const
{
  return BSTIterator<Data>(first(root));
}

/** end()
  *  Parameters: N/A
  *  Returns:
  *    iterator - iterator object pointing past the last item in the BST.
  *  Description: Return an iterator pointing past the last item in the BST.
  */
template <typename Data>
BSTIterator<Data> BST<Data>::end() const
{
  return BSTIterator<Data>(nullptr);
}

/** first(BSTNode<Data> * root)
  *  Parameters:
  *    root - a pointer to the root node of the BST
  *  Returns: 
  *    BSTNode<Data>* - pointer to the node with smallest element of the BST
  *  Description: Find the first element of the BST
  *    Helper function for the begin method above.
  */ 
template <typename Data>
BSTNode<Data>* BST<Data>::first(BSTNode<Data>* root)
{
  BSTNode<Data>* curr = root;
  while (curr->left) {
      curr = curr->left;
  }
  return (curr) ? curr : nullptr;
}

/** deleteAll(BSTNode<Data>* n)
  *  Parameters:
  *    n - pointer to a node to delete on the heap
  *  Returns: N/A
  *  Description: Do a postorder traversal, deleting nodes
  */
template <typename Data>
void BST<Data>::deleteAll(BSTNode<Data>* n)
{
  if (n->left) BST::deleteAll(n->left);
  if (n->right) BST::deleteAll(n->right);
  delete n;
}



#endif //BST_HPP
