#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Function to find the center of a star graph
int findCenter(vector<vector<int>>& edges) {
    // The center of a star graph is the node that is connected to all other nodes
    // In a star graph, there are exactly two edges that connect to the center node
    // We can use a map to count the degree of each node
    vector<int> degree(edges.size() + 1, 0);
    
    for (const auto& edge : edges) {
        degree[edge[0]]++;
        degree[edge[1]]++;
    }
    
    // The center will be the node with degree equal to the number of edges
    for (int i = 1; i < degree.size(); i++) {
        if (degree[i] == edges.size()) {
            return i;
        }
    }
    
    return -1; // This should never happen in a valid star graph
}