/*
    Programming Assignment #2

*/
#include "heap.h"
#include "tree.h"
#include "utils.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/*
    [Task 1] Quiz

    1-1.  Let T is a general k-ary tree and T’ is a binary tree converted from
   T.
            Which of the following traversal visits the nodes in the same order
   \ as the postorder traversal of T?

          (1) Preorder traversal of T’
          (2) Inorder traversal of T’
          (3) Postorder traversal of T’
          (4) None of the aboves


    1-2.  How many following combinations of traversal sequence can always \
            identify the binary tree uniquely?
                  a. inorder
                  b. inorder & postorder
                  c. postorder & preorder & level-order
                  d. level-order & inorder

          (1) 1
          (2) 2
          (3) 3
          (4) 4

*/
void task_1(ofstream &fout, const char *quiz_num) {
  fout << "[Task 1]" << endl;
  int answer_1_1 = 2; // TODO: Change to your answer
  int answer_1_2 = 2; // TODO: Change to your answer

  if (!strcmp(quiz_num, "1")) {
    fout << answer_1_1 << endl;
  } else if (!strcmp(quiz_num, "2")) {
    fout << answer_1_2 << endl;
  } else {
    cerr << "Wrong quiz number:" << quiz_num << endl;
  }
}

/*
    [Task 2] Tree Traversal

    Description:
        Print the expected sequence of values of tree traversal
        TODO: Implement BinaryTree::preOrder, BinaryTree::postOrder and \
          BinaryTree::inOrder functions

    Input:
        - tree_string: string with bracket representation
        - traverse_mode: string that represent traverse mode \
            One of "preorder", "postorder", "inorder"
        - node_value : integer that indicates the root of the subtree

    Output:
        - sequence of values of tree traversal, separated with spacebar
        - "error" if the node_value is not in the binary tree.
*/
void task_2(ofstream &fout, const char *tree_string, const char *traverse_mode,
            int node_value) {
  fout << "[Task 2]" << endl;
  try {
    BinaryTree tree;
    tree.buildFromString(tree_string);

    if (!strcmp(traverse_mode, "preorder")) {
      fout << tree.preOrder(node_value) << endl;
    } else if (!strcmp(traverse_mode, "postorder")) {
      fout << tree.postOrder(node_value) << endl;
    } else if (!strcmp(traverse_mode, "inorder")) {
      fout << tree.inOrder(node_value) << endl;
    } else {
      cerr << "invalid traverse mode" << endl;
    }
  } catch (const char *e) {
    cerr << e << endl;
  }
}

/*
    [Task 3] Tree Depth

    Description:
        Print the depth of the specific node in a given tree
        TODO: Implement BinaryTree::getDepth function

    Input:
        - tree_string: string with bracket representation (all node values in
   the tree are unique)
        - node_value : integer value which indicates specific node

    Output:
        - depth of the specific node in a given tree
        - return -1 if the specific node does not exist in given tree
*/
void task_3(ofstream &fout, const char *tree_string, int node_value) {
  fout << "[Task 3]" << endl;
  try {
    BinaryTree tree;
    tree.buildFromString(tree_string);
    fout << tree.getDepth(node_value) << endl;
  } catch (const char *e) {
    cerr << e << endl;
  }
}

/*
    [Task 4] Reverse Completeness of Binary Tree

    Description:
        Check whether a given binary tree is a reverse complete binary tree or
   not.
        TODO:
        - Implement BinaryTree::isReverseComplete function

    Input:
        - tree_string: string with bracket representation

    Output:
        - "True" if the given tree is reverse complete binary tree, "False"
   otherwise
*/
void task_4(ofstream &fout, const char *tree_string) {
  fout << "[Task 4]" << endl;
  try {
    BinaryTree tree;
    tree.buildFromString(tree_string);
    if (tree.isReverseComplete()) {
      fout << "True" << endl;
    } else {
      fout << "False" << endl;
    }
  } catch (const char *e) {
    cerr << e << endl;
  }
}

/*
    [Task 5] Max Heap Insertion

    Description:
        Insert a new element to a binary max heap.
        Use array to implement the heap
        Heap should maintain the max heap property after the insertion.
        TODO: Implement MaxHeap::insertKey function

    Input:
        (‘insert’,string): insert string into the current max heap

    Output:
        Letters in the heap in a node number order, in a string separated with
        the white space
        There will be no “error case” such as overflow, underflow or empty heap
*/
void task_5(ofstream &fout, InstructionSequence &instr_seq) {
  fout << "[Task 5]" << endl;
  try {
    MaxHeap heap;
    for (int i = 0; i < instr_seq.getLength(); i++) {
      string command = instr_seq.getInstruction(i).getCommand();
      if (command.compare("insert") == 0) {
        heap.insertKey(instr_seq.getInstruction(i).getValue());
      } else {
        cerr << "Invalid command" << endl;
        exit(-1);
      }
    }
    fout << heap.printHeap() << endl;
  } catch (const char *e) {
    cerr << e << endl;
  }
}

/*
    [Task 6] Max Heap Deletion

    Description:
        Delete the highest priority letter from the binary max heap.
        Use array to implement the heap
        Heap should maintain the max heap property after the deletion.
        TODO: Implement MaxHeap::deleteMax function

    Input:
        (‘insert’,string): insert integer into the current max heap
        (‘delMax’,NULL): delete highest priority letter from current binary max
   heap and rearrange heap to maintain the max heap property.

    Output:
        Letters in the heap in a node number order, in a string separated with
        the white space
        There will be no “error case” such as overflow, underflow or empty heap
*/
void task_6(ofstream &fout, InstructionSequence &instr_seq) {
  fout << "[Task 6]" << endl;
  try {
    MaxHeap heap;
    for (int i = 0; i < instr_seq.getLength(); i++) {
      string command = instr_seq.getInstruction(i).getCommand();
      if (command.compare("insert") == 0) {
        heap.insertKey(instr_seq.getInstruction(i).getValue());

      } else if (command.compare("delMax") == 0) {
        heap.deleteMax();

      } else {
        cerr << "Invalid command" << endl;
        exit(-1);
      }
    }
    fout << heap.printHeap() << endl;
  } catch (const char *e) {
    cerr << e << endl;
  }
}

int main(int argc, char **argv) {
  string filename = "submit.txt";
  int task_num = 0;
  const char *instr_seq, *traverse_mode;
  int node_value;
  string result;
  InstructionSequence instr_seq_heap;

  // Open file
  ofstream fout;
  fout.open(filename, fstream::app);
  if (!fout.is_open()) {
    cerr << "Unable to open file: " << filename << endl;
    return -1;
  }

  // Choosing task number. Default is running ALL tasks (0)
  if (argc >= 2)
    task_num = atoi(argv[1]);
  if (argc >= 3) {
    instr_seq = argv[2];
    if (task_num == 2) {
      traverse_mode = argv[3];
      if (argc < 4) {
        cerr << "Invalid argument" << endl;
        return -1;
      } else {
        node_value = atoi(argv[4]);
      }
    }
    if (task_num == 3)
      node_value = atoi(argv[3]);
    if (task_num >= 5)
      instr_seq_heap.parseInstructions(argv[2]);
  } else {
    if (task_num != 0 && task_num < 7) {
      cerr << "Missing argument" << endl;
      return -1;
    }
  }

  // Running the task(s)
  switch (task_num) {
  case 1:
    task_1(fout, instr_seq);
    break;
  case 2:
    task_2(fout, instr_seq, traverse_mode, node_value);
    break;
  case 3:
    task_3(fout, instr_seq, node_value);
    break;
  case 4:
    task_4(fout, instr_seq);
    break;
  case 5:
    task_5(fout, instr_seq_heap);
    break;
  case 6:
    task_6(fout, instr_seq_heap);
    break;
  case 0:
    task_1(fout, "1");
    task_1(fout, "2");
    task_2(fout, TASK_2_DEFAULT_ARGUMENT, TASK_2_DEFAULT_ARGUMENT_2,
           TASK_2_DEFAULT_ARGUMENT_3);
    task_3(fout, TASK_3_DEFAULT_ARGUMENT, TASK_3_DEFAULT_ARGUMENT_2);
    task_4(fout, TASK_4_DEFAULT_ARGUMENT);

    instr_seq_heap.parseInstructions(TASK_5_DEFAULT_ARGUMENT);
    task_5(fout, instr_seq_heap);

    instr_seq_heap.parseInstructions(TASK_6_DEFAULT_ARGUMENT);
    task_6(fout, instr_seq_heap);

    break;
  default:
    cout << "Wrong task number" << endl;
  }

  fout.close();
  return 0;
}
