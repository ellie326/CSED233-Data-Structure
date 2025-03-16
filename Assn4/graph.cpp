#include "graph.h"
#include <fstream>
#include <iostream>
#include <string>
#define INF 2147483647 
using namespace std;


/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////
/*  Write your codes if you have additional functions  */

void Graph::dfs (int current) {
    visited[current] = 1; 
    answer = answer + (char) (current + 65) + " "; 
    for(int j = 0; j <= 26; j++){
        if(arr[current] [j] == 1 && visited[j] == 0){
            dfs(j); 
        }
    }
}

typedef struct QUEUE{
    int front, rear; 
    int data [101]; //NodeMaxCount = 101
}queue; 

void Graph::bfs (int current){
    int walker = 0; 
    queue q; 

    q.front = -1; 
    q.rear = -1; 

    visited[current] = 1; 
    q.rear ++; 
    q.data[q.rear] = current; 

    while(q.front < q.rear){
        q.front ++; 
        walker = q.data[q.front]; 
        answer = answer + (char) (walker + 65) + " "; 
        
        for (int i = 0; i < 26; i++){
            if(arr[walker][i] == 1 && visited[i] == 0){
                visited[i] = 1; 
                q.rear++; 
                q.data[q.rear] = i; 
            }
        }
    }
}

void Graph::reverse(){  
    for(int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            reverse_arr[i][j] = arr[j][i]; 
        }
    }
}

void Graph::topological_sort(int top, int node){
    top ++; 
    visited[node] = true; 
    
    for(int i = 0; i < 26; i++){
        if(arr[node][i] != 0 && visited[i] == 0){
            topological_sort(top, i); 
        }
    }
    stack[top] = node;  
}

void Graph::traverse(int current){ 
    cout << "current: " << current << endl; 
    visited[current] = true; 
    answer = answer + (char)(current + 65) + " "; 
    temp[length] = current; 
    length++; 
    for(int i = 0; i < 26; i++){
        if(reverse_arr[current][i] != 0){
            if(visited[i] == 0){
                traverse(i); 
            }
        }
    }
}

int Graph::dijkstra(){
    int min = INF; 
    int min_node = INF; 
    for(int i = 0; i < 26; i++){
        if(visited[i] == 0 && min > d_arr[i] && d_arr[i] != INF){
            min = d_arr[i]; 
            min_node = i; 
        }
    }

    return min_node;  
}

void Graph::Prim(int current, ofstream& fout, int& cost){
    visited[current] = 1; 
    answer = answer + (char) (current + 65) + " "; 
    fout << answer << endl; 
    for(int j = 0; j <= 26; j++){
        if(arr[current] [j] > 1 && visited[j] == 0){
            cost += arr[current][j]; 
            Prim(j, fout, cost); 
        }
    }
}

typedef struct edge {
    int v1, v2, cost; 
}edge; 

typedef struct edge_list {
    edge data [101]; //NodeMaxCount = 101
    int num_edge; 
}edge_list; 

int Graph::getParent(int node){
    if(parent[node] == node){
        return node;
    }
    return getParent(parent[node]); 
}

bool Graph::isCycle(int v1, int v2){
    int p1, p2; 
    p1 = getParent(v1); 
    p2 = getParent(v2); 
    if(p1 == p2){
        return true; 
    }
    return false; 
}

int Graph::UnionParent(int v1, int v2){
    int p1, p2; 
    p1 = getParent(v1); 
    p2 = getParent(v2); 

    if(p1 < p2){
        parent[p2] = p1;  
        return p1; 
    }else{
        parent[p1] = p2; 
        return p2; 
    }
}

void Graph::find_startNode(string& startNode){
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            if(arr[i][j] != 0){
                startNode = string(1, (char)(i+65)); 
                return; 
            }
        }
    }
    return; 
}

int Graph::Kruskal_d(int endNode_num){
    int min = INF; 
    int min_node = INF; 
    for(int i = 0; i < 26; i++){
        if(visited[i] == 0 && min >= d_arr[i] && d_arr[i] != INF){
            if(min == d_arr[i] && i == endNode_num){
                min_node = i; 
            }else{
                min = d_arr[i]; 
                min_node = i; 
            }
        }
    }

    return min_node;  
}

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

string Graph::DFS() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int start = 0; 
    bool end = false; 
    int cnt = 0; 
    int visited_cnt = 0; 
    int connected = 1; 

    for(int i = 0; i <= 26; i++){
        for(int j = 0; j <= 26; j++){
            if(arr[i][j] == 1){
                if(end == 0){
                    start = i; 
                }
                end = true; 
                cnt++; 
                break; 
            }
        }
    }

    dfs(start); 
    while(true){
        for(int i = 0; i <= 26; i++){
            for(int j = 0; j <= 26; j++){
                if(arr[i][j] == 1 && visited[i] == 0){
                    answer = answer + "\n"; 
                    connected ++; 
                    dfs(i); 
                }
            }
        }

        for(int k = 0; k <= 26; k++){
            if(visited[k] == 1){
                visited_cnt ++; 
            }
        }
        
        if(visited_cnt == cnt){
            break; 
        }
    }

    pr = to_string(connected) + "\n" + answer; 

    return pr;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

string Graph::BFS() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int start = 0; 
    bool end = false; 
    int cnt = 0; 
    int visited_cnt = 0; 
    int connected = 1; 

    for(int i = 0; i <= 26; i++){
        for(int j = 0; j <= 26; j++){
            if(arr[i][j] == 1){
                if(end == 0){
                    start = i; 
                }
                end = true; 
                cnt++; 
                break; 
            }
        }
    }

    bfs(start); 
    while(true){
        for(int i = 0; i <= 26; i++){
            for(int j = 0; j <= 26; j++){
                if(arr[i][j] == 1 && visited[i] == 0){
                    answer = answer + "\n"; 
                    connected ++; 
                    bfs(i); 
                }
            }
        }

        for(int k = 0; k <= 26; k++){
            if(visited[k] == 1){
                visited_cnt ++; 
            }
        }
        
        if(visited_cnt == cnt){
            break; 
        }
    }

    pr = to_string(connected) + "\n" + answer; 

    return pr;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int Graph::addDirectedEdge(string nodeA, string nodeB) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    arr[(int)nodeA[0] - 65][(int)nodeB[0] - 65] = 1; 
    return 0;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int Graph::addDirectedEdge(string nodeA, string nodeB, int weight) {
	/////////////////////////////////////////////////////////
	//////////  TODO: Implement From Here      //////////////

    return 0;
	///////////      End of Implementation      /////////////
	///////////////////////////////////////////////////////
}

int Graph::addUndirectedEdge(string nodeA, string nodeB) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    arr[(int)nodeA[0] - 65][(int)nodeB[0] - 65] = 1; 
    arr[(int)nodeB[0] - 65][(int)nodeA[0] - 65] = 1; 

    return 0;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int Graph::addUndirectedEdge(string nodeA, string nodeB, int weight) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    arr[(int)nodeA[0] - 65][(int)nodeB[0] - 65] = weight; 
    arr[(int)nodeB[0] - 65][(int)nodeA[0] - 65] = weight; 
    return 0;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

string Graph::StronglyConnectedComponent() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    
    bool end; 
    int cnt; 

    // find number of nodes 
    for(int i = 0; i < 26; i++){
        end = false; 
        for(int j = 0; j < 26; j++){
            if(arr[i][j] > 0 || arr[j][i] > 0){
                if(end == false){
                    cnt ++; 
                    end = true; 
                }
            }
        }
    }

    for(int i = 0; i < 101; i++){
        stack[i] = INF; 
    }
    //stack[NodeMaxCount]
    //visited [NodeMaxCount]
    //stack[NodeMaxCount] 
    int num_comp = 0; 
    int top = -1; 

    for(int i = 0; i < 26; i ++){
        visited[i] = false; 
    }

    for(int i = 0; i < cnt; i++){
        if(visited[i] == 0){
            topological_sort(top, i); 
        }
    }


    for(int i = 0; i < 26; i ++){ 
        visited[i] = false; 
    }

    //reverse_arr[NodeMaxCount][NodeMaxCount]
    reverse(); 
    int highest = stack[0]; 

    for (int i = 1; i < 26; i++){
        if(stack[i] != INF){
            highest = stack[i]; 
        }
    } 

    length = 0; 
    for(int i = 0; i <= highest; i++){
        int current = stack[i]; 
        if(visited[current] == 0){
            traverse(current); 
            answer += "\n"; 
            num_comp ++; 
        } 
    }

    pr = to_string(num_comp) + "\n" + answer; 

    return pr; 

    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

string Graph::getShortestPath_task5(string source, string destination) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    bool end; 
    int node_cnt = 0; 

    // find number of nodes 
    for(int i = 0; i < 26; i++){
        end = false; 
        for(int j = 0; j < 26; j++){
            if(arr[i][j] > 0 || arr[j][i] > 0){
                if(end == false){
                    node_cnt ++; 
                    end = true; 
                }
            }
        }
    }
    
    for(int i = 0; i < 26; i++){
        d_arr[i] = arr[(int)source[0] - 65][i]; 
        if(d_arr[i] == 0){
            d_arr[i] = INF; 
        }
        past[i] = -1; 
    }

    d_arr[(int)source[0] - 65] = 0; 
    visited[(int)source[0] - 65] = 1; 

    int node; 
    int visited_cnt; 
    bool check = false; 

    for(int i = 0; i < 26; i++){
        node = dijkstra(); //returns a slot where min length 
        visited[node] = 1; 
        check = false; 
        for(int j = 0; j < 26; j ++){
            if(arr[node][j] == 0){
                continue; 
            }else{
                //out of connected node, find a node that has not been visited and has shorter distance (adjacent nodes) 
                if(visited[j] == 0){
                    check = true; 
                    if(d_arr[j] > d_arr[node] + arr[node][j]){ 
                        d_arr[j] = d_arr[node] + arr[node][j]; 
                        past[j] = node; 
                        
                    }

                    if(check == true){
                        continue; 
                    }else{
                        break; 
                    }
                }
            }
        }
        if(check == true){
            continue; 
        }
        else{
            break; 
        }
    }

    cout << "end for loop" << endl; 

    int path_arr[26] = {0}; //this will save the path from the source to destination in reverse order. 
    int walker = 1; //walker for the path 
    int checker = past[(int)destination[0] - 65]; //checker whether there are nodes between source and destination 
    path_arr[0] = (int)destination[0] - 65; // starts from destination, walk back 

    if(d_arr[(int)destination[0] - 65] < 0 || d_arr[(int) destination[0] - 65] == INF){
        return "error"; 
    }
    
    //when source and destination is connected
    if(checker == -1){
        answer = answer + source + " " + destination + " "; 
    }else{
        //when there are nodes between source and destination 
        while (true){
            path_arr[walker] = checker; 
            checker = past[checker]; 
            walker ++; 
            if(past[checker] != -1){
                break;  
            }
        }

        path_arr[walker] = (int)source[0] - 65;  
    
        for(int i = walker; i >= 0; i--){
            answer = answer + (char)(path_arr[i] + 65) + " "; 
        }
    }

    
    pr = answer + to_string(d_arr[(int) destination[0] - 65]); 

    return pr;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

string Graph::getShortestPath_task6(string source, string destination) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    bool end; 
    int node_cnt = 0; 

    // find number of nodes 
    for(int i = 0; i < 26; i++){
        end = false; 
        for(int j = 0; j < 26; j++){
            if(arr[i][j] > 0 || arr[j][i] > 0){
                if(end == false){
                    node_cnt ++; 
                    end = true; 
                }
            }
        }
    }
    
    for(int i = 0; i < 26; i++){
        d_arr[i] = arr[(int)source[0] - 65][i]; 
        if(d_arr[i] == 0){
            d_arr[i] = INF; 
        }
        cout << i << " : " << d_arr[i] << endl; 
        past[i] = -1; 
    }

    d_arr[(int)source[0] - 65] = 0; 
    visited[(int)source[0] - 65] = 1; 

    int node; 
    int visited_cnt; 
    bool check = false; 

    for(int i = 0; i < 26; i++){
        node = dijkstra(); //returns a slot where min length 
        cout << "node" << node << endl; 
        visited[node] = 1; 
        check = false; 
        for(int j = 0; j < 26; j ++){
            if(arr[node][j] == 0){
                continue; 
            }else{
                //out of connected node, find a node that has not been visited and has shorter distance (adjacent nodes) 
                if(visited[j] == 0){
                    check = true; 
                    if(d_arr[j] > d_arr[node] + arr[node][j]){ 
                        d_arr[j] = d_arr[node] + arr[node][j]; 
                        past[j] = node; 
                    }

                    if(check == true){
                        continue; 
                    }else{
                        break; 
                    }
                }
            }
        }
        if(check == true){
            continue; 
        }
        else{
            break; 
        }
    }

    cout << "end for loop" << endl; 

    int path_arr[26] = {0}; //this will save the path from the source to destination in reverse order. 
    int walker = 1; //walker for the path 
    int checker = past[(int)destination[0] - 65]; //checker whether there are nodes between source and destination 
    path_arr[0] = (int)destination[0] - 65; // starts from destination, walk back 

    if(d_arr[(int)destination[0] - 65] < 0 || d_arr[(int) destination[0] - 65] == INF){
        return "INF"; 
    }
    
    //when source and destination is connected
    if(checker == -1){
        answer = answer + source + " " + destination + " "; 
    }else{
        //when there are nodes between source and destination 
        while (true){
            path_arr[walker] = checker; 
            checker = past[checker]; 
            walker ++; 
            if(past[checker] != -1){
                break;  
            }
        }

        path_arr[walker] = (int)source[0] - 65;  
    
        for(int i = walker; i >= 0; i--){
            answer = answer + (char)(path_arr[i] + 65) + " "; 
        }
    }

    
    pr = answer + to_string(d_arr[(int) destination[0] - 65]); 

    return pr;

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int Graph::primMST(ofstream &fout, string startNode) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    bool end; 
    int node_cnt = 0; 

    // find number of nodes 
    for(int i = 0; i < 26; i++){
        end = false; 
        for(int j = 0; j < 26; j++){
            if(arr[i][j] > 0 || arr[j][i] > 0){
                if(end == false){
                    node_cnt ++; 
                    end = true; 
                }
            }
        }
    }

    //fill out the blank of arr 2d matrix 
    for (int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if(arr[i][j] == 0 && i != j){
                arr[i][j] = INF; 
            }
        }
    }

    // make d_arr set to INF 
    for(int i = 0; i < 26; i++){
        d_arr[i] = arr[(int)startNode[0] - 65][i]; 
        if(d_arr[i] == 0){
            d_arr[i] = INF; 
        }
        past[i] = -1; 
    }

    int walker; 
    int cost = 0; 

    visited [(int)startNode[0] - 65] = 1; 
    order_print[0] = 1; 
    order[0] = (int)startNode[0] - 65; 
    int order_cnt = 0; 
    //walker = startNode -> delete the last order and redo ? -> to print E 
    int iteration = 0; 

    //walk thru the min costs 
    for(int cnt = 1; cnt < node_cnt ; cnt ++){
        walker = dijkstra(); 
        order_cnt ++; 
        if(walker == INF){
            for(int i = 0; i < 26; i ++){
                if(visited[i] == 0){
                    walker = i; 
                    break; 
                }
            }
            order_cnt --; 
        }
        if(past[order[order_cnt-1]] == past[walker] && past[walker] != -1){
            order_cnt --; 
        }
        cost += arr[order[order_cnt-1]][walker]; 

        d_arr[walker] = arr[order[cnt-1]][walker]; 
        order[order_cnt] = walker; 
        order_print[order_cnt] = 1; 
        
        visited [walker] = 1; 
        for (int node = 0; node < node_cnt - 1; node++){
            if(arr[walker][node] != 0 && visited[node] == 0 && arr[walker][node] < d_arr[node]){
                past[node] = walker; 
                d_arr[node] = arr[walker][node]; 
            }
        }

        answer.clear(); 
        for(int j = 0; j <= order_cnt; j++){
            if(order_print[j] == 1){
                answer = answer + (char)(order[j] + 65) + " "; 
            }
        }
        
        fout << answer << " " << endl; 
        }  

    return cost; 

    /*
     //arr[order[cnt-iteration-1]][walker] == arr[order[cnt-iteration-1]][order[cnt-iteration]]
            iteration ++; 
            for(int i = 0; i < 26; i++){
                if(visited[i] == 0){
                    walker = i; 
                    break; 
                }
            }
            order[cnt -iteration] = walker;
            cost += arr[order[cnt-iteration-1]][walker];  
            
    */

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int Graph::kruskalMST(ofstream &fout, string endNode) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    bool end; 
    int node_cnt = 0; 

    // find number of nodes 
    for(int i = 0; i < 26; i++){
        end = false; 
        for(int j = 0; j < 26; j++){
            if(arr[i][j] > 0 || arr[j][i] > 0){
                if(end == false){
                    node_cnt ++; 
                    end = true; 
                }
            }
        }
    }

    // make a parent arr 
    for(int i = 0; i < 26; i++){
        parent [i] = i; 
    }

    edge_list elist; 
    elist.num_edge = 0; 
    
    // find number of edges 
    for(int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            if(arr[i][j] != 0){
                elist.data[elist.num_edge].v1 = i; 
                elist.data[elist.num_edge].v2 = j;
                elist.data[elist.num_edge].cost = arr[i][j];
                (elist.num_edge) ++; 
            }
        }
    }

    //sort the edges in ascending order of cost 
    edge temp; 
    for(int i = 1; i < elist.num_edge; i++){
        for(int k = 0; k < elist.num_edge - 1; k++){
            if(elist.data[k].cost > elist.data[k+1].cost){
                temp = elist.data[k]; 
                elist.data[k] = elist.data[k+1]; 
                elist.data[k+1] = temp; 
            }
        }
    }

    int sum_cost = 0; 
    // check cycle 
    for(int i = 0; i < elist.num_edge; i++){
        if(isCycle(elist.data[i].v1, elist.data[i].v2) == false){ // no cycle 
            sum_cost += elist.data[i].cost; 
            fout << (char) (elist.data[i].v1 + 65) << " " << (char) (elist.data[i].v2 + 65) << " " << elist.data[i].cost << endl; 
            UnionParent(elist.data[i].v1, elist.data[i].v2); 
        }
    }

    
    //find the shortest path : (implementing from the task 5)
    int startnum = elist.data[0].v1; 
    string startNode; 
    find_startNode(startNode); 
    int end_num = (int)endNode[0] - 65; 
    
        for(int i = 0; i < 26; i++){
            d_arr[i] = arr[(int)startNode[0] - 65][i]; 
            if(d_arr[i] == 0){
                d_arr[i] = INF; 
            }
            past[i] = -1; 
        }

        d_arr[(int)startNode[0] - 65] = 0; 
        visited[(int)startNode[0] - 65] = 1; 
        
        int before_node = (int)startNode[0] - 65; 
        int node; 
        for(int i = 0; i < node_cnt - 1; i++){
            node = Kruskal_d(end_num); //returns a slot where min length 
            cout << "node : " << node << endl; 
            visited[node] = 1; 
            past[node] = before_node; 
            before_node = node;  

            for(int j = 0; j < 26; j ++){
                if(arr[node][j] != 0 && visited[j] == 0){
                    d_arr[j] = arr[node][j]; 
                }
            }
        }

        cout << "past: " << endl; 
        for(int i = 0; i < node_cnt; i++){
            cout << past[i] << "\t"; 
        }
        cout << endl; 

        int path_arr[26] = {0}; //this will save the path from the source to destination in reverse order. 
        int walker = 1; //walker for the path 
        int checker = past[(int)endNode[0] - 65]; //checker whether there are nodes between source and destination 
        path_arr[0] = (int)endNode[0] - 65; // starts from destination, walk back 
        
        //when source and destination is connected
        if(checker == -1){
            answer = answer + startNode + " " + endNode + " "; 
        }else{
            //when there are nodes between source and destination 
            while (true){ 
                path_arr[walker] = checker; 
                checker = past[checker]; 
                walker ++; 
                if(checker == -1){
                    break;  
                }
            }
        
            for(int i = walker-1; i >= 0; i--){
                answer = answer + (char)(path_arr[i] + 65) + " "; 
            }
        }

    fout << answer; 

    return sum_cost; 
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/*
    
    int start = 0; 
    bool end = false; 
    int cnt = 0; 
    int visited_cnt = 0; 
    int connected = 1; 

    for(int i = 0; i <= 26; i++){
        for(int j = 0; j <= 26; j++){
            if(arr[i][j] == 1){
                if(end == 0){
                    start = i; 
                }
                end = true; 
                cnt++; 
                break; 
            }
        }
    }

    dfs(start); 
    while(true){
        for(int i = 0; i <= 26; i++){
            for(int j = 0; j <= 26; j++){
                if(arr[i][j] == 1 && visited[i] == 0){
                    answer = answer + "\n"; 
                    connected ++; 
                    dfs(i); 
                }
            }
        }

        for(int k = 0; k <= 26; k++){
            if(visited[k] == 1){
                visited_cnt ++; 
            }
        }
        
        if(visited_cnt == cnt){
            break; 
        }
    }

    cout << "answer : " << answer << endl;  
    answer.clear(); 

    start = 0; 
    end = false; 
    cnt = 0; 
    visited_cnt = 0; 
    connected = 1; 

    for(int i = 0; i <= 26; i++){
        for(int j = 0; j <= 26; j++){
            if(scc[i][j] == 1){
                if(end == 0){
                    start = i; 
                }
                end = true; 
                cnt++; 
                break; 
            }
        }
    }

    
    scc_dfs(start); 
    while(true){
        for(int i = 0; i <= 26; i++){
            for(int j = 0; j <= 26; j++){
                if(scc[i][j] == 1 && visited[i] == 1){
                    answer = answer + "\n"; 
                    connected ++; 
                    scc_dfs(i); 
                }
            }
        }

        for(int k = 0; k <= 26; k++){
            if(visited[k] == 1){
                visited_cnt ++; 
            }
        }
        
        if(visited_cnt == cnt){
            break; 
        }
    }

    pr = to_string(connected) + "\n" + answer; 

    return pr;

*/

   /*
    int num_componenet = 0; 
    int top = -1; 
    //component_arr[NodeMaxCount] 
    //stack[NodeMaxCount]
    //visited [NodeMaxCount]

    for(int i = 0; i < 26; i++){
        if(visited[i] == 0){
            top++; 
            stack[top] = i; 
            
            while (top >= 0){
                int node = stack[top]; 
                top --; 

                if(visited[node] == 0){
                    component_arr [num_componenet] = 0; 
                    scc_dfs(node, num_componenet); 
                    num_componenet ++; 
                }
            }
        }
    }
    
    //int reverse_arr[NodeMaxCount][NodeMaxCount] = {0}; 
    reverse(); 

    top = -1; 
    for(int i = 0; i < 26; i++){
        visited[i] = false;
    }

    for(int i = num_componenet - 1; i >= 0; i--){
        if(visited[i] == 0){
            top ++; 
            reverse_stack[top] = i; 

            while(top >= 0){
                int component = reverse_stack[top]; 
                top --; 

                if(visited[component] == 0){
                    answer = answer + to_string(component) + " "; 

                    for(int j = 0; j < 26; j ++){
                        if (component_arr[j] == component){
                            answer = answer + to_string(j) + " "; 
                        }
                    }
                    
                    answer = answer + "\n"; 

                    visited[component] = true; 
                    reverse_dfs(component, component_arr[component]); 
                }
            } 
        }
    }

    pr = to_string(num_componenet) + answer; 
    
    int num_componenet = 0; 
    int top = -1; 
    //component_arr[NodeMaxCount] 
    //stack[NodeMaxCount]
    //visited [NodeMaxCount]

    for(int i = 0; i < 26; i++){
        if(visited[i] == 0){
            top++; 
            stack[top] = i; 
            
            while (top >= 0){
                int node = stack[top]; 
                top --; 

                if(visited[node] == 0){
                    component_arr [num_componenet] = 0; 
                    scc_dfs(node, num_componenet); 
                    num_componenet ++; 
                }
            }
        }
    }
    
    //int reverse_arr[NodeMaxCount][NodeMaxCount] = {0}; 
    reverse(); 

    top = -1; 
    for(int i = 0; i < 26; i++){
        visited[i] = false;
    }

    for(int i = num_componenet - 1; i >= 0; i--){
        if(visited[i] == 0){
            top ++; 
            reverse_stack[top] = i; 

            while(top >= 0){
                int component = reverse_stack[top]; 
                top --; 

                if(visited[component] == 0){
                    answer = answer + to_string(component) + " "; 

                    for(int j = 0; j < 26; j ++){
                        if (component_arr[j] == component){
                            answer = answer + to_string(j) + " "; 
                        }
                    }
                    
                    answer = answer + "\n"; 

                    visited[component] = true; 
                    reverse_dfs(component, component_arr[component]); 
                }
            } 
        }
    }

    pr = to_string(num_componenet) + answer; 
    */