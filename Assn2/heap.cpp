#include "heap.h"
#include <iostream>
#include <string>

using namespace std;

MaxHeap::MaxHeap() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  heap_size = 0;
  heap_arr = new char[100];

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string MaxHeap::printHeap() {
  string answer;
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  for (int i = 0; i < heap_size; i++) {
    if (i + 1 == heap_size) {
      answer = answer + heap_arr[i];
      continue;
    }
    answer = answer + heap_arr[i] + " ";
  }

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
  return answer;
}

void MaxHeap::insertKey(string sen) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  for (int i = 0; i < sen.size(); i++) {
    if (sen[i] == '\"') {
      continue;
    }
    heap_arr[heap_size] = sen[i];
    heap_size++;
    sort_heap(heap_arr, heap_size);
  }
  heapify(heap_arr, heap_size, 0);

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

void MaxHeap::deleteMax() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  heap_arr[0] = heap_arr[heap_size - 1];
  heap_arr[heap_size - 1] = '\0';
  heap_size--;

  maxHeapProp(heap_arr);

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

void MaxHeap::maxHeapProp(char *heap_arr) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here   /////////////
  heapify(heap_arr, heap_size, 0);

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}