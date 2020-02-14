/*
Author: Peter Jin
Date: 2/11/20
Binary Search Tree Main
This actually just calls functions in BST class
*/

#include "BST.h"
#include "Node.h"
#include <iostream>
#include <cstring>

using namespace std;

bool parse(char*, BST*); //Parse input and call commands
void printHelp();        //Prints the help 
void addNode(BST*);      //Add a node to the BST
void deleteNode(BST*);   //Delete a node from the BST (by number)
void display(BST*);      //Display the BST

int main() {
  BST* bst = new BST();  //Actual BST that does everything
  bool running = true;   //While loop var
  char* in = new char(); //Input char

  cout << "Welcome to Binary Search Tree demo" << endl;
  cout << "Commands are ADD, REMOVE, DISPLAY, and QUIT. Type HELP for more info." << endl;
  
  while (running) {      //Until parse returns false ("QUIT") keep reading and calling parse
    cin.get(in, 70);     
    cin.clear();
    cin.ignore(999, '\n');

    running = parse(in, bst); //Parse the input
  }

  delete bst;            //Delete the BST when quit
}

//Parse input and call functions based on input
bool parse(char* in, BST* bst) {
  for(int i = 0; i < strlen(in); i++) {
    in[i] = toupper(in[i]); //Capitalize input
  }

  if (strcmp(in, "HELP") == 0) {
    printHelp();                             //Call help on HELP
  }
  else if (strcmp(in, "ADD") == 0) {
    addNode(bst);                            //Call addnode on ADD
  }
  else if (strcmp(in, "REMOVE") == 0 || strcmp(in, "DEL") == 0 || strcmp(in, "RM") == 0) {
    deleteNode(bst);                         //Call delete on REMOVE / RM / DEL
  }
  else if (strcmp(in, "DISPLAY") == 0 || strcmp(in, "DISP") == 0) {
    display(bst);                            //call display on DISPLAY / DISP
  }
  else if (strcmp(in, "QUIT") == 0) {
    return false;                            //Stop the while loop by returning false on QUIT
  }
  else {
    cout << "Sorry, I don't recognize that command." << endl; //Command is not recognized otherwise
  }
  return true;                                //Return true, not QUITTING
}

//Print help stuff
void printHelp() {      
  cout << "Binary Search Tree command Help" << endl;
  cout << "ADD: add a node to the binary search tree" << endl;
  cout << "REMOVE: remove a node from the binary search tree" << endl;
  cout << "DISPLAY: display tree horizontally" << endl;
  cout << "QUIT: exit the program" << endl;
}

//Call addnode in BST class
void addNode(BST* bst) {
  cout << "What number to add?" << endl;
  int n;
  cin >> n;
  cin.clear();
  cin.ignore(999, '\n');
  bst -> addNode(n);
}

//Call deletenode in BST class
void deleteNode(BST* bst) {
  cout << "What number to delete?" << endl;
  int n;
  cin >> n;
  cin.clear();
  cin.ignore(999, '\n');
  bst -> deleteNode(n);
}

//call displayTree in BST class
void display(BST* bst) {
  bst -> displayTree();
}  
