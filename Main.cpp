
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
#include <fstream>

using namespace std;

bool parse(char*, BST*); //Parse input and call commands
void printHelp();        //Prints the help 
void addNode(BST*);      //Add a node to the BST
void deleteNode(BST*);   //Delete a node from the BST (by number)
void display(BST*);      //Display the BST
void addFile(BST*);      //Add from file
void searchTree(BST*);   //Check if number in tree
int strToInt(char*);     //Convert string to integer

int main() {
  BST* bst = new BST();  //Actual BST that does everything
  bool running = true;   //While loop var
  char* in = new char(); //Input char

  cout << "Welcome to Binary Search Tree demo" << endl;
  cout << "Commands are ADD, REMOVE, DISPLAY, FILE, SEARCH, and QUIT. Type HELP for more info." << endl;
  
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
  else if (strcmp(in, "FILE") == 0) {        //Call addFile on FILE
    addFile(bst);
  }
  else if (strcmp(in, "SEARCH") == 0) {
    searchTree(bst);
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
  cout << "FILE: add numbers to binary search tree from file" << endl;
  cout << "SEARCH: check if number is in tree" << endl;
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

//Read from file
//Split by space then call bst addNode on each part
void addFile(BST* bst) {
  char* line = new char(); //Eventual line from file

  //Get file name, read from file using ifstream
  cout << "Input file name" << endl;
  char* fileName = new char();
  cin.getline(fileName, 80);
  cin.clear();
  cout << "Reading from \"" << fileName << "\"" << endl;
  ifstream fileStream (fileName);
  if (fileStream.is_open()) {
    fileStream.getline(line, 99);
  } else { //File is not readable
    cout << "Could not read from file" << endl;
    return;
  }
  fileStream.close();

  char* build = new char[strlen(line)+1]();          //temp string to store individual words
  int ind = 0;
  for (int i = 0; i < strlen(line); i++) {
    if (line[i] == ' ') { //Space found
      if (strlen(build) > 0) {
	bst -> addNode(strToInt(build)); //Don't add empty
      }
      build = new char[strlen(line)]();
      ind = 0;
    }
    else {
      if (isdigit(line[i])) build[ind++] = line[i]; //Don't add non-digits
    }
  }
  if (strlen(build) > 0) {
    bst -> addNode(strToInt(build));
  }

  return;
}

//Search
void searchTree(BST* bst) {
  cout << "What number to search for?" << endl;  //get input
  int n;
  cin >> n;
  cin.clear();
  cin.ignore(999, '\n');
  if (bst -> search(n)) {                        //call bst search
    cout << n << " is in the tree." << endl;
  }
  else {
    cout << n << " is not in the tree." << endl;
  }
}

//Convert string to int
int strToInt(char* str) {
  int num = 0;
  for(int i = 0; i < strlen(str); i++) {
    if (!isdigit(str[i])) continue; //Skip over non-numeric characters
    num *= 10;
    num += str[i]-'0';
  }
  return num;
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
