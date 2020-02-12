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
  head = NULL;
}

//Public addNode function
void BST::addNode(int n){
  addNode(head, n);
}

//private addnode function
void BST::addNode(Node* &h, int n) {
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
    Node* left = h -> getLeft();
    addNode(left, n);
    return;
  }
  else {
    if (h -> getRight() == NULL) {
      h -> setRight(new Node(n));
      h -> getRight() -> setParent(h);
      return;
    }
    Node* right = h -> getRight();
    addNode(right, n);
    return;
  }
}

//public deletenode function
void BST::deleteNode(int n) {
  deleteNode(head, n);
}

//private deletenode function
void BST::deleteNode(Node* &h, int n) {
  cout << "Private delete Node" << endl;
  cout << h << endl;
  if (h == NULL) {
    cout << "Empty Tree or Node not found" << endl;
    return;
  }
  //Node to delete found
  if (h -> getValue() == n) {
    cout << "Node found" << endl;
    if (h -> getLeft() == NULL && h -> getRight() == NULL) { //0 children
      cout << "zero Children" << endl;
      if (h -> getParent() == NULL) {
	Node* temp = h;
	h = NULL;
	delete temp;
	return;
      }
      if (h == h -> getParent() -> getLeft()) h -> getParent() -> setLeft(NULL);
      else h -> getParent() -> setRight(NULL);
      delete h;
    }
    else if (h -> getLeft() == NULL) { //right child
      cout << "right children" << endl;
      if (h -> getParent() == NULL) {
	Node* temp = h;
	h = h -> getRight();
	delete temp;
	return;
      }
      Node* right = h -> getRight();
      if (h == h -> getParent() -> getLeft()) h -> getParent() -> setLeft(right); //Point the parent's child pointer to new child
      else h -> getParent() -> setRight(right);
      right -> setParent(h -> getParent());
      delete h;
    }
    else if (h -> getRight() == NULL) { //left child
      if (h -> getParent() == NULL) {
	Node* temp = h;
	h = h -> getLeft();
	delete temp;
	return;
      }
      Node* left = h -> getLeft();
      cout << left << endl;
      if (h == h -> getParent() -> getLeft()) h -> getParent() -> setLeft(left); //Point the parent's child pointer to new child
      else h -> getParent() -> setRight(left);
      left -> setParent(h -> getParent());
      delete h;
    }
    else { //2 children
      cout << "2 children" << endl;
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
    return;
  }

  if (n < h -> getValue()) {
    if (h -> getLeft() == NULL) {
      cout << "Node not found" << endl;
      return;
    }
    Node* t = h -> getLeft();
    deleteNode(t, n);
  }
  else {
    if (h -> getRight() == NULL) {
      cout << "Node not found" << endl;
      return;
    }
    Node* t = h -> getRight();
    deleteNode(t, n);
  }
}

//public display function
void BST::displayTree() {
  displayTree(head, 0);
}

//private display function
void BST::displayTree(Node* h, int d) {
  if(!h) return; //empty tree
  if (h -> getLeft()) displayTree(h->getLeft(), d+1);
  for (int i = 0; i < d; i++) cout << "   ";
  cout << h -> getValue() << endl;
  if (h -> getRight()) displayTree(h -> getRight(), d+1);
}

//destructor
BST::~BST() {
  cout << "Destructor called" << endl;
  while (head) { //Delete tree
    deleteNode(head -> getValue());
  }
}
