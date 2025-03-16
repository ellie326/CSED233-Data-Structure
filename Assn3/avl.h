#pragma once
#include "bst.h"

using namespace std;

class AVLTree : public BinarySearchTree {
public:
  AVLTree(){};
  ~AVLTree(){};

  int insert(int key);
  int remove(int key);

private:
  /////////////////////////////////////////////////////////
  //////  TODO: Add private members if required ///////////
  int insert_node(Node *, Node *);
  Node* avl_check(Node*); 
  int height_calc(Node *);
  int get_height(Node *);
  Node *rotate_LL(Node *);
  Node *rotate_RR(Node *);
  Node *rotate_RL(Node *);
  Node *rotate_LR(Node *);
  Node *reBalance(Node *);
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
};