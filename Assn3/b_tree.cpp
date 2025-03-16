#include "b_tree.h"
#include <iostream>
#include <string>

using namespace std;

/*  Write your codes for other b_tree functions  */



void BTree::not_full(Node* node, int key){
    int num = node->num_key - 1; 

    if (node->is_leaf == true){
        while (num >= 0 && node->key_arr [num] > key){
            node->key_arr[num + 1] = node->key_arr[num]; 
            num --; 
        }
        node->key_arr[num + 1] = key; 
        (node->num_key)++; 
    } else{
        while (num >= 0 && node->key_arr[num] > key){
            num --; 
        }
        if (node -> child [num + 1] -> num_key == 2 * B_order - 1){
            split (num + 1, node->child[num + 1]); 
            
            if(node -> key_arr[num + 1] < key){
                num ++; 
            }
        }
        not_full (node -> child [num + 1], key); 
    }
}

void BTree::split (int sp, Node* node){
    int order = node -> _order; 
    Node* temp = new Node (order, node->is_leaf); 
    temp -> num_key = order - 1; 

    for (int i = 0; i < order - 1 ; i ++){
        temp -> key_arr[i] = node -> key_arr[i + order]; 
    }

    if(node -> is_leaf == false){
        for(int j = 0; j < order; j++){
            temp -> child [j] = node -> child [j + order]; 
        }
    }

    node -> num_key = order - 1; 

    for (int k = node->num_key; k >= sp ; k--){
        node -> child [k + 1] = node->child [k]; 
    }

    node->child [sp + 1] = temp; 

    for (int a = node -> num_key - 1; a >= sp; a--){
        node -> key_arr[a+1] = node->key_arr[a]; 
    }
    node->key_arr [sp] = node -> key_arr[order -1]; 

    (node -> num_key)++; 
}
///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

string BTree::postOrder() {
    /*  Write your codes for b_tree functions  */
    string answer; 
    _postOrder(answer, _root, _root->num_key); 
    return answer;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int BTree::has_elem(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    
    return 1;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int BTree::insert_elem(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    if (_root == NULL){
        _root = new Node (B_order, true); 
        _root -> key_arr[0] = key; 
        (_root -> num_key)++; 
    }
    else { // if root already exists 
        if(_root -> num_key == 2*B_order - 1){ // when the node is full 
            Node* temp = new Node (B_order, false); 
            temp -> child [0] = _root; 
            split (0, _root); 
            
            int ins = 0; 
            if (temp -> key_arr[0] < key){
                ins ++; 
            }
            not_full (temp->child[ins], key); 

            _root = temp; 
        }else{
           not_full (_root, key); 
        }
    }

    return 0; 
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int BTree::delete_elem(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    return 0;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}


