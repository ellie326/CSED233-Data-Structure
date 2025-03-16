#include "hash_function.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int BinaryMidSquareHash::hashing(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int square = pow(key,2); 
    int size = 2 * key_size; 
    int* binary { new int [size] {} }; 
    int i = 0; 
    while (square > 0){
        binary[i] = square % 2; 
        square /= 2; 
        i++; 
    }

    int mid_sq = (2 * binary[key_size]) + binary[key_size-1];  
    
    return mid_sq;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int DigitFoldingHash::hashing(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    //1. convert to binary 
    //2. add up number of 1s. 
    int* binary { new int [key_size] {} }; 
    int i = 0; 
    while (key > 0){
        binary[i] = key % 2; 
        key /= 2; 
        i++; 
    }

    int sum = 0; 
    for(int j = 0; j < key_size; j++){
        if(binary[j] == 1){
            sum ++; 
        }
    }

    return sum;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int MultiplicationHash::hashing(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    double mul = 0.1 * key; 
    while (mul >= 1){
        mul -= 1; 
    }
    double num = floor(pow(2, index_size) * mul); 
    return num;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
