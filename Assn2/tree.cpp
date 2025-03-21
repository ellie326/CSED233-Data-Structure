#include "tree.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/* This is given function. DO NOT MODIFY THIS FUNCTION */
int findIndex(const char *str, int start, int end) {
  if (start > end)
    return -1;

  string s;

  for (int i = start; i <= end; i++) {

    // if open parenthesis, push it
    if (str[i] == '(')
      s.push_back(str[i]);

    // if close parenthesis
    else if (str[i] == ')') {
      if (s.back() == '(') {
        s.pop_back();

        if (!s.length())
          return i;
      }
    }
  }
  // if not found return -1
  return -1;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
Node *BinaryTree::_buildFromString(const char *data, int start, int end) {
  if (start > end)
    return NULL;

  Node *root = new Node(data[start]);
  int index = -1;

  if (start + 1 <= end && data[start + 1] == '(')
    index = findIndex(data, start + 1, end);

  if (index != -1) {
    root->left = _buildFromString(data, start + 2, index - 1);
    root->right = _buildFromString(data, index + 2, end - 1);
  }
  return root;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
void BinaryTree::buildFromString(const char *data) {
  Node *root = _buildFromString(data, 0, strlen(data) - 1);
  _root = root;
}

string BinaryTree::preOrder(int node_value) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  Node *index = _root.find(_root, node_value);

  string answer;
  pre_print(index, answer);

  int tail = answer.size() - 1;
  if (answer[tail] == ' ') {
    answer.erase(tail, 1);
  }
  
  return answer;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::postOrder(int node_value) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  Node *index = find(_root, node_value);

  string answer;
  post_print(index, answer);

  int tail = answer.size() - 1;
  if (answer[tail] == ' ') {
    answer.erase(tail, 1);
  }

  return answer;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::inOrder(int node_value) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  Node *index = find(_root, node_value);

  string answer;
  in_print(index, answer);

  int tail = answer.size() - 1;
  if (answer[tail] == ' ') {
    answer.erase(tail, 1);
  }

  return answer;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

int BinaryTree::getDepth(int node_value) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  int dept = 0;
  int answer = depth(_root, node_value, dept);
  return answer;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

bool BinaryTree::isReverseComplete() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  return check_reverse(_root);
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
  
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////



///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
