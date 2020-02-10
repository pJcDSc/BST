/*
Author: Peter Jin
Date: 2/10/20
Binary Search Tree Class
*/

#include "BST.h"
#include "Node.h"
#include <iostream>

using namespace std;

//Constructor
BST::BST() {
  Node* head = NULL;
}

//Public addNode function
void BST::addNode(int n){
  addNode(head, n);
}

//private addnode function
void BST::addNode(Node* h, int n) {
  if (h == NULL) {
    head = new Node(n);
    return;
  }
  else if (n < h -> getValue()) {
    if (h -> getLeft() == NULL) {
      h -> setLeft(new Node(n));
      h -> getLeft() -> setParent(h);
      return;
    }
    addNode(h -> getLeft(), n);
    return;
  }
  else {
    if (h -> getRight() == NULL) {
      h -> setRight(new Node(n));
      h -> getRight() -> setParent(h);
      return;
    }
    addNode(h -> getRight(), n);
    return;
  }
}

//public deletenode function
void BST::deleteNode(int n) {
  deleteNode(head, n);
}

//private deletenode function
void BST::deleteNode(Node* h, int n) {
  if (h == NULL) {
    cout << "Empty Tree or Node not found" << endl;
    return;
  }
  //Node to delete found
  if (h -> getValue() == n) {
    if (h -> getLeft() == NULL && h -> getRight() == NULL) { //0 children
      if (h == h -> getParent() -> getLeft()) h -> getParent() -> setLeft(NULL);
      else h -> getParent() -> setRight(NULL);
      delete h;
    }
    else if (h -> getLeft() == NULL) { //right child
      h -> setValue(h -> getRight() -> getValue()); //Set value to right child's value
      delete h -> getRight();
      h -> setRight(NULL);
    }
    else if (h -> getRight() == NULL) { //left child
      h -> setValue(h -> getLeft() -> getValue()); //Set value to left child's value
      delete h -> getLeft();
      h -> setLeft(NULL);
    }
    else {
      //Get inorder successor (only called on upper nodes, so don't need to deal with leaves)
      Node* temp = h -> getRight();
      while (temp -> getLeft()) {
	temp = temp -> getLeft();
      }

      //Swap values as normal
      h -> setValue(temp -> getValue());
      if (temp == temp -> getParent() -> getRight()) temp -> getParent() -> setRight(NULL); //make parent pointer to leaf null
      else temp -> getParent() -> setLeft(NULL);

      delete temp;
    }
  }

  if (n < h -> getValue()) {
    if (h -> getLeft() == NULL) {
      cout << "Node not found" << endl;
      return;
    }
    deleteNode(h -> getLeft(), n);
  }
  else {
    if (h -> getRight() == NULL) {
      cout << "Node not found" << endl;
      return;
    }
    deleteNode(h -> getRight() , n);
  }
}

