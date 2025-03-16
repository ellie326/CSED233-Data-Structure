#pragma once
#include <string>
#include <iostream>

using namespace std;

class BTree {
public:

    /////////////////////////////////////////////////////////
    //////  TODO: Implement BTree class, Add public members if required ///////////
    
    class Node{
    public: 
        Node(int order, bool leaf){ 
            _order = order;
            key_arr = new int [2*_order - 1]; 
            child = new Node* [2*_order]; 
            num_key = 0; 
            is_leaf = leaf; 
        }
        int _order; 
        int* key_arr; 
        Node** child;
        int num_key; 
        bool is_leaf;  

        
    }; 

    BTree (int order){
        B_order = order; 
        _root = NULL; 
    }

    //public functions 
    void split(int, Node*); 
    void not_full(Node*, int); 

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
    
    int has_elem(int key);
    int insert_elem(int key);
    int delete_elem(int key);
    string postOrder(); 

    void _postOrder(string& answer, Node* node, int num){
            for (int i = 0; i < num; i ++){
                if (node != NULL)
                    _postOrder(answer, node->child[i], num); 
                answer = answer + to_string(node->key_arr[i]) + " "; 
            }
        } 
       
    
private:
    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////
    Node* _root; 
    int B_order;  
     
    
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};
