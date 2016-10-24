/*
 * Names: Yejia Zhang and Brian Ng
 * Date: 10/4/16
 * Filename: testBST.cpp
 * Description: Tester file to test both BSTInt and generic BST
 *   implementations.
 */

#include "BSTInt.h"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2016
 * Author: Christine Alvarado and YOU
 *
 * TEST 1
 */
int main() {

  /* Create an STL vector of some ints */
  /*test*/

  cout << "\n\nSTARTING TEST 1:" << endl;

  vector<int> v;
  v.push_back(3);
  v.push_back(4);
  v.push_back(1);
  v.push_back(100);
  v.push_back(-33);

  /* Create an instance of BST holding int */
  BSTInt b;

  // Could use: for(auto item : v) { instead of the line below
  cout << "Inserting 3, 4, 1, 100, -33" << endl;
  for(int item : v) {
      bool pr = b.insert(item);
      if(! pr ) {
          cout << "Incorrect bool return value when inserting " << item 
               << endl;
          return -1;
      }
  }
  cout << "Insertion successful!" << endl;


  /* Test size. */
  cout << "Size is: " << b.size() << endl;
  if(b.size() != v.size()) {
      cout << "... which is incorrect." << endl;
      return -1;
  }

  /* Test find return value. */
  // Test the items that are already in the tree
  for(int item : v) {
      if(!b.find(item)) {
          cout << "Incorrect return value when finding " << item << endl;
          return -1;
      }
  }


  /*
   * TEST 2:
   * Test for tree with root (6) and one left node (4) while inserting 3.
   */
  /* Create an STL vector of some ints */
  

  cout << "\n\nSTARTING TEST 2: SIMPLE TREE" << endl;

  /*test*/
  vector<int> v1;
  v1.push_back(6);
  v1.push_back(4);
  v1.push_back(3);

  /* Create an instance of BST holding int */
  BSTInt b1;

  cout << "Inserting 6, 4, and 3.." << endl;
  // Could use: for(auto item : v) { instead of the line below
  for(int item : v1) {
      bool pr = b1.insert(item);
      if(! pr ) {
          cout << "Incorrect bool return value when inserting " << item 
               << endl;
          return -1;
      }
  }
  cout << "Insertion successful!" << endl;


  /* Test size. */
  cout << "Size is: " << b1.size() << endl;
  if(b1.size() != v1.size()) {
      cout << "... which is incorrect." << endl;
      return -1;
  }

  /* Test find return value. */
  // Test the items that are already in the tree
  for(int item : v1) {
      if(!b1.find(item)) {
          cout << "Incorrect return value when finding " << item << endl;
          return -1;
      }
  }

  cout << "TEST 2 COMPLETED SUCCESSFULLY!" << endl;

 
  /*
   * TEST 3:
   * Series of tests ending in a linked list tree.
   *
   * Test for empty tree.
   * Inserts 5 then tests for height, size, empty, find.
   * Inserts 5 again and sees if insert fails.
   * Inserts -10..-15 then tests for h, s, empty, find.
   */

  cout << "\n\nSTARTING TEST 3: LINKED LIST TREE" << endl;

  /* Create an instance of BST holding int */
  BSTInt b4;

  //Test for empty function
  if( !b4.empty() ) {
      cout << "Incorrect implementation of empty()! " << "Should be empty!" 
      << endl;
      return -1;
  }
  //Test for height function
  if( b4.height() != 0 ) {
      cout << "Incorrect implementation of height()! " << endl;
      return -1;
  }
  //Test for size function
  if( b4.size() != 0 ) {
      cout << "Incorrect implementation of size()!" << endl;
      return -1;
  }

  //Creates a root node
  if( !b4.insert(5) ) {
      cout << "Error creating root node when inserting 5" 
          << endl;
      return -1;
  }
  //Test for empty function
  if( b4.empty() ) {
      cout << "Incorrect implementation of empty()! " << "After inserting 5." 
      << endl;
      return -1;
  }
  //Test for height function
  if( b4.height() != 0 ) {
      cout << "Incorrect implementation of height()! " << endl;
      return -1;
  }
  //Test for search function
  if( !b4.find(5) ) {
      cout << "Unable to find 5! Incorrect implementation of find()!"<<endl;
      return -1;
  }
  //Another Test for search function
  if( b4.find(0) ) {
      cout << "Incorrect implementation of find()! No 0 in tree." << endl;
      return -1;
  }
  //Test for size function
  if( b4.size() != 1 ) {
      cout << "Incorrect implementation of size()!"<<endl;
      return -1;
  }

  //Attempts to insert 5 again
  if( b4.insert(5) ) {
      cout << "Error: tree should not allow duplicates!" 
          << endl;
      return -1;
  }
  //Test for empty function
  if( b4.empty() ) {
      cout << "Incorrect implementation of empty()! " << 
          "After inserting 5 after the first 5." << endl;
      return -1;
  }
  //Test for height function
  if( b4.height() != 0 ) {
      cout << "Incorrect implementation of height()! " << 
          "Should be 0 after trying to insert 5 again" << endl;
      return -1;
  }
  //Test for search function
  if( !b4.find(5) ) {
      cout << "Unable to find 5! Incorrect implementation of find()!"<<endl;
      return -1;
  }
  //Test for size function
  if( b4.size() != 1 ) {
      cout << "Incorrect implementation of size()! " << 
          "Should be 1 after trying to insert 5 twice" <<endl;
      return -1;
  }

  cout << "Tests with empty tree, tree with only root node " << 
      "and duplicate entries passed!" << endl;
  cout << "Inserting -10,-11...-15" << endl;
  //Insert -10..-15
  for(int i = -10; i >= -15; i--) {
      bool pr = b4.insert(i);
      if(! pr ) {
          cout << "Incorrect bool return value when inserting " << i
               << endl;
          return -1;
      }
  }
  //Test for empty function
  cout << "Tree is empty: " << b4.empty() << endl;
  if( b4.empty() ) {
      cout << "...which is incorrect!" << endl;
      return -1;
  }
  //Test for height function
  cout << "Height is: " << b4.height() << endl;
  if(b4.height() != 6) {
      cout << "...which is incorrect!" << endl;
      return -1;
  }
  //Test for size function
  cout << "Height is: " << b4.size() << endl;
  if( b4.size() != 7 ) {
      cout << "...which is incorrect!"<<endl;
      return -1;
  }
  //Test for find
  for( int i = -10; i >= -15; i-- )
  {
      if( !b4.find(i) ) {
      cout << "Unable to find " << i << 
          "! Incorrect implementation of find()!" <<endl;
      return -1;
      }
  }

  cout << "TEST 3 COMPLETED SUCCESSFULLY!" << endl;


  /*
   * TEST 4:
   * Series of tests ending in a balanced tree.
   *
   * Inserts 20,10,5,2,6,15,17,13,30,35,37,33,25,23,27.
   * then tests for height, size, find.
   * Tries to insert 23 again.
   * Deletes tree
   *
   */

  cout << "\n\nSTARTING TEST 4: BALANCED TREE" << endl;

  vector<int> v6;
  v6.push_back(20);
  v6.push_back(10);
  v6.push_back(5);
  v6.push_back(2);
  v6.push_back(6);
  v6.push_back(15);
  v6.push_back(17);
  v6.push_back(13);
  v6.push_back(30);
  v6.push_back(35);
  v6.push_back(37);
  v6.push_back(33);
  v6.push_back(25);
  v6.push_back(23);
  v6.push_back(27);

  /* Create an instance of BST holding int */
  BSTInt b6;

  cout << "Inserting 15 items into balanced tree..." << endl;
  // Could use: for(auto item : v) { instead of the line below
  for(int item : v6) {
      bool pr = b6.insert(item);
      if(! pr ) {
          cout << "Incorrect bool return value when inserting " << item 
               << endl;
          return -1;
      }
  }
  cout << "Insertion successful!" << endl;
  //Test Size
  cout << "Size is: " << b6.size() << endl;
  if(b6.size() != v6.size()) {
      cout << "... which is incorrect." << endl;
      return -1;
  }
  //Test Height
  cout << "Height is: " << b6.height() << endl;
  if(b6.height() != 3) {
      cout << "... which is incorrect." << endl;
      return -1;
  }
  // Test the items that are already in the tree
  for(int item : v6) {
      if(!b6.find(item)) {
          cout << "Incorrect return value when finding " << item << endl;
          return -1;
      }
  }    

  cout << "TEST 4 COMPLETED SUCCESSFULLY!" << endl;



// =============================================================================
// ********** TESTS FOR BST BELOW****************
// =============================================================================

  
  // Test the template version of the BST  with ints 
  BST<int> btemp;
  for (int item : v) {
      // The auto type here is the pair of BSTIterator<int>, bool
      cout << "Inserting " << item << " into the int template-based BST...";
      auto p = btemp.insert(item);
      if (*(p.first) != item) {
          cout << "Wrong iterator returned.  "
               << "Expected " << item << " but got " << *(p.first) << endl;
          return -1;
      }
      if (!p.second) {
          cout << "Wrong boolean returned.  Expected true but got " 
               << p.second << endl;
          return -1;
      }
      cout << "success!" << endl;
            
  }

  // Now test finding the elements we just put in
  for (int item: v) {
      cout << "Finding " << item << "...." << endl;
      BSTIterator<int> foundIt = btemp.find(item);
      if (*(foundIt) != item) {
          cout << "incorrect value returned.  Expected iterator pointing to "
               << item << " but found iterator pointing to " << *(foundIt) 
               << endl;
          return -1;
      }
      cout << "success!" << endl;
  }



  // Test the iterator: The iterator should give an in-order traversal

  // Sort the vector, to compare with inorder iteration on the BST
  sort(v.begin(),v.end());

  cout << "traversal using iterator..." << endl;
  auto vit = v.begin();
  auto ven = v.end();

  // This is equivalent to BSTIterator<int> en = btemp.end();
  auto en = btemp.end();

  //This is equivalent to BST<int>::iterator it = btemp.begin();
  auto it = btemp.begin();
  for(; vit != ven; ++vit) {
      if(! (it != en) ) {
          cout << *it << "," << *vit 
               << ": Early termination of BST iteration." << endl;
          return -1;

      }
      cout << *it << endl;
      if(*it != *vit) {
          cout << *it << "," << *vit 
               << ": Incorrect inorder iteration of BST." << endl;
          return -1;
      }
      ++it;
  }

  cout << "success!" << endl;

//------------------------------------------------------------------------------
  /* TEST 1: Balanced Int Tree
  * Tests for: 
  *   empty tree
  *   balanced tree - size, height,
  *   deleteAll - size, height, memory
  */
  cout << "\n\nSTARTING CUSTOM BST TEST 1: BALANCED TREE" << endl;

  /* Create new BST for test */
  BST<int> *BST1 = new BST<int>();

  //Test isEmpty()
  cout << "isEmpty? " << BST1->empty() << endl;
  if(!(BST1->empty())) {
      cout << "... which is incorrect." << endl;
      return -1;
  }

  //reuses v6 from before: Inserts 20,10,5,2,6,15,17,13,30,35,37,33,25,23,27.
  for (int item : v6) {
      // The auto type here is the pair of BSTIterator<int>, bool
      cout << "Inserting " << item << " into the int template-based BST...";
      auto p = BST1->insert(item);
      if (*(p.first) != item) {
          cout << "Wrong iterator returned.  "
               << "Expected " << item << " but got " << *(p.first) << endl;
          return -1;
      }
      if (!p.second) {
          cout << "Wrong boolean returned.  Expected true but got " 
               << p.second << endl;
          return -1;
      }
      cout << "success!" << endl;
            
  }

  //Test Size
  cout << "Size is: " << BST1->size() << endl;
  if(BST1->size() != v6.size()) {
      cout << "... which is incorrect." << endl;
      return -1;
  }
  //Test isEmpty()
  cout << "isEmpty? " << BST1->empty() << endl;
  if(BST1->empty()) {
      cout << "... which is incorrect." << endl;
      return -1;
  }
  //Test Height
  cout << "Height is: " << BST1->height() << endl;
  if(BST1->height() != 3) {
      cout << "... which is incorrect." << endl;
      return -1;
  }
  // Test find
  for(auto item : v6) {
      auto b = BST1->find(item);
      if(*(b) != item) {
          cout << "Incorrect return value when finding " << item << endl;
          return -1;
      }
  }

  //tests for insert duplicate
  cout << "Attempting duplicate insert..should fail.";
  auto p = BST1->insert(20);
  if (*(p.first) != 20) {
    cout << "Wrong iterator returned.  "
      << "Expected " << 20 << " but got " << *(p.first) << endl;
    return -1;
  }
  if (p.second) {
    cout << "Wrong boolean returned.  Expected true but got " 
        << p.second << endl;
    return -1;
  }
  cout << "success!" << endl;

  //REMOVES all nodes
  delete BST1;

  cout << "BST CUSTOM TEST 1 COMPLETED SUCCESSFULLY!" << endl;





  cout << "\nAll tests passed!" << 
      "\n-----------------\n" << endl;
  return 0;
}
