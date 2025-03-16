#include "bst.h"
#include "tree.h"
#include <iostream>
#include <string>

using namespace std;

int BinarySearchTree::insert(int key) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  Node *root = NULL;
  Node *new_node = new Node(key);
  if (_root == NULL) {
    _root = new_node;
    return 0;
  }
  root = _root;
  if (!insert_node(root, new_node)) {
    return -1;
  }
  return 0;

  ///////////      End of Implementation      /////////////
  ///////////////////////////////////////////////////////
}

int BinarySearchTree::remove(int key) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  Node *root = NULL;
  Node *del = NULL;
  Node *parent = NULL;
  Node *temp_sub = NULL;

  // finding key
  root = _root;

  if (root->key == key) {
    _root = NULL;
    return 0;
  }

  while (root != NULL) {
    parent = root;
    if (root->key < key) {
      root = root->right;
    } else {
      root = root->left;
    }
  }

  if (del == NULL) {
    return -1; // the node DNE
  }

  // actual deletion
  if (del->left == NULL && del->right == NULL) {
    if (parent->left == del) {
      parent->left = NULL;
    }
    if (parent->right == del) {
      parent->right = NULL;
    }
  } else if (del->left == NULL || del->right == NULL) {
    if (del->left == NULL) {
      temp_sub = del->right;
    } else {
      temp_sub = del->left;
    }

    if (parent->left == del) {
      parent->left = temp_sub;
    } else {
      parent->right = temp_sub;
    }
  } else { // both left and right child exists
    Node *smallest = del->right;
    Node *small_parent = del;
    // finding smallest node to put in a delete node
    while (smallest->left != NULL) {
      small_parent = smallest;
      smallest = smallest->left;
    }
    if (del == small_parent) { // when the delete node's right child doesn't
                               // have left child
      smallest->left = del->left;
    }
    if (smallest->right == NULL) {
      del = smallest;
      small_parent->left = NULL;
    } else {
      small_parent->left = smallest->right;
      smallest->left = del->left;
      smallest->right = del->right;
    }

    if (parent == NULL) {
      _root = smallest;
    } else if (parent->left == del) {
      parent->left = smallest;
    } else if (parent->right == del) {
      parent->right = smallest;
    }
  }

  return 0;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

int BinarySearchTree::insert_node(Node *root, Node *new_node) {
  while (true) {
    if (root->key > new_node->key) {
      if (root->left == NULL) {
        root->left = new_node;
        return 0;
      } else {
        root = root->left;
      }
    } else if (root->key < new_node->key) {
      if (root->right == NULL) {
        root->right = new_node;
        return 0;
      } else {
        root = root->right;
      }
    } else {
      return -1;
    }
    return 0;
  }
}

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////