#pragma once
#include <iostream>
#include <string>
using namespace std;

class MaxHeap {

public:
    MaxHeap();

    int heap_size;
    
    void maxHeapProp(char *heap_arr);
    void insertKey(string sen);
    void deleteMax();
    string printHeap();
    /////////////////////////////////////////////////////////
    //////  TODO: Add Public members if required ///////////

    ///////////      End of Implementation      /////////////
    char *heap_arr;
/////////////////////////////////////////////////////////

private:
    /////////////////////////////////////////////////////////
    //////  TODO: Add Private members if required ///////////
   void sort_heap(char *heap_arr, int heap_size) {
      int largest = heap_size - 1;
      if (largest == 0) {
        return; // no need to sort, bc only one node
      }
      int parent = (largest - 1) / 2;
      if (parent >= 0 && heap_arr[parent] > heap_arr[largest]) {
        char temp = heap_arr[largest];
        heap_arr[largest] = heap_arr[parent];
        heap_arr[parent] = temp;
        sort_heap(heap_arr, parent + 1);
      }
    }
  
    void heapify(char *heap_arr, int total, int index) {
  
      int largest = index;
      int left_node = 2 * index + 1;
      int right_node = 2 * index + 2;
  
      if (left_node < total && heap_arr[left_node] < heap_arr[largest]) {
        largest = left_node;
      }
      if (right_node < total && heap_arr[right_node] < heap_arr[largest]) {
        largest = right_node;
      }
      if (largest != index) {
        char temp = heap_arr[index];
        heap_arr[index] = heap_arr[largest];
        heap_arr[largest] = temp;
        heapify(heap_arr, total, largest);
      }                                    
  




    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////

};

