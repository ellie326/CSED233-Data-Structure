#pragma once
#include "tree.h"

using namespace std;

class BinarySearchTree : public BinaryTree {
public:
  BinarySearchTree(){};
  ~BinarySearchTree(){};

  int insert(int key);
  int remove(int key);

private:
  /////////////////////////////////////////////////////////
  //////  TODO: Add private members if required ///////////
  int insert_node(Node *, Node *);
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
};