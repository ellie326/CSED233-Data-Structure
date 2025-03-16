#pragma once
#include <fstream>
#include <iostream>
#include <string>
#define NodeMaxCount 101
#define INF 2147483647 //maximum positive value for a 32-bit signed binary integer
using namespace std;

/////////////////////////////////////////////////////////
///  TODO: Add Your Struct or Functions if required /////

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

class Graph{
public:
    Graph() { };
    ~Graph() { };

    string DFS();
    string BFS();
    
    int addDirectedEdge(string nodeA, string nodeB);
    int addDirectedEdge(string nodeA, string nodeB, int weight);
    int addUndirectedEdge(string nodeA, string nodeB);
    int addUndirectedEdge(string nodeA, string nodeB, int weight);

    string StronglyConnectedComponent();

    string getShortestPath_task5(string source, string destination);
    string getShortestPath_task6(string source, string destination);
    int primMST(ofstream &, string startNode);
    int kruskalMST(ofstream &, string endNode);


private:
    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////
    int arr[NodeMaxCount][NodeMaxCount] = {0, }; 
    bool visited [NodeMaxCount] = {0, }; 
    
    string answer;
    string pr;  

    void dfs(int); 
    void bfs(int); 

    int stack[NodeMaxCount] = {0};
    int reverse_arr[NodeMaxCount][NodeMaxCount] = {0}; 
    int cnt; 
    void topological_sort(int, int); 
    void reverse(); 
    void traverse(int); 
    int temp [NodeMaxCount] = {0}; 
    int length; 

    int d_arr[NodeMaxCount] = {0}; 
    int past [NodeMaxCount] = {0}; 
    int dijkstra(); 

    void Prim(int, ofstream&, int&);

    char order [NodeMaxCount]; 
    bool order_print [NodeMaxCount] = {0}; 

    int parent[NodeMaxCount] = {0}; 
    int getParent(int); 
    bool isCycle(int, int); 
    int UnionParent(int, int); 
    void find_startNode (string&); 
    int Kruskal_d(int); 
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};
