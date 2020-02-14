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
  cout << "Node added" << endl;
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
  if(deleteNode(head, n)) cout << "Node deleted" << endl;
}

//private deletenode function
bool BST::deleteNode(Node* &h, int n) {
  if (h == NULL) {
    cout << "Empty Tree or Node not found" << endl;
    return false;
  }
  //Node to delete found
  if (h -> getValue() == n) {
    if (h -> getLeft() == NULL && h -> getRight() == NULL) { //0 children
      if (h -> getParent() == NULL) {
	Node* temp = h;
	h = NULL;
	delete temp;
	return true;
      }
      if (h == h -> getParent() -> getLeft()) h -> getParent() -> setLeft(NULL);
      else h -> getParent() -> setRight(NULL);
      delete h;
    }
    else if (h -> getLeft() == NULL) { //right child
      if (h -> getParent() == NULL) {
	Node* temp = h;
	h = h -> getRight();
	h -> setParent(NULL);
	delete temp;
	return true;
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
	h -> setParent(NULL);
	delete temp;
	return true;
      }
      Node* left = h -> getLeft();
      if (h == h -> getParent() -> getLeft()) h -> getParent() -> setLeft(left); //Point the parent's child pointer to new child
      else h -> getParent() -> setRight(left);
      left -> setParent(h -> getParent());
      delete h;
    }
    else { //2 children
      //Get inorder successor (only called on upper nodes, so don't need to deal with leaves)
      Node* temp = h -> getRight();
      while (temp -> getLeft()) {
	temp = temp -> getLeft();
      }

      int value = temp -> getValue();
      deleteNode(temp, value);
      
      //Swap values as normal
      h -> setValue(temp -> getValue());
    }
    return true;
  }

  if (n < h -> getValue()) {
    if (h -> getLeft() == NULL) {
      cout << "Node not found" << endl;
      return false;
    }
    Node* t = h -> getLeft();
    return deleteNode(t, n);
  }
  else {
    if (h -> getRight() == NULL) {
      cout << "Node not found" << endl;
      return false;
    }
    Node* t = h -> getRight();
    return deleteNode(t, n);
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
  while (head) { //Delete tree
    deleteNode(head, head -> getValue());
  }
}
