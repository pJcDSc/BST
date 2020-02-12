/*
Author: Peter Jin
Date: 2/11/20
Binary Search Tree Main
*/

#include "BST.h"
#include "Node.h"
#include <iostream>
#include <cstring>

using namespace std;

bool parse(char*, BST*);
void printHelp();
void addNode(BST*);
void deleteNode(BST*);
void display(BST*);

int main() {
  BST* bst = new BST();
  bool running = true;
  char* in = new char();

  cout << "Welcome to Binary Search Tree demo" << endl;
  cout << "Commands are ADD, REMOVE, DISPLAY, and QUIT. Type HELP for more info." << endl;
  
  while (running) {
    cin.get(in, 70);
    cin.clear();
    cin.ignore(999, '\n');

    running = parse(in, bst);
  }

  delete bst;
}

bool parse(char* in, BST* bst) {
  for(int i = 0; i < strlen(in); i++) {
    in[i] = toupper(in[i]); //Capitalize input
  }

  if (strcmp(in, "HELP") == 0) {
    printHelp();
  }
  else if (strcmp(in, "ADD") == 0) {
    addNode(bst);
  }
  else if (strcmp(in, "REMOVE") == 0 || strcmp(in, "DEL") == 0 || strcmp(in, "DELETE") == 0) {
    deleteNode(bst);
  }
  else if (strcmp(in, "DISPLAY") == 0 || strcmp(in, "DISP") == 0) {
    display(bst);
  }
  else if (strcmp(in, "QUIT") == 0) {
    return false;
  }
  else {
    cout << "Sorry, I don't recognize that command." << endl;
  }
  return true;
}

void printHelp() {
  cout << "Binary Search Tree command Help" << endl;
  cout << "ADD: add a node to the binary search tree" << endl;
  cout << "REMOVE: remove a node from the binary search tree" << endl;
  cout << "DISPLAY: display tree horizontally" << endl;
  cout << "QUIT: exit the program" << endl;
}

void addNode(BST* bst) {
  cout << "What number to add?" << endl;
  int n;
  cin >> n;
  cin.clear();
  cin.ignore(999, '\n');
  bst -> addNode(n);
}

void deleteNode(BST* bst) {
  cout << "What number to delete?" << endl;
  int n;
  cin >> n;
  cin.clear();
  cin.ignore(999, '\n');
  bst -> deleteNode(n);
}

void display(BST* bst) {
  bst -> displayTree();
}
  
