#include "sort.h"
#include <fstream>
#include <iostream>
#include <string>

sortAlg::sortAlg() {
  arr_size = 0;
  arr = new int[100];  // Each test case will be less than 100 values
  temp = new int[100]; // Each test case will be less than 100 values
}

using namespace std;

void sortAlg::printArray(ofstream &fout) {
  string answer;
  for (int i = 0; i < arr_size - 1; i++)
    answer += to_string(arr[i]) + " ";
  answer += to_string(arr[arr_size - 1]);
  fout << answer << endl;
}

void sortAlg::insertionSort(ofstream &fout) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  temp[0] = 1; 
  for (int i = 1; i < arr_size; i++) {
    int walker = i; 
    while (arr[walker] < arr[walker - 1]) {
      int temp = arr[walker];
      arr[walker] = arr[walker - 1];
      arr[walker - 1] = temp;
      if(walker == 1){
        break; 
      }else{
        walker --; 
        continue;   
      }
    }
    if(temp[i] != 1){
      printArray(fout); // DO NOT ERASE THIS LINE
    }
    temp[i] = 1; 
  }

  return; 
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

void sortAlg::merge(int left, int right, int &count) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  // save left and right subtree
  int mid = left + (right-left) / 2;

  int i = left; 
  int j = mid + 1; 

  while (i <= mid && j <= right){
    if(arr[i] <= arr[j]){
      i++; 
    }else{
      int temp = arr[j]; 
      for(int walker = j - 1; walker >= i; walker--){
        arr[walker + 1] = arr[walker]; 
      }
      arr[i] = temp; 
      count++; 
      i++; 
      mid++; 
      j++; 
    }
  }

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

void sortAlg::mergeSort(ofstream &fout, int left, int right, int &count) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  if (left < right) {
    int mid = left + (right-left) / 2;
      mergeSort(fout, left, mid, count);
      mergeSort(fout, mid + 1, right, count);
    merge(left, right, count);
    printArray(fout); // DO NOT ERASE THIS LINE
  }

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}
