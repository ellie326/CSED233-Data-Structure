#include "dabst.h"
#include "bst.h"
#include "tree.h"
#include <iostream>
#include <string>

using namespace std;

string DABSTree::inOrder() {
  string output;
  _inOrder(output, _root);
  if (!output.empty())
    output.pop_back();
  return output;
}

string DABSTree::preOrder() {
  string output;
  _preOrder(output, _root);
  if (!output.empty())
    output.pop_back();
  return output;
}

void DABSTree::_inOrder(string &output, Node *cur) {
  if (cur == NULL)
    return;
  _inOrder(output, cur->left);
  output.append(cur->print_key());
  output.append("(");
  output.append(cur->print_count());
  output.append(")");
  output.append(" ");
  _inOrder(output, cur->right);
}

void DABSTree::_preOrder(string &output, Node *cur) {
  if (cur == NULL)
    return;
  output.append(cur->print_key());
  output.append("(");
  output.append(cur->print_count());
  output.append(")");
  output.append(" ");
  _preOrder(output, cur->left);
  _preOrder(output, cur->right);
}

int DABSTree::insert(int key) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  Node *root = NULL;
  Node *node = new Node(key);
  if (_root == NULL) {
    _root = node;
    return 0;
  }
  root = _root;
  int num = insert_node(root, node);
  if (num == -1)
    return -1;
  return 0;
  ///////////      End of Implementation      /////////////
  ///////////////////////////////////////////////////////
}

int DABSTree::remove(int key) {
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
  if(del->key == key){
      del->count--;
      if(del->count >=1)
        return 0; 
    }
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

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

int DABSTree::insert_node(Node *root, Node *node) {
  while (1) {
    if(root->key == node->key){
      root->count ++; 
      return 0; 
    }
    if (root->key > node->key) {
      if (root->left == NULL) {
        root->left = node;
        return 0;
      } else
        root = root->left;
    } else if (root->key < node->key)
      if (root->right == NULL) {
        root->right = node;
        return 0;
      } else
        root = root->right;
    else
      return -1;
  }
  return 0;
}

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////