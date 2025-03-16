#pragma once
#include <string>

using namespace std;

struct Node {
  Node(char input_value) : value(input_value), left(NULL), right(NULL) {}
  char value;
  Node *left;
  Node *right;
};

class BinaryTree {
public:
  BinaryTree() { _root = NULL; };
  ~BinaryTree() {
    delete[] _root;
    _root = NULL;
  };
  void buildFromString(const char *data);

  string preOrder(int node_value);
  string postOrder(int node_value);
  string inOrder(int node_value);
  int getDepth(int node_value);
  bool isReverseComplete();

private:
  Node *_root;
  Node *_buildFromString(const char *data, int start, int end);
  /////////////////////////////////////////////////////////
  //////  TODO: Add Private members if required ///////////

 Node *find(Node *node, const int target) {

    if (node == NULL) {
      return NULL;
    }
    int node_value = node->value - '0';

    if (node_value == target) {
      return node;
    }
    Node *left_node = find(node->left, target);
    if (left_node != NULL) {
      return left_node;
    }
    Node *right_node = find(node->right, target);
    if (right_node != NULL) {
      return right_node;
    }
    return NULL;
  }

  void pre_print(Node *index, string &answer) {
    if (index != NULL) {
      int value = index->value - '0';
      answer += to_string(value) + " ";
      if (index->left != NULL) {
        pre_print(index->left, answer);
      }
      if (index->right != NULL) {
        pre_print(index->right, answer);
      }

    } else {
      answer = "error";
    }

    return;
  }

  void post_print(Node *index, string &answer) {
    if (index != NULL) {
      int value = index->value - '0';

      if (index->left != NULL) {
        post_print(index->left, answer);
      }
      if (index->right != NULL) {
        post_print(index->right, answer);
      }

      answer += to_string(value) + " ";

    } else {
      answer += "error";
    }

    return;
  }

  void in_print(Node *index, string &answer) {
    if (index != NULL) {
      int value = index->value - '0';

      if (index->left != NULL) {
        in_print(index->left, answer);
      }

      answer += to_string(value) + " ";

      if (index->right != NULL) {
        in_print(index->right, answer);
      }

    } else {
      answer += "error";
    }

    return;
  }

  int depth(Node *node, const int target, int dept) {
    int value = node->value - '0';

    if (node == NULL) {
      return -1;
    } else if (value == target) { // found target
      return dept;
    } else { // move on to the subtree
      Node *left_tree = node->left;
      if (left_tree != NULL) {
        int left_depth = depth(left_tree, target, dept + 1);
        if (left_depth != -1) {
          return left_depth;
        }
      }
      Node *right_tree = node->right;
      if (right_tree != NULL) {
        int right_depth = depth(right_tree, target, dept + 1);
        if (right_depth != -1) {
          return right_depth;
        }
      }
    }
    return -1;
  }

  int height_tree(Node *node) {
    if (node == NULL) {
      return 0;
    }
    int left_height = height_tree(node->left);
    int right_height = height_tree(node->right);
    return max(left_height, right_height) + 1;
  }

  class Queue {
  public:
    int fr;
    int back;
    int size;
    int cap;

    Queue() {
      fr = 0;
      back = 0;
      size = 0;
      cap = 100;
      queue = new Node *[cap];
    }

    void push(Node *node) {
      if (size == cap) {
        resize();
      }
      queue[back] = node;
      back = (back + 1) % cap;
      size++;
    }

    Node *print_front() { return queue[fr]; }

    void pop() {
      fr = (fr + 1) % cap;
      size--;
    }

    bool is_empty() { return size == 0; }

  private:
    Node **queue;

    void resize() {
      Node **new_queue = new Node *[cap];
      int cnt = 0;
      while (!is_empty()) {
        new_queue[cnt++] = print_front();
        pop();
      }
      fr = 0;
      back = cnt;
      cap *= 2;
      delete[] queue;
      queue = new_queue;
    }
  }; 

  bool
  check_reverse(Node *node) {
    Queue queue;
    queue.push(_root);
    Node *head = NULL;
    bool end = false;

    while (queue.size) {
      head = queue.print_front();
      queue.pop();

      if (end && (head->left || head->right)) {
        return false;
      }

      if (head->left && head->right == NULL) {
        return false;
      }

      if (head->right) {
        queue.push(head->right);
      } else {
        end = true;
      }

      if (head->left) {
        queue.push(head->left);
      } else {
        end = true;
      }
    }
    return true;
  }

  class Queue {
  public:
    int fr;
    int back;
    int size;
    int cap;

    Queue() {
      fr = 0;
      back = 0;
      size = 0;
      cap = 100;
      queue = new Node *[cap];
    }

    void push(Node *node) {
      if (size == cap) {
        resize();
      }
      queue[back] = node;
      back = (back + 1) % cap;
      size++;
    }

    Node *print_front() { return queue[fr]; }

    void pop() {
      fr = (fr + 1) % cap;
      size--;
    }

    bool is_empty() { return size == 0; }

  private:
    Node **queue;

    void resize() {
      Node **new_queue = new Node *[cap];
      int cnt = 0;
      while (!is_empty()) {
        new_queue[cnt++] = print_front();
        pop();
      }
      fr = 0;
      back = cnt;
      cap *= 2;
      delete[] queue;
      queue = new_queue;
    }
  }; 
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
};
