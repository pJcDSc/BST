/*
Author: Peter Jin
Date: 2/10/20
Binary Search Tree Class
this is the class that actually does everything
*/

#include "BST.h"
#include "Node.h"
#include <iostream>

using namespace std;

//Constructor
BST::BST() {
  head = NULL;
}

//Public addNode function which calls private addNode function
void BST::addNode(int n){
  addNode(head, n);
  cout << "Node added" << endl;
}

//private addnode function
void BST::addNode(Node* &h, int n) {
  if (h == NULL) {          //If h is null then this was the head, and BST is empty
    head = new Node(n); 
    return;
  }
  else if (n < h -> getValue()) { //If value to add is less than current node, then we need to go to the left
    if (h -> getLeft() == NULL) { //if there is nothing to the left then add it
      h -> setLeft(new Node(n));
      h -> getLeft() -> setParent(h);
      return;
    }
    Node* left = h -> getLeft();  //Otherwise call addnode again on the left node
    addNode(left, n);
    return;
  }
  else {                          //Otherwise we need to go to the right
    if (h -> getRight() == NULL) {//If there is nothing on the right we add the node
      h -> setRight(new Node(n));
      h -> getRight() -> setParent(h);
      return;
    }
    Node* right = h -> getRight();//Otherwise call addnode again on the right side
    addNode(right, n);            
    return;
  }
}

//public deletenode function
void BST::deleteNode(int n) {
  //Call private deletenode function, which returns true if it deletes and returns false otherwise
  if(deleteNode(head, n)) cout << "Node deleted" << endl; 
}

//private deletenode function
bool BST::deleteNode(Node* &h, int n) {
  if (h == NULL) {               //We have not found the node, return false
    cout << "Empty Tree or Node not found" << endl;
    return false;
  }
  //Node to delete found
  if (h -> getValue() == n) {    //We have found the node, now separate based on how many children
    if (h -> getLeft() == NULL && h -> getRight() == NULL) { //0 children
      if (h -> getParent() == NULL) { //If this is the root node, delete it, and set head to null
	Node* temp = h;
	h = NULL;
	delete temp;
	return true;
      }
      if (h == h -> getParent() -> getLeft()) h -> getParent() -> setLeft(NULL); //Otherwise reconfigure parent's child pointer
      else h -> getParent() -> setRight(NULL);
      delete h;
    }
    else if (h -> getLeft() == NULL) { //right child
      if (h -> getParent() == NULL) {  //if root node, just set this to the right node, and reconfigure parent pointer
	Node* temp = h;
	h = h -> getRight();
	h -> setParent(NULL);
	delete temp;
	return true;
      }
      Node* right = h -> getRight();     
      if (h == h -> getParent() -> getLeft()) h -> getParent() -> setLeft(right); //Point the parent's child pointer to new child
      else h -> getParent() -> setRight(right);
      right -> setParent(h -> getParent());                                       //Re set the parent pointer
      delete h;
    }
    else if (h -> getRight() == NULL) { //left child                  //same thing as the right child
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
      //Get inorder successor (only called on upper nodes, so don't need to deal with inorder succ. for leaves)
      Node* temp = h -> getRight(); //Inorder successor for not-leaves is one right then as many left as possible
      while (temp -> getLeft()) {
	temp = temp -> getLeft();
      }

      int value = temp -> getValue(); //Delete the inorder succ., then set the temps value to this
      deleteNode(temp, value);
      
      //Swap values as normal
      h -> setValue(temp -> getValue()); //set the value of this node to inorder succ.
    }
    return true; //We deleted it so return true
  }

  if (n < h -> getValue()) { //If value we are looking for is less than this value then go left
    if (h -> getLeft() == NULL) { //If there is nothing to the left the value we are looking for doesn't exist
      cout << "Node not found" << endl;
      return false;
    }
    Node* t = h -> getLeft();
    return deleteNode(t, n); //Call deletenode on left node
  }
  else {                     //If value we are looking for is more than this value go right
    if (h -> getRight() == NULL) { //Same as left
      cout << "Node not found" << endl;
      return false;
    }
    Node* t = h -> getRight();
    return deleteNode(t, n);
  }
}

//public display function
void BST::displayTree() {
  displayTree(head, 0); //call private display function
}

//private display function
void BST::displayTree(Node* h, int d) { //inorder print of bst
  if(!h) return; //empty tree
  if (h -> getLeft()) displayTree(h->getLeft(), d+1);
  for (int i = 0; i < d; i++) cout << "   ";
  cout << h -> getValue() << endl;
  if (h -> getRight()) displayTree(h -> getRight(), d+1);
}

//destructor
BST::~BST() { //Repeatedly call delete on head until tree is gone
  while (head) { //Delete tree
    deleteNode(head, head -> getValue());
  }
}
