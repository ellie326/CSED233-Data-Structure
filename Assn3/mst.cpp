#include "mst.h"
#include <iostream>
#include <string>

using namespace std;

string MultiWayTree::preOrder() {
  string output;
  _preOrder(output, _root);
  if (!output.empty())
    output.pop_back();
  return output;
}

void MultiWayTree::_preOrder(string &output, MultiNode *cur) {
  if (cur == NULL)
    return;

  output.append(cur->print_key());
  output.append(" ");
  _preOrder(output, cur->left);
  _preOrder(output, cur->middle);
  _preOrder(output, cur->right);
}

int MultiWaySearchTree::insert(int key) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  MultiNode* root = _root;
  int check;  
  MultiNode* new_root = insertion (root, key, check); 
  if (check == -1){
    return -1; 
  }else{
    _root = new_root; 
    return 0; 
  }

  ///////////      End of Implementation      /////////////
  ///////////////////////////////////////////////////////
}

int MultiWaySearchTree::remove(int key) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  
  MultiNode* root = _root; 
  int check; 
  MultiNode* node = deletion (root, key, check); 
  if (check == -1){
    return -1; 
  }else{
    _root = node; 
    return 0;
  }

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

MultiNode* MultiWaySearchTree::insertion (MultiNode* root, int key, int& check){
  if (root == NULL) {
    root = new MultiNode (key); 
  } else if (root -> key1 == key || root -> key2 == key){
    check = -1; 
    return root; 
  } 
  else if (root -> key1 > 0 && root -> key2 == -1){
    if (key < root->key1) {
          root->key2 = root->key1;
          root->key1 = key;
      } else {
          root->key2 = key;
      }
  }
  else if (key < root->key1) {
    root->left = insertion(root->left, key, check);
  } else if (key > root->key2) {

    root->right = insertion(root->right, key, check);
  } else if (key > root -> key1 && key < root -> key2) { // Key is between key1 and key2
      root->middle = insertion(root->middle, key, check);
  }else {
    return NULL; 
  }
  return root;
}

MultiNode* MultiWaySearchTree::deletion (MultiNode* root, int key, int& check){
  MultiNode* del_1 = NULL; 
  MultiNode* del_2 = NULL; 
  MultiNode* parent = NULL; 
  MultiNode* node = root; 
  if (node == NULL){
    check = -1; 
    return root; 
  }
  while (node != NULL) {
    if (node->key1 == key) {
      del_1 = node;
      if(node->key2 == -1){
        node = NULL; 
      }
      break;
    }else if (node -> key2 == key){
      del_2 = node; 
      if (node -> key1 == -1){
        node = NULL; 
      }
      break; 
    }
    parent = node;
    if (key < node -> key1)
      node = node->left;
    else if (key > node -> key1 && key < node -> key2)
      node = node->middle;
    else 
      node = node -> right; 
  }

  if (del_1 == NULL && del_2 == NULL){
    check = -1; 
    return root; 
  }
  else if (del_1 != NULL){
    MultiNode* temp1 = del_1; 
    int temp = 0; 
    if (temp1 -> middle != NULL){
      temp1 = temp1 -> middle; 
      while (temp1->left != NULL){
        temp1 = temp1 -> left; 
      }
      temp = temp1 -> key1; 
      temp1 -> key1 = -1; 
    }else if (temp1 -> left != NULL){
      temp1 = temp1 -> left; 
      while (temp1->right != NULL){
        temp1 = temp1 -> right; 
      } 
      temp = temp1 -> key2; 
      temp1 -> key2 = -1; 
    }else{ 
      temp = -1; 
    }
    del_1 -> key1 = temp;  
  }
  
  else if (del_2 != NULL){
    MultiNode* temp2 = del_2; 
    int temp = 0; 
    if (temp2 -> right != NULL){
      temp2 = temp2 -> right; 
      while (temp2->left != NULL){
        temp2 = temp2 -> left; 
      }
      temp = temp2 -> key1; 
      temp2 -> key1 = -1; 
    }else if (temp2 -> middle != NULL){
      temp2 = temp2 -> middle; 
      while (temp2->right != NULL){
        temp2 = temp2 -> right; 
      }
      temp = temp2 -> key2; 
      temp2 -> key2 = -1; 
    }
    else{
      del_2 -> key2 = -1; 
      temp = -1;  
    }
    del_2 -> key2 = temp; 
  }else{
    check = -1; 
    return NULL; 
  }
  return root; 
}

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
