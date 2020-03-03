/*
Author: Peter Jin
Date: 2/10/20
Binary Search Tree class header
*/

#ifndef BST_H
#define BST_H

#include "Node.h"

class BST {

 public:

  //Constructor
  BST();

  //Add node
  void addNode(int);

  //Delete node by value
  void deleteNode(int);

  //Display tree
  void displayTree();

  //Search tree
  bool search(int);
  
  //Destructor
  ~BST();

 private:

  void addNode(Node*&, int);
  bool deleteNode(Node*&, int);
  void displayTree(Node*, int);
  bool search(Node*, int);
  Node* head;

};

#endif
