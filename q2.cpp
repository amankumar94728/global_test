#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <utility>

using namespace std;


typedef unordered_map<int, unordered_map<int, int>> Graph;


unordered_map<int, int> dijkstra(const Graph& graph, int source) {

    unordered_map<int, int> distances;
    for (const auto& node : graph) {
        distances[node.first] = numeric_limits<int>::max();
    }
    distances[source] = 0;
    

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    
    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();
        

        if (current_distance > distances[current_vertex]) {
            continue;
        }
        

        for (const auto& neighbor : graph.at(current_vertex)) {
            int vertex = neighbor.first;
            int weight = neighbor.second;
            int distance = current_distance + weight;
            
            if (distance < distances[vertex]) {
                distances[vertex] = distance;
                pq.push({distance, vertex});
            }
        }
    }
    
    return distances;
}


int main() {

    Graph graph = {
        {0, {{1, 4}, {2, 1}}},
        {1, {{3, 1}}},
        {2, {{1, 2}, {3, 5}}},
        {3, {}}
    };
    
    int source = 0;
    unordered_map<int, int> result = dijkstra(graph, source);
    

    for (const auto& [vertex, distance] : result) {
        cout << "Distance from vertex " << source << " to vertex " << vertex << " is " << distance << endl;
    }
    
    return 0;
}
