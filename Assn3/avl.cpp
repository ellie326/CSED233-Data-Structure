#include "avl.h"
#include "bst.h"
#include "tree.h"
#include <iostream>
#include <string>

using namespace std;

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

int AVLTree::insert_node(Node *root, Node *node) {
  while (true) {
    if (root->key > node->key) {
      if (root->left == NULL) {
        root->left = node;
        break;
      } else
        root = root->left;
    } else if (root->key < node->key)
      if (root->right == NULL) {
        root->right = node;
        break;
      } else
        root = root->right;
    else
      return -1;
  } 
  _root = avl_check(_root); 
  return 0;
}

Node* AVLTree::avl_check(Node* current){
  int BalanceFactor = height_calc(current); 
  if(BalanceFactor > 1) {
    if(height_calc(current->left) > 0){
      current = rotate_LR(current);
    }
    else{
      current->left = rotate_RR(current->left);
    }
  }
  else if(BalanceFactor < -1) {
    if(height_calc(current->right) > 0){
      current->right = rotate_LL(current->right);
    }
    else{
      current = rotate_RL(current);
    }
  }
  return current; 
}

int AVLTree::height_calc(Node *node) {
  int left_subtree = get_height(node->left);
  int right_subtree = get_height(node->right);
  return left_subtree - right_subtree;
}

int AVLTree::get_height(Node *node) {
  int height = 0;
  if (node != NULL) {
    int left = get_height(node->left);
    int right = get_height(node->right);
    height = max(left, right) + 1;
  }
  return height;
}

Node *AVLTree::rotate_LL(Node *node) {
  Node *temp; 
  temp = node->left;
  node->left = temp -> right; 
  temp->right = node;
  return temp;
}
Node *AVLTree::rotate_RR(Node *node) {
  Node *temp; 
  temp = node->right;
  node->right = temp->left;
  temp->left = node;
  return temp;
}
Node *AVLTree::rotate_RL(Node *node) {
  Node *temp; 
  temp = node->right;
  node->right = rotate_LL(temp);
  return rotate_RR(node);
}
Node *AVLTree::rotate_LR(Node *node) {
  Node *temp; 
  temp = node->left;
  node->left = rotate_RR(temp);
  return rotate_LL(node);
}

Node *AVLTree::reBalance(Node *node) {
  if (node != NULL) {
    _root = avl_check(_root); 
    if (node->left != NULL) {
      node->left = reBalance(node->left);
    }
    if (node->right != NULL) {
      node->right = reBalance(node->right);
    }
  }
  return node;
}

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

int AVLTree::insert(int key) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  Node *root = NULL;
  Node *new_node = new Node(key);
  if (_root == NULL) {
    _root = new_node;
    return 0;
  }
  root = _root;
  int num = insert_node(root, new_node);
  if (num == -1)
    return -1;
  return 0;

  ///////////      End of Implementation      /////////////
  ///////////////////////////////////////////////////////
}

int AVLTree::remove(int key) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  Node *root = NULL;
  Node *del = NULL;
  Node *parent = NULL;
  Node *temp = NULL;
  Node *sub = NULL;
  Node *sub_parent = NULL;
  root = _root;

  while (root != NULL) {
    if (root->key == key) {
      del = root;
      break;
    }
    parent = root;
    if (root->key < key)
      root = root->right;
    else
      root = root->left;
  }

  if (del == NULL)
    return -1;
  if (del->left == NULL && del->right == NULL) {
    if (parent->left == del)
      parent->left = NULL;
    if (parent->right == del)
      parent->right = NULL;
  } else if (del->left == NULL || del->right == NULL) {
    if (del->left == NULL)
      temp = del->right;
    else
      temp = del->left;
    if (parent == NULL)
      _root = temp;
    else if (parent->left == del)
      parent->left = temp;
    else
      parent->right = temp;
  } else {
    sub = del->right;
    sub_parent = del;
    while (sub->left != NULL) {
      sub_parent = sub;
      sub = sub->left;
    }
    if (del == sub_parent) {
      sub->left = del->left;
    } else {
      sub_parent->left = sub->right;
      sub->left = del->left;
      sub->right = del->right;
    }
    if (parent == NULL)
      _root = sub;
    else if (parent->left == del)
      parent->left = sub;
    else if (parent->right == del)
      parent->right = sub;
  }
  return 0;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}
